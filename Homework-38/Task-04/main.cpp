#include <iostream>
#include <cmath>

/*
Виведіть на екран ромб, який пустий в середині. Його висоту вводить користувач.
Це число обов'язково має бути більше за 2 та обов'язково має бути непарним.

Наприклад, якщо користувач введе висоту 5, то вивід буде наступним:
	  *
	 * *
	*   *
	 * *
	  *
*/

int main() {
	int height;

	bool is_height_correct = false;
	std::cout << "Enter a height of a diamond: ";
	do {
		std::cin >> height;

		if (height < 3) {
			std::cout << "Uncorrect input: The height of romb must be greater than 2." << std::endl;
			std::cout << "try again: ";
		} 
		else if (height % 2 == 0) {
			std::cout << "Uncorrect input: The height of romb must be odd." << std::endl;
			std::cout << "try again: ";
		}
		else {
			is_height_correct = true;
		}
	} while (!is_height_correct);

	int middle_of_diamond = height / 2;
	for (int h = 0; h < height; h++) {
		int side_whitespaces = std::abs(middle_of_diamond - h);
		int inner_whitespaces = (height - 2) - std::abs(middle_of_diamond - h) * 2;

		// whitespaces
		for (int e = 0; e < side_whitespaces; e++) {
			std::cout << " ";
		}
		
		if (h == 0 || h == height - 1) {
			std::cout << "*";
		}
		else {
			// symbols
			std::cout << "*";

			// whitespaces
			for (int e = 0; e < inner_whitespaces; e++) {
				std::cout << " ";
			}

			// symbols
			std::cout << "*";
		}

		// whitespaces
		for (int e = 0; e < side_whitespaces; e++) {
			std::cout << " ";
		}
		
		std::cout << std::endl;
	}

	return 0;
}