#include <iostream>

/*
Користувач вводить два рядки. Перевірте, чи вони однакові (по символам а не по довжині).
*/

int main() {
	constexpr int MAX_INPUT_LENGTH = 100;

	char input1[MAX_INPUT_LENGTH];
	char input2[MAX_INPUT_LENGTH];

	std::cout << "Enter a password: ";
	std::cin.getline(input1, MAX_INPUT_LENGTH);
	std::cout << "Enter password confirmation: ";
	std::cin.getline(input2, MAX_INPUT_LENGTH);

	bool is_equal = true;
	for (int i = 0; input1[i] != '\0' || input2[i] != '\0'; i++) {
		if (input1[i] != input2[i]) {
			is_equal = false;
			break;
		}
	}

	if (is_equal) {
		std::cout << "Congratulations! Your password is correct." << std::endl;
	} else {
		std::cout << "Oops.. Your password and password confirmation are different." << std::endl;
	}

	return 0;
}
