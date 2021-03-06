void loop() {
  if (gb.update()) {
    if(gb.buttons.pressed(BTN_C)){
      if (game.is_running) {
        game.is_running = false;
        gb.display.persistence = true; 

      } else {
        initGame();
        game.is_running = true;
        gb.display.persistence = false; 
      }
    }
    
    if (!game.is_running) {
      gb.titleScreen(F("FirstKlaas"), SPRITE_DISCOVERY);  
      return;
    }
    
    //if (gb.buttons.pressed(BTN_B)) {
    if (gb.buttons.pressed(BTN_A)) {
      if (!discovery.shielded) launchMissile();
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
    drawLives();  
    updateKlingonShips();
    
    gb.display.cursorX = 20;
    gb.display.cursorY = 2;
    gb.display.print(discovery.score);
    gb.display.cursorX = 45;
    gb.display.cursorY = 2;
    gb.display.print("Lvl:");
    gb.display.cursorX = 60;
    gb.display.cursorY = 2;
    gb.display.print(discovery.lvl+1);
    
  }
}
