#pragma once

#include <iostream>

#include "Person.hpp"

class StudentOfCambridge : public Person
{
protected:
	int iq;

public:
	StudentOfCambridge(const char* name, int age, int iq)
		: Person(name, age), iq(iq)
	{
	}

	virtual ~StudentOfCambridge() override = default;

	virtual std::ostream& printDelegator(std::ostream& out) const
	{
		out << name << " is a student of Cambridge University. He has " << iq << " IQ in only " << age << " years old.";
		return out;
	}

	friend std::ostream& operator<<(std::ostream& out, const StudentOfCambridge& student)
	{
		return student.printDelegator(out);
	}
};