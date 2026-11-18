# Fire Opal — Tileset staging library

This directory holds **third-party source tilesets** for future Agave map design. Assets here are **not yet referenced by `data/tilesets`, a Porymap tileset definition, or a map layout**. Merely importing them must not alter vanilla game maps or the ROM build.

## Imported from Team Aqua's Asset Repo

All six assembled sets originate from [Team Aqua's Asset Repo, The Great Tileset Exchange](https://github.com/TeamAquasHideout/Team-Aquas-Asset-Repo/tree/main/Tilesets/The%20Great%20Tileset%20Exchange/Full%20Tilesets). Their source `credits.md` files are retained unchanged. **Credit Rahtak for formatting/assembly/submission where requested**, along with *all* artists in each source `credits.md`.

| Local directory | Original source set | Type | Intended use |
| --- | --- | --- | --- |
| `desert_primary/` | Desert Primary | Primary | Arid landscape and desert routes |
| `desert_village_secondary/` | Desert Village Secondary | Secondary | Desert buildings and villages |
| `shady_forest_secondary/` | Shady Forest Secondary | Secondary | Forest and transitional routes |
| `underwater_reef_secondary/` | Underwater Reef Secondary | Secondary | Reefs, coasts, underwater |
| `volcano_secondary/` | Volcano Secondary | Secondary | Volcanic mountains |
| `small_town_secondary/` | Small town with lab Secondary | Secondary | Residential towns |

The files include source `tiles.png`, native metatile data, palette files `palettes/00.pal`–`12.pal`, and provided animations/layer sheets where available. Original `example.png` previews and source README files were intentionally not duplicated; consult the upstream folders.

## Snow art

`droid779_snow/snow_tiles.png` is additional standalone **snow artwork**, credited to **Droid779**. It is not a complete native Porymap pack: its palettes, metatiles, and collision attributes need to be built before use.

## Integration requirements

1. For an actual in-game area, choose an appropriate primary and secondary set. Existing palettes and metatile indices must be checked for compatibility; do not assume two arbitrary sets work together.
2. Register or rebuild tilesets with Porymap/Porytiles in the current pokeemerald-expansion base. Verify 4bpp palettes, tile indices, behaviors/collision, animations, and object priority.
3. Apply new tilesets to appropriate **new** Agave map layouts and test an actual GBA build. Do **not** overwrite existing maps solely to stage art.
4. Keep all upstream artist credits when importing or editing any portion of a pack.

See [artist credits and original six recommendations](../../../docs/TILESET_CREDITS.md). Noncommercial fan-game reuse terms are pack-specific; public availability does not mean every resource has the same license.
