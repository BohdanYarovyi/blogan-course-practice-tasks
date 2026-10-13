#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "car.hpp"
#include "dollars.hpp"

int main()
{
	std::vector<Car> v;
	v.push_back(Car("Ford", "Mustang"));
	v.push_back(Car("Renault", "Logan"));
	v.push_back(Car("Ford", "Ranger"));
	v.push_back(Car("Renault", "Duster"));

	std::sort(v.begin(), v.end()); // потрібне перевантаження оператора < для класу Car

	for (auto &car : v)
		std::cout << car << '\n'; // потрібне перевантаження оператора << для класу Car

	return 0;
}