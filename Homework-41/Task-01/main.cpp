#include <iostream>

/*
Напишіть програму, яка створює двовимірний масив типу float розмірами 3 на 4.
Ініціалізуйте масив любим значенням завдяки списковій ініціалізації і 
виведіть цей масив на екран так, як вам подобається.
*/

int main() {
	constexpr int OUTER_ARRAY_SIZE = 3;
	constexpr int INNER_ARRAY_SIZE = 4;

	float numbers[OUTER_ARRAY_SIZE][INNER_ARRAY_SIZE]{
		{1.1, 2.2,   3.3,   4.4},
		{5.5, 6.6,   7.7,   8.8},
		{9.9, 10.10, 11.11, 12.12}
	};

	for (int outer = 0; outer < OUTER_ARRAY_SIZE; outer++) {
		std::cout << "{";
		for (int inner = 0; inner < INNER_ARRAY_SIZE; inner++) {
			std::cout << numbers[outer][inner];

			if (inner < INNER_ARRAY_SIZE - 1) {
				std::cout << ", \t";
			}
		}
		std::cout << "}," << std::endl;
	}
	return 0;
}