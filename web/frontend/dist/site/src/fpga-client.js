export const MAX_OUTPUT_HEX_BYTES = 640 * 480 * 8 + 16;

async function readHexResponse(response, signal) {
  const length = response.headers.get("Content-Length");
  if (length && Number(length) > MAX_OUTPUT_HEX_BYTES) throw new Error("The FPGA response is larger than a 640 × 480 RGB888 frame.");
  if (!response.body) throw new Error("The FPGA gateway returned an empty response.");
  const reader = response.body.getReader();
  const chunks = [];
  let size = 0, complete = false;
  try {
    while (true) {
      signal.throwIfAborted();
      const { done, value } = await reader.read();
      if (done) break;
      size += value.byteLength;
      if (size > MAX_OUTPUT_HEX_BYTES) throw new Error("The FPGA response is larger than a 640 × 480 RGB888 frame.");
      chunks.push(value);
    }
    complete = true;
  } finally {
    if (!complete) await reader.cancel().catch(() => {});
    reader.releaseLock();
  }
  const bytes = new Uint8Array(size);
  let offset = 0;
  for (const chunk of chunks) { bytes.set(chunk, offset); offset += chunk.length; }
  try { return new TextDecoder("utf-8", { fatal: true }).decode(bytes); }
  catch { throw new Error("The FPGA response must contain valid HEX text."); }
}

export async function processOnFpga(hexBlob, {
  endpoint, requestId, signal, onStage = () => {}, timeoutMs = 120_000,
  fetchImpl = globalThis.fetch
}) {
  const address = (endpoint || "").trim();
  if (!address) throw new Error("Set the FPGA gateway URL before processing.");
  const url = new URL(address, globalThis.location?.href || "http://localhost/");
  if (!["http:", "https:"].includes(url.protocol) || url.username || url.password) {
    throw new Error("Use an HTTP or HTTPS gateway URL without embedded credentials.");
  }
  if (!(hexBlob instanceof Blob) || !hexBlob.size || hexBlob.size > MAX_OUTPUT_HEX_BYTES) {
    throw new Error("The input HEX file is missing or too large.");
  }
  if (typeof requestId !== "string" || !/^[A-Za-z0-9_-]{1,128}$/.test(requestId)) throw new Error("A valid request ID is required.");
  if (signal?.aborted) throw signal.reason || new DOMException("Processing cancelled.", "AbortError");
  const controller = new AbortController();
  const abort = () => controller.abort(signal.reason);
  signal?.addEventListener("abort", abort, { once: true });
  let timedOut = false;
  let response = null, complete = false;
  const timer = setTimeout(() => { timedOut = true; controller.abort(); }, timeoutMs);
  try {
    onStage("sending");
    response = await fetchImpl(url.href, {
      method: "POST", body: hexBlob, signal: controller.signal,
      credentials: "omit", redirect: "error",
      headers: {
        "Content-Type": "text/plain;charset=utf-8", "Accept": "text/plain",
        "X-Image-Width": "640", "X-Image-Height": "480", "X-Pixel-Format": "RGB888",
        "X-Input-Filename": "input_image.hex", "X-Request-Id": requestId
      }
    });
    if (!response.ok) {
      if (response.status === 404) throw new Error("The FPGA endpoint was not found. Set the correct gateway URL.");
      throw new Error(`FPGA gateway returned HTTP ${response.status}. No new output was accepted.`);
    }
    const returnedId = response.headers.get("X-Request-Id");
    if (returnedId && returnedId !== requestId) throw new Error("The FPGA response belongs to another request.");
    const contentType = response.headers.get("Content-Type") || "";
    if (/text\/html|application\/json/i.test(contentType)) throw new Error("The gateway must return output HEX text, not an HTML or JSON page.");
    onStage("receiving");
    const text = await readHexResponse(response, controller.signal);
    controller.signal.throwIfAborted();
    complete = true;
    return text;
  } catch (error) {
    if (timedOut) throw new Error("The FPGA request timed out. Check the gateway and board before retrying.");
    if (signal?.aborted) throw signal.reason || new DOMException("Processing cancelled.", "AbortError");
    if (error instanceof TypeError) throw new Error("Could not reach the FPGA gateway. Check its HTTPS URL and CORS settings.");
    throw error;
  } finally {
    clearTimeout(timer);
    signal?.removeEventListener("abort", abort);
    if (response && !complete) await response.body?.cancel().catch(() => {});
  }
}
