#include "Dollars.hpp"
#include "Cents.hpp"

Dollars::Dollars(int value)
	: value(value)
{
}

Dollars::operator int()
{
	return value;
}

Dollars::operator Cents()
{
	return Cents(value * 100);
}