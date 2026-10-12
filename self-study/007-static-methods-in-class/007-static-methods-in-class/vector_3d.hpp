#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include "point_3d.hpp"

class Vector_3D
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Vector_3D(double x = 0.0, double y = 0.0, double z = 0.0);

	void print();

	friend void Point_3D::move_by_vector(Vector_3D& vector);
};

#endif // VECTOR_3D_H
