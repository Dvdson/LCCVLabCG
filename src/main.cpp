#include <iostream>

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include "OpenGLCustomObj.h"

using namespace std;

GLfloat ambienceLight[4] = {.2,.2,.2,1};
GLfloat difuseLight[4] = {.7,.7,.7,1};
GLfloat specularLight[4] = {1,1,1,1};

GLfloat specularity[4] = {1,1,1,1};
GLint especMaterial = 50;
GLfloat lightPosition[4] = {-20,50,20,1};
GLfloat lightDirection[4] = {0,1,0,1};
GLfloat blight[] = {2};

void seeVar(int texid[6]){




//    cout << "camPosVector: ";
//    cout << "( " << to_string(camTransX);
//    cout << ", " << to_string(camTransY);
//    cout << ", " << to_string(camTransZ);
//    cout << ")" << endl;
//
//    cout << "camLookVector: ";
//    cout << "( " << to_string(camLookX);
//    cout << ", " << to_string(camLookY);
//    cout << ", " << to_string(camLookZ);
//    cout << ")" << endl;

    for (int i = 0; i < 6; ++i) {

    }
    cout << "camLookVector: ";
    cout << "( " << to_string(camLookX);
    cout << ", " << to_string(camLookY);
    cout << ", " << to_string(camLookZ);
    cout << ")" << endl;

    cout << DirAngleX << endl;
}


void initIlumination() {

    glEnable(GL_LIGHTING);
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_NORMALIZE);

    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT,GL_SPECULAR,specularity);
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambienceLight);

    glLightfv(GL_LIGHT0,GL_AMBIENT,ambienceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,difuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specularLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPosition);
    glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,lightDirection);
    glLightfv(GL_LIGHT0,GL_SPOT_EXPONENT,blight);
    //glLightf(GL_LIGHT0,GL_SPOT_CUTOFF,50);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int texID[6] = {-1,-1,-1,-1,-1,-1};

    //initilazing and setting the camera modelView
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(60.0,(GLfloat) winWidth/(GLfloat) winHeight,1.0,200.0);
    gluLookAt(camTransX, camTransY, camTransZ, camTransX + camLookX , camTransY + camLookY, camTransZ + camLookZ, 0, 1, 0);


    /*glPushMatrix();
        glTranslatef(35,30,-50);
        glColor4f(1,0,0,0);
        glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(0,100,-150);
    glColor4f(1,0,0,0);
    glutSolidSphere(10,10,10);
    glPopMatrix();*/

    //floor
    glPushMatrix();
        glTranslatef(0,0,-100);
        glColor4f(1,1,1,1);
        texID[4] = 5;
        drawHexahedron(100,-0.5,100,texID);
    glPopMatrix();

        texID[4] = -1;

    //glColor4f(0.75,0.75,0.75,1);
    drawRoom();
    drawWindow();
    drawTables();

    //door
    glPushMatrix();
        glTranslatef(5,0,-26);
        glRotatef(doorAngle,0,1,0);
        drawDoor();
    glPopMatrix();

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
        //texID[2]=5;
        glColor4f(1,1,1,1);
        glTranslatef(0,30,-25);
        drawHexahedron(70,1,-75,texID);
    glPopMatrix();

    glutSwapBuffers();

    if(openDoor){

        doorAngle+=1;
        if(doorAngle >=90) openDoor = false;

        glutPostRedisplay();
    }
    if(closeDoor){

        doorAngle-=1;
        if(doorAngle <=0) closeDoor = false;

        glutPostRedisplay();
    }

    glTranslatef(0,0,0);
}


void reshape(GLint w, GLint h){

    glViewport(0,0,(GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(60.0,(GLfloat) w/(GLfloat) h,1.0,200.0);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    //moviment by (w,s,a,d) set new position , the position were the camera Look at, as reference
    switch(key)
    {
        case 'w':
            camTransZ += camSencitivity*camLookZ;
            camTransX += camSencitivity*camLookX;
            break;
        case 's':
            camTransZ -= camSencitivity*camLookZ;
            camTransX -= camSencitivity*camLookX;
            break;
        case 'a':
            camTransZ -= camSencitivity*camLookX;
            camTransX += camSencitivity*camLookZ;
            break;
        case 'd':
            camTransZ += camSencitivity*camLookX;
            camTransX -= camSencitivity*camLookZ;
            break;
        case ' ':
            if(closeDoor || doorAngle<=45) {openDoor = true; closeDoor = false;}
            else if(openDoor || doorAngle>45) {closeDoor = true; openDoor = false;}
            break;
        case '1':
            camSencitivity -= 0.1;
            cout << camSencitivity << endl;
            break;
        case '2':
            camSencitivity += 0.1;
            cout << camSencitivity << endl;
            break;
        case 27:
            break;
        default:
            break;
    }
    //seeVar();
    glutPostRedisplay();
}

void mouseMove(int x, int y) {

    //were the camera look is defined by DirAngleX in radians

    // update deltaAngleX
    GLdouble deltaAngleX = (x - xPast) * 0.01f;
    GLdouble deltaAngleY = (y - yPast) * 0.01f;

    // update camera's direction
    DirAngleX += deltaAngleX;


    camLookX = sin(DirAngleX);
    camLookZ = -cos(DirAngleX);

    //settinf new position of the xPast
    xPast = x;
//    seeVar();
//    glutWarpPointer((int)(winWidth/2 + 0.5),(int)(winHeight/2 + 0.5));
//    seeVar();
    glutPostRedisplay();
}

void init(void) {
    glClearColor(0, 0, 0, 0);

    glEnable(GL_TEXTURE_2D);

    initTextures();
    initIlumination();

    glClearDepth(1.0);

    glViewport(0,0,(GLsizei) winWidth, (GLsizei) winHeight);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

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