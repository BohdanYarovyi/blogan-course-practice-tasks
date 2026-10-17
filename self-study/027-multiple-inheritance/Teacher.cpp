#include "Teacher.hpp"

std::ostream& operator<<(std::ostream& out, const Teacher teacher)
{
	out << "Teacher:\n";
	out << "Name: " << teacher.name << '\n';
	out << "Age: " << teacher.age << '\n';
	out << "Employer: " << teacher.employer << '\n';
	out << "Wage: " << teacher.wage << '\n';
	out << "Teaches grade: " << teacher.teachesGrade << '\n';

	return out;
}
