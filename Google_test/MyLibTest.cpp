#include "gtest/gtest.h"
#include "mylib.h"

const int H = 2;
const int W = 3;

void initializeWith(bool **world, bool initv[H][W]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      world[i][j] = initv[i][j];
    }
  }
}

TEST(MyLibTestSuite, AFirstTest)
{
  bool initv[2][3] = {{true,false,true},{false,true,false}};
  bool expected[2][3] = {{false,true,false},{true,false,true}};

  bool **world = new bool*[2];

  for (int i=0; i < 2; i++) {
    world[i] = new bool[3];
  }

  initializeWith(world, initv);

  nextWorld(world, 2, 3);
  for (int i=0; i < 2; i++) {
    for (int j = 0; j < 3; j++)
      ASSERT_EQ(world[i][j], expected[i][j]);
  }
}

TEST(MyLibTestSuite, JustToSee) {
  const int HEIGHT = 7;
  const int WIDTH = 3;

  int **world;

  world = new int*[HEIGHT];

  for (int i = 0; i < HEIGHT; i++) {
    world[i] = new int[WIDTH];
  }

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      world[i][j] = (i + 2*j);
    }
  }

  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (world[i][j] == 6) {
        printf("youpee");
      }
      printf("%i-", world[i][j]);
    }
    printf("\n");
  }

  ASSERT_EQ(1,2);

  for (int i = 0; i < HEIGHT; i++) {
    delete world[i];
  }

  delete world;
}