#include <iostream>

/*
Користувач вводить число.
	- Якщо число більше за 0 - виведіть повідомлення "Ваше число додатнє"
	- Інакше якщо число рівне 0 - виведіть повідомлення "Ваше число рівне 0"
	- Інакше виведіть повідомлення "Ваше число від'ємне"
*/

int main() {
	int number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	if (number > 0) {
		std::cout << "Your number is positive" << std::endl;
	}
	else if (number == 0) {
		std::cout << "Your number is ZERO" << std::endl;
	}
	else {
		std::cout << "Your number is negative" << std::endl;
	}

	return 0;
}