#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
  private:
	int m_rows;
	int m_columns;
	double* m_data;

  public:
	Matrix(int rows, int columns);

	~Matrix();

	double& at(int row, int column);

	const double& at(int row, int column) const;

	int rows() const;

	int columns() const;

	Matrix transposed() const;

	Matrix multiply(const Matrix& other) const;

	void fill(double value);

	void print() const;
};

#endif
