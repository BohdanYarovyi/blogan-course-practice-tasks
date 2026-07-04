#include <iostream>

/*
Користувач вводить 2 числа: спочатку менше, потім більше. Виведіть
на екран всі числа в цьому діапазоні. Тобто якщо користувач вводить
2 і 8, ваша задача вивести 2 3 4 5 6 7 8.
*/

int main() {
	int lower_bound;
	int upper_bound;

	std::cout << "Enter two bounds [lower_bound upper_bound]: ";
	std::cin >> lower_bound >> upper_bound;

	while (lower_bound <= upper_bound) {
		std::cout << lower_bound++ << " ";
	}

	return 0;
}