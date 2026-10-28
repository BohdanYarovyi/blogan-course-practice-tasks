#include "Triangle.hpp"

Triangle::Triangle(double sideA, double sideB, double sideC)
	: Shape("Triangle"), sideA(sideA), sideB(sideB), sideC(sideC)
{
}

Triangle::Triangle(const Triangle& other)
	: Shape(other), sideA(other.sideA), sideB(other.sideB), sideC(other.sideC)
{
}

double Triangle::getArea() const
{
	// Heron's Formula
	double s = (sideA + sideB + sideC) / 2;

	return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangle::getPerimeter() const
{
	return sideA + sideB + sideC;
}