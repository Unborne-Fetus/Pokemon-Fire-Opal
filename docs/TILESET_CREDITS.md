# Pokémon Fire Opal — Tileset credits and sourcing

> **Import state (2026-11-18):** The repository contains six **GBA-format tileset sources from Team Aqua's Asset Repo**, plus Droid779 snow art. They are staged under `assets/fire_opal/tilesets/`, **not integrated into active maps**. This document distinguishes those assets from the six originally recommended packs, some of whose original archives were not obtainable in this session.

## Attributions for files actually in the repository

Source: [Team Aqua's Asset Repo / The Great Tileset Exchange](https://github.com/TeamAquasHideout/Team-Aquas-Asset-Repo/tree/main/Tilesets/The%20Great%20Tileset%20Exchange/Full%20Tilesets). Thanks to Team Aqua's Hideout and **Rahtak** for the assembled/import-ready sets; preserve the complete attribution lists distributed inside each local `credits.md`.

- **Desert Primary** and **Desert Village Secondary:** KingTapir, Ekat, TheDeadHeroAlistair, Skillmen; **Rahtak** for formatting/submission.
- **Shady Forest Secondary:** **Yumekua** (assembler); Ekat99, Heartlessdragoon, Vurtax, Dawnbronze and many additional artists and teams; see `shady_forest_secondary/credits.md` for the full required list.
- **Underwater Reef Secondary:** Ekat, Vurtax, Heartlessdragoon (RSE rips).
- **Volcano Secondary:** **Hek-el-grande** (buildings), **Yumekua** (assembler), Ekat99, Heartlessdragoon, Vurtax, Dawnbronze and many additional artists and teams; see `volcano_secondary/credits.md` for the full required list.
- **Small town with lab Secondary:** Ekat, Anonalpaca, Idilio, Heartlessdragoon, Vurtax, Skidmarc25, Thewilddeadhero, Zein; **Rahtak** for formatting/submission.
- **Snow tiles (standalone artwork):** **Droid779**, [creator gallery](https://www.deviantart.com/droid779/gallery), from [Team Aqua's Asset Repo](https://github.com/TeamAquasHideout/Team-Aquas-Asset-Repo/tree/main/Tilesets/Other%20Tilesets/Droid779).

The artist lists in the individual `credits.md` files take precedence over abbreviated summaries above. Retain those files and check credits again for any additional third-party artwork introduced when mapping.

## The six originally recommended tileset resources

These are references for later *direct* source imports. **Listing a resource below is not a claim that its complete original pack has been copied or activated.**

| Original resource | Artist(s) / credit requirements | Status of direct original pack |
| --- | --- | --- |
| [Ekat's Public Gen 3 Tilesets](https://eeveeexpo.com/resources/621/) | Ekat and contributors, including Heartless Dragoon, Morlockhater, Nemu, Ross Hawkins, Pokémon Dawn, Slimshady, TheDeadHeroAlistair, The-Red-Ex, Vurtax, Zein, Redblueyellow, Fabnt, War8, Dragoon, Silverdeoxys563, SteamyJ, Anonalpaca, Pokémon Rejuvenation, Puggsoy, Aveontrainer, Idillio, Dasani, Shyin. Consult the **full per-set credits.txt in the original download**. | **Not directly imported in full.** Several contributors' graphics are represented in the GBA-ready exchange sets above. |
| [KingTapir Desert Tileset Deluxe Edition](https://www.deviantart.com/kingtapir/art/Desert-Tileset-Deluxe-Edition-909169932) | KingTapir; verify original artwork usage terms and other contributors before distribution. | **Original Deluxe pack not imported.** Desert exchange sets credit KingTapir but are not claimed to be the entire Deluxe release. |
| [Arid Desert Town](https://eeveeexpo.com/resources/2037/) | TerribleJared; credit Aveontrainer where indicated by the original resource. | **Not imported**; direct download unavailable in this session. |
| [Cinna's Gen 3 Snow Tileset](https://eeveeexpo.com/resources/1631/) | Cinna / CinnaYva; preserve the credit file in the original archive. | **Not imported**; the bundled snow image is instead by Droid779, clearly credited separately. |
| [St's Jungle Tileset](https://eeveeexpo.com/resources/684/) | Mezz8118 / ST1107, TheDeadHeroAlistair, Pokémon Rejuvenation Team; **noncommercial use only, with credit**. | **Not imported**; Shady Forest is an alternative landscape set and must not be attributed to Mezz8118. |
| [Dawn Bronze's Public Gen 3 Tileset](https://eeveeexpo.com/resources/26/) | Dawn Bronze; Heartlessdragoon, TheDeadHeroAlistair, Calis Projects, Cilerba, Magiscarf, DaNerdyDude, XDinky, KyleDove, as relevant to the tiles used. | **Original package not imported**; Dawnbronze appears among contributors to some exchange sets above. |

## Next implementation stage

Before any of these graphics become active Fire Opal map tilesets: acquire and verify each missing original resource archive under its reuse terms, convert any RPG Maker/Essentials atlases to GBA-compatible palettes and metatiles, register the tilesets and animations, assign appropriate maps, and run the ROM plus Porymap checks.

Do not label work as a fully integrated map tileset until collision, palette, metatile index, and build checks pass.
