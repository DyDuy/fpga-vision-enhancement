import { prepareImage, enhanceImage, decodeHexImage, analyzeImage, FPGA_WIDTH, FPGA_HEIGHT } from "./processor.js";
import { openHistory } from "./storage.js";
import { processOnFpga, MAX_OUTPUT_HEX_BYTES } from "./fpga-client.js";
import { drawHistogram } from "./histogram.js";

const $ = id => document.getElementById(id);
const MAX_FILES = 12;
const MAX_BYTES = 20 * 1024 * 1024;
const state = { images: [], selected: null, processing: null, importing: false, exporting: null,
  version: 0, history: [], store: null, historyReady: false, historyBusy: false };
const historyUrls = new Map();
let toastTimer;
let historyOperations = Promise.resolve();

function icon(name) {
  const svg = document.createElementNS("http://www.w3.org/2000/svg", "svg");
  svg.classList.add("icon");
  svg.setAttribute("aria-hidden", "true");
  const use = document.createElementNS(svg.namespaceURI, "use");
  use.setAttribute("href", `#icon-${name}`);
  svg.append(use);
  return svg;
}

function toast(message, error = false) {
  clearTimeout(toastTimer);
  $("toast-message").textContent = message;
  $("toast").classList.toggle("error", error);
  $("toast").hidden = false;
  toastTimer = setTimeout(() => { $("toast").hidden = true; }, error ? 6500 : 3800);
}

function storageWarning(message) {
  $("storage-warning").textContent = message;
  $("storage-warning").hidden = false;
}

function selectedImage() {
  return state.images.find(image => image.id === state.selected);
}

function formatBytes(bytes) {
  return bytes >= 1024 * 1024 ? `${(bytes / (1024 * 1024)).toLocaleString("en-US", { maximumFractionDigits: 1 })} MB` : `${Math.max(1, Math.round(bytes / 1024))} KB`;
}

function newEntry(data) {
  return { ...data, sourceUrl: URL.createObjectURL(data.sourceBlob),
    resultUrl: data.resultBlob ? URL.createObjectURL(data.resultBlob) : null,
    resultHexUrl: data.resultHexBlob ? URL.createObjectURL(data.resultHexBlob) : null };
}

function resultLabel(image) {
  return image?.resultKind === "fpga" ? "FPGA" : image?.resultKind === "import" ? "Imported HEX" : "Browser demo";
}

function setControls() {
  const selected = selectedImage();
  const busy = !!state.processing;
  $("add-images").disabled = state.importing || state.images.length >= MAX_FILES;
  $("upload-target").disabled = state.importing;
  $("file-input").disabled = state.importing;
  $("clear-workspace").disabled = !state.images.length && !state.importing && !busy;
  $("process-image").disabled = !selected || busy || state.importing || !!state.exporting || !state.historyReady;
  $("download-hex").disabled = !selected || busy || state.importing || !!state.exporting;
  $("download-hex-label").textContent = state.exporting ? "Preparing HEX…" : "Download input HEX";
  $("load-output-hex").disabled = !selected || busy || state.importing || !!state.exporting || !state.historyReady;
  $("output-hex-input").disabled = $("load-output-hex").disabled;
  $("processing-mode").disabled = busy;
  $("fpga-endpoint").disabled = busy;
  const demo = $("processing-mode").value === "demo";
  $("demo-controls").hidden = !demo;
  $("connection-settings").hidden = demo;
  $("strength").disabled = busy;
  $("process-label").textContent = busy ? "Processing…" : demo ? "Run browser demo" : "Process on FPGA";
  $("mode-badge-text").textContent = demo ? "Browser demo · v0.2" : "FPGA workflow · v0.2";
  $("processing-note").textContent = demo ? "Browser demo · No FPGA request is sent" : "FPGA gateway · Configure the endpoint when your board is ready";
  $("privacy-note").textContent = demo ? "Demo images are processed on this device. History stays in this browser." : "FPGA mode sends images to your configured gateway. History stays in this browser.";
  $("clear-history").disabled = !state.history.length || state.historyBusy || !state.historyReady;
}

