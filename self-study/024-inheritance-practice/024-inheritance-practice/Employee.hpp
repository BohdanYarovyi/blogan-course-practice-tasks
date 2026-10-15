#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

#include "Person.hpp"
#include "StringUtility.hpp"

class Employee : public Person
{
protected:
	double salary;
	char* position;

public:
	Employee(const char* name, int age, double salary, const char* position)
		: Person(name, age), salary(salary)
	{
		this->position = StringUtility::copyString(position);
	}

	~Employee()
	{
		delete[] position;
	}

	double getSalary() const
	{
		return salary;
	}

	const char* getPosition() const
	{
		return position;
	}

	void printEmployee(bool terminated = true) const
	{
		print(false);
		std::cout << "Employee(salary=" << salary << ", position=" << position << ")";

		if (terminated) 
		{
			std::cout << std::endl;
		}
	}
};

#endif // !EMPLOYEE_H
