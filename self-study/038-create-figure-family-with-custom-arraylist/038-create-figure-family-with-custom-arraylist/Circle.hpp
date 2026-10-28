#pragma once

#include <numbers>

#include "Shape.hpp"

class Circle : public Shape
{
protected:
	double radius;

public:
	Circle(double radius);

	Circle(const Circle& other);

	virtual ~Circle() = default;

	virtual double getArea() const override;

	virtual double getPerimeter() const override;
};