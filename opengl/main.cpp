//
//  main.cpp
//  opengl
//
//  Created by Robin Malhotra on 31/07/14.
//  Copyright (c) 2014 Robin's code kitchen. All rights reserved.
//
//#include <BulletDynamics/btBulletDynamicsCommon.h>

#include <iostream>
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif
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
void mousey(int xx, int yy);

GLubyte fly[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x80, 0x01, 0xC0, 0x06, 0xC0, 0x03, 0x60,
    0x04, 0x60, 0x06, 0x20, 0x04, 0x30, 0x0C, 0x20,
    0x04, 0x18, 0x18, 0x20, 0x04, 0x0C, 0x30, 0x20,
    0x04, 0x06, 0x60, 0x20, 0x44, 0x03, 0xC0, 0x22,
    0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
    0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
    0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
    0x66, 0x01, 0x80, 0x66, 0x33, 0x01, 0x80, 0xCC,
    0x19, 0x81, 0x81, 0x98, 0x0C, 0xC1, 0x83, 0x30,
    0x07, 0xe1, 0x87, 0xe0, 0x03, 0x3f, 0xfc, 0xc0,
    0x03, 0x31, 0x8c, 0xc0, 0x03, 0x33, 0xcc, 0xc0,
    0x06, 0x64, 0x26, 0x60, 0x0c, 0xcc, 0x33, 0x30,
    0x18, 0xcc, 0x33, 0x18, 0x10, 0xc4, 0x23, 0x08,
    0x10, 0x63, 0xC6, 0x08, 0x10, 0x30, 0x0c, 0x08,
    0x10, 0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x08};


int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    windowInit();
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(keyProcessor);
    glutPassiveMotionFunc(mousey);
	glutSpecialFunc(processSpecialKeys);
    glutMainLoop();
    return 0;

}

void mousey(int xx, int yy)
{
    float mouseShift=atan(double(yy)/xx);
    lx = sin(mouseShift);
    lz = -cos(mouseShift);
}

//why didn't this get added?
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
    glShadeModel (GL_FLAT);
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);


    glEnable(GL_DEPTH_TEST);


}


void renderScene()
{
    
   	// Clear Color and Depth Buffers
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
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
    glVertex3f(100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f, -100.0f);

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
