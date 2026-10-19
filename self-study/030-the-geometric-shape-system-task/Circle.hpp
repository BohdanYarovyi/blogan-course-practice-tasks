#pragma once

#include <cmath>
#include <numbers>

#include "Shape.hpp"

class Circle : public Shape
{
  protected:
	double radius;

  public:
	Circle(double radius)
	    : Shape("Circle"), radius(radius)
	{
	}

	double diameter() const
	{
		return radius * 2;
	}

	virtual double area() const override
	{
		return std::numbers::pi * radius * radius;
	}

	virtual double perimeter() const override
	{
		return 2 * std::numbers::pi * radius;
	}

	virtual void print() const override
	{
		// todo:
	}
};
