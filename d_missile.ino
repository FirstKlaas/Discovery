byte findNextMissile() {
  for (byte i=0; i < NUM_MISSILES; i++) {
    if (!missiles[i].isActive) return i;
  }
  return -1;
}
void initMissiles() {
  for (byte i=0; i < NUM_MISSILES; i++) {
    missiles[i].x  = 0;
    missiles[i].y  = 0;
    missiles[i].vx = 2;
    missiles[i].w  = 4;
    missiles[i].h  = 2;
    missiles[i].isActive = false;
  }  
}

void launchMissile() {
  const byte index = findNextMissile();
  if (index < 0) return;
  missiles[index].y = discovery.y + (SPRITE_DISCOVERY_HEIGHT / 2);
  missiles[index].x = discovery.x + 16;
  missiles[index].isActive = true;
}

void drawMissilesAndUpdatePosition() {
  for (byte i=0; i < NUM_MISSILES; i++) {
    if (missiles[i].isActive) {
      gb.display.fillRect(missiles[i].x, missiles[i].y, missiles[i].w, missiles[i].h);
      missiles[i].x += missiles[i].vx;
      // Auf Collision mit Klingonenschiffen pruefen
      for (byte k=0; k < NUM_KLINGONSHIPS; k++) {
        if (gb.collideRectRect(missiles[i].x, missiles[i].y, missiles[i].w, missiles[i].h, klingonShips[k].x, klingonShips[k].y, 14, 8)) {
          // Klingonenschiff getroffen
          if (!klingonShips[k].exploding) {
            gb.sound.playCancel();
            missiles[i].isActive = false;
            spawnKlingonShip(k);
            discovery.score += 10;
          }
        }
      }
      
      // Wenn die Rakete rechts aus dem Bildschirm laeuft,
      // dann wieder zurueck in das Arsenal legen. 
      if (missiles[i].x > LCDWIDTH) missiles[i].isActive = false;
    }
  }
}