function setPreview(id, url) {
  const image = $(id);
  image.hidden = !url;
  if (url) image.src = url;
  else image.removeAttribute("src");
}

function renderWorkspace() {
  const image = selectedImage();
  const busy = image && state.processing?.id === image.id;
  setPreview("source-image", image?.sourceUrl);
  setPreview("result-image", image?.resultUrl);
  $("upload-target").hidden = !!image;
  $("source-overlay").hidden = !image;
  $("result-overlay").hidden = !image?.resultBlob || busy;
  $("result-placeholder").hidden = !!image?.resultBlob || busy;
  $("processing-overlay").hidden = !busy;
  $("result-stage").setAttribute("aria-busy", String(!!busy));
  $("source-description").textContent = image ? `${image.name} · ${formatBytes(image.sourceBytes)} · ${image.originalWidth} × ${image.originalHeight} → ${image.width} × ${image.height} px` : "No image selected";
  $("source-description").title = image ? $("source-description").textContent : "";
  const normalized = !image || (image.width === FPGA_WIDTH && image.height === FPGA_HEIGHT);
  $("source-dimensions").textContent = `${normalized ? "FPGA input" : "Saved input"} · ${image?.width ?? FPGA_WIDTH} × ${image?.height ?? FPGA_HEIGHT} px`;
  $("source-format").textContent = image ? image.format : "INPUT";
  $("result-status").textContent = busy ? "PROCESSING" : image?.resultBlob ? "COMPLETE" : "READY";
  $("result-status").className = `small-badge${busy ? " busy" : image?.resultBlob ? " success" : ""}`;
  $("result-description").textContent = busy ? "Preparing the processed output…" : image?.resultBlob ?
    `${resultLabel(image)} · ${image.width} × ${image.height} px · ${(image.elapsed / 1000).toLocaleString("en-US", { maximumFractionDigits: 2 })} s${image.resultKind === "fpga" ? " round trip" : image.resultKind === "import" ? " import" : ` · Strength ${image.strength}%`}` :
    image ? "Process on FPGA or load an output HEX file" : "Add an image to get started";
  $("result-overlay").textContent = `AFTER · ${resultLabel(image).toUpperCase()}`;
  $("result-image").alt = `${resultLabel(image)} output image`;
  $("expand-source").disabled = !image;
  $("expand-result").disabled = !image?.resultBlob;
  $("download-result").hidden = !image?.resultBlob || busy;
  if (image?.resultUrl) {
    $("download-result").href = image.resultUrl;
    $("download-result").download = `${image.name.replace(/\.[^.]+$/, "")}-enhanced.png`;
  } else $("download-result").removeAttribute("href");
  $("download-output-hex").hidden = !image?.resultHexUrl || busy;
  if (image?.resultHexUrl) $("download-output-hex").href = image.resultHexUrl;
  else $("download-output-hex").removeAttribute("href");
  $("queue-count").textContent = state.images.length;
  renderQueue();
  setControls();
  renderTransfer();
  renderHistogramPanel();
}

