void drawKlingonShips() {
  for (byte i=0; i < NUM_KLINGONSHIPS; i++) {
    gb.display.drawBitmap(klingonShips[i].x,klingonShips[i].y,klingonship,ROTCCW,NOFLIP);
  }  
}

/**
 * Materialisiert ein neues Klingonenschiff in der neutralen Zone.
 * (Links ausserhalb des sichbaren Bereichs des LCD Screens)
 */
void spawnKlingonShip(const byte i) {
  klingonShips[i].x = random(LCDWIDTH , 127);
  klingonShips[i].y = random(0,LCDHEIGHT-SPRITE_KLINGONSHIP_WIDTH);
  klingonShips[i].vx = random(1,3);
  klingonShips[i].vy = 0;
  klingonShips[i].exploding = false;
}
/**
 * Setzt die Startwerte fuer alle 
 * feindlichen Klingonenschiffe.
 */
void initKlingonShips() {
  for (byte i=0; i < NUM_KLINGONSHIPS; i++) {
    spawnKlingonShip(i);
  }
}

void updateKlingonShip(const byte i) {
  klingonShips[i].x -= klingonShips[i].vx;
  klingonShips[i].y -= klingonShips[i].vy;
  if (klingonShips[i].x < - 16) {
    spawnKlingonShip(i);
  }
}

void updateKlingonShips() {
  for (byte i=0; i < NUM_KLINGONSHIPS; i++) {
    updateKlingonShip(i);
  }
}




