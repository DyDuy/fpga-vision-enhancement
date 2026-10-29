// Fixed FPGA input frame; enhanceImage remains a browser-only demo.
import { calculateHistogram } from "./histogram.js";

export const FPGA_WIDTH = 640;
export const FPGA_HEIGHT = 480;
const MAX_PIXELS = 40_000_000;
const HEX_BYTES = Array.from({ length: 256 }, (_, value) => value.toString(16).padStart(2, "0").toUpperCase());

function checkAbort(signal) {
  if (signal?.aborted) throw new DOMException("Processing cancelled.", "AbortError");
}

async function decode(blob) {
  if (typeof createImageBitmap === "function") return createImageBitmap(blob);
  const url = URL.createObjectURL(blob);
  try {
    const image = new Image();
    image.src = url;
    await image.decode();
    return image;
  } finally {
    URL.revokeObjectURL(url);
  }
}

function toBlob(canvas) {
  return new Promise((resolve, reject) => {
    canvas.toBlob(blob => blob ? resolve(blob) : reject(new Error("Could not create the image preview.")), "image/png");
  });
}

// $readmemh-compatible text: one RGB888 word per line, scanned left-to-right,
// top-to-bottom. Composite alpha over black because the FPGA has no alpha channel.
export function pixelsToHex(pixels, width = FPGA_WIDTH, height = FPGA_HEIGHT) {
  if (!(pixels instanceof Uint8Array || pixels instanceof Uint8ClampedArray) ||
      !Number.isInteger(width) || !Number.isInteger(height) || width <= 0 || height <= 0 ||
      width * height > MAX_PIXELS || pixels.length !== width * height * 4) {
    throw new Error("Pixel data must contain exactly one RGBA value per pixel.");
  }
  const rows = [];
  for (let y = 0; y < height; y++) {
    let row = "";
    for (let x = 0; x < width; x++) {
      const offset = (y * width + x) * 4;
      const alpha = pixels[offset + 3] / 255;
      row += HEX_BYTES[Math.round(pixels[offset] * alpha)] +
        HEX_BYTES[Math.round(pixels[offset + 1] * alpha)] +
        HEX_BYTES[Math.round(pixels[offset + 2] * alpha)] + "\n";
    }
    rows.push(row);
  }
  return rows.join("");
}

export function hexToPixels(text, width = FPGA_WIDTH, height = FPGA_HEIGHT) {
  if (typeof text !== "string" || !Number.isInteger(width) || !Number.isInteger(height) ||
      width <= 0 || height <= 0 || width * height > MAX_PIXELS) {
    throw new Error("Invalid HEX frame dimensions or text.");
  }
  const count = width * height;
  if (text.length > count * 8 + 16) throw new Error("The HEX file is larger than the expected frame.");
  const cleaned = text.replace(/^\uFEFF/, "").trim();
  const words = cleaned ? cleaned.split(/\s+/) : [];
  if (words.length !== count) {
    throw new Error(`Expected ${count.toLocaleString("en-US")} RGB888 pixels; received ${words.length.toLocaleString("en-US")}.`);
  }
  const pixels = new Uint8ClampedArray(count * 4);
  for (let index = 0; index < count; index++) {
    if (!/^[0-9a-fA-F]{6}$/.test(words[index])) {
      throw new Error(`Invalid RGB888 HEX word at pixel ${index + 1}. Use six RRGGBB digits per pixel.`);
    }
    const value = Number.parseInt(words[index], 16), offset = index * 4;
    pixels[offset] = value >>> 16;
    pixels[offset + 1] = (value >>> 8) & 255;
    pixels[offset + 2] = value & 255;
    pixels[offset + 3] = 255;
  }
  return pixels;
}

export async function decodeHexImage(text) {
  const pixels = hexToPixels(text);
  const canvas = document.createElement("canvas");
  canvas.width = FPGA_WIDTH;
  canvas.height = FPGA_HEIGHT;
  const context = canvas.getContext("2d");
  if (!context) throw new Error("This browser cannot decode the output image.");
  const frame = context.createImageData(FPGA_WIDTH, FPGA_HEIGHT);
  frame.data.set(pixels);
  context.putImageData(frame, 0, 0);
  return {
    resultBlob: await toBlob(canvas),
    resultHexBlob: new Blob([pixelsToHex(pixels)], { type: "text/plain;charset=utf-8" }),
    outputHistogram: calculateHistogram(pixels),
    width: FPGA_WIDTH, height: FPGA_HEIGHT
  };
}

