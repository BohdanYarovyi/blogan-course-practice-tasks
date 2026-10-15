#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

#include "Human.hpp"

class Employee : public Human
{
private:
	int wage;
	long employeeId;

public:
	Employee(int wage = 0, long employeeId = 0)
		: wage(wage), employeeId(employeeId)
	{
	}

	void printNameAndWage()
	{
		std::cout << getName() << ": " << wage << '\n';
	}
};

#endif // !EMPLOYEE_H
