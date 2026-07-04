#include <iostream>
#include <cmath>

/*
Користувач вводить додатнє число. Виведіть на екран корінь цього чила.
*/

int main() {
	float number;

	std::cout << "Enter any number and I will find the root of it: ";
	std::cin >> number;
	std::cout << "The root of " << number << " is " << std::sqrt(number) << "." << std::endl; 

	return 0;
}