#include <iostream>

/*
Переробіть попередню задачу так, щоб якщо користувач дав всі правильні відповіді,
то після циклу виводилося відповідне вітальне повідомлення.
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

	std::cout << "You answered every question correctly. You are really good!" << std::endl;
	return 0;
}