#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

float bkgrnd[] = { 0.73f, 0.68f, 0.62f };
float yellow[] = { 1.0f, 1.0f, 0.0f };

float empt[] = { 0.8f, 0.76f, 0.7f };
float num2[] = { 0.93f, 0.89f, 0.85f };
float num4[] = { 0.93f, 0.88f, 0.78f };
float num8[] = { 0.98f, 0.68f, 0.44f };
float num16[] = { 0.99f, 0.54f, 0.34f };
float num32[] = { 1.0f, 0.42f, 0.32f };
float num64[] = { 1.0f, 0.25f, 0.11f };
float num128[] = { 0.93f, 0.81f, 0.41f };
float num256[] = { 0.94f, 0.81f, 0.33f };
float num512[] = { 0.94f, 0.79f, 0.25f };
float num1024[] = { 0.98f, 0.77f, 0.16f };
float num2048[] = { 0.95f, 0.69f, 0.15f };

float textcol1[3] = { 0.47f, 0.43f, 0.39f };
float textcol2[3] = { 0.97f, 0.96f, 0.94f };

float* getColor(int num) {
    switch (num) {
    case 0: return empt; break;
    case 2: return num2; break;
    case 4: return num4; break;
    case 8: return num8; break;
    case 16: return num16; break;
    case 32: return num32; break;
    case 64: return num64; break;
    case 128: return num128; break;
    case 256: return num256; break;
    case 512: return num512; break;
    case 1024: return num1024; break;
    case 2048: return num2048; break;
    default: std::cout << num << std::endl; break;
    }
    return NULL;
}

float* getTextColor(int num) {
    switch (num) {
    case 2 || 4: return textcol2; break;
    default: return textcol1; break;
    }
}

void line(float x1, float y1, float x2, float y2, float z, float* color) {
    glLineWidth(3);
    glColor3f(color[0], color[1], color[2]);
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f(x1, y1, z);
    glVertex3f(x2, y2, z);
    glEnd();
    glPopMatrix();
}

void parallelepiped(float* crds, float length, float width, float height, float* color) {
    glPushMatrix();
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_QUADS);

    glVertex3f(crds[0] + length / 2, crds[1] + width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] + width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] + width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] + length / 2, crds[1] + width / 2, crds[2] + height / 2);

    glVertex3f(crds[0] + length / 2, crds[1] - width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] - width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] - width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] + length / 2, crds[1] - width / 2, crds[2] - height / 2);

    glVertex3f(crds[0] + length / 2, crds[1] + width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] + width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] - width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] + length / 2, crds[1] - width / 2, crds[2] + height / 2);

    glVertex3f(crds[0] + length / 2, crds[1] - width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] - width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] + width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] + length / 2, crds[1] + width / 2, crds[2] - height / 2);

    glVertex3f(crds[0] - length / 2, crds[1] + width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] + width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] - width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] - length / 2, crds[1] - width / 2, crds[2] + height / 2);

    glVertex3f(crds[0] + length / 2, crds[1] + width / 2, crds[2] - height / 2);
    glVertex3f(crds[0] + length / 2, crds[1] + width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] + length / 2, crds[1] - width / 2, crds[2] + height / 2);
    glVertex3f(crds[0] + length / 2, crds[1] - width / 2, crds[2] - height / 2);
    glEnd();
    glPopMatrix();
}

void drawString(void* font, const char* text, float x, float y) {
    if (!text) return;
    glRasterPos2f(x, y);
    while (*text) {
        if (*text == '\n') {
            glRasterPos2f(x, y+0.05);
        }
        glutBitmapCharacter(font, *text);
        text++;
    }
}

int randint(int min, int max) {
    srand(time(0));
    return (rand() % max) + min;
}
