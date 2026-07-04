#include <iostream>

/*
Користувач вводить число. 
	- Якщо воно парне - виведіть на екран повідомлення "Ваше число парне".
	- Інакше виведіть повідомлення "Ваше число непарне".
*/

int main() {
	int number;

	std::cout << "Enter eny number: ";
	std::cin >> number;

	std::cout << "Your number is " << (number % 2 == 0 ? "even" : "odd") << std::endl; 
	return 0;
}