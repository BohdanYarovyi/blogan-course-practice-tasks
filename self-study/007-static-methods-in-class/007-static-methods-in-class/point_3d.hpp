#ifndef POINNT_3D_H
#define POINNT_3D_H

class Vector_3D;

class Point_3D
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Point_3D(double x = 0.0, double y = 0.0, double z = 0.0);

	void print();

	void move_by_vector(Vector_3D& vector);
};

#endif // POINNT_3D_H