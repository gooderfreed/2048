#pragma once
#ifndef utils_h
#define utils_h

extern float bkgrnd[];
extern float yellow[10];

extern float empt[];
extern float num2[];
extern float num4[];
extern float num8[];
extern float num16[];
extern float num32[];
extern float num64[];
extern float num128[];
extern float num256[];
extern float num512[];
extern float num1024[];
extern float num2048[];

extern float textcol1[];
extern float textcol2[];

float* getColor(int num);
float* getTextColor(int num);
void line(float x1, float y1, float x2, float y2, float z, float* color);
void parallelepiped(float* crds, float length, float width, float height, float* color);
void drawString(void* font, const char* text, float x, float y);
int randint(int min, int max);

#endif
