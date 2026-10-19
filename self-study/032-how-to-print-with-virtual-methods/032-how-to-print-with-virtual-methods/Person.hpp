#pragma once

#include <iostream>

#include "./../../mylib/StringUtility.hpp"

class Person
{
protected:
	char* name;
	int age;
	
public:
	Person(const char* name, int age)
		: age(age)
	{
		this->name = StringUtility::copy(name);
	}

	virtual ~Person()
	{
		delete[] name;
	}

	virtual std::ostream& printDelegator(std::ostream& out) const
	{
		out << "Stranger with name " << name << " already " << age << " years old.";
		return out;
	}

	friend std::ostream& operator<<(std::ostream& out, const Person& person)
	{
		return person.printDelegator(out);
	}
};