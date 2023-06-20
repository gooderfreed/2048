#include "../inc/DinamicText.h"
#include "../inc/utils.h"
#include <GL/glut.h>

void DinamicText::draw() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    std::string tmp = text + std::to_string(arg);
    glColor3f(color[0], color[1], color[2]);
    glOrtho(0, 1, 1, 0, 0, 1);
    drawString(GLUT_BITMAP_TIMES_ROMAN_24, tmp.c_str(), x, y);
    glPopMatrix();
}

void DinamicText::set_arg(int arg) {
    this->arg = arg;
}