#pragma once

#include <iostream>

#include "./../../mylib/StringUtility.hpp"

class Shape
{
protected:
	char* name;

	Shape(const char* name)
	{
		this-> name = StringUtility::copy(name);
	}

public:
	virtual ~Shape()
	{
		delete[] name;
	}

	virtual double area() const
	{
		return 0;
	}

	virtual double perimeter() const
	{
		return 0;
	}

	virtual void print() const
	{
		std::cout << name << "(area=" << area() << ", perimeter=" << perimeter() << ")\n";
	}
};
