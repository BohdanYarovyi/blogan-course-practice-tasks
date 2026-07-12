#include <iostream>

/*
Виведіть на екран усі числа від 1 до 100, які діляться націло на 7. Використовуйте лише
один цикл for, один оператор if і лише один continue. Ну і звісно можна використовувати 
будь-яку кількість cout та створювати будь-яку кількість змінних.
*/

int main() {
	constexpr int TOP_RANGE_VALUE = 100;
	constexpr int BOTTOM_RANGE_VALUE = 1;
	constexpr int DENOMINATOR = 7;


	for (int i = BOTTOM_RANGE_VALUE; i <= TOP_RANGE_VALUE; i++) {
		if (i % DENOMINATOR != 0) {
			continue;
		}

		std::cout << i << std::endl;
	}

	return 0;
}