#include <iostream>

/*
Користувач вводить число. Перевірте, чи воно не входить в діпазоні [2...8] завдяки операторам >, || та <.
*/

int main() {
	int number;
	std::cout << "Enter a number not between [2 - 8] inclusively: ";
	std::cin >> number;

	if (number > 8 || number < 2) {
		std::cout << "The number is correct." << std::endl;
	}
	else {
		std::cout << "The number is not correct." << std::endl;
	}

	return 0;
}