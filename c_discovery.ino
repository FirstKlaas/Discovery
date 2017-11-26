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

void removePoints(int points) {
  if (discovery.score < points) {
    discovery.score = 0;
  } else {
    discovery.score -= points;
  }
}

void addPoints(int points) {
  discovery.score += points;
}



/**
 * Prueft, ob die Discovery mit einem der Klingonenschiffe
 * kollidiert. Bei einer Kollision werden zwei Faelle unterschieden.
 * 
 * Fall 1: Shielded
 * Die Schilde der Discovery sind oben. Dann gibt es fuenf Punkte und das
 * Klingonenschiff wird nu in der neutralen Zone gespawned.
 * 
 * Fall 2: Not Shielded
 * Die Schilde sind unten. Dann wird die Discovery zertoert. 
 * Es gibt 150 Punkte Abzug
 */
void checkForCollisions(){
  for (byte i=0; i < NUM_KLINGONSHIPS; i++) {
    if (checkForCollisionWithKlingonShip(i)) {
        spawnKlingonShip(i);
        if(discovery.shielded) {
        //addPoints(5);
      } else {
        discovery.exploding = true;
        removePoints(150);
        gb.sound.playTick();
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

