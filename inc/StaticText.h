#pragma once
#ifndef Statictext_h
#define Statictext_h

#include <string>
#include "Text.h"

class StaticText: Text {
public:
    StaticText(float y, float x, char* text, float* color) : Text(y, x, text, color) {};
    void set_text(char* text);
    float get_x();
    float get_y() { return y; };
    void set_coords(float y, float x);
    void draw() override;
};

#endif