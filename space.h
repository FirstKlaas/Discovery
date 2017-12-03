#ifndef __space_h
#define __space_h
#include <stdint.h>

#include <Gamebuino.h>

#define LEVEL_JUMP_DX 1
#define DAMAGE_COLLISION 50
#define NUMBER_OF_EXPLOSION_FRAMES 25

typedef struct {
  uint8_t number_of_lives, max_number_of_lives; 
  boolean is_running; 
} Game;

typedef struct{
  int8_t x, y;
  uint8_t exploding, vx, vy;
} KlingonShip;

typedef struct {
  int8_t x, y, x0;
  uint8_t exploding, shielded, damage, vx, vy, h, w,shield_dx, shield_dy, lvl;
  uint16_t score;
} Discovery;

typedef struct {
  int8_t x, y;
  uint8_t w, h, isActive, vx;
} Missile;

#endif
