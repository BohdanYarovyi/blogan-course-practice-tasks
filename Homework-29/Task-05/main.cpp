#include <iostream>

/*
Користувач має ввести число від 0 до 99. Якщо він введе інше число - виведіть повідомлення "Ви ввели число,
яке не входить в заданий діапазон". Якщо з вводом все добре - виведіть на екран кількість цифр, 
яка є в числі що ввів користучач. Це може бути або 1 або 2.
*/

int main() {
	const int LOWER_BORDER = 0;
	const int UPPER_BORDER = 99;
	int number;
	
	std::cout << "Enter a number in range [" << UPPER_BORDER << " - " << LOWER_BORDER << "]: ";
	std::cin >> number;

	if (number < LOWER_BORDER || number > UPPER_BORDER) {
		std::cout << "The number is out of range" << std::endl;
		return 1;
	}

	std::cout << (number / 10 > 0 ? 2 : 1) << std::endl;

	return 0;
}