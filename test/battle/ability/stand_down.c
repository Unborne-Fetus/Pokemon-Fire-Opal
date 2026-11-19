#include "global.h"
#include "test/battle.h"

// Jessie keeps Containment Protocol's first-hit protection, but Stand Down
// replaces the offensive escalation with a defensive posture and Speed loss.

SINGLE_BATTLE_TEST("Stand Down halves the first damaging hit", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_STAND_DOWN; }
    PARAMETRIZE { ability = ABILITY_STURDY; }
    GIVEN {
        PLAYER(SPECIES_ARCHALUDON) { Ability(ability); MaxHP(900); HP(900); Defense(120); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(120); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH, WITH_RNG(RNG_DAMAGE_MODIFIER, 0)); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_LT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Stand Down raises both defenses two stages and lowers Speed one stage")
{
    GIVEN {
        PLAYER(SPECIES_ARCHALUDON) { Ability(ABILITY_STAND_DOWN); MaxHP(500); HP(500); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_STAND_DOWN);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Stand Down triggers only once per switch-in")
{
    GIVEN {
        PLAYER(SPECIES_ARCHALUDON) { Ability(ABILITY_STAND_DOWN); MaxHP(500); HP(500); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_STAND_DOWN);
        NONE_OF { ABILITY_POPUP(player, ABILITY_STAND_DOWN); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Stand Down resets after switching out and back in")
{
    GIVEN {
        PLAYER(SPECIES_ARCHALUDON) { Ability(ABILITY_STAND_DOWN); MaxHP(500); HP(500); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_STAND_DOWN);
        ABILITY_POPUP(player, ABILITY_STAND_DOWN);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Stand Down does not activate through Substitute")
{
    GIVEN {
        PLAYER(SPECIES_ARCHALUDON) { Ability(ABILITY_STAND_DOWN); MaxHP(500); HP(500); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(player, ABILITY_STAND_DOWN); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Stand Down does not activate when Protect blocks the first hit")
{
    GIVEN {
        PLAYER(SPECIES_ARCHALUDON) { Ability(ABILITY_STAND_DOWN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(player, ABILITY_STAND_DOWN); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}
