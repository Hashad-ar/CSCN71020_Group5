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
		TEST_METHOD(AnglesInsideTriangle_NotATriangleNegativeNum)
			//Testing if the function will output the correct result for the angles of a non triangle input, which would return -1 on all cases.
		{
			int side1 = -3;
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
		TEST_METHOD(ItIsRectangle_FirstPossibility)
		{
			COORDINATES Rectangle_Points[4];

			Rectangle_Points[0].x_axis = 0;
			Rectangle_Points[0].y_axis = 0;
			Rectangle_Points[1].x_axis = 3;
			Rectangle_Points[1].y_axis = 0;
			Rectangle_Points[2].x_axis = 3;
			Rectangle_Points[2].y_axis = 6;
			Rectangle_Points[3].x_axis = 0;
			Rectangle_Points[3].y_axis = 6;

			char* result = "It's a Rectangle\n";
			Assert::AreEqual(result, analyzeRectangle(Rectangle_Points));
		}
		//Testing if the function will output the correct result for an Invalid rectangle case using point values for the 4 x,y coordinates at 1. 5,0 | 2. 3,0 | 3. 0,6| 4. 3,6|.
		TEST_METHOD(ItIsRectangle_SecondPossibility)
		{
			COORDINATES Rectangle_Points[4];

			Rectangle_Points[0].x_axis = 0;
			Rectangle_Points[0].y_axis = 0;
			Rectangle_Points[1].x_axis = 3;
			Rectangle_Points[1].y_axis = 0;
			Rectangle_Points[2].x_axis = 0;
			Rectangle_Points[2].y_axis = 6;
			Rectangle_Points[3].x_axis = 3;
			Rectangle_Points[3].y_axis = 6;

			char* result = "It's a Rectangle\n";
			Assert::AreEqual(result, analyzeRectangle(Rectangle_Points));
		}
		TEST_METHOD(ItIsRectangle_ThirdPossibility)
		{
			COORDINATES Rectangle_Points[4];

			Rectangle_Points[0].x_axis = 0;
			Rectangle_Points[0].y_axis = 0;
			Rectangle_Points[1].x_axis = 3;
			Rectangle_Points[1].y_axis = 6;
			Rectangle_Points[2].x_axis = 0;
			Rectangle_Points[2].y_axis = 6;
			Rectangle_Points[3].x_axis = 3;
			Rectangle_Points[3].y_axis = 0;

			char* result = "It's a Rectangle\n";
			Assert::AreEqual(result, analyzeRectangle(Rectangle_Points));
		}
		TEST_METHOD(ItIsNotRectangle)
		{
			COORDINATES Rectangle_Points[4];

			Rectangle_Points[0].x_axis = 5;
			Rectangle_Points[0].y_axis = 0;
			Rectangle_Points[1].x_axis = 3;
			Rectangle_Points[1].y_axis = 0;
			Rectangle_Points[2].x_axis = 0;
			Rectangle_Points[2].y_axis = 6;
			Rectangle_Points[3].x_axis = 3;
			Rectangle_Points[3].y_axis = 6;

			char* result = "Not a Rectangle\n";
			Assert::AreEqual(result, analyzeRectangle(Rectangle_Points));
		}
		TEST_METHOD(RectangleInvalidEqualPoints)
		{
			COORDINATES Rectangle_Points[4];

			Rectangle_Points[0].x_axis = 0;
			Rectangle_Points[0].y_axis = 0;
			Rectangle_Points[1].x_axis = 0;
			Rectangle_Points[1].y_axis = 0;
			Rectangle_Points[2].x_axis = 0;
			Rectangle_Points[2].y_axis = 6;
			Rectangle_Points[3].x_axis = 3;
			Rectangle_Points[3].y_axis = 6;

			char* result = "Error, two or more coordinates are equal\n";
			Assert::AreEqual(result, analyzeRectangle(Rectangle_Points));
		}
	};
}
