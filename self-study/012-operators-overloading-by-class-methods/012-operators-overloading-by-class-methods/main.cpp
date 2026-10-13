#include <iostream>

#include "dollars.hpp"

int main()
{
	Dollars dollars = {10};
	Dollars new_dollars = dollars + 3;
	std::cout << new_dollars << std::endl;
}