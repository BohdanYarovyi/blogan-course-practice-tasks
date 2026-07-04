#include <iostream>

/*
Напишемо гру, в якій користувач відгадує число комп'ютера. Комп'ютер загадує число 27.
Користувачу гра говорить "Відгадайте число комп'ютера. Він загадав число від 0 до 100".
Користувач вводить число. Якщо воно рівне 27 - виводиться повідомлення "Ви вгадали!" і гра закінчується.
Якщо він не вгадав, то виводиться повідомлення "Ви не вгадали. Спробуйте знову".

При цьому в грі є лічильник спроб. Коли гравець відгадує число, гра його не тільки вітає,
але й виводить кількість спроб, які знадобилися гравцю для відгадування.
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
			std::cout << "computer: No. Try again" << std::endl;
		}

		std::cout << "user: ";
		std::cin >> user_number;
		tries++;
	}

	std::cout << "computer: Congratulations! The number was geussed with only " << tries << " tries." << std::endl;

	return 0;
}