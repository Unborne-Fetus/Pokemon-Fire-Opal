#include "global.h"
#include "test/battle.h"

// Shadow Rage's battle component is based on XD's Reverse Mode.
// A rage attempt happens after the holder uses a move; once active,
// it takes 1/16 max HP recoil at the end of each turn.

SINGLE_BATTLE_TEST("Shadow Rage has a 20 percent chance to enter Reverse Mode after attacking")
{
    PASSES_RANDOMLY(1, 5, RNG_SHADOW_RAGE);
    GIVEN {
        PLAYER(SPECIES_HOUNDOUR) { Ability(ABILITY_SHADOW_RAGE); MaxHP(160); HP(160); Speed(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SHADOW_RAGE);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 150);
        EXPECT_EQ(player->volatiles.shadowRageActive, TRUE);
    }
}

SINGLE_BATTLE_TEST("Shadow Rage can remain calm after attacking")
{
    PASSES_RANDOMLY(4, 5, RNG_SHADOW_RAGE);
    GIVEN {
        PLAYER(SPECIES_HOUNDOUR) { Ability(ABILITY_SHADOW_RAGE); MaxHP(160); HP(160); Speed(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SHADOW_RAGE);
            HP_BAR(player);
        }
    } THEN {
        EXPECT_EQ(player->hp, 160);
        EXPECT_EQ(player->volatiles.shadowRageActive, FALSE);
    }
}

SINGLE_BATTLE_TEST("Shadow Rage inflicts one sixteenth maximum HP per turn once active")
{
    PASSES_RANDOMLY(1, 5, RNG_SHADOW_RAGE);
    GIVEN {
        PLAYER(SPECIES_HOUNDOUR) { Ability(ABILITY_SHADOW_RAGE); MaxHP(160); HP(160); Speed(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SHADOW_RAGE);
        HP_BAR(player);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->hp, 140);
        EXPECT_EQ(player->volatiles.shadowRageActive, TRUE);
    }
}

SINGLE_BATTLE_TEST("Shadow Rage does not start merely from taking damage")
{
    GIVEN {
        PLAYER(SPECIES_HOUNDOUR) { Ability(ABILITY_SHADOW_RAGE); MaxHP(160); HP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(player, ABILITY_SHADOW_RAGE); }
    } THEN {
        EXPECT_EQ(player->volatiles.shadowRageActive, FALSE);
    }
}

SINGLE_BATTLE_TEST("Shadow Rage clears on switching out")
{
    PASSES_RANDOMLY(1, 5, RNG_SHADOW_RAGE);
    GIVEN {
        PLAYER(SPECIES_HOUNDOUR) { Ability(ABILITY_SHADOW_RAGE); MaxHP(160); HP(160); Speed(200); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SHADOW_RAGE);
    } THEN {
        EXPECT_EQ(player->volatiles.shadowRageActive, FALSE);
    }
}
