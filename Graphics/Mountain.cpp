#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Mountain.h"
#include "glut.h"

#define PI 3.14

void initilizeMountain(MOUNTAIN* mountain) 
{
	mountain->offsetX = 5;// (-1000 + rand() % 2000) / 1000.0;
	mountain->offsetY = 0;
}

void drawMountain(MOUNTAIN* mountain)
{
	double x, y;

	for (x = -1; x <= 1.1; x += 0.01)
	{
		y = (sin(PI * x + mountain->offsetX) * 0.3) + mountain->offsetY;
		if (y >= -0.3) 
		{
			glColor3d(0, 0.5, 0);
			glBegin(GL_POLYGON);
			glVertex2d(x, -0.3);
			glVertex2d(x - 0.01, -0.3);
			glColor3d(0.2, 0.3, 0.2);
			glVertex2d(x - 0.01, y);
			glVertex2d(x, y);
			glEnd();
		}
	}
}

void drawMountainReflection(MOUNTAIN* mountain)
{
	double x, y;

	for (x = -1; x <= 1.1; x += 0.01)
	{
		y = (sin(PI * x + mountain->offsetX) * 0.1 * -1) - 0.5;
		if (y <= -0.45)
		{
			glColor3d(0, 0.5, 0);
			glBegin(GL_POLYGON);
			glVertex2d(x, -0.3);
			glVertex2d(x - 0.01, -0.3);
			glColor3d(0.2, 0.3, 0.2);
			glVertex2d(x - 0.01, y);
			glVertex2d(x, y);
			glEnd();
		}
	}
}