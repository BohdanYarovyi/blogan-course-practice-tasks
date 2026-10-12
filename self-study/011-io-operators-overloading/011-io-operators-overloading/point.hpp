#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private:
	double x;
	double y;
	double z;

public:
	Point(int x = 0, int y = 0, int z = 0);

	friend std::ostream& operator<<(std::ostream& out, const Point& point);

	friend std::istream& operator>>(std::istream& in, Point& point);
};

#endif // !POINT_H
