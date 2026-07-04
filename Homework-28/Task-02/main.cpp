#include <iostream>

/*
Користувач вводить число.
	- Якщо число більше за 0 - виведіть повідомлення "Ваше число додатнє"
	- Інакше виведіть повідомлення "Ваше число не додатнє"
*/

int main() {
	int number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	if (number > 0) {
		std::cout << "Your number is positive" << std::endl;
	}
	else {
		std::cout << "Tour number is not positive" << std::endl; 
	}

	return 0;
}