#include <iostream>

#include "Square.hpp"
#include "Average.hpp"

int main()
{
	Square s1(5);
	Square s2(10);

	Square s3 = 7;
	Square s4 = -s3;

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	std::cout << s1 + s2 << std::endl;

	Average avg;
	std::cout << avg << std::endl;
	avg += 10;
	std::cout << avg << std::endl;
	avg += 3;
	std::cout << avg << std::endl;
	avg += 5;
	std::cout << avg << std::endl;
	avg += 21;
	std::cout << avg << std::endl;

}