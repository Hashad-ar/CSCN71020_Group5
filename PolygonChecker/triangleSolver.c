#include <stdio.h>
#include <stdbool.h>

#include "math.h"
#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1 + side2 < side3 || side2 + side3 < side1 || side3 + side1 < side2) // added triangle inequality theorem
	{
		result = "Not a triangle\n";
	}
	else if (side1 == side2 && side1 == side3)
	{
		result = "Equilateral triangle\n";
		printf("All angles are 60 degrees.\n"); // added an output for Equilateral triangle's angles 

	}
	else if (side1 == side2 && side1 == side3) 
	{
		result = "Equilateral triangle\n";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2) || 
		(side2 == side3 && side3 != side1))  //fixed the missing scenario where side 2 and 3 were the same size.
	{
		result = "Isosceles triangle\n";

		// added calculation to the angles 
		float temp1 = (float)(side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
		float temp2 = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
		float angle1 = acos(temp1) * (180 / 3.14159265358979323846); // converting radians to angles 
		float angle2 = acos(temp2) * (180 / 3.14159265358979323846); // converting radians to angles 
		float angle3 = 180 - angle1 - angle2;

		printf("first angle is %.1f \n second angle is %.1f \n third angle is %.1f \n", angle1, angle2, angle3); //added output of the angles
	}
	else 
	{
		result = "Scalene triangle\n";

		float temp1 = (float)(side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
		float temp2 = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
		float angle1 = acos(temp1) * (180 / 3.14159265358979323846); // converting radians to angles 
		float angle2 = acos(temp2) * (180 / 3.14159265358979323846); // converting radians to angles 
		float angle3 = 180 - angle1 - angle2; 

		printf("first angle is %.1f \n second angle is %.1f \n third angle is %.1f \n", angle1, angle2, angle3); //added output of the angles
	}


	return result;
}