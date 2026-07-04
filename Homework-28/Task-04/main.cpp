#include <iostream>

/*
Користувач вводить число. 
	- Якщо воно парне - виведіть на екран повідомлення "Ваше число парне".
	- Інакше виведіть повідомлення "Ваше число непарне".
*/

int main() {
	int number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	if (number % 2 == 0) {
		std::cout << "Your number is even" << std::endl;
	}
	else {
		std::cout << "Your number is odd" << std::endl;
	}
}