#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"
#include "Stars.h"

void initializeStars(STARS* allStars, int numOfStars)
{
	int i;

	srand(time(0));

	for (i = 0; i < numOfStars; i++)
	{
		allStars[i].x = (-1000 + rand() % 2000) / 1000.0;
		allStars[i].y = (-1000 + rand() % 2000) / 1000.0;
		allStars[i].size = 1 + rand() % 2;
	}
}

void displayStars(STARS* allStars, int numOfStars)
{
	int i;
	glColor3d(1, 1, 1);

	for (i = 0; i < numOfStars; i++)
	{
		glPointSize(allStars[i].size);
		glBegin(GL_POINTS);
		glVertex2d(allStars[i].x, allStars[i].y);
		glEnd();
	}
}

void displayStarsReflection(STARS* allStars, int numOfStars)
{
	int i;
	glColor3d(1, 1, 1);
	glPointSize(2);

	glBegin(GL_POINTS);
	double reflectionY;
	for (i = 0; i < numOfStars; i++)
	{
		if ((allStars[i].y > -0.2) && (allStars[i].y < 0.4))
		{
			reflectionY = -0.3 - ((-0.3) - allStars[i].y) * -1;
			if(reflectionY < -0.45)
				glVertex2d(allStars[i].x, reflectionY);
		}
	}
	glEnd();
}

void rotateAllStars(STARS* allStars, int numOfStars)
{
	int i;

	for (i = 0; i < numOfStars; i++)//Rotates each star 0.0005 degrees counter clockwise around point (0,0)
	{
		double s = sin(0.0005);
		double c = cos(0.0005);
		allStars[i].x = allStars[i].x * c - allStars[i].y * s;
		allStars[i].y = allStars[i].x * s + allStars[i].y * c;
	}
}