function renderTransfer() {
  const image = selectedImage();
  const operation = state.processing?.id === image?.id ? state.processing : null;
  const messages = {
    preparing: ["Preparing input HEX…", "Normalizing the selected image to 640 × 480"],
    sending: ["Waiting for FPGA…", "Sending input HEX and waiting for processed output HEX"],
    receiving: ["Receiving output HEX…", "Reading the processed frame from the gateway"],
    decoding: ["Decoding output HEX…", "Rebuilding the image and calculating its brightness histogram"],
    demo: ["Running browser demo…", "Processing locally; no FPGA request is sent"]
  };
  const message = operation ? messages[operation.stage] || messages.preparing : null;
  if (message) {
    $("processing-message").textContent = message[0];
    $("processing-detail").textContent = message[1];
  }
  $("transfer-status").textContent = operation ? message.join(" ") : image?.lastError ? image.lastError : image?.resultBlob ?
    image.resultKind === "fpga" ? "Gateway output HEX received and decoded. The brightness comparison uses the returned pixels." :
    image.resultKind === "import" ? "Output HEX loaded from a file. Hardware transfer has not been verified." :
    "Browser demo result. No FPGA processing was performed." : image ?
    "Input HEX is ready. Process on FPGA when the gateway is available, or load an output HEX file to test decoding." :
    "Add an image to prepare input_image.hex. Configure the gateway when your board is ready.";
  const index = { preparing: 0, sending: 1, receiving: 2, decoding: 3 }[operation?.stage];
  const demo = operation?.mode === "demo" || (!operation && $("processing-mode").value === "demo");
  $("transfer-steps").hidden = demo;
  [...$("transfer-steps").children].forEach((step, position) => {
    let status = "pending";
    if (operation && index !== undefined) status = position < index ? "done" : position === index ? "active" : "pending";
    else if (image?.resultKind === "fpga") status = "done";
    else if (image && position === 0) status = "done";
    if (image?.resultKind === "import" && !operation && position >= 2) status = "done";
    if (operation?.mode === "import" && position === 1) status = "pending";
    step.dataset.status = status;
  });
}

function renderHistogramPanel() {
  const image = selectedImage();
  const input = image?.inputHistogram, output = image?.outputHistogram;
  const busy = !!state.processing && state.processing.id === image?.id;
  const ready = !!image?.resultBlob && !!input && !!output && !busy;
  $("histogram-empty").hidden = ready;
  $("histogram-content").hidden = !ready;
  $("histogram-empty").textContent = busy ? "Waiting for the new output before updating the brightness comparison…" : "Process an image or load an output HEX file to compare brightness.";
  if (!ready) return;
  const level = Number($("histogram-level").value);
  drawHistogram($("histogram-chart"), input, output, level);
  const fixed = value => value.toLocaleString("en-US", { minimumFractionDigits: 2, maximumFractionDigits: 2 });
  const signed = value => `${value > 0 ? "+" : ""}${fixed(value)}`;
  $("input-mean").textContent = fixed(input.mean);
  $("output-mean").textContent = fixed(output.mean);
  $("mean-change").textContent = signed(output.mean - input.mean);
  $("input-spread").textContent = fixed(input.stdDev);
  $("output-spread").textContent = fixed(output.stdDev);
  $("spread-change").textContent = signed(output.stdDev - input.stdDev);
  const inputCount = input.bins[level], outputCount = output.bins[level];
  $("histogram-inspection").textContent = `Level ${level} · Input: ${inputCount.toLocaleString("en-US")} pixels · Output: ${outputCount.toLocaleString("en-US")} pixels`;
  const delta = output.mean - input.mean;
  $("histogram-explanation").textContent = `${resultLabel(image)} · ${Math.abs(delta) < .005 ? "Mean brightness is unchanged." : `Output is ${fixed(Math.abs(delta))} levels ${delta > 0 ? "brighter" : "darker"} on average.`} Input: ${input.total.toLocaleString("en-US")} pixels; output: ${output.total.toLocaleString("en-US")} pixels.`;
}

async function ensureHistograms(image) {
  if (!image.resultBlob || (image.inputHistogram && image.outputHistogram)) return;
  const sourceBlob = image.sourceBlob, resultBlob = image.resultBlob;
  try {
    const [inputHistogram, outputHistogram] = await Promise.all([
      image.inputHistogram || analyzeImage(sourceBlob), image.outputHistogram || analyzeImage(resultBlob)
    ]);
    if (!state.images.includes(image) || image.sourceBlob !== sourceBlob || image.resultBlob !== resultBlob) return;
    Object.assign(image, { inputHistogram, outputHistogram });
    if (selectedImage() === image) renderHistogramPanel();
  } catch {
    if (selectedImage() === image) $("histogram-empty").textContent = "Could not calculate the histogram for this saved image.";
  }
}

