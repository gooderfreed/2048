#pragma once
#ifndef Dinamictext_h
#define Dinamictext_h

#include <string>
#include "Text.h"

class DinamicText : Text {
    int arg;
public:
    DinamicText(float y, float x, char* text, int arg, float* color) : Text(y, x, text, color) { this->arg = arg; };
    void draw() override;
    int get_arg() { return arg; }
    void set_arg(int arg);
};

#endif