#include <stdio.h>
#include <stdbool.h>

#include "math.h"
#include "triangleSolver.h"
#include "main.h"

float* analyzeAngle(int side1, int side2, int side3);

char* analyzeTriangle(int side1, int side2, int side3) 
{
	if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1 + side2 <= side3 || side2 + side3 <= side1 || side3 + side1 <= side2) // added triangle inequality theorem
	{
		return "Not a triangle\n";
	}
	else if (side1 == side2 && side1 == side3)
	{
		analyzeAngle(side1, side2, side3);
		return "Equilateral triangle\n";		//calling the function to calculate the angles
	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2) || (side2 == side3 && side3 != side1))
	{
		analyzeAngle(side1, side2, side3);		//calling the function to calculate the angles
		return "Isosceles triangle\n";
	}
	else
	{
		analyzeAngle(side1, side2, side3);		//calling the function to calculate the angles
		return "Scalene triangle\n";
	}
}
	
float* analyzeAngle(int side1, int side2, int side3) 
{
	float angles[3];
		

		if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1 + side2 <= side3 || side2 + side3 <= side1 || side3 + side1 <= side2) //  triangle inequality theorem
		{
				angles[0] = -1;
				angles[1] = -1;
				angles[2] = -1;
				return angles; 
				// returns every angle as -1 if the input is not valid to make a triangle. 
		}

		// added calculation to the angles 
		float temp1 = (float)(side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
		float temp2 = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
		angles[0] = acos(temp1) * (180 / 3.14159265358979323846); // converting radians to angles 
		angles[1] = acos(temp2) * (180 / 3.14159265358979323846); // converting radians to angles 
		angles[2] = 180 - angles[0] - angles[1];

		printf("first angle is %.1f \n second angle is %.1f \n third angle is %.1f \n", angles[0], angles[1], angles[2]); //added output of the angles

	return angles;
} 