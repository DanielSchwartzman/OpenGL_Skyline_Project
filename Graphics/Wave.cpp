#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Wave.h"
#include "glut.h"

#define PI 3.14
#define BOTTOM -1
#define HEIGHT_INCREASE 0.015

void initializeAllWaves(WAVE* waves, int numOfWaves)
{
	int i,iteration=0;
	double currHeight = BOTTOM;

	for (i = 0; i < numOfWaves; i++)
	{
		if (iteration++ == 10) 
		{
			iteration = 0;
			currHeight += HEIGHT_INCREASE;
		}
		waves[i].offsetY = currHeight;
		initilizeWave(&waves[i]);
	}
}

void initilizeWave(WAVE* wave)
{
	wave->offsetX = 0;
	wave->offsetXChange = (-100 + (rand() % 200)) / 10000.0;
}

void drawWaves(WAVE* waves, int numOfWaves)
{
	double x, y;
	int i;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	for (i = 0; i < numOfWaves; i++)
	{
		glBegin(GL_LINE_STRIP);
		for (x = -1; x <= 1.1; x += 0.01)
		{
			y = (sin(PI * x + waves[i].offsetX) * 0.05) + waves[i].offsetY;
			if (y < -0.35)
			{
				glPointSize(1);
				defineWaveColor(y);
				glVertex2d(x, y);
			}
			if (y >= -0.2)
				initilizeWave(&waves[i]);
		}
		glEnd();
	}
}

void defineWaveColor(double y)
{
	if ((y > -1) && (y < -0.9))
		glColor4d(0.3, 0.3, 1,0.5);
	else if ((y > -0.9) && (y < -0.8))
		glColor4d(0.33, 0.33, 1, 0.5);
	else if ((y > -0.8) && (y < -0.7))
		glColor4d(0.36, 0.36, 1, 0.5);
	else if ((y > -0.7) && (y < -0.6))
		glColor4d(0.39, 0.39, 1, 0.5);
	else if ((y > -0.6) && (y < -0.5))
		glColor4d(0.42, 0.42, 1, 0.5);
	else if ((y > -0.5) && (y < -0.4))
		glColor4d(0.45, 0.45, 1, 0.5);
	else if ((y > -0.4) && (y < -0.37))
		glColor4d(0.47, 0.47, 1, 0.5);
	else if ((y > -0.37) && (y < -0.35))
		glColor4d(0.5, 0.5, 1, 0.5);
}

void moveWave(WAVE* waves, int numOfWaves)
{
	int i;

	for (i = 0; i < numOfWaves; i++)
	{
		waves[i].offsetX += waves[i].offsetXChange;
	}
}