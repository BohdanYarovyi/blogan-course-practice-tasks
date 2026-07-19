#include <iostream>

/*
Користувач вводить границі діапазону чисел (мінімальне число і максимальне число).
Якщо перше число більше за друге - поміняйте їх значення місцями. Виведіть на екран
всі прості числа в цьому діапазоні.
*/

int main() {
	int user_min;
	int user_max;

	bool is_numbers_valid = false;
	do {
		std::cout << "Input two numbers (<min> <max>): ";
		std::cin >> user_min >> user_max;

		if (user_max < 1 || user_min < 1) {
			std::cout << "The input is incorrect: Numbers must be greater than 1." << std::endl;
		}
		else {
			is_numbers_valid = true;
		}
	} while (!is_numbers_valid);


	if (user_min > user_max) {
		int tmp = user_max;
		user_max = user_min;
		user_min = tmp;
	}

	bool is_prime;
	for (int c = user_min; c < user_max; c++) {
		is_prime = true;
		for (int i = 2; i < c; i++) {
			if (c % i == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) {
			std::cout << c << std::endl; 
		}
	}
	return 0;
}