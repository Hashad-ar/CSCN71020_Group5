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
		
		TEST_METHOD(TypeOfTriangle_Equilateral)
		{
			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			char* result = "Equilateral triangle";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
		TEST_METHOD(TypeOfTriangle_Isosceles)
		{
			int side1 = 2;
			int side2 = 3;
			int side3 = 3;
			char* result = "Isosceles triangle";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
		TEST_METHOD(TypeOfTriangle_Scalene)
		{
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			char* result = "Scalene triangle";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
		TEST_METHOD(TypeOfTriangle_NotATriangle)
		{
			int side1 = -3;
			int side2 = 0;
			int side3 = 3;
			char* result = "Not a triangle";
			Assert::AreEqual(result, analyzeTriangle(side1, side2, side3));
		}
	};

	TEST_CLASS(AnglesInsideTriangle)
	{
	public:
		TEST_METHOD(AnglesInsideTriangle_Equilateral)
		{
			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			float result = 60;

			/*The angle calculator function copied and pasted*/
			float temp1 = (float)(side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
			float temp2 = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
			float angle1 = acos(temp1) * (180 / 3.14159265358979323846); // converting radians to angles 
			float angle2 = acos(temp2) * (180 / 3.14159265358979323846); // converting radians to angles 
			float angle3 = 180 - angle1 - angle2;

			Assert::AreEqual(result, angle1);
			Assert::AreEqual(result, angle2);
			Assert::AreEqual(result, angle3);
		}
		TEST_METHOD(AnglesInsideTriangle_Isosceles)
		{
			int side1 = 2;
			int side2 = 3;
			int side3 = 3;
			float result1 = 70.528779365509;
			float result2 = 38.942441268981;
			float result3 = 70.528779365509;

			/*The angle calculator function copied and pasted*/
			float temp1 = (float)(side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
			float temp2 = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
			float angle1 = acos(temp1) * (180 / 3.14159265358979323846); // converting radians to angles 
			float angle2 = acos(temp2) * (180 / 3.14159265358979323846); // converting radians to angles 
			float angle3 = 180 - angle1 - angle2;

			Assert::AreEqual(result1, angle1);
			Assert::AreEqual(result2, angle2);
			Assert::AreEqual(result3, angle3);
		}
		TEST_METHOD(AnglesInsideTriangle_Scalene)
		{
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			float result1 = 90;
			float result2 = 36.86989764584;
			float result3 = 53.130102354156;

			/*The angle calculator function copied and pasted*/
			float temp1 = (float)(side1 * side1 + side2 * side2 - (side3 * side3)) / (2 * side1 * side2);
			float temp2 = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
			float angle1 = acos(temp1) * (180 / 3.14159265358979323846); // converting radians to angles 
			float angle2 = acos(temp2) * (180 / 3.14159265358979323846); // converting radians to angles 
			float angle3 = 180 - angle1 - angle2;

			Assert::AreEqual(result1, angle1);
			Assert::AreEqual(result2, angle2);
			Assert::AreEqual(result3, angle3);
		}
	};

	TEST_CLASS(Rectangle)
	{
	public:
		TEST_METHOD(ItIsRectangle)
		{
			double xaxis[] = { 0, 3, 0, 3 };
			double yaxis[] = { 0, 0, 6, 6 };

			char* result = "It's a Rectangle";
			Assert::AreEqual(result, analyzeRectangle(xaxis, yaxis));
		}
		TEST_METHOD(ItIsNotRectangle)
		{
			double xaxis[] = { 5, 3, 0, 3 };
			double yaxis[] = { 0, 0, 6, 6 };

			char* result = "Not a Rectangle";
			Assert::AreEqual(result, analyzeRectangle(xaxis, yaxis));
		}
	};
}
