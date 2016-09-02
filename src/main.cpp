#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "OpenGLCustomObj.h"
#define PI 3.14159265359

using namespace std;

int winWidth = 1280, winHeight = 720;

bool firstT = true;

GLfloat QPosX=0, QPosY=0, QPosZ=0;
GLfloat keySencitivity = 1;
GLdouble camPosX=0, camPosY=0, camPosZ=1;
GLdouble camSencitivity=1;


void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

//      glOrtho(0.0, winWidth, 0.0, winHeight, -100, 100);
    glViewport(0,0,(GLsizei) winWidth, (GLsizei) winHeight);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT
            | GL_DEPTH_BUFFER_BIT
    );

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    gluLookAt(camPosX, camPosY, camPosZ, camPosX, camPosY, camPosZ-1, 0, 1, 0);
    camPosX = 0, camPosY = 0, camPosZ = 0;



//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
    //floor
    glPushMatrix();
        glTranslatef(QPosX,QPosY,QPosZ);
        glColor4f(1,1,1,1);
        drawHexahedron(1,1,1);
    glPopMatrix();

    //displayRoom();
    //drawPlan(x,y,z,winWidth,winHeight);

    glutSwapBuffers();
}

void reshape(GLint w, GLint h){

    glViewport(0,0,(GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(60.0,(GLfloat) w/(GLfloat) h,1.0,200.0);
    gluLookAt(camPosX,camPosY,camPosZ,camPosX,camPosY,camPosZ-1,0,1,0);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key)
    {
        case 'w':
            camPosY += keySencitivity;
            //glutPostRedisplay();
            break;
        case 's':
            camPosY -= keySencitivity;
            //glutPostRedisplay();
            break;
        case 'a':
            QPosX -= keySencitivity;
            //glutPostRedisplay();
            break;
        case 'd':
            QPosX += keySencitivity;
            //glutPostRedisplay();
            break;
        case 'r':
            QPosZ -= keySencitivity;
            //glutPostRedisplay();
            break;
        case 'f':
            QPosZ += keySencitivity;
            //glutPostRedisplay();
            break;
        case '1':
            keySencitivity -= 0.1;
            //glutPostRedisplay();
            break;
        case '2':
            keySencitivity += 0.1;
            //glutPostRedisplay();
            break;
        case 'i':
            camPosY += camSencitivity;
            //glutPostRedisplay();
            break;
        case 'k':
            camPosY -= camSencitivity;
            //glutPostRedisplay();
            break;
        case 'j':
            camPosX -= camSencitivity;
            //glutPostRedisplay();
            break;
        case 'l':
            camPosX += camSencitivity;
            //glutPostRedisplay();
            break;
        case 'y':
            camPosZ -= camSencitivity;
            //glutPostRedisplay();
            break;
        case 'h':
            camPosZ += camSencitivity;
            //glutPostRedisplay();
            break;
        case '3':
            camSencitivity -= 0.1;
            cout << camSencitivity << endl;
            //glutPostRedisplay();
            break;
        case '4':
            camSencitivity += 0.1;
            cout << camSencitivity << endl;
            //glutPostRedisplay();
            break;
        default:
            break;
    }
    cout << "( " << to_string(camPosX) << endl;
    cout << ", " << to_string(camPosY) << endl;
    cout << ", " << to_string(camPosZ) << endl;
    cout << ")" << endl;
    glutPostRedisplay();
}



int main(int argc, char** argv) {

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Waves");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}