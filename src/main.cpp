#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "OpenGLCustomObj.h"
#define PI 3.14159265359

using namespace std;

int winWidth = 1280, winHeight = 720;

void init(void) {
    glEnable(GL_BLEND);

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);

    glOrtho(0.0, winWidth, 0.0, winHeight, -1000.0, 1000.0);
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

    float x = 320, y = 180, z = .0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();

        glTranslatef(x,y,z);
        glRotatef(30,1,0,0);
        glRotatef(60,0,1,0);
        drawHexahedron(300,200,50);

    glPopMatrix();
    //drawPlan(x,y,z,winWidth,winHeight);

    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Waves");

    glutDisplayFunc(display);

    init();

    glutMainLoop();

    return 0;
}