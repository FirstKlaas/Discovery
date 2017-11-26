void drawKlingonShips() {
  for (byte i=0; i < NUM_KLINGONSHIPS; i++) {
    gb.display.drawBitmap(klingonShips[i].x,klingonShips[i].y,klingonship,ROTCCW,NOFLIP);
    //gb.display.drawRect(klingonShips[i].x,klingonShips[i].y,14,8);
  
  }  
}

void spawnKlingonShip(const byte i) {
  klingonShips[i].x = random(LCDWIDTH , LCDWIDTH + 150);
  klingonShips[i].y = random(0,LCDHEIGHT);
  klingonShips[i].vx = 2;
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
  if (klingonShips[i].x < -16) {
    spawnKlingonShip(i);
  }
}

void updateKlingonShips() {
  for (byte i=0; i < NUM_KLINGONSHIPS; i++) {
    updateKlingonShip(i);
  }
}




