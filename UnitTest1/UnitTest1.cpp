#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Triangle)
	{
	public:
		//Testing if the function will output the correct result for an Equilateral triangle using 3, 3, 3 for side lengths. 
		TEST_METHOD(TypeOfTriangle_Equilateral)
		{
			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			char* result = "Equilateral triangle\n";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
		//Testing if the function will output the correct result for an Isosceles triangle using 2, 3, 3 for side lengths.
		TEST_METHOD(TypeOfTriangle_Isosceles)
		{
			int side1 = 2;
			int side2 = 3;
			int side3 = 3;
			char* result = "Isosceles triangle\n";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
		//Testing if the function will output the correct result for a Scalene triangle using 3, 4, 5.
		TEST_METHOD(TypeOfTriangle_Scalene)
		{
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			char* result = "Scalene triangle\n";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
		//Testing if the function will output the correct result for invalid input that's not a triangle using -3, 0, 3 for side lengths.
		TEST_METHOD(TypeOfTriangle_NotATriangle)
		{
			int side1 = -3;
			int side2 = 0;
			int side3 = 3;
			char* result = "Not a triangle\n";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
		//Testing if the function will output the correct result for invalid input that's not a triangle using -3, 0, 3 for side lengths.
		TEST_METHOD(TypeOfTriangle_NotATriangleLetterInput)
		{
			int side1 = 'a';
			int side2 = 0;
			int side3 = 3;
			char* result = "Not a triangle\n";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
	};

	TEST_CLASS(AnglesInsideTriangle)
	{
	public:
		//Testing if the function will output the correct result for the angles inside an Equilateral triangle with expected result as 60 for all side lengths.
		TEST_METHOD(AnglesInsideTriangle_Equilateral)
		{
			/*
			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			float result = 60;

			The angle calculator function copied and pasted
			float temp1 = (float)(side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
			float temp2 = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
			float angle1 = acos(temp1) * (180 / 3.14159265358979323846); // converting radians to angles
			float angle2 = acos(temp2) * (180 / 3.14159265358979323846); // converting radians to angles
			float angle3 = 180 - angle1 - angle2;

			Assert::AreEqual(result, angle1);
			Assert::AreEqual(result, angle2);
			Assert::AreEqual(result, angle3);
			*/

			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			float result = 60; // the desired result 

			float * FuncResult = analyzeAngle(side1, side2, side3);

			Assert::AreEqual(result, FuncResult[0]);
			Assert::AreEqual(result, FuncResult[1]);
			Assert::AreEqual(result, FuncResult[2]);
		}
		//Testing if the function will output the correct result for the angles of an Isoceles triangle with expected result of approximately  39, 70.5, 70.5. 
		TEST_METHOD(AnglesInsideTriangle_Isosceles)
		{
			/*
			int side1 = 2;
			int side2 = 3;
			int side3 = 3;
			float result1 = 70.528779365509;
			float result2 = 38.942441268981;
			float result3 = 70.528779365509;

			float temp1 = (float)(side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
			float temp2 = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
			float angle1 = acos(temp1) * (180 / 3.14159265358979323846); // converting radians to angles
			float angle2 = acos(temp2) * (180 / 3.14159265358979323846); // converting radians to angles
			float angle3 = 180 - angle1 - angle2;

			Assert::AreEqual(result1, angle1);
			Assert::AreEqual(result2, angle2);
			Assert::AreEqual(result3, angle3);
			*/

			int side1 = 2;
			int side2 = 3;
			int side3 = 3;
			float result1 = 70.528779365509; //desired results 
			float result2 = 38.942441268981;
			float result3 = 70.528779365509;
			float* FuncResult = analyzeAngle(side1, side2, side3);

			Assert::AreEqual(result1, FuncResult[0]);
			Assert::AreEqual(result2, FuncResult[1]);
			Assert::AreEqual(result3, FuncResult[2]);

		}
		//Testing if the function will output the correct result for the angles of an Scalene triangle with expected result of approximately  90, 36.9, 53.1.
		TEST_METHOD(AnglesInsideTriangle_Scalene)
		{
			/*int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			float result1 = 90;
			float result2 = 36.86989764584;
			float result3 = 53.130102354156;

			float* arrr[3] = analyzeAngle(side1, side2, side3);


			Assert::AreEqual(result1, angle1);
			Assert::AreEqual(result2, angle2);
			Assert::AreEqual(result3, angle3);
			*/
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			float result1 = 90; // desired results 
			float result2 = 36.86989764584;
			float result3 = 53.130102354156;
			float* FuncResult = analyzeAngle(side1, side2, side3);

			Assert::AreEqual(result1, FuncResult[0]);
			Assert::AreEqual(result2, FuncResult[1]);
			Assert::AreEqual(result3, FuncResult[2]);
		}

		TEST_METHOD(AnglesInsideTriangle_NotATriangle)
			//Testing if the function will output the correct result for the angles of a non triangle input, which would return -1 on all cases.
		{
			int side1 = 3;
			int side2 = 10;
			int side3 = 5;
			float result = -1; // desired results 

			float* FuncResult = analyzeAngle(side1, side2, side3);

			Assert::AreEqual(result, FuncResult[0]);// supposed to return all angles as being -1, since this combination of sides does not return proper angles and does not create a triangle
			Assert::AreEqual(result, FuncResult[1]);
			Assert::AreEqual(result, FuncResult[2]);
		}
	};

	TEST_CLASS(Rectangle)
	{
	public:
		//Testing if the function will output the correct result for a valid rectangle case using point values for the 4 x,y coordinates at 1. 0,0| 2. 3,0| 3. 0,6| 4. 3,6|.
		TEST_METHOD(ItIsRectangle)
		{
			double xaxis[] = { 0, 3, 0, 3 };
			double yaxis[] = { 0, 0, 6, 6 };

			char* result = "It's a Rectangle";
			Assert::AreEqual(result, analyzeRectangle(xaxis, yaxis));
		}
		//Testing if the function will output the correct result for an Invalid rectangle case using point values for the 4 x,y coordinates at 1. 5,0 | 2. 3,0 | 3. 0,6| 4. 3,6|.
		TEST_METHOD(ItIsNotRectangle)
		{
			double xaxis[] = { 5, 3, 0, 3 };
			double yaxis[] = { 0, 0, 6, 6 };

			char* result = "Not a Rectangle";
			Assert::AreEqual(result, analyzeRectangle(xaxis, yaxis));
		}
	};
}
