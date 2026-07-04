#include <iostream>

/*
Користувач вводить число.
	- Якщо число більше за 0 - виведіть повідомлення "Ваше число додатнє"
	- Інакше виведіть повідомлення "Ваше число не додатнє"
*/

int main() {
	int number;

	std::cout << "Enter any number: ";
	std::cin >> number;

	std::cout << "Your number is " << (number > 0 ? "positive" : "not positive") << std::endl;
	return 0;
}