#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "OpenGLCustomObj.h"

using namespace std;


void seeVar(void){

    cout << "camPosVector: ";
    cout << "( " << to_string(camTransX);
    cout << ", " << to_string(camTransY);
    cout << ", " << to_string(camTransZ);
    cout << ")" << endl;

    cout << "camLookVector: ";
    cout << "( " << to_string(camLookX);
    cout << ", " << to_string(camLookY);
    cout << ", " << to_string(camLookZ);
    cout << ")" << endl;

    cout << DirAngle << endl;

}


void init(void) {
    glClearColor(0, 0, 0, 0);

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

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

//    TODO camera is always center in (0,0,0), to right rotate I need to do the same thing
    //seeVar();
    gluPerspective(60.0,(GLfloat) winWidth/(GLfloat) winHeight,1.0,200.0);
    gluLookAt(camTransX, camTransY, camTransZ, camTransX + camLookX , camTransY, camTransZ + camLookZ, 0, 1, 0);
    //camTransX = 0, camTransY = 0, camTransZ = 0;
    //camDirX = 0, camDirZ = -1;



//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
    //floor
    glPushMatrix();
        glTranslatef(0,0,-100);
        glColor4f(1,1,1,1);
        drawHexahedron(100,-0.5,100);
    glPopMatrix();

    glColor4f(0.75,0.75,0.75,0.5);
    drawRoom();
    drawDoor();
    drawWindow();
    drawTables();

    //Everton PC
    glPushMatrix();
        glTranslatef(60,10,-35);
        glRotatef(135,0,-1,0);
        drawMonitor();
        glRotatef(45,0,-1,0);
        glTranslatef(10,-2,-6);
        drawPC();
    glPopMatrix();
    //Everton chairs
    glPushMatrix();
        glColor4f(0.5,0.5,0.7,1);
        glTranslatef(55,0,-40);
        glRotatef(135,0,-1,0);
        drawChair();
    glPopMatrix();

    //JP PC
    glPushMatrix();
        glTranslatef(60,10,-90);
        glRotatef(45,0,-1,0);
        drawMonitor();
        glRotatef(45,0,-1,0);
        glTranslatef(10,-2,-6);
        drawPC();
    glPopMatrix();
    //JP chairs
    glPushMatrix();
        glColor4f(0.5,0.5,0.7,1);
        glTranslatef(55,0,-87);
        glRotatef(80,0,-1,0);
        drawChair();
    glPopMatrix();

    //Bal PC
    glPushMatrix();
        glTranslatef(10,10,-50);
        glRotatef(240,0,-1,0);
        drawMonitor();
        glRotatef(30,0,-1,0);
        glTranslatef(15,-12,-6);
        drawPC();
    glPopMatrix();
    //Bal chairs
    glPushMatrix();
        glColor4f(0.5,0.5,0.7,1);
        glTranslatef(15,0,-55);
        glRotatef(120,0,1,0);
        drawChair();
    glPopMatrix();

    //roof
    glPushMatrix();
        glColor4f(1,1,1,1);
        glTranslatef(0,30,-25);
        drawHexahedron(70,1,-75);
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
    //gluLookAt(camTransX,camTransY,camTransZ,camTransX,camTransY,camTransZ-1,0,1,0);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key)
    {
        case 'w':
            camTransZ += camSencitivity*camLookZ;
            camTransX += camSencitivity*camLookX;
            //camPosZ += camTransZ;
           // camTransX = camSencitivity*camLookX;
            //glutPostRedisplay();
            break;
        case 's':
            camTransZ -= camSencitivity*camLookZ;
            camTransX -= camSencitivity*camLookX;
            //camPosZ += camTransZ;
            //camTransX = -camSencitivity*camLookX;
            //glutPostRedisplay();
            break;
        case 'a':
            camTransZ -= camSencitivity*camLookX;
            camTransX += camSencitivity*camLookZ;
            //camPosX += camTransX;
            //camTransX = camSencitivity*camLookZ;
            //glutPostRedisplay();
            break;
        case 'd':
            camTransZ += camSencitivity*camLookX;
            camTransX -= camSencitivity*camLookZ;
            //camPosX += camTransX;
            //camTransX = -camSencitivity*camLookZ;
            //glutPostRedisplay();
            break;
        case '1':
            camSencitivity -= 0.1;
            cout << camSencitivity << endl;
            //glutPostRedisplay();
            break;
        case '2':
            camSencitivity += 0.1;
            cout << camSencitivity << endl;
            //glutPostRedisplay();
            break;
        default:
            break;
    }
    seeVar();
    glutPostRedisplay();
}

void mouseMove(int x, int y) {

    // update deltaAngle
    GLdouble deltaAngle = (x - xPast) * 0.01f;

    // update camera's direction
    DirAngle += deltaAngle;
    camLookX = sin(DirAngle);
    camLookZ = -cos(DirAngle);

    //seeVar();

    xPast = x;
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
    glutPassiveMotionFunc(mouseMove);

    glutMainLoop();

    return 0;
}