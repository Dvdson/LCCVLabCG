//
// Created by dvdson on 8/29/16.
//

#ifndef LCCVLABCG_OPENGLCUSTOMOBJ_H
#define LCCVLABCG_OPENGLCUSTOMOBJ_H

#include <GL/glut.h>

void drawHexahedron(GLfloat Dx,GLfloat Dy,GLfloat Dz){


    GLfloat x1 =0+Dx, y1=0+Dy, z1=0+Dz;
    //first face

    glBegin(GL_QUADS);
    glColor4f(1,1,1,1);
        glVertex3f(0, 0, 0);
        glVertex3f(x1, 0, 0);
        glVertex3f(x1, y1, 0);
        glVertex3f(0, y1, 0);

    //second face
    glColor4f(1,1,0,1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, z1);
        glVertex3f(0, y1, z1);
        glVertex3f(0, y1, 0);

    //third face
    glColor4f(1,0,1,1);

        glVertex3f(0, 0, 0);
        glVertex3f(x1, 0, 0);
        glVertex3f(x1, 0, z1);
        glVertex3f(0, 0, z1);

    //fourth face
    glColor4f(1,0,0,1);
        glVertex3f(x1, y1, z1);
        glVertex3f(0, y1, z1);
        glVertex3f(0, 0, z1);
        glVertex3f(x1, 0, z1);

    //fifth face
    glColor4f(0,0,1,1);
        glVertex3f(x1, y1, z1);
        glVertex3f(x1, y1, 0);
        glVertex3f(0, y1, 0);
        glVertex3f(0, y1, z1);

    //sixth face
    glColor4f(0,1,0,1);
        glVertex3f(x1, y1, z1);
        glVertex3f(x1, y1, 0);
        glVertex3f(x1, 0, 0);
        glVertex3f(x1, 0, z1);
    glEnd();

}


#endif //LCCVLABCG_OPENGLCUSTOMOBJ_H
