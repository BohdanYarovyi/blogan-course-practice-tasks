#include <iostream>

/*
Давайте ще ускладнимо задачу 6. Виводьте ромби не вертикально а горизонтально, тобто
якщо користувач хоче вивести 3 ромби, то вивід має бути наступний:
	  *	    *     *  
	 * *   * *   * * 
	*   * *   * *   *
	 * *   * *   * * 
	  *     *     *  
*/

int main() {
	int height;
	int horizontal_count;

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

	bool is_horizontal_count_correct = false;
	std::cout << "Enter a count of diamons to show them horizontal: ";
	do {
		std::cin >> horizontal_count;

		if (horizontal_count < 1) {
			std::cout << "Uncorrect input: The count of rombs must be ar least 1." << std::endl;
			std::cout << "try again: ";
		} 
		else {
			is_horizontal_count_correct = true;
		}
	} while (!is_horizontal_count_correct);

	int middle_of_diamond = height / 2;
	for (int h = 0; h < height; h++) {
		for (int d = 0; d < horizontal_count; d++) {
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

		}

		std::cout << std::endl;
	}

	return 0;
}