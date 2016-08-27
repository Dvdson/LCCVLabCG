#include <iostream>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265359

using namespace std;

int winWidth = 1280, winHeight = 720;

void init(void) {

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);

    glOrtho(0.0, winWidth, 0.0, winHeight, -1.0, 1.0);
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(50);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
        glVertex2f(winWidth/2, winHeight/2);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Waves");

    glutDisplayFunc(display);

    init();

    glutMainLoop();

    return 0;
}