function renderQueue() {
  const queue = $("image-queue");
  queue.replaceChildren();
  if (!state.images.length) {
    const empty = document.createElement("span");
    empty.className = "queue-empty";
    empty.textContent = state.importing ? "Preparing image previews…" : "Your images will appear here.";
    queue.append(empty);
    return;
  }
  for (const image of state.images) {
    const button = document.createElement("button");
    button.type = "button";
    button.className = `queue-item${image.resultBlob ? " done" : ""}`;
    button.setAttribute("aria-label", `Select image ${image.name}`);
    button.setAttribute("aria-pressed", String(image.id === state.selected));
    button.title = image.name;
    const thumbnail = document.createElement("img");
    thumbnail.src = image.sourceUrl;
    thumbnail.alt = "";
    button.append(thumbnail);
    button.addEventListener("click", () => {
      state.selected = image.id;
      renderWorkspace();
      // Rebuilding thumbnails must not discard the keyboard focus.
      [...$("image-queue").children].find(item => item.getAttribute("aria-pressed") === "true")?.focus();
    });
    queue.append(button);
  }
  if (state.images.length < MAX_FILES) {
    const add = document.createElement("button");
    add.type = "button";
    add.className = "queue-add";
    add.setAttribute("aria-label", "Add images to session");
    add.disabled = state.importing;
    add.append(icon("plus"));
    add.addEventListener("click", openPicker);
    queue.append(add);
  }
}

function openPicker() {
  if (!state.importing && state.images.length < MAX_FILES) $("file-input").click();
}

async function addFiles(files) {
  if (!files.length || state.importing) return;
  const remaining = MAX_FILES - state.images.length;
  if (remaining <= 0) return toast(`You can add up to ${MAX_FILES} images per session. Clear session images to add more.`, true);
  const selectedFiles = [...files].slice(0, remaining);
  if (files.length > remaining) toast(`Adding only ${remaining} ${remaining === 1 ? "image" : "images"} to keep this session within the ${MAX_FILES}-image limit.`, true);
  const version = state.version;
  state.importing = true;
  renderWorkspace();
  let added = 0;
  try {
    for (const file of selectedFiles) {
      if (version !== state.version) break;
      if (!/\.(jpe?g|png|webp)$/i.test(file.name) || (file.type && !["image/jpeg", "image/png", "image/webp"].includes(file.type))) {
        toast(`${file.name}: only JPG, PNG and WebP images are supported.`, true);
        continue;
      }
      if (!file.size || file.size > MAX_BYTES) {
        toast(`${file.name}: the image must not be empty or larger than 20 MB.`, true);
        continue;
      }
      try {
        const prepared = await prepareImage(file);
        if (version !== state.version) break;
        const entry = newEntry({ ...prepared, id: crypto.randomUUID(), name: file.name,
          format: file.name.split(".").pop().toUpperCase(), sourceBytes: file.size });
        state.images.push(entry);
        if (!added) state.selected = entry.id;
        added++;
        renderWorkspace();
      } catch (error) {
        if (version !== state.version) break;
        toast(`${file.name}: could not read the image. ${error.message || "Try another file."}`, true);
      }
    }
  } finally {
    if (version === state.version) {
      state.importing = false;
      $("file-input").value = "";
      renderWorkspace();
      if (added) $("workspace-announcement").textContent = `Added ${added} ${added === 1 ? "image" : "images"} to the session.`;
    }
  }
}

function clearWorkspace() {
  state.version++;
  state.processing?.controller.abort();
  state.processing = null;
  state.exporting = null;
  state.importing = false;
  $("file-input").value = "";
  $("output-hex-input").value = "";
  $("lightbox").close();
  const previous = state.images;
  state.images = [];
  state.selected = null;
  renderWorkspace();
  for (const image of previous) {
    URL.revokeObjectURL(image.sourceUrl);
    if (image.resultUrl) URL.revokeObjectURL(image.resultUrl);
    if (image.resultHexUrl) URL.revokeObjectURL(image.resultHexUrl);
  }
  toast("Session images cleared. You can still view your saved history.");
}

