#include "../inc/StaticText.h"
#include "../inc/utils.h"
#include <GL/glut.h>

void StaticText::draw(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(color[0], color[1], color[2]);
    glOrtho(0, 1, 1, 0, 0, 1);
    drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, x, y);
    glPopMatrix();
}