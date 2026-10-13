#include "number.hpp"

Number::Number(int value)
	: value(value)
{
}

Number& Number::operator++()
{
	value++;
	return *this;
}

Number Number::operator++(int)
{
	Number temp = {value};
	value++;
	return temp;
}

Number& Number::operator--()
{
	value--;
	return *this;
}

Number Number::operator--(int)
{
	Number temp = {value};
	value--;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Number& number)
{
	return out << "Value: " << number.value;
}