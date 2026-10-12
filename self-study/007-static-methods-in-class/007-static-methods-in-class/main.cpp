#include <iostream>

#include "point_3d.hpp"
#include "vector_3d.hpp"

int main()
{
	Point_3D p(3.0, 4.0, 5.0);
	Vector_3D v(3.0, 3.0, -2.0);

	p.print();
	p.move_by_vector(v);
	p.print();
	return 0;
}