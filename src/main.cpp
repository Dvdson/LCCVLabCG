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

void drawPlan(float x, float y, float z, int width, int height) {
    glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex3f(x, y, z);
        glVertex3f(x, height-y, z);
        glVertex3f(width-x, height-y, z);
        glVertex3f(width-x, y, z);
    glEnd();
}

void display(void) {

    float x = 320, y = 180, z = -1.0;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    drawPlan(x,y,z,winWidth,winHeight);

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