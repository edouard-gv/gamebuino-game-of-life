//
// Created by edoua on 02/02/2020.
//

#ifndef HELLO_MYLIB_H
#define HELLO_MYLIB_H

void nextWorld(bool **input, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            input[i][j] = !input[i][j];
        }
    }
}

#endif //HELLO_MYLIB_H
