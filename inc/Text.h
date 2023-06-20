#pragma once
#ifndef text_h
#define text_h

#include <cstring>

class Text {
protected:
    float x, y;
    char text[100];
    int size;
    float* color;
public:
    Text(float y, float x, char* text, float* color);
    void set_text(char* text);
    float get_x() { return x; };
    float get_y() { return y; };
    void set_coords(float y, float x);
    virtual void draw() = 0;
};

#endif