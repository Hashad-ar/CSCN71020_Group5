#pragma once
void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
void getRectanglePoints(int* xAxis, int* yAxis);
char* analyzeRectangle(double xaxis[4], double yaxis[4]);
char* analyzeTriangle(int side1, int side2, int side3);
float* analyzeAngle(int side1, int side2, int side3);