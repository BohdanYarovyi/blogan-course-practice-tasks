#ifndef DOLLARS_H
#define DOLLARS_H

#include <iostream>

class Dollars
{
private:
	int value;

public:
	Dollars(int value);

	Dollars operator+(int value);

	int get_value() const;
};

std::ostream& operator<<(std::ostream& out, const Dollars& dollars);

#endif // DOLLARS_H
