//
// Created by dvdson on 7/26/16.
//



#include <GL/glut.h>
#include <stdlib.h>

static int year = 0, day = 0;

void init (void)
{
    /* selecionar cor de fundo (preto) */
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){



    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();

}

void reshape(GLint w, GLint h){
    glViewport(0,0,(GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(60.0,(GLfloat) w/(GLfloat) h,1.0,20.0);
    gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);


}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'd':
            day = (day + 10) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            day = (day - 10) % 360;
            glutPostRedisplay();
            break;
        case 'y':
            year = (year + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Y':
            year = (year - 5) % 360;
            glutPostRedisplay();
            break;
        case 27:
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
    glutCreateWindow ("Planetarium");

    init ();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;

}