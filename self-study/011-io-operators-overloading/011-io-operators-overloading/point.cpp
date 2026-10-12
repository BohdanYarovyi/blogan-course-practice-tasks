#include "point.hpp"

Point::Point(int x, int y, int z)
	: x(x), y(y), z(z)
{
}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	return out << "Point(" << point.x << ", " << point.y << ", " << point.z << ")";
}

std::istream& operator>>(std::istream& in, Point& point)
{
	std::cout << "Intput x: ";
	in >> point.x;
	std::cout << "Intput y: ";
	in >> point.y;
	std::cout << "Intput z: ";
	in >> point.z;

	return in;
}