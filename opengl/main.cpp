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

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    windowInit();
    glutDisplayFunc(renderScene);
    glutMainLoop();
    return 0;

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
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.0,0.5,0.0);
    glEnd();
    glutSwapBuffers();
}