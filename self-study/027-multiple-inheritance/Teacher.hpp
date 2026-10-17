#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <ostream>

#include "Human.hpp"
#include "Employee.hpp"

class Teacher : public Human, public Employee
{
  private:
	int teachesGrade;

  public:
	Teacher(const char* name, int age, const char* employer, double wage, int teachesGrade)
		: Human(name, age), Employee(employer, wage), teachesGrade(teachesGrade)
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Teacher teacher);
};

#endif // TEACHER_H
