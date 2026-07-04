#include <iostream>

/*
Користувач вводить число від 0 до 99. 
Якщо він введе інше число - виведіть повідомлення "Ви ввели число, яке не входить в заданий діапазон."
Якщо з вводом все добре - виведіть на екран кількість цифр, яка є в числі, яке він ввів. Це може бути 1 або 2.
*/

int main() {
	int number;

	std::cout << "Enter a number between [0 - 99]: ";
	std::cin >> number;

	if (number < 0 || number > 99) {
		std::cout << "The number you have inputed is out of bounds [0 - 99]" << std::endl;
		return 1;
	}

	int counter_of_numbers = 1;
	number /= 10;

	if (number > 0) {
		counter_of_numbers++;
	}

	std::cout << "Your number consists of " << counter_of_numbers << " numbers" << std::endl;
	return 0;
}