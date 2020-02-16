void input() {
  if (gb.buttons.repeat(BUTTON_A, 0)) {
    nextWorld(world, newWorld, gb.display.height(), gb.display.width());
    bool **tmp = world;
    world = newWorld;
    newWorld = tmp;
  }

  if (gb.buttons.repeat(BUTTON_B, 0)) {
    initializeWorld(world, gb.display.height(), gb.display.width());
  }
}


