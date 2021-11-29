#pragma once
#include "rectangleSolver.h"

void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
void getRectanglePoints(COORDINATES[]);
char* analyzeRectangle(COORDINATES[]);
char* analyzeTriangle(int side1, int side2, int side3);
float* analyzeAngle(int side1, int side2, int side3);