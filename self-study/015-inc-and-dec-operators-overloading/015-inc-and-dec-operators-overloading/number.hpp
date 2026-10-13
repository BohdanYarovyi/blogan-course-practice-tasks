#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>

class Number
{
private:
	int value;

public:
	Number(int value = 0);

	Number& operator++();

	Number operator++(int);

	Number& operator--();

	Number operator--(int);

	friend std::ostream& operator<<(std::ostream& out, const Number& number);
};

#endif // NUMBER_H
