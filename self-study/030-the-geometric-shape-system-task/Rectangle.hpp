#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
  protected:
	int width;
	int height;

  public:
	Rectangle(int width, int height)
		: Shape("Rectangle"), width(width), height(height)
	{
	}

	virtual double area() const override
	{
		return width * height;
	}

	virtual double perimeter() const override
	{
		return (width + height) * 2;
	}

	virtual void print() const override
	{
		// todo:
	}
};
