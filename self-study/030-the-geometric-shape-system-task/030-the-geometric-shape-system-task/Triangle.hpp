#pragma once

#include <cmath>

#include "Shape.hpp"

class Triangle : public Shape
{
protected:
	double side1;
	double side2;
	double side3;

public:
	Triangle(double side1, double side2, double side3)
		: Shape("Triangle"), side1(side1), side2(side2), side3(side3)
	{
	}

	double getSide1() const
	{
		return side1;
	}

	double getSide2() const
	{
		return side2;
	}

	double getSide3() const
	{
		return side3;
	}

	virtual double area() const override
	{	
		double p = (side1 + side2 + side3) / 2;
		double p1 = p - side1;
		double p2 = p - side2;
		double p3 = p - side3;

		return std::sqrt(p * p1 * p2 * p3);
	}

	virtual double perimeter() const override
	{
		return side1 + side2 + side3;
	}

	virtual void print() const override
	{
		std::cout << name << "(sides=(" << side1 << ", " << side2 << ", " << side3 << "), area=" << area() << ", perimeter=" << perimeter() << ")\n";
	}
};