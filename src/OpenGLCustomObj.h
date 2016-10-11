//
// Created by dvdson on 8/29/16.
//

#ifndef LCCVLABCG_OPENGLCUSTOMOBJ_H
#define LCCVLABCG_OPENGLCUSTOMOBJ_H

#include <GL/glut.h>
#include <SOIL/SOIL.h>
//#include<SOIL.h>
#include<vector>

#define PI 3.14159265359
#define MAX_NUM_TEXTURES 10

GLuint textureID[MAX_NUM_TEXTURES];


int winWidth = 1280, winHeight = 720;

// the key states. These variables will be zero
//when no key is being presses

GLdouble xPast = 0,yPast = 0, DirAngleX = 3*PI/2;
GLdouble X = 0,Y = 0, R = 3;
GLdouble camLookX=0,camLookY=0,camLookZ =-1;
//GLdouble camDirX=0, camDirZ=-1;
//GLdouble camPosX=0, camPosY=15, camPosZ=0;
GLdouble camTransX=0, camTransY=15, camTransZ=0;
GLdouble camSencitivity=1;
float P = 1.0;

GLfloat doorAngle = 0;
bool openDoor=false, closeDoor=false;
void loadTexture(char *texturePath, int index) {
    int width, height;

    unsigned char* image = SOIL_load_image(texturePath, &width, &height, 0, SOIL_LOAD_RGBA);
    //printf("%d %d\n", width, height);

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
    loadTexture((char *) "/home/wmarques/Development/ClionProjects/LCCVLabCG/textures/table.jpg", 1);
    loadTexture((char *) "/home/wmarques/Development/ClionProjects/LCCVLabCG/textures/chair.jpg", 2);
    loadTexture((char *) "/home/wmarques/Development/ClionProjects/LCCVLabCG/textures/texturespcscreen.png", 3);
    loadTexture((char *) "/home/wmarques/Development/ClionProjects/LCCVLabCG/textures/cpu-front.JPG", 4);
    loadTexture((char *) "/home/wmarques/Development/ClionProjects/LCCVLabCG/textures/floor2.jpg", 5);
}

//A = (0,1), B = (1,1), C = (1,0), D = (0,0).
//Formato do Array: vertex[12] = {Ax,Ay,Az,Bx,By,Bz,Cx,Cy,Cz,Dy,Dy,Dz};
void drawWall(std::vector<float> vertex, int textureIndex) {

    if(vertex.size() != 12) return;

    glBindTexture(GL_TEXTURE_2D, textureID[textureIndex]);

    glBegin(GL_QUADS);
        if(textureIndex >= 0 && textureIndex <= 5) glTexCoord2d(0,1); glVertex3f(vertex[0],vertex[1],vertex[2]);
        if(textureIndex >= 0 && textureIndex <= 5) glTexCoord2d(1,1); glVertex3f(vertex[3],vertex[4],vertex[5]);
        if(textureIndex >= 0 && textureIndex <= 5) glTexCoord2d(1,0); glVertex3f(vertex[6],vertex[7],vertex[8]);
        if(textureIndex >= 0 && textureIndex <= 5) glTexCoord2d(0,0); glVertex3f(vertex[9],vertex[10],vertex[11]);
    glEnd();
}



void drawHexahedron(GLfloat Dx,GLfloat Dy,GLfloat Dz, int textedID[6]){


    GLfloat x1 =0+Dx, y1=0+Dy, z1=0+Dz;
    //glColor4f(1,1,1,1);
    std::vector<float> wall;

    //Front
    wall = {0,0,0,
            x1,0,0,
            x1,y1,0,
            0,y1,0};
    drawWall(wall,textedID[0]);

    //Left
    wall = {0,0,0,
            0,0,z1,
            0,y1,z1,
            0,y1,0};
    drawWall(wall,textedID[1]);

    //Base
    wall = {0,0,0,
            x1,0,0,
            x1,0,z1,
            0,0,z1};
    drawWall(wall,textedID[2]);

    //Back
    wall = {0, 0, z1,
            x1, 0, z1,
            x1,y1,z1,
            0, y1, z1};
    drawWall(wall,textedID[3]);

    //Edge
    wall = {x1,y1,z1,
            x1, y1, 0,
            0, y1, 0,
            0,y1, z1};
    drawWall(wall,textedID[4]);

    //Right
    wall = {x1,y1,z1,
            x1, y1, 0,
            x1, 0, 0,
            x1, 0, z1};
    drawWall(wall,textedID[5]);

}

