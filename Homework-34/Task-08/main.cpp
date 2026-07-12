#include <iostream>

/*
Модернізуйте задачу 6 так, щоб на екран не тільки кількість цифр виводилось, але й обернене число.
Тобто якщо користувач вводить 123, то ви маєте вивести:
	Кількість цифр: 3
	Обернене число: 321

Якщо користувач введе від'ємне значення, наприклад -8218, то маєте вивести ось так:
	Кількість цифр: 4
	Обернене число: -8128

Вам знадобиться алгоритм, який рахує степінь. Можете скористатись своїм алгоритмом із задачі №5,
або можете скористатись функцією std::pow. Читайте про неї в інтернеті.
*/

int main() {
	int user_number;
	int counter = 0;
	int result = 0;

	std::cout << "Enter a number: ";
	std::cin >> user_number;

	for (int i = user_number; i != 0;) {
		if (i / 10 != 0 || i % 10 != 0) {
			counter++;
		}

		i = i / 10;
	}
	
	int origin_number = user_number;
	for (int i = 0; i < counter; i++) {
		int low_rank = origin_number % 10;
		origin_number = origin_number / 10;

		result = result + low_rank;
		if (i != counter - 1) {
			result = result * 10;
		}
	}

	std::cout << "The entered number " << user_number << " has " << counter << " digits" << std::endl; 
	std::cout << "The reversed number of " << user_number << " is " << result << std::endl; 

	return 0;
}