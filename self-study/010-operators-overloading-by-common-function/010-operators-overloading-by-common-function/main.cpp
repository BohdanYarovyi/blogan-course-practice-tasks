#include <iostream>

#include "dollars.hpp"

int main()
{
	Dollars dollars1(7);
	Dollars dollars2(9);
	Dollars dollarsSum = dollars1 + dollars2;
	std::cout << "I have " << dollarsSum.get_value() << " dollars." << std::endl;

	return 0;
}