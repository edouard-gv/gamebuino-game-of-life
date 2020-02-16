//
// Created by edoua on 02/02/2020.
//

#ifndef HELLO_MYLIB_H
#define HELLO_MYLIB_H

void nextWorld(bool **world, bool **newWorld, int h, int w);
int livingNeighbours(int i, int j, bool **world, int h, int w);
void initializeWorld(bool **world, int h, int w);

void nextWorld(bool **world, bool **newWorld, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int an = livingNeighbours(i, j, world, h, w);
            if (an < 2 || an > 3)
                newWorld[i][j] = false;
            else if (an == 3)
                newWorld[i][j] = true;
            else
                newWorld[i][j] = world[i][j];
        }
    }
}

int livingNeighbours(int i, int j, bool **world, int h, int w) {
    int livings = 0;
    for (int k = i-1; k <= i+1; ++k) {
        for (int l = j-1; l <= j+1 ; ++l) {
            if (!(k==i && l==j) && world[(k + h) % h][(l + w) % w]) livings++;
        }
    }
    return livings;
}

void initializeWorld(bool **world, int h, int w) {
    for (int i=0; i < h; i++) {
        for (int j=0; j < w; j++) {
            world[i][j] = (rand() % 3 == 0);
        }
    }
}

void copyWorld(bool **source, bool **target, int h, int w) {
    for (int i=0; i < h; i++) {
        for (int j = 0; j < w; ++j) {
            target[i][j] = source[i][j];
        }
    }
}

#endif //HELLO_MYLIB_H
