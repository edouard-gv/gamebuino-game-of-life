#include <Gamebuino-Meta.h>
#include "MyLib_lib/mylib.h"
bool **world;

void setup() {
  gb.begin();

  world = new bool*[gb.display.height()];

  for (int i=0; i < gb.display.height(); i++) {
    world[i] = new bool[gb.display.width()];
    for (int j=0; j < gb.display.width(); j++) {
      world[i][j] = (i==3 || i==j);
    }
  }

  //TODO: This must be put somewhere!
  /*
  for (int i = 0; i < HEIGHT; i++) {
    delete world[i];
  }
  delete world;
  */
}

void loop() {
  while(!gb.update());

  input();
  //compute();
  render();
}

