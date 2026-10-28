#include "Circle.hpp"

Circle::Circle(double radius)
	: Shape("Circle"), radius(radius)
{
}

Circle::Circle(const Circle& other)
	: Shape(other), radius(other.radius)
{
}

double Circle::getArea() const
{
	return std::numbers::pi * radius * radius;
}

double Circle::getPerimeter() const
{
	return std::numbers::pi * radius * 2;
}