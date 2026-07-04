#include <iostream>

/*
Перепишіть попередню задачу так, щоб до суми кожного року додавалась початкова сума + 5%
ВІД ПОТОЧНОЇ СУМИ. Тобто якщо користувач ввів 100 доларів і 5 років, то обрахунок 
йде наступний:
	- через 1 рік сума рівна:	100.00 + (100.00 + 100.00 * 0.05) = 205
	- через 2 роки сума рівна:	205.00 + (100.00 + 205.00 * 0.05) = 315.25
	- через 3 роки сума рівна:	315.25 + (100.00 + 315.25 * 0.05) = 431.01
	- через 4 роки сума рівна:	431.01 + (100.00 + 431.01 * 0.05) = 552.56
	- через 5 років сума рівна: 552.56 + (100.00 + 552.56 * 0.05) = 680.19

Отже відповідь: 680.19 доларів
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
		deposit_sum = deposit_sum + start_sum + deposit_sum * annual_interest_delta;
		time++;
	}

	std::cout << deposit_sum << std::endl;

	return 0;
}