#define _CRT_SECURE_NO_WARNINGS
#include "../inc/Text.h"
#include "../inc/utils.h"
#include <GL/glut.h>
#include <cstring>
#include <cstdio>

Text::Text(float y, float x, char* text, float* color) {
    this->x = x;
    this->y = y;
    this->size = strlen(text);
    this->color = color;

    sprintf(this->text, "%s", text);
}

void Text::set_text(char* text) {
    if (size != 0) return;
    sprintf(this->text, "%s", text);
}


void Text::set_coords(float y, float x) {
    this->x = x;
    this->y = y;
}
