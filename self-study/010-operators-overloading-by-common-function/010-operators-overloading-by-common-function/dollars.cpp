#include "dollars.hpp"

Dollars::Dollars(int value)
	: m_dollars(value)
{
}

int Dollars::get_value() const {
	return m_dollars;
}

Dollars operator+(const Dollars& object_1, const Dollars& object_2)
{
	return Dollars(object_1.get_value() + object_2.get_value());
}