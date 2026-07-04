#include <iostream>

/*
Користувач покористувався нашою програмою із задачі №11 і не вірить,
що йому мають заплатити саме стільки. Він просить вивести йому,
яка сума депозиту находиться в банку кожного року.
Тобто тепер вам треба виводити суму депозиту кожну ітерацію циклу.
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
		deposit_sum = deposit_sum + deposit_sum + deposit_sum * annual_interest_delta;
		time++;
		std::cout << "Year " << time << ": $" << deposit_sum << std::endl;
	}

	return 0;
}