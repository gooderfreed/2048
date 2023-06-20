#pragma once
#ifndef board_h
#define board_h

#include "Cell.h"
#include <cmath>

const int N = 4;

class Board {
private:
    Cell* matrix[N][N];
    float size;
    int score = 0;
public:
    Board(float size);

    ~Board();

    int get_score() { return score; }
    void draw();
    void gen_new();
    int check();
    void move(char dur);
};

#endif