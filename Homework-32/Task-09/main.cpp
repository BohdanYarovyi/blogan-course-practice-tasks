#include <iostream>

/*
Користувач вводить наступні речі:
	- суму, яку він кладе на депозит
	- через скільки років він забере суму

Програма має вивести йому на екран, яку суму він забере через вказаний період.
Схема наступна:
	Кожний рік до суми, яку поклав на депозит користувач, 
	додається його початкова сума + 5% від початкової суми.

Тобто якщо користувач ввів 100 доларів і 5 років, то обрахунок йде наступний:
	- Через 1 рік сума рівна:	100 + (100 + 100 * 0.05) = 205
	- Через 2 роки сума рівна:	205 + (100 + 100 * 0.05) = 310
	- Через 3 роки сума рівна:	310 + (100 + 100 * 0.05) = 415
	- Через 4 роки сума рівна:	415 + (100 + 100 * 0.05) = 520
	- Через 5 років сума рівна: 520 + (100 + 100 * 0.05) = 625

Отже треба вивести 625 доларів.
*/

int main() {
	constexpr double ANNUAL_INTEREST = 5.0;

	double start_sum;
	int deposit_period;
	
	
	std::cout << "Enter a start sum to deposit (dollars): ";
	std::cin >> start_sum;
	std::cout << "Enter a period of deposit (years): ";
	std::cin >> deposit_period;

	int time = 0;
	double deposit_sum = start_sum;
	double annual_interest_delta = ANNUAL_INTEREST / 100;
	while (time < deposit_period) {
		deposit_sum = deposit_sum + start_sum + start_sum * annual_interest_delta;
		time++;
	}

	std::cout << deposit_sum << std::endl;

	return 0;
}