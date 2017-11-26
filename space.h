#ifndef __space_h
#define __space_h
#include <stdint.h>

typedef struct{
  uint8_t x, y, vx, vy;
  uint8_t exploding;
} KlingonShip;

typedef struct {
  uint8_t x, y, vx, vy, h, w,shield_dx, shield_dy  ;
  uint8_t exploding, shielded;
  uint16_t score;
} Discovery;

typedef struct {
  uint8_t x, y, w, h, isActive, vx;
} Missile;

#endif
