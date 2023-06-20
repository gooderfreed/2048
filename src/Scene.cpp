#include "../inc/Scene.h"
#include "../inc/Board.h"
#include "../inc/DinamicText.h"
#include "../inc/StaticText.h"
#include <GL/glut.h>


Scene::~Scene() {
    delete board;
    delete score_text;
    delete time_text;
};

void Scene::restart() {
    game = 0;
    time = 0;
    delete board;
    board = new Board(5.0f);
    score_text->set_arg(0);
    time_text->set_arg(0);
    glutPostRedisplay();
}

void Scene::on_size(int width, int height)
{
    this->width = width;
    if (height == 0)
        height = 1;
    this->height = height;
}

void Scene::on_motion(int x, int y) {
    rotate_y += x - mouseX;
    rotate_x += y - mouseY;
    mouseX = x;
    mouseY = y;
    glutPostRedisplay();
}

void Scene::on_mouse(int button, int state, int x, int y) {
    mouseX = x;
    mouseY = y;
    switch (button) {
    case 3:
        if (dist_z > -4.8) {
            break;
        }
        dist_z += 0.1;
        break;
    case 4:
        dist_z -= 0.1;
        break;
    }
}

void Scene::special(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        if (dist_z > -4.8) {
            break;
        }
        dist_z += 0.1;
        break;
    case GLUT_KEY_DOWN:
        dist_z -= 0.1;
        break;
    }
    glutPostRedisplay();
}

void Scene::normal(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': case 'a': case 's': case 'd':
    case 'W': case 'A': case 'S': case 'D':
        board->move(key);
        game = board->check();
        if (game == 0) {
            board->gen_new();
            score_text->set_arg(board->get_score());
        }
        glutPostRedisplay();
        break;
    case 'q': case 'Q':
        exit(0);
        break;
    case 'r': case 'R':
        restart();
        break;
    }
}

void Scene::on_timer(int value) {
    if (game == 0) {
        time++;
        time_text->set_arg(time);
        time_text->draw();
        glutPostRedisplay();
    }
}

void Scene::display() {

    char info_txt[] = "Q - Quit\nR - Restart";

    glViewport(0, 0, width, height);
    switch (game) {
    case 1:
        glClearColor(0, 1, 0, 0);
        break;
    case 0:
        glClearColor(0, 0, 0, 0);
        break;
    case -1:
        glClearColor(1, 0, 0, 0);
        break;
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    StaticText qt(0.04, 0.0, info_txt, yellow);
    qt.draw();
    score_text->draw();
    time_text->draw();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, width / height, 1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, dist_z);
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    float zero[3] = { 0.0f, 0.0f, 0.0f };
    parallelepiped(zero, 5.5, 5.5, 0.5, bkgrnd);

    board->draw();
    glutSwapBuffers();
}