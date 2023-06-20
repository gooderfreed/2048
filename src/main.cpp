#define _CRT_SECURE_NO_WARNINGS
#include "../inc/Scene.h"
#include <GL/glut.h>

Scene* scene;

void on_motion(int x, int y) {
    scene->on_motion(x, y);
}

void on_size(int width, int height) {
    scene->on_size(width, height);
}

void on_mouse(int button, int state, int x, int y) {
    scene->on_mouse(button, state, x, y);
}

void special(int key, int x, int y) {
    scene->special(key, x, y);
}

void normal(unsigned char key, int x, int y) {
    scene->normal(key, x, y);
}

void on_timer(int value) {
    scene->on_timer(value);
    glutTimerFunc(1000, on_timer, 0);
}

void display() {
    scene->display();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    scene = new Scene();
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("2048");
    glutSetIconTitle("icon.ico");
    glutDisplayFunc(display);
    glutSpecialFunc(special);
    glutMotionFunc(on_motion);
    glutMouseFunc(on_mouse);
    glutKeyboardFunc(normal);
    glutReshapeFunc(on_size);
    glutTimerFunc(1000, on_timer, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    delete scene;
    return 0;
}