#include <iostream>

#include "matrix.hpp"

Matrix::Matrix(int rows, int columns) : m_rows {rows}, m_columns {columns}
{
	if (rows < 1 || columns < 1)
	{
		// throw an exception
	}

	m_data = new double[m_rows * m_columns] {};
}

Matrix::Matrix(const Matrix& other) : m_rows(other.m_rows), m_columns(other.m_columns)
{
	int size = m_rows * m_columns;
	m_data = new double[size] {};
	for (int i = 0; i < size; i++)
	{
		m_data[i] = other.m_data[i];
	}
}

Matrix::~Matrix()
{
	//delete[] m_data;
}

double& Matrix::at(int row, int column)
{
	if (row < 0 || row >= m_rows || column < 0 || column >= m_columns)
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
	if (this->columns() != other.rows())
	{
		// throw an exception
	}

	int matrix_index_multiplications = this->columns();
	int new_matrix_rows	= this->rows();
	int new_matrix_columns = other.columns(); 
	Matrix new_one(new_matrix_rows, new_matrix_columns);

	for (int h = 0; h < new_matrix_rows; h++)
	{
		for (int w = 0; w < new_matrix_columns; w++)
		{
			double new_element = 0;
			for (int i = 0; i < matrix_index_multiplications; i++)
			{
				double element_1 = this->at(h, i);
				double element_2 = other.at(i, w);
				new_element += element_1 * element_2;
			}

			new_one.at(h, w) = new_element;
		}
	}

	return new_one;
}

void Matrix::print() const
{
	for (int h = 0; h < this->rows(); h++)
	{
		for (int w = 0; w < this->columns(); w++)
		{
			std::cout << this->at(h, w);

			if (w < this->columns() - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
}

void Matrix::fill(double value)
{
	for (int h = 0; h < m_rows; h++)
	{
		for (int w = 0; w < m_columns; w++)
		{
			at(h, w) = value;
		}
	}
}

Matrix Matrix::identity(int size) {
	Matrix identity(size, size);

	for (int i = 0; i < size; i++)
	{
		identity.at(i, i) = 1;
	}

	return identity;
}