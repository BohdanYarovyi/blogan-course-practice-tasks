#include "Matrix.hpp"

Matrix::Matrix()
{
    for (int row=0; row < 5; ++row)
        for (int col=0; col < 5; ++col)
            data[row][col] = 0.0;
}

double& Matrix::operator()(int row, int col)
{
    return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
    return data[row][col];
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
    for (int i = 0; i < 5; i++)
    {
        out << "| ";
        for (int j = 0; j < 5; j++)
        {
            out << matrix(i, j);

            if (j < 5 - 1)
            {
                out << " ";
            }
        }
        out << "|\n";
    }
    out << "\n";

    return out;
}
