#include "dollars.hpp"

Dollars::Dollars(int value)
	: value(value)
{
}

bool operator>(const Dollars& d1, const Dollars& d2)
{
	return d1.value > d2.value;
}

bool operator<(const Dollars& d1, const Dollars& d2)
{
	return d1.value < d2.value;
}

bool operator>=(const Dollars& d1, const Dollars& d2)
{
	return d1.value >= d2.value;
}

bool operator<=(const Dollars& d1, const Dollars& d2)
{
	return d1.value <= d2.value;
}
