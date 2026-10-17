#ifndef CHILD_H
#define CHILD_H

#include "Parent.hpp"

class Child : public Parent
{
  public:
	Child(int value)
		: Parent(value)
	{
	}

	using Parent::printValue;
};

#endif // CHILD_H
