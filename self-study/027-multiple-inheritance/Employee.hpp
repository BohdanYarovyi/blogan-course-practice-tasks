#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "StringUtility.hpp"

class Employee
{
  protected:
	char* employer;
	double wage;

  public:
	Employee(const char* employer, double wage)
		: wage(wage)
	{
		this->employer = StringUtility::copy(employer);
	}

	const char* getEmployer() const
	{
		return employer;
	}

	double getWage() const
	{
		return wage;
	}
};

#endif // EMPLOYEE_H
