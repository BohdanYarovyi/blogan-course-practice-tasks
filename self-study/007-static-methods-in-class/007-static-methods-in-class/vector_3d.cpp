#include <iostream>

#include "vector_3d.hpp"

Vector_3D::Vector_3D(double x, double y, double z) 
: m_x(x), m_y(y), m_z(z)
{
}

void Vector_3D::print()
{
	std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
}