void drawRoom(void){

    GLfloat hWall = 30.0;
    GLfloat tWall = 5;

    int texID[6] = {0,0,0,0,0,0};

    // begin of front door wall
        glPushMatrix();
            glTranslatef(0,0,-30);
            //glRotatef();
            drawHexahedron(tWall,hWall,tWall,texID);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(tWall,2*hWall/3,-30);
            //glRotatef();
            drawHexahedron(3*tWall,hWall/3,tWall,texID);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(4*tWall,0,-30);
            //glRotatef();
            drawHexahedron(70-4*tWall,hWall,tWall,texID);
        glPopMatrix();
    //end of front door wall

    // second wall
    glPushMatrix();
        glTranslatef(70-tWall,0,-30);
        //glRotatef();
        drawHexahedron(tWall,hWall,-(70-tWall),texID);
    glPopMatrix();

    // third wall
    glPushMatrix();
        glTranslatef(30,0,-100);
        //glRotatef();
        drawHexahedron(40,hWall,tWall,texID);
    glPopMatrix();

    // 4 wall
    glPushMatrix();
        glTranslatef(30-tWall,0,-(85-tWall));
        //glRotatef();
        drawHexahedron(tWall,hWall,-(tWall+15),texID);
    glPopMatrix();

    // wall with the window
    glPushMatrix();
        glTranslatef(0+tWall,0,-85);
        //glRotatef();
        drawHexahedron(30-tWall,hWall/3,tWall,texID);
    glPopMatrix();

    // 6 wall
    glPushMatrix();
        glTranslatef(0,0,-(35-tWall));
        //glRotatef();
        drawHexahedron(tWall,hWall,-70,texID);
    glPopMatrix();

    // 7 wall
    glPushMatrix();
        glTranslatef(5,5,-90);
        //glRotatef();
        drawHexahedron(20,5,-10,texID);
    glPopMatrix();

}

void drawDoor(void){

//x=15
//y=20

    int texID[6] = {-1,-1,-1,-1,-1,-1};
        glColor4f(0.9,0.9,0.9,1);
        drawHexahedron(9,8,1,texID);

        glColor4f(0.7,0.7,0.9,1);
        glTranslatef(9,0,0);
        drawHexahedron(6,8,1,texID);

        glColor4f(0.7,0.7,50.9,1);
        glTranslatef(-9,8,0);
        drawHexahedron(9,2,1,texID);

        glColor4f(0.5,0.5,0.5,1);
        glTranslatef(9,0,0);
        drawHexahedron(6,2,1,texID);

        glColor4f(0.9,0.9,0.9,1);
        glTranslatef(-9,2,0);
        drawHexahedron(6,10,1,texID);

        glColor4f(0.9,0.9,0.9,1);
        glTranslatef(6,8,0);
        drawHexahedron(3,2,1,texID);

        glColor4f(0.7,0.7,0.9,1);
        glTranslatef(3,-8,0);
        drawHexahedron(6,10,1,texID);
}


