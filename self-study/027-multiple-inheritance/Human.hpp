#ifndef HUMAN_H
#define HUMAN_H

#include "StringUtility.hpp"

class Human
{
  protected:
	char* name;
	int age;

  public:
	Human(const char* name, int age)
		: age(age)
	{
		this->name = StringUtility::copy(name);
	}

	const char* getName() const
	{
		return name;
	}

	const int getAge() const
	{
		return age;
	}
};

#endif // HUMAN_H
