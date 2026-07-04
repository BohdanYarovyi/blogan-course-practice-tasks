#include <iostream>

/*
Користувач вводить число. Перевірте, чи воно находиться в діпазоні [-100...100] завдяки виразу зі операторів >=, && та <=.
*/

int main() {
	int number;
	std::cout << "Enter a number between [-100 - 100]: ";
	std::cin >> number;

	if (number >= -100 && number <= 100) {
		std::cout << "The number is correct." << std::endl;
	}
	else {
		std::cout << "The number is not correct." << std::endl;
	}

	return 0;
}