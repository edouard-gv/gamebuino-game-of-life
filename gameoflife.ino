#include <Gamebuino-Meta.h>
#include "MyLib_lib/mylib.h"
bool **world;
bool **newWorld;

void setup() {
  gb.begin();

  const int height = gb.display.height();
  const int width = gb.display.width();

  world = new bool*[height];
  newWorld = new bool*[height];

  for (int i=0; i < height; i++) {
      world[i] = new bool[width];
      newWorld[i] = new bool[width];
  }

  initializeWorld(world, height, width);

  //TODO: This must be put somewhere!
  /*
  for (int i = 0; i < HEIGHT; i++) {
    delete world[i];
    delete newWorld[i];
  }
  delete world;
  delete newWorld;
  */
}

void loop() {
  while(!gb.update());

  input();
  compute();
  render();
}

