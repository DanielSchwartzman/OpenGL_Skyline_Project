#pragma once
typedef struct
{
	double x;
	double y;
	int size;
}STARS;

//Stars functions
void initializeStars(STARS* allStars, int numOfStars);
void displayStars(STARS* allStars, int numOfStars);
void displayStarsReflection(STARS* allStars, int numOfStars);
void rotateAllStars(STARS* allStars, int numOfStars);