void drawWindow(void){


    int texID[6] = {-1,-1,-1,-1,-1,-1};

    glColor4f(0.2,0.1,0.1,1);
    //fisrt
    glPushMatrix();
        glTranslatef(5,10,-85);
        drawHexahedron(20,1,0.5,texID);
        drawHexahedron(1,20,0.5,texID);
        glTranslatef(0,15,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(20,5,0);
        drawHexahedron(-20,-1,0,texID);
        drawHexahedron(-1,-20,0,texID);
    glPopMatrix();

    //second

    glPushMatrix();
        glTranslatef(5,9,-100);
        drawHexahedron(20,1,0.,texID);
        drawHexahedron(1,20,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(0,2,0);
        drawHexahedron(20,1,0.5,texID);
        glTranslatef(20,5,0);
        drawHexahedron(-1,-20,0,texID);
    glPopMatrix();

}

void drawTables(void){

    glColor4f(0.8,0.8,0.8,1);

    int texID[6] = {1,1,1,1,1,1};

    glPushMatrix();
        glTranslatef(30,10,-37);
        drawHexahedron(35,-1 , 7, texID);
        glTranslatef(28,0,0);
        drawHexahedron(7,-1 , -58, texID);
        glTranslatef(-53,0,-7);
        drawHexahedron(7, -1, -35, texID);
    glPopMatrix();


}

void drawPC(void){
    glColor4f(0.2,0.2,0.2,1);
    int texID[6] = {-1,-1,-1,4,-1,-1};
    drawHexahedron(3,6,6, texID);
}

void drawMonitor(void){
    glColor4f(0.7,0.7,0.7,1);

    int texID[6] = {-1,-1,-1,-1,-1,-1};

    glTranslatef(-1.5,0,-1);
    drawHexahedron(3,1,2,texID);

    glTranslatef(1.0,0,0.5);
    drawHexahedron(1,4,1,texID);

    glTranslatef(0,3,0.5);
    drawHexahedron(1,1,1,texID);

    texID[3] = 3;

    glTranslatef(-2,-1,0.5);
    drawHexahedron(5,4,1,texID);


}

void drawChair(void){

    //glColor4f(0.7,0.7,0.7,1);
    glTranslatef(0,2,0);

    int texID[6] = {-1,-1,-1,-1,-1,-1};

    //pernas
    drawHexahedron(1,1,4,texID);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1,texID);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    drawHexahedron(1,1,4,texID);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1,texID);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    drawHexahedron(1,1,4,texID);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1,texID);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    drawHexahedron(1,1,4,texID);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1,texID);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);

    glRotatef(72,0,1,0);
    drawHexahedron(1,1,4,texID);
    glTranslatef(0,0,3);
    drawHexahedron(1,-1,1,texID);
    glTranslatef(0.5,-1.5,0.5);
    glutSolidSphere(0.5,10,8);
    glTranslatef(-0.5,1.5,-0.5);
    glTranslatef(0,0,-3);
    //pernas end


    //pillar
    glRotatef(72,0,1,0);
    glTranslatef(-0.5,0,-0.5);
    drawHexahedron(1,4,1,texID);
    glTranslatef(0.5,0,0.5);

    //sitter
    texID[0] = 2;
    texID[1] = 2;
    texID[3] = 2;
    texID[4] = 2;
    texID[5] = 2;
    glTranslatef(0,4,0);
    drawHexahedron(3,0.5,3,texID);
    drawHexahedron(3,0.5,-3,texID);
    drawHexahedron(-3,0.5,3,texID);
    drawHexahedron(-3,0.5,-3,texID);

    //back-stanchion pillar
    texID[0] = -1;
    texID[1] = -1;
    texID[3] = -1;
    texID[4] = -1;
    texID[5] = -1;
    glTranslatef(0,0,3);
    drawHexahedron(1,4,1,texID);

    //back-stanchion
    texID[1] = 2;
    texID[2] = 2;
    texID[3] = 2;
    texID[4] = 2;
    texID[5] = 2;
    glTranslatef(-2.5,2,0);
    drawHexahedron(5,5,-1,texID);


}
#endif //LCCVLABCG_OPENGLCUSTOMOBJ_H
