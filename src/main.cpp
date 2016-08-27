//
// Created by dvdson on 7/26/16.
//
#include <GL/glut.h>
#include <stdlib.h>


void init (void)
{

    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(50);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
        glVertex2f(640,360);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex3f(320, 0.0f, -320.0f);
        glVertex3f(-100.0f, 0.0f,  100.0f);
        glVertex3f( 100.0f, 0.0f,  100.0f);
        glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

    glutSwapBuffers();

}

void reshape(GLint w, GLint h){
    glViewport(0,0,(GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //gluPerspective(60.0,(GLfloat) w/(GLfloat) h,1.0,20.0);
    //gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'd':

            break;
        default:
            break;

    }
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1280, 720);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("CG Room");

    init ();

    glutDisplayFunc(display);
    //glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;

}