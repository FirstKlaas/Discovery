void drawDiscovery() {
  gb.display.drawBitmap(discovery.x,discovery.y,SPRITE_DISCOVERY,NOROT,NOFLIP);
  //gb.display.drawRect(discovery.x,discovery.y,16,8);
  if (discovery.shielded) {
    gb.display.drawBitmap(getShieldX() ,getShieldY(),SPRITE_DISCOVERY_SHIELD,NOROT,NOFLIP);
  }
}

boolean checkForCollisionWithKlingonShip(const byte i) {
  //return gb.collideBitmapBitmap(discovery.x, discovery.y, SPRITE_DISCOVERY, klingonShips[i].x, klingonShips[i].y, klingonship);
  return gb.collideRectRect(discovery.x, discovery.y, 16, 8, klingonShips[i].x, klingonShips[i].y, SPRITE_KLINGONSHIP_HEIGHT, SPRITE_KLINGONSHIP_WIDTH);
}

/**
 * Prueft, ob die Discovery mit einem der Klingonenschiffe
 * kollidiert. 
 */
void checkForCollisions(){
  for (byte i=0; i < NUM_KLINGONSHIPS; i++) {
    if (checkForCollisionWithKlingonShip(i)) {
      if(discovery.shielded) {
        spawnKlingonShip(i);
        discovery.score += 5;
      } else {
        discovery.exploding = true;
      }
    }
  }
}

void initDiscovery() {
  discovery.x  = 5;
  discovery.y  = LCDHEIGHT/2;
  discovery.vx = 0;
  discovery.vy = 2;
  discovery.h  = 14;
  discovery.w  = 8;
  discovery.shield_dx = 11;
  discovery.shield_dy = -2;
  discovery.exploding = false;
  discovery.shielded  = false;
  discovery.score = 0;
}

int getShieldX() {
  return discovery.x + discovery.shield_dx;
}

int getShieldY() {
  return discovery.y + discovery.shield_dy;
}

