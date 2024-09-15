#include "Window.h"

#pragma once
typedef struct
{
	double startX;
	double endX;
	double height;
	WINDOW allWindows[1000];
	int numWindows;
}BUILDINGS;

void initializeBuildings(BUILDINGS* allBuildings, int numOfBuildings);
void drawBuildings(BUILDINGS* allBuildings, int numOfBuildings);
void drawBuildingsReflection(BUILDINGS* allBuildings, int numOfBuildings);
void drawWindows(BUILDINGS* building);
void drawWindowsReflection(BUILDINGS* building);