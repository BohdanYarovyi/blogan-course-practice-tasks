#pragma once

#include <cmath>

#include "Shape.hpp"

class Triangle : public Shape
{
private:
	double sideA;
	double sideB;
	double sideC;

public:
	Triangle(double sideA, double sideB, double sideC);

	Triangle(const Triangle& other);

	virtual ~Triangle() = default;

	virtual double getArea() const override;

	virtual double getPerimeter() const override;
};