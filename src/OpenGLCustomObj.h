//
// Created by dvdson on 8/29/16.
//

#ifndef LCCVLABCG_OPENGLCUSTOMOBJ_H
#define LCCVLABCG_OPENGLCUSTOMOBJ_H

#include <GL/glut.h>
#include <SOIL/SOIL.h>

#define PI 3.14159265359
#define MAX_NUM_TEXTURES 10

GLuint textureID[MAX_NUM_TEXTURES];

int winWidth = 1280, winHeight = 720;

// the key states. These variables will be zero
//when no key is being presses

GLdouble xPast = 0, DirAngleX = 3*PI/2;
GLdouble camLookX=0,camLookY=0,camLookZ =-1;
//GLdouble camDirX=0, camDirZ=-1;
//GLdouble camPosX=0, camPosY=15, camPosZ=0;
GLdouble camTransX=0, camTransY=15, camTransZ=0;
GLdouble camSencitivity=1;

GLfloat doorAngle = 0;
bool openDoor=false, closeDoor=false;

void loadTexture(char *texturePath, int index) {
    int width, height;

    unsigned char* image = SOIL_load_image(texturePath, &width, &height, 0, SOIL_LOAD_RGBA);
    printf("%d %d\n", width, height);

    glGenTextures(1, &textureID[index]);
    glBindTexture(GL_TEXTURE_2D, textureID[index]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
}

void initTextures() {
    loadTexture((char *) "/home/wmarques/Development/ClionProjects/LCCVLabCG/textures/wall.jpg", 0);
    loadTexture((char *) "textures/table.jpg", 1);
    loadTexture((char *) "textures/chair.jpg", 2);
    loadTexture((char *) "textures/pcscreen.png", 3);
    loadTexture((char *) "textures/cpu-front.JPG", 4);
    loadTexture((char *) "textures/lamp.jpg", 5);
}

//A = (0,1), B = (1,1), C = (1,0), D = (0,0).
//Formato do Array: vertex[12] = {Ax,Ay,Az,Bx,By,Bz,Cx,Cy,Cz,Dy,Dy,Dz};
void drawWall(float vertex[12], int textureIndex) {

    glBindTexture(GL_TEXTURE_2D, textureID[textureIndex]);

    glBegin(GL_QUADS);
    glTexCoord2d(0,1); glVertex3f(vertex[0],vertex[1],vertex[2]);
    glTexCoord2d(1,1); glVertex3f(vertex[3],vertex[4],vertex[5]);
    glTexCoord2d(1,0); glVertex3f(vertex[6],vertex[7],vertex[8]);
    glTexCoord2d(0,0); glVertex3f(vertex[9],vertex[10],vertex[11]);
    glEnd();
}

void drawHexahedron(GLfloat Dx,GLfloat Dy,GLfloat Dz){


    GLfloat x1 =0+Dx, y1=0+Dy, z1=0+Dz;
    //first face

    float wall[12] = {0,0,0,
                      x1,0,0,
                      x1,y1,0,
                      0,y1,0};
    drawWall(wall,0);
    /*glBegin(GL_QUADS);
    //glColor4f(1,1,1,1);//white
        glVertex3f(0, 0, 0);
        glVertex3f(x1, 0, 0);
        glVertex3f(x1, y1, 0);
        glVertex3f(0, y1, 0);
    glEnd();*/

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

    // begin of front door wall
        glPushMatrix();
            glTranslatef(0,0,-30);
            //glRotatef();
            drawHexahedron(tWall,hWall,tWall);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(tWall,2*hWall/3,-30);
            //glRotatef();
            drawHexahedron(3*tWall,hWall/3,tWall);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(4*tWall,0,-30);
            //glRotatef();
            drawHexahedron(70-4*tWall,hWall,tWall);
        glPopMatrix();
    //end of front door wall

    // second wall
    glPushMatrix();
        glTranslatef(70-tWall,0,-30);
        //glRotatef();
        drawHexahedron(tWall,hWall,-(70-tWall));
    glPopMatrix();

    // third wall
    glPushMatrix();
        glTranslatef(30,0,-100);
        //glRotatef();
        drawHexahedron(40,hWall,tWall);
    glPopMatrix();

    // 4 wall
    glPushMatrix();
        glTranslatef(30-tWall,0,-(85-tWall));
        //glRotatef();
        drawHexahedron(tWall,hWall,-(tWall+15));
    glPopMatrix();

    // wall with the window
    glPushMatrix();
        glTranslatef(0+tWall,0,-85);
        //glRotatef();
        drawHexahedron(30-tWall,hWall/3,tWall);
    glPopMatrix();

    // 6 wall
    glPushMatrix();
        glTranslatef(0,0,-(35-tWall));
        //glRotatef();
        drawHexahedron(tWall,hWall,-70);
    glPopMatrix();

    // 7 wall
    glPushMatrix();
        glTranslatef(5,5,-90);
        //glRotatef();
        drawHexahedron(20,5,-10);
    glPopMatrix();

}

void drawDoor(void){

//x=15
//y=20

        glColor4f(0.9,0.9,0.9,1);
        drawHexahedron(9,8,1);

        glColor4f(0.7,0.7,0.9,1);
        glTranslatef(9,0,0);
        drawHexahedron(6,8,1);

        glColor4f(0.7,0.7,50.9,1);
        glTranslatef(-9,8,0);
        drawHexahedron(9,2,1);

        glColor4f(0.5,0.5,0.5,1);
        glTranslatef(9,0,0);
        drawHexahedron(6,2,1);

        glColor4f(0.9,0.9,0.9,1);
        glTranslatef(-9,2,0);
        drawHexahedron(6,10,1);

        glColor4f(0.9,0.9,0.9,1);
        glTranslatef(6,8,0);
        drawHexahedron(3,2,1);

        glColor4f(0.7,0.7,0.9,1);
        glTranslatef(3,-8,0);
        drawHexahedron(6,10,1);
}


void drawWindow(void){


    glColor4f(0.2,0.1,0.1,1);
    //fisrt
    glPushMatrix();
        glTranslatef(5,10,-85);
        drawHexahedron(20,1,0.5);
        drawHexahedron(1,20,0.5);
        glTranslatef(0,15,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(20,5,0);
        drawHexahedron(-20,-1,0);
        drawHexahedron(-1,-20,0);
    glPopMatrix();

    //second

    glPushMatrix();
        glTranslatef(5,9,-100);
        drawHexahedron(20,1,0.5);
        drawHexahedron(1,20,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5);
        glTranslatef(20,5,0);
        drawHexahedron(-1,-20,0);
    glPopMatrix();

}

void drawTables(void){

    glColor4f(0.8,0.8,0.8,1);

    glPushMatrix();
        glTranslatef(30,10,-37);
        drawHexahedron(35,-1 , 7);
        glTranslatef(28,0,0);
        drawHexahedron(7,-1 , -58);
        glTranslatef(-53,0,-7);
        drawHexahedron(7, -1, -35);
    glPopMatrix();


}

void drawPC(void){
    glColor4f(0.2,0.2,0.2,1);
    drawHexahedron(3,6,6);
}

void drawMonitor(void){
    glColor4f(0.7,0.7,0.7,1);

    glTranslatef(-1.5,0,-1);
    drawHexahedron(3,1,2);

    glTranslatef(1.0,0,0.5);
    drawHexahedron(1,4,1);

    glTranslatef(0,3,0.5);
    drawHexahedron(1,1,1);

    glTranslatef(-2,-1,0.5);
    drawHexahedron(5,4,1);


}

void drawChair(void){

    //glColor4f(0.7,0.7,0.7,1);
    glTranslatef(0,2,0);

    drawHexahedron(1,1,4);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    drawHexahedron(1,1,4);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    drawHexahedron(1,1,4);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    drawHexahedron(1,1,4);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    drawHexahedron(1,1,4);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    glTranslatef(-0.5,0,-0.5);
    drawHexahedron(1,4,1);
    glTranslatef(0.5,0,0.5);

    glTranslatef(0,4,0);
    drawHexahedron(3,0.5,3);
    drawHexahedron(3,0.5,-3);
    drawHexahedron(-3,0.5,3);
    drawHexahedron(-3,0.5,-3);

    glTranslatef(0,0,3);
    drawHexahedron(1,4,1);

    glTranslatef(-2.5,2,0);
    drawHexahedron(5,5,-1);


}
#endif //LCCVLABCG_OPENGLCUSTOMOBJ_H
