#include <iostream>

#include "Matrix.hpp"

int main()
{
	Matrix m = {};
	m(1, 1) = 4.3;
	m(1, 2) = 0.22;
	std::cout << m;
}