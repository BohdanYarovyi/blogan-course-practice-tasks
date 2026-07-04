#include <iostream>

/*
Давайте перепишемо попередню гру, зробивши її легшою. Додайте такий функціонал, 
який підказує наступне:
	- якщо він вводить число, яке більше за число комп'ютера, то виводиться 
	  повідомлення "Ви не вгадали. Я загадав МЕНШЕ число."
	- якщо гравець введе менше, то виводиться повідомлення "Ви не вгадали.
	  Я загадав БІЛЬШЕ число.".
*/

int main() {
	const int SECRET_NUMBER = 27;
	const int UPPER_BOUND = 100;
	const int LOWER_BOUND = 0;
	int user_number;

	std::cout << "computer: Try to guess my number. The number is between "
		<< LOWER_BOUND << " and " << UPPER_BOUND << "." << std::endl;
	std::cout << "user: ";
	std::cin >> user_number;

	int tries = 0;
	while (user_number != SECRET_NUMBER) {
		if (user_number > UPPER_BOUND || user_number < LOWER_BOUND) {
			std::cout << "computer: Are you really? I said the number IS BETWEEN "
				<< LOWER_BOUND << " AND " << UPPER_BOUND << "." << std::endl;
		} else {
			bool is_bigger = SECRET_NUMBER > user_number;
			std::cout << "No. I guessed a " << (is_bigger ? "BIGGER" : "SMALLER") << " number. Try again." << std::endl;
		}

		std::cout << "user: ";
		std::cin >> user_number;
		tries++;
	}

	std::cout << "computer: Congratulations! The number was geussed with only " << tries << " tries." << std::endl;

	return 0;
}