async function downloadHex() {
  const image = selectedImage();
  if (!image || state.processing || state.importing || state.exporting) return;
  const operation = { version: state.version };
  state.exporting = operation;
  setControls();
  try {
    // Older history records predate HEX export; normalize their source on demand.
    const blob = image.hexBlob || (await prepareImage(image.sourceBlob)).hexBlob;
    if (operation.version !== state.version || selectedImage() !== image) return;
    image.hexBlob = blob;
    const url = URL.createObjectURL(blob);
    const link = document.createElement("a");
    link.href = url;
    link.download = "input_image.hex";
    document.body.append(link);
    try { link.click(); }
    finally {
      link.remove();
      setTimeout(() => URL.revokeObjectURL(url), 60_000);
    }
    toast(`FPGA input exported: ${FPGA_WIDTH} × ${FPGA_HEIGHT}, RGB888.`);
  } catch {
    toast("Could not export the FPGA HEX file. Please try again.", true);
  } finally {
    if (state.exporting === operation) {
      state.exporting = null;
      setControls();
    }
  }
}

function historyOperation(action) {
  const promise = historyOperations.then(action);
  historyOperations = promise.catch(() => {});
  return promise;
}

async function saveHistory(record) {
  return historyOperation(async () => {
    if (state.store) {
      try { await state.store.save(record); }
      catch { storageWarning("Storage is full or unavailable. This result is only available for this session; download it to keep a copy."); }
    }
    state.history.unshift(record);
    renderHistory();
  });
}

function operationIsCurrent(operation) {
  return state.processing === operation && operation.version === state.version && !operation.controller.signal.aborted;
}

function setStage(operation, stage) {
  if (!operationIsCurrent(operation)) return;
  operation.stage = stage;
  renderTransfer();
}

async function ensureInputFrame(image, operation) {
  if (image.hexBlob && image.inputHistogram && image.width === FPGA_WIDTH && image.height === FPGA_HEIGHT) return image;
  const prepared = await prepareImage(image.sourceBlob);
  return operationIsCurrent(operation) ? prepared : null;
}

async function acceptResult(image, operation, result, input, start, strength = null) {
  if (!operationIsCurrent(operation)) return;
  const oldUrl = image.resultUrl, oldHexUrl = image.resultHexUrl;
  if (input.sourceBlob !== image.sourceBlob) {
    const previous = image.sourceUrl;
    image.sourceUrl = URL.createObjectURL(input.sourceBlob);
    URL.revokeObjectURL(previous);
  }
  Object.assign(image, result, {
    sourceBlob: input.sourceBlob, hexBlob: input.hexBlob, inputHistogram: input.inputHistogram,
    width: input.width, height: input.height,
    resultUrl: URL.createObjectURL(result.resultBlob),
    resultHexUrl: result.resultHexBlob ? URL.createObjectURL(result.resultHexBlob) : null,
    resultHexBlob: result.resultHexBlob || null,
    elapsed: performance.now() - start, strength, resultKind: operation.mode,
    requestId: operation.mode === "fpga" ? operation.requestId : null, lastError: null
  });
  if (oldUrl) URL.revokeObjectURL(oldUrl);
  if (oldHexUrl) URL.revokeObjectURL(oldHexUrl);
  const record = {
    id: crypto.randomUUID(), name: image.name, format: image.format,
    sourceBlob: image.sourceBlob, resultBlob: image.resultBlob, resultHexBlob: image.resultHexBlob,
    width: image.width, height: image.height,
    originalWidth: image.originalWidth, originalHeight: image.originalHeight,
    sourceBytes: image.sourceBytes, elapsed: image.elapsed, strength,
    resultKind: image.resultKind, requestId: image.requestId,
    inputHistogram: image.inputHistogram, outputHistogram: image.outputHistogram, createdAt: Date.now()
  };
  renderWorkspace();
  await saveHistory(record);
  if (operationIsCurrent(operation)) toast(`${resultLabel(image)} output is ready. Brightness comparison updated.`);
}

