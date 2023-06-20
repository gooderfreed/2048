#pragma once
#ifndef scene_h
#define scene_h

#include "Board.h"
#include "DinamicText.h"

class Scene {
private:
    int game = 0;
    float mouseX = 0;
    float mouseY = 0;
    double rotate_y = 0;
    double rotate_x = 0;
    double dist_z = -7;
    float width;
    float height;
    int time = 0;
    Board* board = new Board(5.0f);
    char txt_score[10] = "Score: ";
    char txt_time[10] = "Time: ";
    DinamicText* score_text = new DinamicText(0.04, 0.45, txt_score, 0, yellow);
    DinamicText* time_text = new DinamicText(0.04, 0.8, txt_time, 0, yellow);
public:
    Scene() {};
    ~Scene();
    void restart();
    void on_size(int width, int height);
    void on_motion(int x, int y);
    void on_mouse(int button, int state, int x, int y);
    void special(int key, int x, int y);
    void normal(unsigned char key, int x, int y);
    void on_timer(int value);
    void display();
};

#endif