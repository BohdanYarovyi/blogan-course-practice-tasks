#include <iostream>

#include "matrix.hpp"

int main()
{
	Matrix a(3, 3);
	Matrix b(3, 3);

    double current_val_a = 1.0;
    for (int i = 0; i < a.rows(); ++i) {
        for (int j = 0; j < a.columns(); ++j) {
            a.at(i, j) = current_val_a;
            current_val_a += 1.0;
        }
    }

    double current_val_b = 9.0;
    for (int i = 0; i < b.rows(); ++i) {
        for (int j = 0; j < b.columns(); ++j) {
            b.at(i, j) = current_val_b;
            current_val_b -= 1.0;
        }
    }

    Matrix c = a.multiply(b);

    a.print();
    std::cout << std::endl;
    b.print();
    std::cout << std::endl;
    c.print();
    std::cout << std::endl;

    Matrix identity = Matrix::identity(5);
    identity.print();
    std::cout << std::endl;

    Matrix a_mod = a.multiply(Matrix::identity(3));
    a_mod.print();
    std::cout << std::endl;

	return 0;
}
