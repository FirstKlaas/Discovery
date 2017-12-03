void setup() {
  Serial.begin(9600);
  initGame();
  gb.begin();
  gb.display.persistence = true; 
  gb.titleScreen(F("FirstKlaas"), SPRITE_DISCOVERY);  
}

