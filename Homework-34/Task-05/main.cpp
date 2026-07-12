#include <iostream>

/*
Користувач вводить число і його степінь. Виведіть на екран степінь цього числа.
Тобто якщо користувач вводить 3 і 2, то вам треба вивести 3 в степені 2, тобто число 9.

Врахуйте наступні ситуації:
	1. Якщо число степіня = 0
	2. Якщо число = 0
	3. Якщо степінь від'ємний

Гугліть в інтернеті, як рахувати степінь. Головне те, що не використовуйте дробові степені. Число же дробовим може бути.

*/

int main() {
	int user_number;
	int user_exponent;
	int power = 1;
	bool is_input_correct;

	is_input_correct = false;
	do {
		std::cout << "Enter a number and exponent (<number> <exponent>): ";
		std::cin >> user_number >> user_exponent;

		if (user_number == 0) {
			std::cout << "The number cannot be 0" << std::endl;
		}
		else if (user_exponent < 1) {
			std::cout << "The exponent must be greater than 0" << std::endl;
		}
		else {
			is_input_correct = true;
		}
	} while (!is_input_correct);

	for (int i = 0; i < user_exponent; i++) {
		power = power * user_number;
	}

	std::cout << "The power of " << user_number << "^" << user_exponent << " is: " << power << std::endl;

	return 0;
}