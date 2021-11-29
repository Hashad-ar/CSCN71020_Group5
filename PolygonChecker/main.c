#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "math.h"
#include "rectangleSolver.h"
#include "angleSolver.h"

int side = 0;
COORDINATES Rectangle_Points[4] = { 0 };

//Hello from Prof. Coleshill
//Hello from dani

int main() {

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2: // added another case for the rectangle and intiliazed the x and y axis 
			printf_s("Rectangle selected.\n");
			getRectanglePoints(Rectangle_Points);
			char* result2 = analyzeRectangle(Rectangle_Points);
			printf_s("%s\n", result2);
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			continueProgram = false;				//Added to fix infinite loop
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("2. Rectangle\n");
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

//added input for Rectangle points
void getRectanglePoints(COORDINATES AxisArray[])
{
	for (int i = 0; i < 4; i++)
	{
		printf_s("Enter the coordinates for point %d:\n", i + 1);
		printf_s("X: ");
		scanf_s("%lf",&AxisArray[i].x_axis);
		printf_s("Y: ");
		scanf_s("%lf",&AxisArray[i].y_axis);
	}
}	