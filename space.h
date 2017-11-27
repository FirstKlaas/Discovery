#ifndef __space_h
#define __space_h
#include <stdint.h>

typedef struct{
  int8_t x, y;
  uint8_t exploding, vx, vy;
} KlingonShip;

typedef struct {
  int8_t x, y;
  uint8_t exploding, shielded, damage, vx, vy, h, w,shield_dx, shield_dy;
  uint16_t score;
} Discovery;

typedef struct {
  int8_t x, y;
  uint8_t w, h, isActive, vx;
} Missile;

#endif
