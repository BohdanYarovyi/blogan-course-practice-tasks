#include "Drob.hpp"

Drob::Drob(int numerator, int denominator)
	: numerator(numerator)
{
	this->denominator = denominator != 0 ? denominator : 1;
}

Drob::Drob(const Drob& other)
	: numerator(other.numerator)
{
	this->denominator = other.denominator != 0 ? other.denominator : 1;
}

std::ostream& operator<<(std::ostream& out, const Drob& drob)
{
	out << drob.numerator << "/" << drob.denominator;

	return out;
}