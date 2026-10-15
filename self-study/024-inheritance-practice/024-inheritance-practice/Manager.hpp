#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>

#include "Employee.hpp"

class Manager : public Employee
{
protected:
	int teamSize;

public:
	Manager(const char* name, int age, double salary, const char* position, int teamSize)
		: Employee(name, age, salary, position), teamSize(teamSize)
	{
	}

	int getTeamSize() const
	{
		return teamSize;
	}

	void printManager() const
	{
		printEmployee(false);
		std::cout << "Manager(teamSize=" << teamSize << ")" << std::endl;
	}
};

#endif // !MANAGER_H
