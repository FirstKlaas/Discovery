void loop() {
  if (gb.update()) {
    if(gb.buttons.pressed(BTN_C)){
      initDiscovery();
      initKlingonShips();
    }
    //if (gb.buttons.pressed(BTN_B)) {
    if (gb.buttons.pressed(BTN_A)) {
      launchMissile();
    }
    if (gb.buttons.repeat(BTN_B, 1)) {
      discovery.shielded = true;
    } else {
      discovery.shielded = false;
    }
    //move the player
    if(gb.buttons.repeat(BTN_UP, 1)){
      discovery.y = max(1, discovery.y - discovery.vy);
    }
    if(gb.buttons.repeat(BTN_DOWN, 1)){
      discovery.y = min(LCDHEIGHT - discovery.w, discovery.y + discovery.vy);
    }
    checkForCollisions();
    drawMissilesAndUpdatePosition();
    drawDiscovery();
    drawKlingonShips();
    updateKlingonShips();
    
    gb.display.cursorX = 10;
    gb.display.cursorY = 2;
    gb.display.print(discovery.score);
    
  }
}
