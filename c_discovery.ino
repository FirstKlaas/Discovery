void drawLives() {
  for (uint8_t i=0; i<game.number_of_lives; i++) {
    gb.display.drawBitmap(50+(i*6),LCDHEIGHT - 5, SPRITE_LIVE);
  }
}

void drawDiscovery() {
  if (discovery.damage == NUMBER_OF_EXPLOSION_FRAMES) {
    discovery.exploding = false;
  }

  if (discovery.exploding) {
    discovery.damage++;
    for (byte i=0; i<15; i++) {
      if (((discovery.damage - (4*i))) > 1) gb.display.drawCircle(discovery.x + (SPRITE_DISCOVERY_WIDTH/2),discovery.y + (SPRITE_DISCOVERY_HEIGHT / 2), (discovery.damage - (4*i)));
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
    addPoints(-1 * discovery.score);
  } else {
    addPoints(-1 * points);
  }
}

void addPoints(int points) {
  discovery.score += points;
  discovery.lvl = discovery.score / 100;
  discovery.x   = min(discovery.x0 + (discovery.lvl * LEVEL_JUMP_DX), 10*LEVEL_JUMP_DX); 
}

void shootDiscovery() {
  if (discovery.exploding) return;
  discovery.exploding = true;
  discovery.damage = 0;
  removePoints(DAMAGE_COLLISION);      
  if (game.number_of_lives > 1) {
    game.number_of_lives--;
  } else {
    game.is_running = false;
  }
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
  discovery.x0        = 5;
  discovery.x         = discovery.x0;
  discovery.y         = LCDHEIGHT/2;
  discovery.vx        = 0;
  discovery.vy        = 2;
  discovery.h         = 14;
  discovery.w         = 8;
  discovery.shield_dx = 11;
  discovery.shield_dy = -2;
  discovery.exploding = false;
  discovery.shielded  = false;
  discovery.score     = 0;
  discovery.damage    = 0;
  discovery.lvl       = 0;
}

int getShieldX() {
  return discovery.x + discovery.shield_dx;
}

int getShieldY() {
  return discovery.y + discovery.shield_dy;
}

