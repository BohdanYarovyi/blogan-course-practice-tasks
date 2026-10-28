#include "Rectangle.hpp"

Rectangle::Rectangle(double width, double height)
	: Shape("Rectangle"), width(width), height(height)
{
}

Rectangle::Rectangle(const Rectangle& other)
	: Shape(other), width(other.width), height(other.height)
{
}

double Rectangle::getArea() const
{
	return width * height;
}

double Rectangle::getPerimeter() const
{
	return (width + height) * 2;		
}