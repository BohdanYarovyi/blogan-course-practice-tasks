#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Employee.hpp"

class Supervisor : public Employee
{
private:
	long overseesIds[5];

public:
	Supervisor()
	{
	}
};

#endif // !SUPERVISOR_H
