#include <iostream>

/*
Користувач вводить число. Виведіть на екран повідомлення "Ви ввели число, яке більше за 0", якщо це так.
*/

int main() {
	int number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	if (number > 0) {
	std::cout << "You have entered a number that is greater than zero." << std::endl;
	}

	return 0;
}