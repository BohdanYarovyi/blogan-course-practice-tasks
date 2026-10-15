#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "StringUtility.hpp"

class Person
{
protected:
	char* name;
	int age;

public:
	Person(const char* name, int age)
		: age(age)
	{
		this->name = StringUtility::copyString(name);
	}

	~Person()
	{
		delete[] name;
	}

	const char* getName() const
	{
		return name;
	}

	int getAge() const
	{
		return age;
	}

	void print(bool terminated = true) const
	{
		std::cout << "Person(name=" << name << ", age=" << age << ")";
		if (terminated)
		{
			std::cout << std::endl;
		}
	}
};

#endif // PERSON_H