#include <iostream>

/*
Користувач може вводити числа до того моменту, поки не введе 0. Після того,
як він введе 0, на екран виводиться кількість додатніх і від'ємних чисел.
*/

int main() {
	int odd_numbers		= 0;
	int even_numbers	= 0;
	int current_nuumber;

	do {
		std::cout << "Enter a number or exit with 0 as input: ";
		std::cin >> current_nuumber;

		if (current_nuumber != 0) {
			current_nuumber % 2 == 0 ? even_numbers++ : odd_numbers++;
		}
	} while (current_nuumber != 0);

	std::cout << "You are inputted " << even_numbers << " even number(s) and " << odd_numbers << " odd numnber(s)" << std::endl;

	return 0;
}