async function runProcessing(mode, file = null) {
  const image = selectedImage();
  if (!image || state.processing || state.importing || state.exporting || !state.historyReady) return;
  const operation = { id: image.id, controller: new AbortController(), version: state.version,
    mode, requestId: crypto.randomUUID(), stage: "preparing" };
  const endpoint = $("fpga-endpoint").value;
  const strength = Number($("strength").value);
  state.processing = operation;
  image.lastError = null;
  renderWorkspace();
  const start = performance.now();
  try {
    const input = await ensureInputFrame(image, operation);
    if (!input || !operationIsCurrent(operation)) return;
    let result;
    if (mode === "demo") {
      setStage(operation, "demo");
      const resultBlob = await enhanceImage(input.sourceBlob, strength, operation.controller.signal);
      if (!operationIsCurrent(operation)) return;
      result = { resultBlob, outputHistogram: await analyzeImage(resultBlob) };
    } else {
      let text;
      if (mode === "import") {
        if (!file || !/\.hex$/i.test(file.name) || !file.size || file.size > MAX_OUTPUT_HEX_BYTES) {
          throw new Error("Choose a non-empty RGB888 .hex file for a 640 × 480 frame.");
        }
        text = await file.text();
      } else {
        text = await processOnFpga(input.hexBlob, {
          endpoint, requestId: operation.requestId, signal: operation.controller.signal,
          onStage: stage => setStage(operation, stage)
        });
      }
      if (!operationIsCurrent(operation)) return;
      setStage(operation, "decoding");
      result = await decodeHexImage(text);
    }
    await acceptResult(image, operation, result, input, start, mode === "demo" ? strength : null);
  } catch (error) {
    if (operationIsCurrent(operation) && error.name !== "AbortError") {
      image.lastError = error.message || "Processing failed. Please try again.";
      toast(image.lastError, true);
    }
  } finally {
    if (state.processing === operation) {
      state.processing = null;
      $("output-hex-input").value = "";
      renderWorkspace();
    }
  }
}

function processImage() {
  return runProcessing($("processing-mode").value === "demo" ? "demo" : "fpga");
}

function recordUrls(record) {
  if (!historyUrls.has(record.id)) historyUrls.set(record.id,
    { source: URL.createObjectURL(record.sourceBlob), result: URL.createObjectURL(record.resultBlob) });
  return historyUrls.get(record.id);
}

function restoreHistory(record) {
  if (state.importing || state.processing) return toast("Please wait for the current task to finish before opening history.");
  const id = `history-${record.id}`;
  const existing = state.images.findIndex(item => item.id === id);
  if (existing < 0 && state.images.length >= MAX_FILES) return toast("This session is full. Clear session images before opening more history.", true);
  // A workspace copy may have been processed again; always restore the saved snapshot.
  const previous = existing < 0 ? null : state.images[existing];
  const image = newEntry({ ...record, id });
  if (existing < 0) state.images.push(image);
  else state.images[existing] = image;
  state.selected = image.id;
  if (Number.isFinite(image.strength)) {
    $("strength").value = image.strength;
    $("strength-value").value = `${image.strength}%`;
  }
  renderWorkspace();
  if (previous) {
    URL.revokeObjectURL(previous.sourceUrl);
    if (previous.resultUrl) URL.revokeObjectURL(previous.resultUrl);
    if (previous.resultHexUrl) URL.revokeObjectURL(previous.resultHexUrl);
  }
  ensureHistograms(image);
  $("workspace").scrollIntoView({ behavior: "smooth" });
  $("process-image").focus({ preventScroll: true });
}

