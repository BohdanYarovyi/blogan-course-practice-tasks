#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
private:
	double data[5][5];

public:
	Matrix();

	double& operator()(int row, int col);

	const double& operator()(int row, int col) const;

	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};

#endif // MATRIX_H