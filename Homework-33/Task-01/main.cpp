#include <iostream>

/*
Користувач може вводити числа до того моменту, поки не введе 0.
Якщо число парне - на екран виводиться повідомлення "Ваше число парне".
Інакше виводиться число "Ваше число непарне". Що таке парне число?
Це число, яке ділиться націло на 2.
*/

int main() {
	
	int number;

	do {
		std::cout << "Enter a number and I will say you is it odd or even: ";
		std::cin >> number;

		std::cout << "The number is " << (number % 2 == 0 ? "even" : "odd") << std::endl;
	} while (number != 0);

	return 0;
}