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

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

//    TODO camera is always center in (0,0,0), to right rotate I need to do the same thing
    //seeVar();
    gluLookAt(camTransX, camTransY, camTransZ, camTransX + camDirX , camTransY, camTransZ + camDirZ, 0, 1, 0);
    camTransX = 0, camTransY = 0, camTransZ = 0;
    camDirX = 0, camDirZ = -1;



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


    glPushMatrix();

        glTranslatef(60,10,-35);
        glRotatef(135,0,-1,0);
        drawMonitor();
        glTranslatef(7,-2,-5);
        drawPC();
    glPopMatrix();

    //roof
    glPushMatrix();
        glColor4f(1,1,1,1);
        glTranslatef(0,30,-30);
        drawHexahedron(70,1,-70);
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
            camTransZ -= camSencitivity;
            camPosZ += camTransZ;
           // camTransX = camSencitivity*camLookX;
            //glutPostRedisplay();
            break;
        case 's':
            camTransZ += camSencitivity;
            camPosZ += camTransZ;
            //camTransX = -camSencitivity*camLookX;
            //glutPostRedisplay();
            break;
        case 'a':
            camTransX -= camSencitivity;
            camPosX += camTransX;
            //camTransX = camSencitivity*camLookZ;
            //glutPostRedisplay();
            break;
        case 'd':
            camTransX += camSencitivity;
            camPosX += camTransX;
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
    camDirX = sin(deltaAngle);
    camDirZ = -cos(deltaAngle);
    DirAngle += deltaAngle;
    camLookX += -cos(DirAngle);
    camLookZ += sin(DirAngle);

    seeVar();

    cout << "sin: (" << to_string(camDirX) << ") ";
    cout << "-cos: (" << to_string(camDirZ) << ")" << endl;


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