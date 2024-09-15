#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"
#include "Buildings.h"

#define PI 3.14

//Window Colors
#define WHITE 0
#define YELLOW 1
#define BLUE 2
#define RED 3
#define PURPLE 4

void initializeBuildings(BUILDINGS* allBuildings, int numOfBuildings)
{
	double x, y;
	int i=0;

	for (x = -1; x <= 1; x += 0.2,i++)//Initialize first buildings row
	{
		if (i == 10) 
		{
			break;
		}
		y = 0.5 * cos(0.5 * PI * x) + 0.2 * sin(6 * PI * x);
		allBuildings[i].startX = x;
		allBuildings[i].endX = x + 0.15;
		allBuildings[i].height = y;

		int iter = 0;
		for (double k = -0.29; k < allBuildings[i].height - 0.01; k += 0.01)//Initialize windows
		{
			for (double j = allBuildings[i].startX + 0.01; j < allBuildings[i].endX - 0.03; j += 0.01)
			{
				allBuildings[i].allWindows[iter].x = j;
				allBuildings[i].allWindows[iter].y = k;
				allBuildings[i].allWindows[iter].intensity = rand() % 2;
				iter++;
			}
		}
		allBuildings[i].numWindows = iter;
	}
	for (x = -0.92; x <= 1; x += 0.2, i++)//Initialize second buildings row
	{
		if (i != 19)
			y = 0.4 * cos(0.5 * PI * x + 0.2) + 0.2 * sin(6 * PI * x + 0.2);
		else
			y = 0.2;
		allBuildings[i].startX = x;
		allBuildings[i].endX = x + 0.15;
		allBuildings[i].height = y;

		int iter = 0;
		for (double k = -0.29; k < allBuildings[i].height - 0.01; k += 0.01)//Initialize windows
		{
			for (double j = allBuildings[i].startX + 0.01; j < allBuildings[i].endX - 0.03; j += 0.01)
			{
				allBuildings[i].allWindows[iter].x = j;
				allBuildings[i].allWindows[iter].y = k;
				allBuildings[i].allWindows[iter].intensity = rand() % 2;
				iter++;
			}
		}
		allBuildings[i].numWindows = iter;
	}
}

void drawBuildings(BUILDINGS* allBuildings, int numOfBuildings)
{
	for (int i = 0; i < numOfBuildings; i++)
	{
		glBegin(GL_POLYGON);
			glColor3d(0,0,0);
			glVertex2d(allBuildings[i].startX, -0.3);
			glVertex2d(allBuildings[i].endX-0.03, -0.3);
			glColor3d(0.2, 0.2, 0.2);
			glVertex2d(allBuildings[i].endX - 0.03, allBuildings[i].height);
			glVertex2d(allBuildings[i].startX, allBuildings[i].height);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3d(0, 0, 0);
			glVertex2d(allBuildings[i].endX - 0.03, -0.3);
			glVertex2d(allBuildings[i].endX, -0.3);
			glColor3d(0.1, 0.1, 0.1);
			glVertex2d(allBuildings[i].endX, allBuildings[i].height);
			glVertex2d(allBuildings[i].endX - 0.03, allBuildings[i].height);
		glEnd();

		drawWindows(&allBuildings[i]);
	}
}

void drawBuildingsReflection(BUILDINGS* allBuildings, int numOfBuildings) 
{
	for (int i = 0; i < numOfBuildings; i++)
	{
		glBegin(GL_POLYGON);
		glColor3d(0, 0, 0);
		glVertex2d(allBuildings[i].startX, -0.3);
		glVertex2d(allBuildings[i].endX - 0.03, -0.3);
		glColor3d(0.4, 0.4, 0.4);
		glVertex2d(allBuildings[i].endX - 0.03, -0.3 - fabs(-0.3-allBuildings[i].height) * 0.65);
		glVertex2d(allBuildings[i].startX, -0.3 - fabs(-0.3 - allBuildings[i].height) * 0.65);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3d(0, 0, 0);
		glVertex2d(allBuildings[i].endX - 0.03, -0.3);
		glVertex2d(allBuildings[i].endX, -0.3);
		glColor3d(0.2, 0.2, 0.2);
		glVertex2d(allBuildings[i].endX, -0.3 - fabs(-0.3 - allBuildings[i].height) * 0.65);
		glVertex2d(allBuildings[i].endX - 0.03, -0.3 - fabs(-0.3 - allBuildings[i].height) * 0.65);
		glEnd();

		drawWindowsReflection(&allBuildings[i]);
	}
}

void drawWindows(BUILDINGS* building)
{
	glColor3d(1, 1, 0);
	glPointSize(1);
	glBegin(GL_POINTS);
	for (int i = 0; i < building->numWindows; i++)
	{
		if(building->allWindows[i].intensity ==1)
			glVertex2d(building->allWindows[i].x, building->allWindows[i].y);
	}
	glEnd();
}

void drawWindowsReflection(BUILDINGS* building)
{
	glColor3d(1, 1, 0);
	glPointSize(1);
	glBegin(GL_POINTS);
	for (int i = 0; i < building->numWindows; i++)
	{
		if (building->allWindows[i].intensity == 1)
			glVertex2d(building->allWindows[i].x, -0.3 - fabs(-0.3 -building->allWindows[i].y) * 0.65);
	}
	glEnd();
}