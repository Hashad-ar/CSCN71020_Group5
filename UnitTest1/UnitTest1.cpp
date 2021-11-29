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
			float result = 60;

			float angle1 = analyzeAngle(side1, side2, side3)[0];
			float angle2 = analyzeAngle(side1, side2, side3)[1];
			float angle3 = analyzeAngle(side1, side2, side3)[2];

			Assert::AreEqual(result, angle1);
			Assert::AreEqual(result, angle2);
			Assert::AreEqual(result, angle3);
		}
		//Testing if the function will output the correct result for the angles of an Isoceles triangle with expected result of approximately  39, 70.5, 70.5. 
		TEST_METHOD(AnglesInsideTriangle_Isosceles)
		{
			int side1 = 2;
			int side2 = 3;
			int side3 = 3;
			float result1 = 70.528779365509;
			float result2 = 38.942441268981;
			float result3 = 70.528779365509;

			float angle1 = analyzeAngle(side1, side2, side3)[0];
			float angle2 = analyzeAngle(side1, side2, side3)[1];
			float angle3 = analyzeAngle(side1, side2, side3)[2];

			Assert::AreEqual(result1, angle1);
			Assert::AreEqual(result2, angle2);
			Assert::AreEqual(result3, angle3);
		}
		//Testing if the function will output the correct result for the angles of an Scalene triangle with expected result of approximately  90, 36.9, 53.1.
		TEST_METHOD(AnglesInsideTriangle_Scalene)
		{
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			float result1 = 90;
			float result2 = 36.86989764584;
			float result3 = 53.130102354156;

			float angle1 = analyzeAngle(side1, side2, side3)[0];
			float angle2 = analyzeAngle(side1, side2, side3)[1];
			float angle3 = analyzeAngle(side1, side2, side3)[2];

			Assert::AreEqual(result1, angle1);
			Assert::AreEqual(result2, angle2);
			Assert::AreEqual(result3, angle3);
		}
	};

	TEST_CLASS(Rectangle)
	{
	public:
	/*	//Testing if the function will output the correct result for a valid rectangle case using point values for the 4 x,y coordinates at 1. 0,0| 2. 3,0| 3. 0,6| 4. 3,6|.
		TEST_METHOD(ItIsRectangle)
		{
			double xaxis[] = { 0, 3, 0, 3 };
			double yaxis[] = { 0, 0, 6, 6 };

			char* result = "It's a Rectangle";
			Assert::AreEqual(result, analyzeRectangle(xaxis[], yaxis[]));
		}
		//Testing if the function will output the correct result for an Invalid rectangle case using point values for the 4 x,y coordinates at 1. 5,0 | 2. 3,0 | 3. 0,6| 4. 3,6|.
		TEST_METHOD(ItIsNotRectangle)
		{
			double xaxis[] = { 5, 3, 0, 3 };
			double yaxis[] = { 0, 0, 6, 6 };

			char* result = "Not a Rectangle";
			Assert::AreEqual(result, analyzeRectangle(xaxis, yaxis));
		}*/
	}; 
}
