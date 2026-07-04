#include <iostream>

/*
А якщо в попередній задачі користувач введе спочатку більше число, а потім менше?
Якщо ви це не врахували, але виконали попередню задачу, то у вас при такому
розкладі нічого не виводить. А я хочу, щоб коли користувач ввів числа, наприклад,
8 і 2, то все одно виводилося 2 3 4 5 6 7 8. Для цього перед виводом чисел
перевірте чи перше число більше за друге. Якщо так - поміняйте їх місцями.
Не знаєте, як міняти значення двох змінних місцями? Спробуйте додуматись самі.
Не виходить? Гугліть.
*/

int main() {
	int lower_bound;
	int upper_bound;

	std::cout << "Enter two bounds [lower_bound upper_bound]: ";
	std::cin >> lower_bound >> upper_bound;

	if (lower_bound > upper_bound) {
		int tmp = upper_bound;
		upper_bound = lower_bound;
		lower_bound = tmp;
	}

	while (lower_bound <= upper_bound) {
		std::cout << lower_bound++ << " ";
	}

	return 0;
}