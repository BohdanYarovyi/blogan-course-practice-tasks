#include <iostream>

/*
Є діапазон чисел [2...10]. Програма проходить завдяки циклу for по кожному з цих чисел
і питає в користувача, чи є дане число простим. Якщо користувач відповідає правильно,
то програма переходить до наступного числа. Якщо користувач відповів не вірно, то цикл зупиняє
свою роботу завдяки break. Нагадую, просте число - це число, яке ділиться лише на себе та на 1.
Із діапазону [2...10] це числа 2, 3, 5 і 7.
*/

int main() {
	constexpr int TOP_RANGE_VALUE		= 10;
	constexpr int BOTTOM_RANGE_VALUE	= 2;

	bool user_answer;
	bool is_number_prime;
	for (int i = BOTTOM_RANGE_VALUE; i <= TOP_RANGE_VALUE; i++) {
		std::cout << "Is " << i << " prime number? (0 - no, 1 - yes): ";
		std::cin >> user_answer;

		is_number_prime = true;
		for (int k = 2; k < i; k++) {
			if (i % k == 0) {
				is_number_prime = false;
				break;
			}
		}

		if (user_answer ^ is_number_prime) {
			std::cout << "Your answer is not correct." << std::endl;
			break;
		}
	}

	return 0;
}