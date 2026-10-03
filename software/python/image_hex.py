"""Portable RGB24 image/HEX conversion; rejects malformed or incomplete frames."""
import argparse
from pathlib import Path


def image_to_hex(source, destination, width, height):
    from PIL import Image
    with Image.open(source) as image:
        image = image.convert("RGB").resize((width, height))
        destination.parent.mkdir(parents=True, exist_ok=True)
        with destination.open("w", encoding="ascii", newline="\n") as output:
            channels = iter(image.tobytes())
            for r, g, b in zip(channels, channels, channels):
                output.write(f"{r:02x}{g:02x}{b:02x}\n")


def hex_to_image(source, destination, width, height):
    from PIL import Image
    pixels = bytearray()
    with source.open(encoding="ascii") as input_file:
        for number, line in enumerate(input_file, 1):
            value = line.strip()
            if not value:
                continue
            if len(value) != 6 or any(c not in "0123456789abcdefABCDEF" for c in value):
                raise ValueError(f"Invalid RGB24 pixel at line {number}: {value!r}")
            pixels.extend(bytes.fromhex(value))
    expected = width * height * 3
    if len(pixels) != expected:
        raise ValueError(f"Expected {width * height} pixels, received {len(pixels) // 3}")
    destination.parent.mkdir(parents=True, exist_ok=True)
    Image.frombytes("RGB", (width, height), bytes(pixels)).save(destination)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode", choices=("encode", "decode"))
    parser.add_argument("source", type=Path)
    parser.add_argument("destination", type=Path)
    parser.add_argument("--width", type=int, default=640)
    parser.add_argument("--height", type=int, default=480)
    args = parser.parse_args()
    if args.width < 1 or args.height < 1:
        parser.error("Dimensions must be positive")
    try:
        (image_to_hex if args.mode == "encode" else hex_to_image)(
            args.source, args.destination, args.width, args.height
        )
    except (ValueError, OSError, ImportError) as error:
        parser.exit(1, f"Error: {error}\n")


if __name__ == "__main__":
    main()