function renderHistory() {
  const list = $("history-list");
  list.replaceChildren();
  const currentIds = new Set(state.history.map(record => record.id));
  for (const [id, urls] of historyUrls) if (!currentIds.has(id)) {
    URL.revokeObjectURL(urls.source);
    URL.revokeObjectURL(urls.result);
    historyUrls.delete(id);
  }
  $("history-empty").hidden = state.history.length > 0;
  $("history-count").textContent = state.history.length;
  $("history-nav-count").textContent = state.history.length;
  for (const record of state.history) {
    const urls = recordUrls(record);
    const card = document.createElement("article");
    card.className = "history-card";
    const open = document.createElement("button");
    open.type = "button";
    open.className = "history-open";
    open.setAttribute("aria-label", `View result for ${record.name}`);
    open.addEventListener("click", () => restoreHistory(record));
    const thumbnails = document.createElement("div");
    thumbnails.className = "history-thumbnails";
    for (const [url, alt] of [[urls.source, "Before enhancement"], [urls.result, `${resultLabel(record)} output image`]]) {
      const thumbnail = document.createElement("img");
      thumbnail.src = url;
      thumbnail.alt = alt;
      thumbnail.loading = "lazy";
      thumbnails.append(thumbnail);
    }
    const content = document.createElement("div");
    content.className = "history-card-content";
    const title = document.createElement("h3");
    title.textContent = record.name;
    title.title = record.name;
    const description = document.createElement("p");
    description.textContent = `${record.width} × ${record.height} px · ${resultLabel(record)}${Number.isFinite(record.strength) ? ` · Strength ${record.strength}%` : ""}`;
    content.append(title, description);
    open.append(thumbnails, content);
    const footer = document.createElement("div");
    footer.className = "history-card-footer";
    const time = document.createElement("time");
    time.dateTime = new Date(record.createdAt).toISOString();
    time.textContent = new Date(record.createdAt).toLocaleString("en-US", { day: "2-digit", month: "2-digit", year: "numeric", hour: "2-digit", minute: "2-digit" });
    const remove = document.createElement("button");
    remove.type = "button";
    remove.className = "icon-button";
    remove.disabled = state.historyBusy;
    remove.setAttribute("aria-label", `Delete history for ${record.name}`);
    remove.append(icon("trash"));
    remove.addEventListener("click", () => removeHistory(record.id));
    footer.append(time, remove);
    card.append(open, footer);
    list.append(card);
  }
  setControls();
}

async function removeHistory(id) {
  if (state.historyBusy) return;
  state.historyBusy = true;
  renderHistory();
  try {
    await historyOperation(async () => {
      if (state.store) await state.store.remove(id);
      state.history = state.history.filter(record => record.id !== id);
    });
    toast("Image removed from history.");
  } catch { toast("Could not delete the saved history entry. Please try again.", true); }
  finally { state.historyBusy = false; renderHistory(); }
}

async function clearHistory() {
  if (!state.history.length || state.historyBusy || $("confirm-dialog").open) return;
  const dialog = $("confirm-dialog");
  dialog.returnValue = "cancel";
  const confirmed = new Promise(resolve => dialog.addEventListener("close", () => resolve(dialog.returnValue === "confirm"), { once: true }));
  dialog.showModal();
  if (!await confirmed) return;
  state.historyBusy = true;
  renderHistory();
  try {
    await historyOperation(async () => {
      if (state.store) await state.store.clear();
      state.history = [];
    });
    toast("All history cleared from this browser.");
  } catch { toast("Could not clear history. Please try again.", true); }
  finally { state.historyBusy = false; renderHistory(); }
}

function expandImage(kind) {
  const image = selectedImage();
  const url = kind === "source" ? image?.sourceUrl : image?.resultUrl;
  if (!url) return;
  $("lightbox-image").src = url;
  $("lightbox-image").alt = `${image.name} · ${kind === "source" ? "Input image" : `${resultLabel(image)} output`}`;
  $("lightbox-caption").textContent = $("lightbox-image").alt;
  $("lightbox").showModal();
}

