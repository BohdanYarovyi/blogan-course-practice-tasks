#pragma once

#include <iostream>

#include "./../../mylib/StringUtility.hpp"

class Shape
{
protected:
	char* name;

public:
	Shape(const char* name);

	Shape(const Shape& other);

	virtual ~Shape();

	virtual double getArea() const = 0;

	virtual double getPerimeter() const = 0;

	virtual const char* getName() const;

	virtual void print() const;
};