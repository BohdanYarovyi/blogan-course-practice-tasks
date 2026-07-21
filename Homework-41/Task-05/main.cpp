#include <iostream>

/*
Є два магазини. В них є 3 товари: апельсини, яблука, банани. Тобто має бути масив 2 на 3.
Перший магазин називається "JustBuy", другий "At All Costs". Цей масив в собі зберігає
цілі числа - кількість кожного товару в кожному магазині. Ви маєте дати користувачу
його заповнити з клавіатури.
Ось так має виглядати повідомлення при введення:
	Введіть кількість апельсинів для магазину "JustBuy": (користувач вводить)
	Введіть кількість яблук для магазину "JustBuy": (користувач вводить)
	Введіть кількість бананів для магазину "JustBuy": (користувач вводить)

	Введіть кількість апельсин для магазину "At All Costs": (користувач вводить)
	Введіть кількість яблук для магазину "At All Costs": (користувач вводить)
	Введіть кількість бананів для магазину "At All Costs": (користувач вводить)

	Після цього виведіть на екран таблицю з цими значеннями, наприклад ось так:
	Магазин "JustBuy" містить:
	- Апельсини: 23
	- Яблука: 10
	- Банани: 54

	Аналогічно з магазином At All Costs.


	Можете писати повідомлення англійською мовою. Також якщо користувач введе від'ємне число -
	скажіть йому про це і дайте можливість ввести заново (тобто має бути цикл).
*/

int main() {
	constexpr int SHOPS_COUNT = 2;
	constexpr int GOODS_COUNT = 3;

	int goods[SHOPS_COUNT][GOODS_COUNT];

	for (int shop = 0; shop < SHOPS_COUNT; shop++) {
		for (int product = 0; product < GOODS_COUNT; product++) {

			float user_input;
			bool is_quantity_correct = false;
			do {
				std::cout << "Enter a number of ";
				switch (product) {
					case 0: {
						std::cout << "oranges";
						break;
					}
					case 1: {
						std::cout << "apples";
						break;
					}
					case 2: {
						std::cout << "bananas";
						break;
					}
					default: {
						std::cout << std::endl << "Unconsistancy State: Not found appropreate product name for index="
						<< product << std::endl;
						return 1;
					}
				}
				std::cout << " for shop " << (shop == 0 ? "JustBuy" : "At All Costs") << ": ";
				std::cin >> user_input;

				if (user_input < 0) {
					std::cout << "The number of products quantity cannot be negative." << std::endl;
				}
				else {
					is_quantity_correct = true;
				}
			} while (!is_quantity_correct);

			goods[shop][product] = user_input;
		}
	}

	std::cout << "JustBuy shop contains:" << std::endl;
	std::cout << "\t - Oranges: "	<< goods[0][0] << std::endl;
	std::cout << "\t - Apples: "	<< goods[0][1] << std::endl;
	std::cout << "\t - Bananas: "	<< goods[0][2] << std::endl;
	std::cout << std::endl;
	std::cout << "At All Costs shop contains:" << std::endl;
	std::cout << "\t - Oranges: "	<< goods[1][0] << std::endl;
	std::cout << "\t - Apples: "	<< goods[1][1] << std::endl;
	std::cout << "\t - Bananas: "	<< goods[1][2] << std::endl;

	return 0;
}
