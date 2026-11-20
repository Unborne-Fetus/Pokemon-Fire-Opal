#!/usr/bin/env python3
"""Reproduce the Fire Opal 12-to-8-reference metatile conversion.

The imported Team Aqua exchange tilesets contain 12 u16 tile references per
metatile (three 2x2 layers). This engine uses eight (two layers). Preserve
the first two nonempty 2x2 layers (or blank layers if fewer than two). When
all three are populated, the third cannot be represented and requires
manual map-art review. Original source assets are never modified.
"""
from pathlib import Path
import argparse

ROOT = Path(__file__).resolve().parents[2]
SETS = (
    ("desert_primary", "primary/fire_opal_desert"),
    ("desert_village_secondary", "secondary/fire_opal_desert_village"),
    ("shady_forest_secondary", "secondary/fire_opal_shady_forest"),
    ("underwater_reef_secondary", "secondary/fire_opal_underwater_reef"),
    ("volcano_secondary", "secondary/fire_opal_volcano"),
    ("small_town_secondary", "secondary/fire_opal_small_town"),
)


def convert(raw: bytes) -> tuple[bytes, int]:
    if len(raw) % 24:
        raise ValueError("Expected 12 little-endian u16 tile references per block")
    out = bytearray()
    dropped_third_layer = 0
    for start in range(0, len(raw), 24):
        groups = [raw[start + i:start + i + 8] for i in (0, 8, 16)]
        populated = [any(group) for group in groups]
        choices = [i for i, has_tiles in enumerate(populated) if has_tiles][:2]
        choices.extend(i for i in range(3) if i not in choices)
        if sum(populated) == 3:
            dropped_third_layer += 1
        out.extend(groups[choices[0]])
        out.extend(groups[choices[1]])
    return bytes(out), dropped_third_layer


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="Validate committed output without overwriting")
    args = parser.parse_args()
    for source_name, target_dir in SETS:
        source_dir = ROOT / "assets/fire_opal/tilesets" / source_name
        target = ROOT / "data/tilesets" / target_dir / "metatiles.bin"
        converted, dropped = convert((source_dir / "metatiles.bin").read_bytes())
        attrs = (source_dir / "metatile_attributes.bin").read_bytes()
        assert len(converted) == len(attrs) * 8, f"{source_name}: metatile/attribute count mismatch"
        if args.check:
            assert target.read_bytes() == converted, f"{target}: converted data does not match"
        else:
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(converted)
        print(f"{source_name}: {len(attrs)//2} metatiles, {dropped} require 3-layer art review")


if __name__ == "__main__":
    main()
