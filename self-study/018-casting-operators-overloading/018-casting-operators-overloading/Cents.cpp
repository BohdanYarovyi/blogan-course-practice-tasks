#include "Cents.hpp"
#include "Dollars.hpp"

Cents::Cents(int value)
	: value(value)
{
}

Cents::operator int()
{
	return value;
}

Cents::operator Dollars()
{
	return Dollars(value / 100);
}