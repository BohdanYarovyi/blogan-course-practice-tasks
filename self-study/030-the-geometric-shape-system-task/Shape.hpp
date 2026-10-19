#pragma once

#include <iostream>

#include "./../mylib/StringUtility.hpp"

class Shape
{
  protected:
	char* name;

  protected:
	Shape(const char* name)
	{
		this-> name = StringUtility::copy(name);
	}

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
