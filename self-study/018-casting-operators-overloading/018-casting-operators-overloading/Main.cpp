#include <iostream>

#include "Dollars.hpp"
#include "Cents.hpp"

int main()
{
	Dollars dollar1 = {5};
	std::cout << dollar1 << "\n";
	Cents cents = dollar1;
	std::cout << cents << "\n";
}