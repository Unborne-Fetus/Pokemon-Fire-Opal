# Shadow Rage — Fire Opal

Shadow Rage is a new **regular ability ID** inspired by Cipher's Shadow Pokémon, which appeared in *Pokémon Colosseum* and *Pokémon XD: Gale of Darkness*. Its current effects model the **Reverse Mode battle condition from XD** rather than inventing an unrelated Attack boost.

## Implemented battle effects

- After using a move, a Pokémon with Shadow Rage has a **20% chance** to enter Reverse Mode. Entering it does not consume its move. Only one activation roll happens per turn, including spread-move cases.
- Once in Reverse Mode, the Pokémon loses **1/16 of maximum HP at the end of each turn** (minimum 1 HP), which can cause fainting.
- The Pokémon cannot receive battle-use bag items while raging. Other party members may still receive items, and Poké Balls can still target foes.
- An ability popup signals activation and recurring backlash. Switching the Pokémon out clears the current Reverse Mode condition. It can enter again after it returns and uses a move.
- The condition is stored on the **battler**, not on a species, so it can be used for any Shadow Pokémon trainer encounter without replacing a whole species line.

## Deliberate adaptation

Pokémon XD uses a species/Heart-Gauge-dependent chance to enter Reverse Mode. Because Fire Opal does not yet have a Heart Gauge, this ability uses a fixed **20%** rate for now. The original Reverse Mode recoil amount (1/16 max HP) is preserved.

The GBA battle engine also has no separate **Call** action: switching out currently calms a Pokémon, providing an escape from Reverse Mode. This differs from XD, where Reverse Mode persists until Calling, Scent, or fainting.

## Not yet implemented as part of Shadow Rage

This is **not** a complete Colosseum/XD Shadow Pokémon subsystem. These require additional save-data, battle/menu, overworld, and narrative systems:

- Shadow-type move pool (e.g. Shadow Rush), Shadow-type effectiveness, and battle animations
- Snagging a Shadow Pokémon from an opposing trainer
- Saved per-Pokémon Heart Gauge, blocked training, retained experience, and gradual purification
- **Call** battle action, Scents, purification chamber or relic, and story-driven permanent conversion
- Persistent red Shadow aura and Reverse Mode HUD elements

A new Shadow system should use `ABILITY_SHADOW_RAGE` as its ability-facing entry point and add a persistent per-Pokémon Shadow flag/Heart Gauge independently of ability slots. This also permits purification to replace the Shadow Rage ability without treating every member of that species as Shadow.

## Assignment

The ability is defined and usable, but **no species-wide ability slots or trainer teams were changed**. Assign `ABILITY_SHADOW_RAGE` to designated Cipher Shadow Pokémon party entries when those encounters are added.

## Test coverage

`test/battle/ability/shadow_rage.c` includes five scenarios: 20% activation chance, no activation, repeated end-turn recoil, no activation from merely taking damage, and clearing Reverse Mode after switching.
