#include "Drob.hpp"

std::ostream& operator<<(std::ostream& out, const Drob &d1)
{
	out << d1.numerator << "/" << d1.denominator;
	return out;
}