//
// Created by dvdson on 8/29/16.
//

#ifndef LCCVLABCG_OPENGLCUSTOMOBJ_H
#define LCCVLABCG_OPENGLCUSTOMOBJ_H

#include <GL/glut.h>

int winWidth = 1280, winHeight = 720;

// the key states. These variables will be zero
//when no key is being presses

float xPast = 0;
GLdouble camLookX=0,camLookY=0,camLookZ =-1.0;
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


#endif //LCCVLABCG_OPENGLCUSTOMOBJ_H
