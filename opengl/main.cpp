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
float angle = 0.0f;

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
    glutIdleFunc(renderScene);
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
    //refer to notes for what exactly glviewport does
 
    
    
    
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
    
   	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 6.0f, 6.0f,
              0.0f, 0.0f,  0.0f,
              0.0f, 1.0f,  0.0f);
    
	glRotatef(angle, 1.0f, 0.0f, 1.0f);
    
	glBegin(GL_TRIANGLES);
    glVertex3f(-2.0f,-2.0f, 0.0f);
    glVertex3f( 2.0f, 0.0f, 0.0);
    glVertex3f( 0.0f, 2.0f, 0.0);
	glEnd();
    
	angle+=1.0f;
    
	glutSwapBuffers();
    
}