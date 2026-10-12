#include <iostream>

#include "vector_3d.hpp"
#include "point_3d.hpp"

Point_3D::Point_3D(double x, double y, double z)
: m_x(x), m_y(y), m_z(z)
{
}

void Point_3D::print()
{
	std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

void Point_3D::move_by_vector(Vector_3D& vector)
{
	this->m_x += vector.m_x;
	this->m_y += vector.m_y;
	this->m_z += vector.m_z;
}