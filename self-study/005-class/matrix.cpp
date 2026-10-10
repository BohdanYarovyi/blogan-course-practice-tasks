#include "matrix.hpp"

Matrix::Matrix(int rows, int columns) : m_rows {rows}, m_columns {columns}
{
	if (rows < 1 || columns < 1)
	{
		// throw an exception
	}

	m_data = new double[m_rows * m_columns] {};
}

Matrix::~Matrix()
{
	delete[] m_data;
}

double& Matrix::at(int row, int column)
{
	if (row < 0 || row > m_rows || column < 0 || column > m_columns)
	{
		// throw an exception
	}

	return m_data[row * m_columns + column];
}

const double& Matrix::at(int row, int column) const
{
	if (row < 0 || row >= m_rows || column < 0 || column >= m_columns)
	{
		// throw an exception
	}

	return m_data[row * m_columns + column];
}

int Matrix::rows() const
{
	return m_rows;
}

int Matrix::columns() const
{
	return m_columns;
}

Matrix Matrix::transposed() const {
	Matrix transposed(m_columns, m_rows);

	for (int r = 0; r < m_rows; r++) {
		for (int c = 0; c < m_columns; c++)
		{
			transposed.at(c, r) = this->at(r, c);
		}
	}

	return transposed;
}

Matrix Matrix::multiply(const Matrix& other) const
{

}
