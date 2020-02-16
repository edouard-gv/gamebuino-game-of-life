#include "gtest/gtest.h"
#include "mylib.h"

const bool x = true;
const bool o = false;

void printfWorld(bool **world, int h, int w) {
  printf("\n");
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%i-", world[i][j]);
    }
    printf("\n");
  }
}

void printfNbNeighbours(bool **world, int h, int w) {
    printf("\n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%i-", livingNeighbours(i, j, world, h, w));
        }
        printf("\n");
    }
}

bool ** createNewWorld(int h, int w) {
    bool **newWorld  = new bool *[h];
    for (int i = 0; i < h; ++i) {
        newWorld[i] = new bool[w];
    }
    return newWorld;
}

void deleteWorld(bool **world, int h) {
  for (int i = 0; i < h; i++) {
    delete world[i];
  }
  delete world;
}

std::string scoord(int i, int j);

void assertExpectedWorld(bool **expected, bool **world, int h, int w) {
  for (int i=0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::string world_v = scoord(i, j) + (world[i][j] ? "true" : "false");
      std::string expected_v = scoord(i, j) + (expected[i][j] ? "true" : "false");
      EXPECT_EQ(world_v, expected_v);
    }
  }
}

std::string scoord(int i, int j) { return std::to_string(i) + "," + std::to_string(j) + ": "; }

TEST(MyLibTestSuite, Die) {
    int H = 3;
    int W = 3;

    bool **world = new bool *[H] {
            new bool[W] { o, o, o },
            new bool[W] { o, x, o },
            new bool[W] { o, o, o }
    };

    bool **expected = new bool *[H] {
            new bool[W]{ o, o, o },
            new bool[W]{ o, o, o },
            new bool[W]{ o, o, o }
    };

    bool **newWorld = createNewWorld(H, W);
    nextWorld(world, newWorld, H, W);
    assertExpectedWorld(expected, newWorld, H, W);

    deleteWorld(world, H);
    deleteWorld(newWorld, H);
    deleteWorld(expected, H);
}

TEST(MyLibTestSuite, Blink) {
    int H = 4;
    int W = 4;

    bool **world = new bool *[H] {
            new bool[W] { o, x, o, o },
            new bool[W] { o, x, o, o },
            new bool[W] { o, x, o, o },
            new bool[W] { o, o, o, o },
    };

    bool **expected = new bool *[H] {
            new bool[W] { o, o, o, o },
            new bool[W] { x, x, x, o },
            new bool[W] { o, o, o, o },
            new bool[W] { o, o, o, o },
    };

    bool **newWorld = createNewWorld(H, W);
    nextWorld(world, newWorld, H, W);
    assertExpectedWorld(expected, newWorld, H, W);

    deleteWorld(world, H);
    deleteWorld(newWorld, H);
    deleteWorld(expected, H);
}

TEST(MyLibTestSuite, OverPopulation) {
    int H = 4;
    int W = 4;

    bool **world = new bool *[H] {
            new bool[W] { x, x, o, o },
            new bool[W] { x, x, o, o },
            new bool[W] { x, x, o, o },
            new bool[W] { o, o, o, o },
    };

    bool **expected = new bool *[H] {
            new bool[W] { x, x, o, o },
            new bool[W] { o, o, x, x },
            new bool[W] { x, x, o, o },
            new bool[W] { o, o, o, o },
    };

    bool **newWorld = createNewWorld(H, W);
    nextWorld(world, newWorld, H, W);
    assertExpectedWorld(expected, newWorld, H, W);

    deleteWorld(world, H);
    deleteWorld(newWorld, H);
    deleteWorld(expected, H);
}

TEST(MyLibTestSuite, allDyings) {
    int H = 3;
    int W = 3;

    bool **world = new bool *[H] {
            new bool[W] { o, o, o },
            new bool[W] { o, x, o },
            new bool[W] { o, o, o }
    };

    EXPECT_EQ(livingNeighbours(1, 1, world, H, W), 0);

    deleteWorld(world, H);
}

TEST(MyLibTestSuite, oneSurvives) {
    int H = 5;
    int W = 5;

    bool **world = new bool *[H] {
            new bool[W] { o, o, o, o, o },
            new bool[W] { o, o, o, o, o },
            new bool[W] { o, o, x, o, o },
            new bool[W] { o, o, o, o, o },
            new bool[W] { o, o, o, o, o }
    };

    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            EXPECT_EQ(scoord(i, j) + std::to_string(livingNeighbours(i, j, world, H, W)),
                      scoord(i, j) + std::to_string(i==2 && j==2 ? 0 : 1));
        }
    }

    deleteWorld(world, H);
}

TEST(MyLibTestSuite, livingOnTheBorders) {
    int H = 3;
    int W = 3;

    bool **world = new bool *[H] {
            new bool[W] { o, o, o },
            new bool[W] { o, o, x },
            new bool[W] { o, o, o }
    };

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            EXPECT_EQ(scoord(i, j) + std::to_string(livingNeighbours(i, j, world, H, W)),
                      scoord(i, j) + std::to_string(i==1 && j==2 ? 0 : 1));
        }
    }

    deleteWorld(world, H);
}

TEST(MyLibTestSuite, play) {
    EXPECT_EQ(-1 % 4, -1);
}