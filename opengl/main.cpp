//
//  main.cpp
//  opengl
//
//  Created by Robin Malhotra on 31/07/14.
//  Copyright (c) 2014 Robin's code kitchen. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>

void display(void);
void reshape(int, int);
void windowInit();
void renderScene();
void reshape();
int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    windowInit();
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;

}


void reshape(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;
	float ratio = 1.0* w / h;
    
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
    
    // Reset Matrix
	glLoadIdentity();
    
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
    
	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000);
    
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void windowInit()
{
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(512, 512);
    glutCreateWindow("trial");

}


void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glVertex3f(-2,-2,-5.0);
    glVertex3f(2,0.0,-5.0);
    glVertex3f(0.0,2,-5.0);
    glEnd();
    glutSwapBuffers();
}