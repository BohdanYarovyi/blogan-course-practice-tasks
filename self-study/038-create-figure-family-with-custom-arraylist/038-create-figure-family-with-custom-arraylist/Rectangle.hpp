#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
private:
	double width;
	double height;

public:
	Rectangle(double width, double height);

	Rectangle(const Rectangle& other);

	virtual ~Rectangle() = default;

	virtual double getArea() const override;

	virtual double getPerimeter() const override;
};