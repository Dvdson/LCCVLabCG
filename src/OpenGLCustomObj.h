//
// Created by dvdson on 8/29/16.
//

#ifndef LCCVLABCG_OPENGLCUSTOMOBJ_H
#define LCCVLABCG_OPENGLCUSTOMOBJ_H

#include <GL/glut.h>
#define PI 3.14159265359


int winWidth = 1280, winHeight = 720;

// the key states. These variables will be zero
//when no key is being presses

GLdouble xPast = 0, DirAngle = 3*PI/2;
GLdouble camLookX=sin(DirAngle),camLookY=0,camLookZ =-cos(DirAngle);
GLdouble camDirX=0, camDirZ=-1;
GLdouble camPosX=0, camPosY=3, camPosZ=1;
GLdouble camSencitivity=1;

void drawHexahedron(GLfloat Dx,GLfloat Dy,GLfloat Dz){


    GLfloat x1 =0+Dx, y1=0+Dy, z1=0+Dz;
    //first face

    glBegin(GL_QUADS);
    //glColor4f(1,1,1,1);//white
        glVertex3f(0, 0, 0);
        glVertex3f(x1, 0, 0);
        glVertex3f(x1, y1, 0);
        glVertex3f(0, y1, 0);
    glEnd();

    //second face
    //glColor4f(1,1,0,1);//yellow
    glBegin(GL_QUADS);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, z1);
        glVertex3f(0, y1, z1);
        glVertex3f(0, y1, 0);
    glEnd();

    //third face
    glBegin(GL_QUADS);
    //glColor4f(1,0,1,1);
        glVertex3f(0, 0, 0);
        glVertex3f(x1, 0, 0);
        glVertex3f(x1, 0, z1);
        glVertex3f(0, 0, z1);
    glEnd();

    //fourth face
    glBegin(GL_QUADS);
    //glColor4f(1,0,0,1);
        glVertex3f(x1, y1, z1);
        glVertex3f(0, y1, z1);
        glVertex3f(0, 0, z1);
        glVertex3f(x1, 0, z1);
    glEnd();

    //fifth face
    glBegin(GL_QUADS);
    //glColor4f(0,0,1,1);
        glVertex3f(x1, y1, z1);
        glVertex3f(x1, y1, 0);
        glVertex3f(0, y1, 0);
        glVertex3f(0, y1, z1);
    glEnd();

    //sixth face
    glBegin(GL_QUADS);
    //glColor4f(0,1,0,1);
        glVertex3f(x1, y1, z1);
        glVertex3f(x1, y1, 0);
        glVertex3f(x1, 0, 0);
        glVertex3f(x1, 0, z1);
    glEnd();

}

void drawRoom(void){

    GLfloat hWall = 30.0;
    GLfloat tWall = 5;

    //
    glPushMatrix();
        glTranslatef(0,0,-30);
        //glRotatef();
        drawHexahedron(tWall,hWall,tWall);
    glPopMatrix();

    // pillar 2
    glPushMatrix();
        glTranslatef(70-tWall,0,-30);
        //glRotatef();
        drawHexahedron(tWall,hWall,tWall);
    glPopMatrix();

    // pillar 3
    glPushMatrix();
        glTranslatef(70-tWall,0,-(100-tWall));
        //glRotatef();
        drawHexahedron(tWall,hWall,tWall);
    glPopMatrix();

    // pillar 4
    glPushMatrix();
        glTranslatef(50-tWall,0,-(100-tWall));
        //glRotatef();
        drawHexahedron(tWall,hWall,tWall);
    glPopMatrix();

    // pillar 5
    glPushMatrix();
        glTranslatef(50-tWall,0,-85);
        //glRotatef();
        drawHexahedron(tWall,hWall,tWall);
    glPopMatrix();

    // pillar 6
    glPushMatrix();
        glTranslatef(0,0,-85);
        //glRotatef();
        drawHexahedron(tWall,hWall,tWall);
    glPopMatrix();

}

#endif //LCCVLABCG_OPENGLCUSTOMOBJ_H
