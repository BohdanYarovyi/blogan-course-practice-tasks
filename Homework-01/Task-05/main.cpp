#include <iostream>
#include <string>

/*
Виведіть на екран 5 будь-яких речей на англійській мові. Напишіть їх всіх в одному cout.
*/

int main() {
	std::string thing1 = "Bread";
	std::string thing2 = "Car";
	std::string thing3 = "Water";
	std::string thing4 = "Sun";
	std::string thing5 = "Ball";

	std::cout << thing1 << " " << thing2 << " " << thing3 << " " << thing4 << " " << thing5 << std::endl;
	return 0;
}