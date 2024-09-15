#pragma once
typedef struct
{
	double offsetX;
	double offsetY;
}MOUNTAIN;

void initilizeMountain(MOUNTAIN* mountain);
void drawMountain(MOUNTAIN* mountain);
void drawMountainReflection(MOUNTAIN* mountain);