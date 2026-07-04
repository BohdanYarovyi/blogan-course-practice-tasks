#include <iostream>

/*
Давайте пробачимо користувачу помилку в попередній задачі.
Переробіть код так, щоб коли він вводив число менше або рівне 0,
йому виводилося повідомлення "Ви ввели не додатнє число",
після чого він знову може вводити число.

Підказка: ввід числа має находитися також в циклі.
*/

int main() {
	int number;

	std::cout << "Enter an upper bound: ";
	std::cin >> number;

	while (number < 1) {
		std::cout << "Inputed number is not positive, try again: ";
		std::cin >> number;
	}

	int i = 0;
	while (i <= number) {
		std::cout << i++ << std::endl;
	}

	return 0;
}