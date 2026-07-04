#include <iostream>

/*
Переробіть попередню задачу так, щоб на екран виводилось повідомлення "Перша цифра (ось така), друга цифра (соь така)".
*/

int main() {
	int number;
	int first_digit = -1;
	int second_digit = -1;

	std::cout << "Enter a number between [0 - 99]: ";
	std::cin >> number;

	if (number < 0 || number > 99) {
		std::cout << "The number you have inputed is out of bounds [0 - 99]" << std::endl;
		return 1;
	}

	int counter_of_numbers = 1;
	first_digit = number % 10;
	number /= 10;

	if (number > 0) {
		second_digit = first_digit;
		first_digit = number;
		counter_of_numbers++;
	}

	std::cout << "Your number consists of " << counter_of_numbers << " number(s)" << std::endl;
	std::cout << "\tFirst number is " << first_digit << std::endl;

	if (second_digit != -1) {
		std::cout << "\tSecond number is " << second_digit << std::endl;
	}
	return 0;
}