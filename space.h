#ifndef __space_h
#define __space_h
#include <stdint.h>

typedef struct{
  uint8_t x, y;
  uint8_t exploding, vx, vy;
} KlingonShip;

typedef struct {
  uint8_t x, y, score;
  uint8_t exploding, shielded, damage, vx, vy, h, w,shield_dx, shield_dy;
} Discovery;

typedef struct {
  uint8_t x, y;
  uint8_t w, h, isActive, vx;
} Missile;

#endif
