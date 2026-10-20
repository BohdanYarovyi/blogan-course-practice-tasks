#include <iostream>

#include "Pair.hpp"
#include "StringPair.hpp"

int main()
{
	Pair<int, int> pairInteger(6, 13);
	std::cout << pairInteger << std::endl;

	Pair<double, char> pair(9.8, 'g');
	std::cout << pair << std::endl;

	StringPair<int> me("Bohdan", 24);
	std::cout << me << std::endl;

}