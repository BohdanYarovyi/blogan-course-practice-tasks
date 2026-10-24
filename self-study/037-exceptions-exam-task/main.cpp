#include <iostream>
#include <exception>

#include "Fraction.hpp"

int main()
{
	try
	{
		Fraction f = Fraction::create();
		std::cout << f;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
