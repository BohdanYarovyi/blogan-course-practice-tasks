#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Square
{
private:
	int side;

public:
	Square(int side)
		: side(side)
	{
	}

	Square operator-()
	{
		return Square(-side);
	}

	Square operator=(int value)
	{
		return Square(value);
	}

	friend Square operator+(const Square& s1, const Square& s2);

	friend std::ostream& operator<<(std::ostream& out, const Square& square);
};

#endif // !SQUARE_H
