#include "space.h"

#define NUM_KLINGONSHIPS 6
#define NUM_MISSILES 10
#define SPRITE_DISCOVERY_HEIGHT 8
#define SPRITE_DISCOVERY_WIDTH  16
#define SPRITE_KLINGONSHIP_HEIGHT 15
#define SPRITE_KLINGONSHIP_WIDTH  8

KlingonShip klingonShips[NUM_KLINGONSHIPS];
Discovery discovery;
Missile missiles[NUM_MISSILES];
Game game;

Gamebuino gb;

void initGame() {
  game.number_of_lives = 5; 
  game.max_number_of_lives  = 6; 
  game.is_running = false;
  initDiscovery();
  initKlingonShips();
  initMissiles();

}





