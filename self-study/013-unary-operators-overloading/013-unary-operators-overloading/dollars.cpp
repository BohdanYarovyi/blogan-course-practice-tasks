#include "dollars.hpp"

Dollars::Dollars(int value)
	: value(value)
{
}

Dollars Dollars::operator-() const
{
	return Dollars(-value);
}

int Dollars::get_value() const
{
	return value;
}