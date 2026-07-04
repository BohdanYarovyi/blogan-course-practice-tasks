#include <iostream>
#include <cmath>

/*
Користувач вводить з клавіаутри ціле число. Виведіть на екран його квадрат.
*/

int main() {
	int number;
	std::cout << "Enter any number: ";
	std::cin >> number;

	std::cout << "I powered your number and got " << std::pow(number, 2) << std::endl;
	return 0;
}