#include "init.h"

#include <GL/glut.h>

void init_opengl()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(140.0f/255.0f, 222.0f/255.0f, 200.0f/255.0f, 1.0f);
	
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}
