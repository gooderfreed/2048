#pragma once
#ifndef cell_h
#define cell_h

#include <string>
#include "utils.h"

class Cell {
private:
    float x, y, z;
    float size;
    int value = 0;
public:
    Cell(float x, float y, float z, float size);
    void draw();
    void set_val(int val);
    int get_val();
};

#endif