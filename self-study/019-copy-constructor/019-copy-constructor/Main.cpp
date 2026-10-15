#include <iostream>

#include "Drob.hpp"

int main()
{
	Drob d = {2, 4};
	Drob b2 = d;
	std::cout << b2 << std::endl;

	return 0;
}