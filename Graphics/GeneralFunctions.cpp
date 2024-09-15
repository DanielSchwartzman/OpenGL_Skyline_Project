#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "GeneralFunctions.h"
#include "glut.h"

void drawBackgroundSky()
{
	//Top sky
	glBegin(GL_POLYGON);
	glColor3d(0, 0, 0);// top
	glVertex2d(-1, 1);
	glVertex2d(1, 1);

	glColor3d(0.4, 0.2, 0.7);// bottom
	glVertex2d(1, -0.3);
	glVertex2d(-1, -0.3);

	glEnd();
}

void drawBackgroupWater() 
{
	//Bottom water
	glBegin(GL_POLYGON);
	glColor3d(0.4, 0.2, 0.7);// top
	glVertex2d(-1, -0.3);
	glVertex2d(1, -0.3);

	glColor3d(0.1, 0.1, 0.4);// bottom
	glVertex2d(1, -1);
	glVertex2d(-1, -1);

	glEnd();
}

void drawCoastLine()
{
	glBegin(GL_POLYGON);//Draw Coast line
	glColor3d(0,0,0);
	glVertex2d(-1,-0.35);
	glVertex2d(1, -0.35);
	glColor3d(0.1, 0.1, 0.1);
	glVertex2d(1,-0.2);
	glVertex2d(-1, -0.2);
	glEnd();

	glBegin(GL_POLYGON);//Draw Coast line reflection
	glColor3d(0.1,0.1,0.1);
	glVertex2d(-1, -0.35);
	glVertex2d(1, -0.35);
	glColor3d(0.2, 0.2, 0.2);
	glVertex2d(1, -0.45);
	glVertex2d(-1, -0.45);
	glEnd();
}