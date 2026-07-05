#include <iostream>

/*
Попрацюємо зі статистикою. Попросіть у користувача ввести наступні дані:
	- Скільки людей проживає у його місті
	- Скільки з цих людей розмовлють українською мовою
Після цього виведіть на екран, який шанс того, що він розмовляє українською.
Тобто, якщо жителів 100 і серед них розмовляє 80 людей, то виходить, що шанс того,
що він розмовляє українською мовою - 80%. Так, виведіть саме у відсотках. 
Тобто це має бути дробове число.

А куди засунути цикли? Зробіть ввід так, щоб користувач вводив правильні значення.
Тобто він не може ввести 0 або від'ємне число кількості жителів. Аналогічно до цього
він не може ввести 0 або від'ємне число кількості людей, що говорять українською мовою.
*/

int main() {
	int amount_of_citizens;
	int amount_of_citizens_ua;

	bool valid_input = false;
	do {
		std::cout << "Please, enter a number of citizens in your city: ";
		std::cin >> amount_of_citizens;

		if (amount_of_citizens > 0) {
			valid_input = true;
		}
		else {
			std::cout << "The number of amount of citizens cannot be zero or less" << std::endl;
		}

	} while (!valid_input);

	valid_input = false;
	do {
		std::cout << "Please, enter a number of ukrainian talk citizens in your city: ";
		std::cin >> amount_of_citizens_ua;

		if (amount_of_citizens_ua > 0) {
			valid_input = true;
		}
		else {
			std::cout << "The number of amount of ukrainian talk citizens cannot be zero or less" << std::endl;
		}

	} while (!valid_input);

	float ukrainian_talk_part = 100.0f / static_cast<float>(amount_of_citizens) * static_cast<float>(amount_of_citizens_ua);
	std::cout << "The ukrainian talk part is " << ukrainian_talk_part << "% of all citizens in your city" << std::endl;
	return 0;
}