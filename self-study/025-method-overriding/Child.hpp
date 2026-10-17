#ifndef CHILD_H
#define CHILD_H

#include <iostream>

#include "Parent.hpp"

class Child : public Parent
{
  public:
	Child(int value)
		: Parent(value)
	{
	}

	void identify() const
	{
		Parent::identify();
		std::cout << "I am a child!" << std::endl;
	}
};

#endif // CHILD_H
