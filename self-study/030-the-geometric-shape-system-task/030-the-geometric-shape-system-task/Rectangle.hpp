#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
protected:
	double width;
	double height;

	Rectangle(const char* name, double width, double height)
		: Shape(name), width(width), height(height)
	{
	}

public:
	Rectangle(double width, double height)
		: Shape("Rectangle"), width(width), height(height)
	{
	}

	double getWidth() const
	{
		return width;
	}

	double getHeight() const
	{
		return height;
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
		std::cout << name << "(width=" << width << ", height=" << height << ", area = " << area() << ", perimeter = " << perimeter() << ")\n";
	}
};
