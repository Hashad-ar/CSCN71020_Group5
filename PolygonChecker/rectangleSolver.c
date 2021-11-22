#include <stdio.h>
#include <stdbool.h>

#include "math.h"
#include "rectangleSolver.h"
//added new main file for rectangle feature

char* analyzeRectangle(double xaxis[4], double yaxis[4])
{
	double side11 = sqrt((xaxis[1] - xaxis[0]) * (xaxis[1] - xaxis[0]) + (yaxis[1] - yaxis[0]) * (yaxis[1] - yaxis[0]));
	double side12 = sqrt((xaxis[2] - xaxis[1]) * (xaxis[2] - xaxis[1]) + (yaxis[2] - yaxis[1]) * (yaxis[2] - yaxis[1]));
	double side13 = sqrt((xaxis[3] - xaxis[2]) * (xaxis[3] - xaxis[2]) + (yaxis[3] - yaxis[2]) * (yaxis[3] - yaxis[2]));
	double side14 = sqrt((xaxis[0] - xaxis[3]) * (xaxis[0] - xaxis[3]) + (yaxis[0] - yaxis[3]) * (yaxis[0] - yaxis[3]));

	double side21 = sqrt((xaxis[2] - xaxis[0]) * (xaxis[2] - xaxis[0]) + (yaxis[2] - yaxis[0]) * (yaxis[2] - yaxis[0]));
	double side22 = sqrt((xaxis[3] - xaxis[2]) * (xaxis[3] - xaxis[2]) + (yaxis[3] - yaxis[2]) * (yaxis[3] - yaxis[2]));
	double side23 = sqrt((xaxis[1] - xaxis[3]) * (xaxis[1] - xaxis[3]) + (yaxis[1] - yaxis[3]) * (yaxis[1] - yaxis[3]));
	double side24 = sqrt((xaxis[0] - xaxis[1]) * (xaxis[0] - xaxis[1]) + (yaxis[0] - yaxis[1]) * (yaxis[0] - yaxis[1]));

	double side31 = sqrt((xaxis[3] - xaxis[0]) * (xaxis[3] - xaxis[0]) + (yaxis[3] - yaxis[0]) * (yaxis[3] - yaxis[0]));
	double side32 = sqrt((xaxis[2] - xaxis[3]) * (xaxis[2] - xaxis[3]) + (yaxis[2] - yaxis[3]) * (yaxis[2] - yaxis[3]));
	double side33 = sqrt((xaxis[1] - xaxis[2]) * (xaxis[1] - xaxis[2]) + (yaxis[1] - yaxis[2]) * (yaxis[1] - yaxis[2]));
	double side34 = sqrt((xaxis[0] - xaxis[1]) * (xaxis[0] - xaxis[1]) + (yaxis[0] - yaxis[1]) * (yaxis[0] - yaxis[1]));

	double perimeterOfShape;
	double areaOfRectangle;

	if (side11 == side13 && side12 == side14 && acos((side11 * side11 + side13 * side13) / (2*side11*side13)) == 1.57)
	{
		perimeterOfShape = side11 + side12 + side13 + side14;
		printf("The perimeter is %.2f\n", perimeterOfShape);
		return "It's a Rectangle";
		areaOfRectangle = side11 * side13;
		printf("The area of the rectangle is %.2f", areaOfRectangle);
	}
	else if (side21 == side23 && side22 == side24 && acos((side21 * side21 + side23 * side23) / (2 * side21 * side23)) == 1.57)
	{
		perimeterOfShape = side21 + side22 + side23 + side24;
		printf("The perimeter is %.2f\n", perimeterOfShape);
		return "It's a Rectangle";
		areaOfRectangle = side21 * side23;
		printf("The area of the rectangle is %.2f", areaOfRectangle);
	}
	else if (side31 == side33 && side32 == side34 && acos((side31 * side31 + side33 * side33) / (2 * side31 * side33)) == 1.57)
	{
		perimeterOfShape = side31 + side32 + side33 + side34;
		printf("The perimeter is %.2f\n", perimeterOfShape);
		return "It's a Rectangle";
		areaOfRectangle = side31 * side33;
		printf("The area of the rectangle is %.2f", areaOfRectangle);
	}
	else 
	{
		perimeterOfShape = side11 + side12 + side13 + side14;
		printf("The perimeter is %.2f\n", perimeterOfShape);
		return "Not a Rectangle";
	}

	

	//printf("Side1 is %.2f, Side2 is %.2f, Side3 is %.2f, Side4 is %.2f", side11, side12, side13, side14);

}