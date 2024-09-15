#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "glut.h"
#include "GeneralFunctions.h"

#define NUM_STARS 100
#define NUM_BUILDINGS 20
#define NUM_WAVES 500

STARS stars[NUM_STARS];
BUILDINGS buildings[NUM_BUILDINGS];
WAVE waves[NUM_WAVES];
MOUNTAIN mountain;

void init()
{
	glClearColor(0, 0, 0.3, 0);// color of window background
	glOrtho(-1, 1, -1, 1, -1, 1); // set the coordinates system

	initializeStars(stars, NUM_STARS);
	initializeBuildings(buildings, NUM_BUILDINGS);
	initializeAllWaves(waves, NUM_WAVES);
	initilizeMountain(&mountain);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clean frame buffer

	drawBackgroundSky();
	displayStars(stars, NUM_STARS);
	drawBackgroupWater();
	displayStarsReflection(stars, NUM_STARS);
	drawMountain(&mountain);
	drawMountainReflection(&mountain);
	drawBuildings(buildings, NUM_BUILDINGS);
	drawBuildingsReflection(buildings, NUM_BUILDINGS);
	drawCoastLine();
	drawWaves(waves, NUM_WAVES);

	glutSwapBuffers(); // show all
}

void idle() 
{
	rotateAllStars(stars, NUM_STARS);
	moveWave(waves, NUM_WAVES);
	glutPostRedisplay(); // calls indirectly display
}


int main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("HomeWork Computer graphics - 1");

	glutDisplayFunc(display);
	glutIdleFunc(idle);

	init();

	glutMainLoop();
}