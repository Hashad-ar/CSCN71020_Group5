#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>
#include "math.h"
#include "rectangleSolver.h"
//added new main file for rectangle feature

bool CheckRightTriangleInRectangle(double side1, double side2, double side3);

#define M_PI 3.14159265358979323846				//To convert radians to degree
double RightAngleRadian = 90.0f * M_PI / 180.0f;	//90 degree angle to radian value

char* analyzeRectangle(COORDINATES Rectangle_Points[])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = j + 1; i < 4; i++)
			if (Rectangle_Points[j].x_axis == Rectangle_Points[i].x_axis && Rectangle_Points[j].y_axis == Rectangle_Points[i].y_axis)
			{
				return "Error, two or more coordinates are equal\n";
			}
	}

	double sides[3][4];
	double perimeterOfShape;
	double areaOfRectangle;

	sides[0][0] = sqrt( pow(abs(Rectangle_Points[1].x_axis - Rectangle_Points[0].x_axis), 2) + pow(abs(Rectangle_Points[1].y_axis - Rectangle_Points[0].y_axis), 2));
	sides[0][1] = sqrt( pow(abs(Rectangle_Points[2].x_axis - Rectangle_Points[1].x_axis), 2) + pow(abs(Rectangle_Points[2].y_axis - Rectangle_Points[1].y_axis), 2));
	sides[0][2] = sqrt( pow(abs(Rectangle_Points[3].x_axis - Rectangle_Points[2].x_axis), 2) + pow(abs(Rectangle_Points[3].y_axis - Rectangle_Points[2].y_axis), 2));
	sides[0][3] = sqrt( pow(abs(Rectangle_Points[0].x_axis - Rectangle_Points[3].x_axis), 2) + pow(abs(Rectangle_Points[0].y_axis - Rectangle_Points[3].y_axis), 2));

	double extraSides1 = sqrt(pow(abs(Rectangle_Points[1].x_axis - Rectangle_Points[3].x_axis), 2) + pow(abs(Rectangle_Points[1].y_axis - Rectangle_Points[3].y_axis), 2));
	double extraAngle1 = acos((sides[0][1] * sides[0][1] + sides[0][3] * sides[0][3] - extraSides1 * extraSides1) / (2.0 * sides[0][1] * sides[0][3]));

	sides[1][0] = sqrt( pow(abs(Rectangle_Points[2].x_axis - Rectangle_Points[0].x_axis), 2) + pow(abs(Rectangle_Points[2].y_axis - Rectangle_Points[0].y_axis), 2));
	sides[1][1] = sqrt( pow(abs(Rectangle_Points[3].x_axis - Rectangle_Points[2].x_axis), 2) + pow(abs(Rectangle_Points[3].y_axis - Rectangle_Points[2].y_axis), 2));
	sides[1][2] = sqrt( pow(abs(Rectangle_Points[1].x_axis - Rectangle_Points[3].x_axis), 2) + pow(abs(Rectangle_Points[1].y_axis - Rectangle_Points[3].y_axis), 2));
	sides[1][3] = sqrt( pow(abs(Rectangle_Points[0].x_axis - Rectangle_Points[1].x_axis), 2) + pow(abs(Rectangle_Points[0].y_axis - Rectangle_Points[1].y_axis), 2));

	double extraSides2 = sqrt(pow((double)abs(Rectangle_Points[2].x_axis - Rectangle_Points[1].x_axis), 2) + pow((double)abs(Rectangle_Points[2].y_axis - Rectangle_Points[1].y_axis), 2));
	double extraAngle2 = acos((sides[1][1] * sides[1][1] + sides[1][3] * sides[1][3] - extraSides2 * extraSides2) / (2.0 * sides[1][1] * sides[1][3]));

	sides[2][0] = sqrt( pow(abs(Rectangle_Points[3].x_axis - Rectangle_Points[0].x_axis), 2) + pow(abs(Rectangle_Points[3].y_axis - Rectangle_Points[0].y_axis), 2));
	sides[2][1] = sqrt( pow(abs(Rectangle_Points[1].x_axis - Rectangle_Points[3].x_axis), 2) + pow(abs(Rectangle_Points[1].y_axis - Rectangle_Points[3].y_axis), 2));
	sides[2][2] = sqrt( pow(abs(Rectangle_Points[2].x_axis - Rectangle_Points[1].x_axis), 2) + pow(abs(Rectangle_Points[2].y_axis - Rectangle_Points[1].y_axis), 2));
	sides[2][3] = sqrt( pow(abs(Rectangle_Points[0].x_axis - Rectangle_Points[2].x_axis), 2) + pow(abs(Rectangle_Points[0].y_axis - Rectangle_Points[2].y_axis), 2));
	
	double extraSides3 = sqrt(pow(abs(Rectangle_Points[3].x_axis - Rectangle_Points[2].x_axis), 2) + pow(abs(Rectangle_Points[3].y_axis - Rectangle_Points[2].y_axis), 2));
	double extraAngle3 = acos((sides[2][1] * sides[2][1] + sides[2][3] * sides[2][3] - extraSides3 * extraSides3) / (2.0 * sides[2][1] * sides[2][3]));

	if (sides[0][0] == sides[0][2] && sides[0][1] == sides[0][3] && CheckRightTriangleInRectangle(sides[0][0], sides[0][1], extraSides1) == true)
	{
		//printf("CONDITION ONE\n");
		perimeterOfShape = sides[0][0] + sides[0][1] + sides[0][2] + sides[0][3];
		printf("The perimeter is %.2f\n", perimeterOfShape);
		areaOfRectangle = sides[0][0] * sides[0][1];
		printf("The area of the rectangle is %.2f\n", areaOfRectangle);

		return "It's a Rectangle\n";
	}
	else if (sides[1][0] == sides[1][2] && sides[1][1] == sides[1][3] && CheckRightTriangleInRectangle(sides[1][0], sides[1][1], extraSides2) == true)
	{
		//printf("CONDITION TWO\n");
		perimeterOfShape = sides[1][0] + sides[1][1] + sides[1][2] + sides[1][3];
		printf("The perimeter is %.2f\n", perimeterOfShape);
		areaOfRectangle = sides[1][0] * sides[1][1];
		printf("The area of the rectangle is %.2f\n", areaOfRectangle);

	return "It's a Rectangle\n";
	}
		
	else if (sides[2][0] == sides[2][2] && sides[2][1] == sides[2][3] && CheckRightTriangleInRectangle(sides[2][0], sides[2][1], extraSides3) == true)
	{
		//printf("CONDITION THREE\n");
		perimeterOfShape = sides[2][0] + sides[2][1] + sides[2][2] + sides[2][3];
		printf("The perimeter is %.2f\n", perimeterOfShape);
		areaOfRectangle = sides[2][0] * sides[2][1];
		printf("The area of the rectangle is %.2f\n", areaOfRectangle);

		return "It's a Rectangle\n";
	}
	else 
	{
		perimeterOfShape = sides[0][0] + sides[0][1] + sides[0][2] + sides[0][3];
		printf("The perimeter is %.2f\n", perimeterOfShape);

		return "Not a Rectangle\n";
	}
}

bool CheckRightTriangleInRectangle(double side1, double side2, double side3)
{
	if (side1 < side3 && side2 < side3)
	{
		double angles[3];
		double temp1 = (side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
		double temp2 = (side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
		double temp3 = (side3 * side3 + side1 * side1 - side2 * side2) / (2 * side3 * side1);

		angles[0] = (acos(temp1) * (180 / M_PI)); // converting radians to angles 
		angles[1] = (acos(temp2) * (180 / M_PI)); // converting radians to angles 
		angles[2] = (acos(temp3) * (180 / M_PI));

		if (angles[0] >= 89.99 && angles[0] <= 90.01 || angles[1] >= 89.99 && angles[0] <= 90.01 || angles[2] >= 89.99 && angles[0] <= 90.01)
		{
			return true;
		}
	}
	else
		return false;
}