export async function analyzeImage(blob) {
  const image = await decode(blob);
  try {
    const width = image.width || image.naturalWidth, height = image.height || image.naturalHeight;
    if (!width || !height || width * height > MAX_PIXELS) throw new Error("Cannot analyze this image size.");
    const canvas = document.createElement("canvas");
    canvas.width = width;
    canvas.height = height;
    const context = canvas.getContext("2d", { willReadFrequently: true });
    if (!context) throw new Error("This browser cannot analyze the image.");
    context.drawImage(image, 0, 0);
    return calculateHistogram(context.getImageData(0, 0, width, height).data);
  } finally {
    image.close?.();
  }
}

export async function prepareImage(file) {
  const image = await decode(file);
  try {
    const width = image.width || image.naturalWidth;
    const height = image.height || image.naturalHeight;
    if (!width || !height || width * height > MAX_PIXELS) throw new Error("The image is invalid or exceeds the 40-megapixel limit.");
    const canvas = document.createElement("canvas");
    canvas.width = FPGA_WIDTH;
    canvas.height = FPGA_HEIGHT;
    const context = canvas.getContext("2d", { willReadFrequently: true });
    if (!context) throw new Error("This browser cannot prepare the FPGA image.");
    context.imageSmoothingEnabled = true;
    context.imageSmoothingQuality = "high";
    context.fillStyle = "#000000";
    context.fillRect(0, 0, canvas.width, canvas.height);
    context.drawImage(image, 0, 0, canvas.width, canvas.height);
    const pixels = context.getImageData(0, 0, canvas.width, canvas.height).data;
    const hexBlob = new Blob([pixelsToHex(pixels)], { type: "text/plain;charset=utf-8" });
    return { sourceBlob: await toBlob(canvas), hexBlob, inputHistogram: calculateHistogram(pixels), width: canvas.width, height: canvas.height,
      originalWidth: width, originalHeight: height };
  } finally {
    image.close?.();
  }
}

export function contrastBounds(pixels) {
  const histogram = new Uint32Array(256);
  let count = 0;
  for (let i = 0; i < pixels.length; i += 4) {
    if (!pixels[i + 3]) continue;
    histogram[Math.round(.2126 * pixels[i] + .7152 * pixels[i + 1] + .0722 * pixels[i + 2])]++;
    count++;
  }
  let low = 0, high = 255, cumulative = 0;
  for (let i = 0; i < 256; i++) {
    cumulative += histogram[i];
    if (cumulative > count * .01) { low = i; break; }
  }
  cumulative = 0;
  for (let i = 255; i >= 0; i--) {
    cumulative += histogram[i];
    if (cumulative > count * .01) { high = i; break; }
  }
  // Uniform images have no contrast to recover; preserve their brightness.
  return high - low >= 16 ? { low, range: high - low } : { low: 0, range: 255 };
}

export function enhancePixels(pixels, strength, bounds, start = 0, end = pixels.length) {
  const amount = Math.max(0, Math.min(100, strength)) / 100;
  for (let i = start; i < end; i += 4) {
    if (!pixels[i + 3]) continue;
    for (let channel = 0; channel < 3; channel++) {
      const original = pixels[i + channel];
      const stretched = Math.max(0, Math.min(255, (original - bounds.low) * 255 / bounds.range));
      pixels[i + channel] = original * (1 - amount) + stretched * amount;
    }
  }
  return pixels;
}

export async function enhanceImage(sourceBlob, strength, signal) {
  checkAbort(signal);
  const image = await decode(sourceBlob);
  try {
    checkAbort(signal);
    const canvas = document.createElement("canvas");
    canvas.width = image.width || image.naturalWidth;
    canvas.height = image.height || image.naturalHeight;
    const context = canvas.getContext("2d", { willReadFrequently: true });
    context.drawImage(image, 0, 0);
    const data = context.getImageData(0, 0, canvas.width, canvas.height);
    const bounds = contrastBounds(data.data);
    const chunk = canvas.width * 4 * 128;
    for (let start = 0; start < data.data.length; start += chunk) {
      checkAbort(signal);
      enhancePixels(data.data, strength, bounds, start, Math.min(start + chunk, data.data.length));
      await new Promise(resolve => setTimeout(resolve, 0));
    }
    context.putImageData(data, 0, 0);
    checkAbort(signal);
    const blob = await toBlob(canvas);
    checkAbort(signal);
    return blob;
  } finally {
    image.close?.();
  }
}
