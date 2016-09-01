#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "OpenGLCustomObj.h"
#define PI 3.14159265359

using namespace std;

int winWidth = 1280, winHeight = 720;

GLfloat QPosx=0, QPosy=0, QPosz=0;
GLfloat keySencitivity = 5;
GLdouble camPosX=0, camPosY=0, camPosZ=3.0;
GLdouble camSencitivity=5;

void init(void) {
    glEnable(GL_BLEND);

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    //glMatrixMode(GL_PROJECTION);

    glOrtho(0.0, winWidth, 0.0, winHeight, -5000.0, 5000.0);
}


void displayRoom(void){

    //Some predefinitions
    GLfloat proporX, proporY, thicknessWall,
    //The Walls especified in coments


    glPushMatrix();
        glTranslatef(QPosx,QPosy,QPosz);
        drawHexahedron(500,300,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(QPosx,QPosy,QPosz);
        drawHexahedron(500,300,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(QPosx,QPosy,QPosz);
        drawHexahedron(500,300,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(QPosx,QPosy,QPosz);
        drawHexahedron(500,300,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(QPosx,QPosy,QPosz);
        drawHexahedron(500,300,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(QPosx,QPosy,QPosz);
        drawHexahedron(500,300,1);
    glPopMatrix();

}

void display(void) {

    //float x = 320, y = 180, z = .0;
    gluLookAt(camPosX ,camPosY,camPosZ,0.0,0.0,.0,0.0,1.0,0.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //floor


    displayRoom();
    //drawPlan(x,y,z,winWidth,winHeight);

    glutSwapBuffers();
}

void reshape(GLint w, GLint h){
    glViewport(0,0,(GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //gluPerspective(60,(GLfloat) w/(GLfloat) h,2,1);


}

void keyboard(unsigned char key, int x, int y) {
    switch(key)
    {
        case 'w':
            QPosy += keySencitivity;
            break;
        case 's':
            QPosy -= keySencitivity;
            break;
        case 'a':
            QPosx -= keySencitivity;
            break;
        case 'd':
            QPosx += keySencitivity;
            break;
        case '1':
            keySencitivity -= 5;
            break;
        case '2':
            keySencitivity += 5;
            break;
        case 'i':
            camPosY += camSencitivity;
            break;
        case 'j':
            camPosY -= camSencitivity;
            break;
        case 'h':
            camPosX -= camSencitivity;
            break;
        case 'l':
            camPosX += camSencitivity;
            break;
        case '3':
            camSencitivity -= 5;
            break;
        case '4':
            camSencitivity += 5;
            break;
    }

    glutPostRedisplay();
}



int main(int argc, char** argv) {

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
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