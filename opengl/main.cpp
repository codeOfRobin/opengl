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
#include <math.h>       /* sin */
#define PI 3.14159
float angle = 0.0f;
float lx=0.0f,lz=-1.0f;
float x=0.0f,z=5.0f;
float deltaAngle=0.0f,deltaDist=0.0f;

void display(void);
void reshape(int, int);
void windowInit();
void renderScene();
void reshape();
void keyProcessor(unsigned char key, int x,int y);
void processSpecialKeys(int key, int x, int y);
void drawASnowman();//Do you want to build a snowman? It doesn't have to be a snowman..
void computeAngle();
void computeDist();
void pressKey(int key, int xx, int yy);
void releaseKey(int key, int xx, int yy);


int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    windowInit();
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(keyProcessor);
	glutSpecialFunc(processSpecialKeys);
    glutMainLoop();
    return 0;

}


void drawASnowman()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 0.75f, 0.0f);
    glutSolidSphere(0.75f, 20, 20);
    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.25f, 20, 20);
    
    glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();
    
    // Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glutSolidCone(0.08f,0.5f,10,2);
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
    glEnable(GL_DEPTH_TEST);


}


void renderScene()
{
    
   	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutIgnoreKeyRepeat(false);
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, 1.0f, z,
              lx+x, 1.0f,  lz+z,
              0.0f, 1.0f,  0.0f);
    
    glColor3f(0.9f, 0.9f, 0.9f);
    
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glVertex3f(100.0f, 0.0f, 100.0f);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(100.0f, 0.0f, -100.0f);
	
    glEnd();
    
    for (int i=-3; i<3; i++)
    {
        for (int j=-3; j<3; j++)
        {
            glPushMatrix();
            glTranslatef(i*10.0, 0.0f, j*10.0);
            drawASnowman();
            glPopMatrix();
        }
    }
    
    if (deltaAngle)
    {
        computeAngle();
    }
    else if (deltaDist)
    {
        computeDist();
    }
    glutSpecialFunc(pressKey);
    
	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

	glutSwapBuffers();
    
}


void computeAngle()
{
    angle=angle+deltaAngle;
    lx=sin(angle);
    lz=-cos(angle);
}


void computeDist()
{
    float fraction=0.1f;
    x=x+lx*deltaDist*fraction;
    z=z+lz*deltaDist*fraction;
}

void keyProcessor(unsigned char key, int x,int y)
{
    if (key==27)
    {
        std::cout<<x<<" asdcjknasd "<<y;
        exit(4);
    }
}

void processSpecialKeys(int key, int xx, int yy)
{
    float fraction=0.1f;

    if (key==GLUT_KEY_UP)
    {
        x=x+lx*fraction;
        z=z+lz*fraction;
    }
    else if (key==GLUT_KEY_DOWN)
    {
        x=x-lx*fraction;
        z=z-lz*fraction;
    }
    else if(key==GLUT_KEY_RIGHT)
    {
        angle += 0.01f;
        lx = sin(angle);
        lz = -cos(angle);

    }

    else if(key==GLUT_KEY_LEFT)
    {
        angle -= 0.01f;
        lx = sin(angle);
        lz = -cos(angle);
        
        std::cout<<angle<<" "<<asin(lx)/PI*180;
    }
}


void pressKey(int key, int xx, int yy)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            deltaDist=0.5f;
            break;
        case GLUT_KEY_DOWN:
            deltaDist=-0.5f;
            break;
        case GLUT_KEY_LEFT:
            deltaAngle=-0.01f;
            break;
        case GLUT_KEY_RIGHT:
            deltaAngle=0.01f;
            break;
        default:
            break;
    }
}


void releaseKey(int key, int xx, int yy)
{
    switch (key)
    {
        case GLUT_KEY_UP:

        case GLUT_KEY_DOWN:
            deltaDist=-0.0f;
            break;
        case GLUT_KEY_LEFT:

        case GLUT_KEY_RIGHT:
            deltaAngle=0.0f;
            break;
        default:
            break;
    }
}
