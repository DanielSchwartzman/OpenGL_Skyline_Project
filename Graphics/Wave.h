#pragma once
typedef struct 
{
	double offsetX;
	double offsetY;
	double offsetXChange;
}WAVE;

//Wave functuions
void initializeAllWaves(WAVE* waves, int numOfWaves);
void initilizeWave(WAVE* wave);
void drawWaves(WAVE* waves, int numOfWaves);
void moveWave(WAVE* waves, int numOfWaves);
void defineWaveColor(double y);