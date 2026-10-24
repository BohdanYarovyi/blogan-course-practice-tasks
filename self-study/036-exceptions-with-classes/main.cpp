#include <iostream>
#include <exception>
#include <string>

#include "ArrayInt.hpp"

int main()
{
	try
	{
		ArrayInt arr(-2);
		try
		{
			arr[0] = 75;
			arr[2] = 30;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "arr[0]=" << arr[0] << std::endl;
		std::cout << "arr[1]=" << arr[1] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::string s;
		s.resize(-1);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Standart exception: " << e.what() << std::endl;
	}
	return 0;
}
