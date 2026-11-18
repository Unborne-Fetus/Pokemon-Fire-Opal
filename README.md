# Pokémon Fire Opal

**Pokémon Fire Opal** is an early-stage, Mexico-inspired Pokémon GBA ROM hack built on [Rom Hacking Hideout's `pokeemerald-expansion`](https://github.com/rh-hideout/pokeemerald-expansion).

The planned setting takes inspiration from Mexico's varied landscapes and cultures, including deserts, forests, coasts, cities, and colder mountainous regions such as Durango. The region, story, and Pokémon distribution are still in development.

> **Development status:** Very early development. The repository contains the game-development base and an initial stat editor, not a finished new region or a complete playable adventure.

## Currently implemented

- **Pokémon stat editor**, adapted from [Pokémon Brisk Emerald](https://github.com/Unborne-Fetus/Pokemon-Brisk-Emerald). In the overworld, open the party menu, choose a Pokémon (not an Egg), and select **STAT EDIT** to view stats and change individual EVs and IVs.
  - Use the D-pad to choose a stat and EV/IV column; press **A** to edit, then **Left/Right** to decrease/increase. **Up/Down** jumps to the allowed maximum/minimum. Press **B** to leave edit mode, or leave the editor when not editing.
  - Use **L/R** outside edit mode to cycle party Pokémon.
- Underlying `pokeemerald-expansion` engine and its existing functionality. Features supplied by the base are not necessarily custom Fire Opal features.

## Tileset library

- [Fire Opal tileset staging library](assets/fire_opal/tilesets/README.md) — desert, village, forest, reef, volcano, town, and snow artwork prepared for later map work.
- [Tileset artist credits and original resource references](docs/TILESET_CREDITS.md) — individual creator attributions and import status.

**These graphics are staged in the repository, not yet applied to in-game maps.** New palettes, metatiles, and collisions must be registered and tested before the region uses them.

## Building

Follow the upstream [installation and build instructions](INSTALL.md). A properly configured GBA development toolchain is required. The repository includes source code and assets, not a distributable ROM.

## Credits and upstream

- **RHH / `pokeemerald-expansion`** — original engine and contributors. This repository started from **v1.17.2**: [upstream project](https://github.com/rh-hideout/pokeemerald-expansion). See [CREDITS.md](CREDITS.md) and [FEATURES.md](FEATURES.md).
- **Pokémon Brisk Emerald** — source of the in-game EV/IV stat editor and its graphical assets.
- **pret's `pokeemerald`** — original decompilation project underlying the expansion: [pret/pokeemerald](https://github.com/pret/pokeemerald).

This is an unofficial, fan-made project. Pokémon belongs to Nintendo, Creatures, and GAME FREAK.
