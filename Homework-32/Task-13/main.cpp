#include <iostream>

/*
Окей, але користувач все одно не розуміє, звідки беруться ці суми. Він просить
не лише виводити суму депозиту кожного року, а й показувати, які числа використовуються у
формулі обчислення.

Ваша задача вивести на екран інформацію саме так, як вона виглядає в задачі №11. Тобто
якщо користувач ввів 100 доларів і 4 роки, то вивід (не лише обрахунок) буде наступний:
	- через 1 рік сума рівна:
	  100.00 + (100.00 + 100.00 * 0.05) = 205

	- через 2 роки сума рівна:
	  205.00 + (205.00 + 205.00 * 0.05) = 420.25

	- через 3 роки сума рівна:
	  420.25 + (420.25 + 420.25 * 0.05) = 861.51

	- через 4 роки сума рівна:
	  861.51 + (861.51 + 861.51 * 0.05) = 1766.10

Ваша фінальна сума: $1766.10
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
		time++;

		std::cout << "For " << time << " year the sum will be:\n";
		std::cout << "    " << deposit_sum << " + (" << deposit_sum << " + " << deposit_sum 
					<< " * " << annual_interest_delta << ") = ";
		deposit_sum = deposit_sum + deposit_sum + deposit_sum * annual_interest_delta;
		std::cout << deposit_sum << std::endl << std::endl ;
	}

	std::cout << "The final sum is: " << deposit_sum << std::endl;
	return 0;
}