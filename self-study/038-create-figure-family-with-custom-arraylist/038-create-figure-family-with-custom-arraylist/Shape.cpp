#include "Shape.hpp"

Shape::Shape(const char* name)
{
	this->name = StringUtility::copy(name);
}

Shape::Shape(const Shape& other) 
{
	this->name = StringUtility::copy(other.name);
}

Shape::~Shape()
{
	delete[] name;
}

const char* Shape::getName() const
{
	return name;
}

void Shape::print() const
{
	std::cout << "Shape(name='" << getName() << "',area=" << getArea() << ",perimeter=" << getPerimeter() << ")\n";
}