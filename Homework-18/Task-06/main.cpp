#include <iostream>

/*
Користувач вводить наступні дані:
	1. Скільки пиріжків він купив
	2. Скільки пиріжків він з'їдає за 1 день
Виведіть на екран, скільки днів він з'їдатиме вказану кількість пиріжків,
і скільки пиріжків у нього залишиться, коли він вже не зможе з'їсти вказану кількість.
Наприклад:
	- він купив 100 пиріжків.
	- їсть по 9 пиріжків в день.
	- отже він 11 днів буде їсти по 9 пиріжків, а на 10 день у нього залишиться 1 пиріжок.
	  (1, бо 11 * 9 = 99. 100 - 99 = 1)
(Використовуються оператори = та %)
*/

int main() {
	int total_pies;
	int daily_patty_consuming;

	std::cout << "How many pies did you buy? -> ";
	std::cin >> total_pies;
	std::cout << "How many pies do you eat every day? -> ";
	std::cin >> daily_patty_consuming;

	int full_ration_days = total_pies / daily_patty_consuming;
	int rest_pies = total_pies % daily_patty_consuming;

	std::cout << "Based on total pies (" << total_pies << ") ";
	std::cout << "and daily patty consuming (" << daily_patty_consuming  << " pies per day)" << std::endl;
	std::cout << "you will be well-fed for " << full_ration_days << " days, ";
	std::cout << "but on the " << full_ration_days + 1 << " day you will have only " << rest_pies << "." << std::endl;
	return 0;
}