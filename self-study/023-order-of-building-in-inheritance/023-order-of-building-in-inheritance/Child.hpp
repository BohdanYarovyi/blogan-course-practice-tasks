#ifndef CHILD_H
#define CHILD_H

#include "Parent.hpp"

#include <iostream>

class Child : public Parent
{
private:
	double value;

public:
	Child(double value, int id)
		: Parent(id), value(value)
	{
	}

	double getValue() const
	{
		return value;
	}

	void show()
	{
		std::cout << "Child(id=" << getId() << ", value=" << value << ")" << std::endl;
	}
};

#endif // !CHILD_H