async function initialize() {
  try {
    const settings = JSON.parse(localStorage.getItem("fpga-vision-connection") || "null");
    if (settings?.mode === "demo" || settings?.mode === "fpga") $("processing-mode").value = settings.mode;
    if (typeof settings?.endpoint === "string") $("fpga-endpoint").value = settings.endpoint;
  } catch { /* Connection settings are optional when storage is unavailable. */ }
  try {
    state.store = await openHistory();
    const saved = await state.store.all();
    state.history = saved.filter(record => record.sourceBlob instanceof Blob && record.resultBlob instanceof Blob &&
      typeof record.id === "string" && typeof record.name === "string" && Number.isFinite(record.createdAt));
    state.history.sort((a, b) => b.createdAt - a.createdAt);
  } catch {
    state.store = null;
    storageWarning("Persistent storage is unavailable in this browser. History will only last for this session; download any results you want to keep.");
  } finally {
    state.historyReady = true;
    renderHistory();
    renderWorkspace();
  }
}

$("add-images").addEventListener("click", openPicker);
$("upload-target").addEventListener("click", openPicker);
$("file-input").addEventListener("change", event => addFiles(event.target.files));
$("clear-workspace").addEventListener("click", clearWorkspace);
$("process-image").addEventListener("click", processImage);
$("download-hex").addEventListener("click", downloadHex);
$("load-output-hex").addEventListener("click", () => { if (!$("load-output-hex").disabled) $("output-hex-input").click(); });
$("output-hex-input").addEventListener("change", event => {
  const file = event.target.files[0];
  if (file) runProcessing("import", file);
});
for (const id of ["processing-mode", "fpga-endpoint"]) $(id).addEventListener("change", () => {
  try { localStorage.setItem("fpga-vision-connection", JSON.stringify({ mode: $("processing-mode").value, endpoint: $("fpga-endpoint").value.trim() })); }
  catch { /* Settings remain available for the current page. */ }
  renderWorkspace();
});
$("histogram-level").addEventListener("input", renderHistogramPanel);
$("histogram-chart").addEventListener("pointermove", event => {
  const bounds = $("histogram-chart").getBoundingClientRect();
  if (!bounds.width) return;
  $("histogram-level").value = String(Math.round(Math.max(0, Math.min(255, ((event.clientX - bounds.left) / bounds.width * 800 - 56) / 708 * 255))));
  renderHistogramPanel();
});
$("clear-history").addEventListener("click", clearHistory);
$("strength").addEventListener("input", event => { $("strength-value").value = `${event.target.value}%`; });
$("expand-source").addEventListener("click", () => expandImage("source"));
$("expand-result").addEventListener("click", () => expandImage("result"));
$("close-lightbox").addEventListener("click", () => $("lightbox").close());
$("lightbox").addEventListener("click", event => { if (event.target === $("lightbox")) $("lightbox").close(); });
let dragDepth = 0;
$("drop-zone").addEventListener("dragenter", event => { event.preventDefault(); dragDepth++; $("drop-zone").classList.add("drag-over"); });
$("drop-zone").addEventListener("dragover", event => { event.preventDefault(); event.dataTransfer.dropEffect = "copy"; });
$("drop-zone").addEventListener("dragleave", () => { if (--dragDepth <= 0) { dragDepth = 0; $("drop-zone").classList.remove("drag-over"); } });
$("drop-zone").addEventListener("drop", event => {
  event.preventDefault();
  dragDepth = 0;
  $("drop-zone").classList.remove("drag-over");
  addFiles(event.dataTransfer.files);
});
// Dropping outside the upload area must not navigate away and discard the session.
window.addEventListener("dragover", event => event.preventDefault());
window.addEventListener("drop", event => event.preventDefault());

initialize();
