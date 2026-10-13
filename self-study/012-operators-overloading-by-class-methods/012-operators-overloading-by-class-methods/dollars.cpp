#include "dollars.hpp"

Dollars::Dollars(int value)
	: value(value)
{
}

Dollars Dollars::operator+(int value)
{
	return Dollars(this->value + value);
}

std::ostream& operator<<(std::ostream& out, const Dollars& dollars)
{
	return out << "Dollars: " << dollars.get_value(); 
}

int Dollars::get_value() const
{
	return value;
}