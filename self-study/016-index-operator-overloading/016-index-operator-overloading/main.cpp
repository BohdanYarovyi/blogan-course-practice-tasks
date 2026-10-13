#include <iostream>

#include "grade_map.hpp"

int main()
{
	Grade_Map map = {3};
	map["Bohdan"] = 10;
	map["Bohdan"] = 60;
	map["Mr. Business"] = 10000;
	std::cout << map;

	return 0;
}