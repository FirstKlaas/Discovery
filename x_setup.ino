void setup() {
  Serial.begin(9600);  
  initDiscovery();
  discovery.score = LCDWIDTH;
  initKlingonShips();
  initMissiles();
  gb.begin();
  gb.titleScreen(F("FirstKlaas"), SPRITE_DISCOVERY);  
  gb.display.persistence = false; 
}

