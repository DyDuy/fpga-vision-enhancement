// Brightness is the rounded Rec.709-weighted RGB code value, on a 0–255 scale.
export function calculateHistogram(pixels) {
  if (!(pixels instanceof Uint8Array || pixels instanceof Uint8ClampedArray) || pixels.length % 4) {
    throw new Error("Histogram input must contain complete RGBA pixels.");
  }
  const bins = new Array(256).fill(0);
  let sum = 0, squares = 0;
  for (let offset = 0; offset < pixels.length; offset += 4) {
    const alpha = pixels[offset + 3] / 255;
    const red = Math.round(pixels[offset] * alpha);
    const green = Math.round(pixels[offset + 1] * alpha);
    const blue = Math.round(pixels[offset + 2] * alpha);
    const intensity = Math.round(.2126 * red + .7152 * green + .0722 * blue);
    bins[intensity]++;
    sum += intensity;
    squares += intensity * intensity;
  }
  const total = pixels.length / 4;
  const mean = total ? sum / total : 0;
  return { bins, total, mean, stdDev: total ? Math.sqrt(Math.max(0, squares / total - mean * mean)) : 0 };
}

function element(name, attributes = {}, text) {
  const node = document.createElementNS("http://www.w3.org/2000/svg", name);
  for (const [key, value] of Object.entries(attributes)) node.setAttribute(key, value);
  if (text !== undefined) node.textContent = text;
  return node;
}

export function drawHistogram(svg, input, output, activeLevel = 128) {
  svg.replaceChildren();
  const left = 56, top = 20, width = 708, height = 204, bottom = top + height;
  const percentages = histogram => histogram.bins.map(count => histogram.total ? count / histogram.total * 100 : 0);
  const inputValues = percentages(input), outputValues = percentages(output);
  const maximum = Math.min(100, Math.max(.1, ...inputValues, ...outputValues) * 1.08);
  const x = level => left + level / 255 * width;
  const y = value => bottom - value / maximum * height;
  svg.append(element("title", {}, "Input and output brightness histograms"));
  for (let step = 0; step <= 4; step++) {
    const value = maximum * step / 4;
    const position = y(value);
    svg.append(element("line", { x1: left, y1: position, x2: left + width, y2: position, class: "histogram-gridline" }));
    svg.append(element("text", { x: left - 9, y: position + 4, "text-anchor": "end", class: "histogram-tick" }, value.toFixed(maximum < 1 ? 2 : 1)));
  }
  for (const level of [0, 64, 128, 192, 255]) {
    svg.append(element("text", { x: x(level), y: bottom + 21, "text-anchor": "middle", class: "histogram-tick" }, String(level)));
  }
  for (const [values, kind] of [[inputValues, "input"], [outputValues, "output"]]) {
    const points = values.map((value, level) => `${level ? "L" : "M"}${x(level).toFixed(2)},${y(value).toFixed(2)}`).join(" ");
    svg.append(element("path", { d: `${points} L${left + width},${bottom} L${left},${bottom} Z`, class: `histogram-fill histogram-${kind}` }));
    svg.append(element("path", { d: points, class: `histogram-line histogram-${kind}` }));
  }
  svg.append(element("line", { x1: x(activeLevel), y1: top, x2: x(activeLevel), y2: bottom, class: "histogram-cursor" }));
  svg.append(element("text", { x: left, y: 11, class: "histogram-axis-label" }, "Pixels (%)"));
  svg.append(element("text", { x: left + width / 2, y: 267, "text-anchor": "middle", class: "histogram-axis-label" }, "Brightness intensity (0–255)"));
}
