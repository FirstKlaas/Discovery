#ifndef __space_h
#define __space_h
#include <stdint.h>

#define LEVEL_JUMP_DX 1
#define DAMAGE_COLLISION 50

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
