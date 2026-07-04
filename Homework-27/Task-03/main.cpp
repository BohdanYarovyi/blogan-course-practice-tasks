#include <iostream>

/*
Користувач вводить число. Перевірте, чи воно рівне числу 1, або числу 2, або числу 3 завдяки операторам == та ||.
*/

int main() {
	int number;
	std::cout << "Enter a number of [1, 2, 3]: ";
	std::cin >> number;

	if (number == 1 || number == 2 || number == 3) {
		std::cout << "The number is correct." << std::endl;
	}
	else {
		std::cout << "The number is not correct." << std::endl;
	}

	return 0;
}