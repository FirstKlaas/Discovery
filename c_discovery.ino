void drawDiscovery() {
  if (discovery.damage == 15) {
    discovery.exploding = false;
  }
  
  if (discovery.exploding) {
    discovery.damage++;
    for (byte i=0; i<15; i++) {
      if (((discovery.damage - (2*i))) > 1) gb.display.drawCircle(discovery.x + (SPRITE_DISCOVERY_WIDTH/2),discovery.y + (SPRITE_DISCOVERY_HEIGHT / 2), (discovery.damage - (2*i)));
    }
  } else {
    gb.display.drawBitmap(discovery.x,discovery.y,SPRITE_DISCOVERY,NOROT,NOFLIP);
    if (discovery.shielded) {
      gb.display.drawBitmap(getShieldX() ,getShieldY(),SPRITE_DISCOVERY_SHIELD,NOROT,NOFLIP);
    }
  }
}

boolean checkForCollisionWithKlingonShip(const byte i) {
  if (discovery.exploding) return false;
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

void shootDiscovery() {
  if (discovery.exploding) return;
  discovery.exploding = true;
  discovery.damage = 0;
  removePoints(150);      
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
  // Wenn das Schiff bereits explodiert, dann
  // braucht man auch nicht auf moegliche 
  // Kollisionen testen.
  if (discovery.exploding) return;
  
  for (byte i=0; i < NUM_KLINGONSHIPS; i++) {
    if (checkForCollisionWithKlingonShip(i)) {
      if(discovery.shielded) {
        spawnKlingonShip(i);
      } else {
        shootDiscovery();
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
  discovery.damage = 0;
}

int getShieldX() {
  return discovery.x + discovery.shield_dx;
}

int getShieldY() {
  return discovery.y + discovery.shield_dy;
}

