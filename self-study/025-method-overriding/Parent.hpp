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

	void identify() const
	{
		std::cout << "I am a parent!" << std::endl;
	}
};

#endif // PARENT_H
