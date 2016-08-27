//
// Created by dvdson on 8/27/16.
//

#ifndef LCCVLABCG_OBJECT_H
#define LCCVLABCG_OBJECT_H

#include <GL/glut.h>


class Object {
private:
    GLfloat posX;
    GLfloat posY;
    GLfloat posZ;

public:
    bool setPosition(GLfloat X, GLfloat Y, GLfloat Z);
    virtual void drawObj(void) = 0;

};


#endif //LCCVLABCG_OBJECT_H
