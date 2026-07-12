#include <iostream>

/*
Напишіть програму, в якій користувачу треба постійно вводити, скільки мілілітрів води він випив за день. 
Він вводить  це число нескінченно (тобто використовуючи вічний цикл while). Після кожного введення додавайте 
це число до загальної кількості випитої води. Якщо це число перевисить число 6000 мілілітрів, 
то виведіть попередження, що можливо досить. Цикл закінчується тоді, коли число перевищить 8000 мілілітрів.
Після цього виведіть повідомлення "Вітаємо, ви померли".
*/

int main() {
	constexpr int DANGEROUS_AMOUNT_OF_WATER = 6000;
	constexpr int DEADLY_AMOUNT_OF_WATER	= 8000;

	int total_milliliters_of_water = 0;
	int user_input;

	while (true) {
		std::cout << "How many water did you drink (milliliters): ";
		std::cin >> user_input;
		
		total_milliliters_of_water += user_input;

		if (total_milliliters_of_water > DANGEROUS_AMOUNT_OF_WATER &&
			total_milliliters_of_water < DEADLY_AMOUNT_OF_WATER) {
			std::cout << "Be careful. You have drunk more than daylie normal of water." << std::endl;
		}
		else if (total_milliliters_of_water > DEADLY_AMOUNT_OF_WATER) {
			std::cout << "Congratulations! You died." << std::endl;
			break;
		}
	}

	return 0;
}