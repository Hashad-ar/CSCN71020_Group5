#include <stdio.h>
#include <stdbool.h>

#include "math.h"
#include "rectangleSolver.h"
//added new main file for rectangle feature

#define M_PI 3.14159265358979323846				//To convert radians to degree
double RightAngleRadian = 90 * M_PI / 180;	//90 degree angle to radian value

char* analyzeRectangle(COORDINATES Rectangle_Points[])
{
	double sides[3][4];
	double perimeterOfShape;
	double areaOfRectangle;

	sides[0][0] = sqrt( pow(abs(Rectangle_Points[1].x_axis - Rectangle_Points[0].x_axis), 2) + pow(abs(Rectangle_Points[1].y_axis - Rectangle_Points[0].y_axis), 2));
	sides[0][1] = sqrt( pow(abs(Rectangle_Points[2].x_axis - Rectangle_Points[1].x_axis), 2) + pow(abs(Rectangle_Points[2].y_axis - Rectangle_Points[1].y_axis), 2));
	sides[0][2] = sqrt( pow(abs(Rectangle_Points[3].x_axis - Rectangle_Points[2].x_axis), 2) + pow(abs(Rectangle_Points[3].y_axis - Rectangle_Points[2].y_axis), 2));
	sides[0][3] = sqrt( pow(abs(Rectangle_Points[0].x_axis - Rectangle_Points[3].x_axis), 2) + pow(abs(Rectangle_Points[0].y_axis - Rectangle_Points[3].y_axis), 2));

	double extraSides1 = sqrt(pow(abs(Rectangle_Points[1].x_axis - Rectangle_Points[3].x_axis), 2) + pow(abs(Rectangle_Points[1].y_axis - Rectangle_Points[3].y_axis), 2));
	double extraAngle1 = acos((sides[0][1] * sides[0][1] + sides[0][3] * sides[0][3] - extraSides1 * extraSides1) / (2 * sides[0][1] * sides[0][3]));

	sides[1][0] = sqrt( pow(abs(Rectangle_Points[2].x_axis - Rectangle_Points[0].x_axis), 2) + pow(abs(Rectangle_Points[2].y_axis - Rectangle_Points[0].y_axis), 2));
	sides[1][1] = sqrt( pow(abs(Rectangle_Points[3].x_axis - Rectangle_Points[2].x_axis), 2) + pow(abs(Rectangle_Points[3].y_axis - Rectangle_Points[2].y_axis), 2));
	sides[1][2] = sqrt( pow(abs(Rectangle_Points[1].x_axis - Rectangle_Points[3].x_axis), 2) + pow(abs(Rectangle_Points[1].y_axis - Rectangle_Points[3].y_axis), 2));
	sides[1][3] = sqrt( pow(abs(Rectangle_Points[0].x_axis - Rectangle_Points[1].x_axis), 2) + pow(abs(Rectangle_Points[0].y_axis - Rectangle_Points[1].y_axis), 2));

	double extraSides2 = sqrt(pow(abs(Rectangle_Points[2].x_axis - Rectangle_Points[1].x_axis), 2) + pow(abs(Rectangle_Points[2].y_axis - Rectangle_Points[1].y_axis), 2));
	double extraAngle2 = acos((sides[1][1] * sides[1][1] + sides[1][3] * sides[1][3] - extraSides2 * extraSides2) / (2 * sides[1][1] * sides[1][3]));

	sides[2][0] = sqrt( pow(abs(Rectangle_Points[3].x_axis - Rectangle_Points[0].x_axis), 2) + pow(abs(Rectangle_Points[3].y_axis - Rectangle_Points[0].y_axis), 2));
	sides[2][1] = sqrt( pow(abs(Rectangle_Points[1].x_axis - Rectangle_Points[3].x_axis), 2) + pow(abs(Rectangle_Points[1].y_axis - Rectangle_Points[3].y_axis), 2));
	sides[2][2] = sqrt( pow(abs(Rectangle_Points[2].x_axis - Rectangle_Points[1].x_axis), 2) + pow(abs(Rectangle_Points[2].y_axis - Rectangle_Points[1].y_axis), 2));
	sides[2][3] = sqrt( pow(abs(Rectangle_Points[0].x_axis - Rectangle_Points[2].x_axis), 2) + pow(abs(Rectangle_Points[0].y_axis - Rectangle_Points[2].y_axis), 2));
	
	double extraSides3 = sqrt(pow(abs(Rectangle_Points[3].x_axis - Rectangle_Points[2].x_axis), 2) + pow(abs(Rectangle_Points[3].y_axis - Rectangle_Points[2].y_axis), 2));
	double extraAngle3 = acos((sides[2][1] * sides[2][1] + sides[2][3] * sides[2][3] - extraSides3 * extraSides3) / (2 * sides[2][1] * sides[2][3]));

	if (sides[0][0] == sides[0][2] && sides[0][1] == sides[0][3] && extraAngle1 == RightAngleRadian)
	{
		perimeterOfShape = sides[0][0] + sides[0][1] + sides[0][2] + sides[0][3];
		printf("The perimeter is %.2f\n", perimeterOfShape);
		areaOfRectangle = sides[0][0] * sides[0][1];
		printf("The area of the rectangle is %.2f\n", areaOfRectangle);

		return "It's a Rectangle\n";
	}
	else if (sides[1][0] == sides[1][2] && sides[1][1] == sides[1][3] && extraAngle2 == RightAngleRadian)
	{
		perimeterOfShape = sides[1][0] + sides[1][1] + sides[1][2] + sides[1][3];
		printf("The perimeter is %.2f\n", perimeterOfShape);
		areaOfRectangle = sides[1][0] * sides[1][1];
		printf("The area of the rectangle is %.2f\n", areaOfRectangle);

		return "It's a Rectangle\n";
	}
	else if (sides[2][0] == sides[2][2] && sides[2][1] == sides[2][3] && extraAngle3 == RightAngleRadian)
	{
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