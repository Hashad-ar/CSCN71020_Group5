#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "math.h"
#include "rectangleSolver.h"
#include "angleSolver.h"

int side = 0;

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
			int Rectangle_xAxis[4] = { 0, 0, 0, 0 };
			int Rectangle_yAxis[4] = { 0, 0, 0, 0 };
			getRectanglePoints(Rectangle_xAxis, Rectangle_yAxis);

			/*for (int i = 0; i < 4; i++)
			{
				printf("the %d point is: \n", (i + 1));
				printf("x: %d,  y: %d\n", Rectangle_xAxis[i], Rectangle_yAxis[i]);
			}
			break;
			*/
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
void getRectanglePoints(int* xAxis, int* yAxis)
{
	int j = 1; // counter for the order of the point 
	for (int i = 0; i< 4; i++)
	{
	
		printf_s("Enter the coordinates for the %d's point :\n", j);
		scanf_s("%d", &xAxis[i]);
		scanf_s("%d", &yAxis[i]);
		j++;
	}
	
}	