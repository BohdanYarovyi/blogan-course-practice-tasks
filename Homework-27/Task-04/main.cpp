#include <iostream>

/*
Користувач вводить число. Перевірте, чи воно не рівне числам 2, 5 і 8 завдяки операторам != та &&.
*/

int main() {
	int number;
	std::cout << "Enter any number not of [2, 5, 8]: ";
	std::cin >> number;

	if (number != 2 && number != 5 && number != 8) {
		std::cout << "The number is correct." << std::endl;
	}
	else {
		std::cout << "The number is not correct." << std::endl;
	}

	return 0;
}