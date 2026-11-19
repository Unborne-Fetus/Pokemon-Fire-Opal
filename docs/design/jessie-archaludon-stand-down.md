# Jessie's Archaludon — Stand Down

## Story purpose

In Pokémon Brisk Emerald, Jessie deployed **Containment Protocol**: the first damaging hit was halved, then survival led to +2 Attack, +2 Sp. Atk and +2 Speed.

For Fire Opal, **Stand Down** is the successor: the same protection is retained, but the counterattack has been abandoned. Jessie is no longer trying to overpower everyone they encounter. The ability reflects someone who still knows how to survive, but has given up their old campaign.

## Mechanics

- **Once per switch-in**, the first attack that actually damages the user's HP deals **half damage** (minimum 1 damage).
- After surviving that hit, its **Defense rises by 2 stages**, **Sp. Def rises by 2 stages**, and **Speed falls by 1 stage**.
- The activation is spent on the first HP-damaging attack even if that hit KOs the user; a KO grants no stat changes.
- Hits blocked by Protect, a Substitute, Disguise, or Ice Face do not spend the shield.
- Switching out resets the protection; Baton Pass cannot transfer the spent/ready state.
- No offensive stat boosts are granted.

## Intended Pokémon assignment

**Jessie's Archaludon** is intended to have `Ability: Stand Down` in its **specific trainer-party entry**.

As of this import, Fire Opal's trainer-party files do not yet define a Jessie trainer/battle. Therefore no Pokémon's species-wide ability slots are changed, and no trainer entry is invented. When the Jessie battle is added, set `Ability: Stand Down` on Archaludon there only.

This intentionally does **not** import Team Xiphos's Containment Protocol into Fire Opal.
