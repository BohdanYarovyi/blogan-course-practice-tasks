#include "Square.hpp"

std::ostream& operator<<(std::ostream& out, const Square& square)
{
	out << "Square(side=" << square.side << ")";
	return out;
}

Square operator+(const Square& s1, const Square& s2)
{
	return Square(s1.side + s2.side);
}