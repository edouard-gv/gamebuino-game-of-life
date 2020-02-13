#include "gtest/gtest.h"
#include "mylib.h"

void printfWorld(bool **world, int H, int W) {
  printf("\n");
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%i-", world[i][j]);
    }
    printf("\n");
  }
}

void deleteWorld(bool **world, int H) {
  for (int i = 0; i < H; i++) {
    delete world[i];
  }
  delete world;
}

void assertExpectedWorld(bool **expected, bool **world, int H, int W) {
  for (int i=0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      std::string world_v = std::to_string(i) + "," + std::to_string(j) + ": " + (world[i][j] ? "true" : "false");
      std::string expected_v = std::to_string(i) + "," + std::to_string(j) + ": " + (expected[i][j] ? "true" : "false");
      EXPECT_EQ(world_v, expected_v);
    }
  }
}

TEST(MyLibTestSuite, Die) {
  int H = 2;
  int W = 3;

  bool **world = new bool *[H] {
    new bool[W] { true, false, false },
    new bool[W] { true, false, false }
  };

  bool **expected = new bool *[H] {
      new bool[W]{ false, false, true },
      new bool[W]{ false, false, false }
  };

  nextWorld(world, H, W);

  assertExpectedWorld(expected, world, H, W);

  printfWorld(world, H, W);

  deleteWorld(world, H);
  deleteWorld(expected, H);

}