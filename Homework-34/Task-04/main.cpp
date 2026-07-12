#include <iostream>

/*
Користувач вводить число, більше за 0. Виведіть на екран суму всіх чисел від 1 до цього числа включно.
*/

int main() {
	int user_input;

	std::cout << "Enter a npositive number: ";
	std::cin >> user_input;

	for (int i = 1; i <= user_input; i++) {
		std::cout << i << std::endl;
	}

	return 0;
}