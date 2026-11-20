# Fire Opal — Tileset staging library

This directory preserves the **original third-party source assets**. The six complete GBA tilesets are now registered as copies under `data/tilesets/primary/` and `data/tilesets/secondary/` and in the engine's tileset headers, so Porymap can select them for map layouts. They have **not** been assigned to any existing maps. The standalone Droid779 snow image is still unregistered.

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

## Registration and next steps

- All six GBA tile sources have `gTileset_FireOpal*` registrations in `src/data/tilesets/headers.h`; original art remains untouched here.
- Source `metatiles.bin` uses 12 tile references per metatile; the current engine uses 8. Converted copies in `data/tilesets` retain the first two populated layers. Three-layer metatiles may need manual correction in Porymap to restore lost details. Recreate the conversion with `python tools/fire_opal/convert_metatiles.py`.
- Water, flower, and other animation frames are present in staging when provided, but their animation callbacks still need integration.
- No existing maps have been reassigned. Verify palettes, behaviors/collision, and in-game rendering before map release, and preserve the credits.

See [artist credits and original six recommendations](../../../docs/TILESET_CREDITS.md). Noncommercial fan-game reuse terms are pack-specific; public availability does not mean every resource has the same license.
