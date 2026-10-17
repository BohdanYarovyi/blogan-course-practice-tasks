#ifndef PARENT_H
#define PARENT_H

#include <iostream>

class Parent
{
  protected:
	int value;

  public:
	Parent(int value)
		: value(value)
	{
	}

  protected:
	void printValue() const
	{
		std::cout << "My value is " << value << std::endl;
	}
};

#endif // PARENT_H
