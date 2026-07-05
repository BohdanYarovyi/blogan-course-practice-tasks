#include <iostream>

/*
Користувач вводить діапазон з двох чисел. Перше число ОБОВ'ЯЗКОВО має бути меншим за друге.
Наприклад перше - 1, друге - 100. Якщо користувач порушує цю умову - поясніть йому,
в чому проблема і дайте ввести знову.

Підказка: перше число вводиться без циклу, друге завдяки циклу do while.

Далі користувач має ввести ще 2 числа, які мають ОБОВ'ЯЗКОВО знаходитись в цьому діапазоні.
Наприклад якщо він ввів 1 і 100, то інші два числа можуть бути 5 і 20. Якщо він введе
якесь число, яке НЕ ВХОДИТЬ в діапазон з двох перших чисел (в моєму прикладі якщо одне
з двох чисел менше за 1 або більше за 100) - поясніть проблему і дайте ввести знову.
При цьому четверте число має бути ОБОВ'ЯЗКОВО НЕ меншим за перше.
*/

int main() {
	int first_number;
	int second_number;
	int third_number;
	int fourth_number;
	bool valid_input;

	std::cout << "Enter a number: ";
	std::cin >> first_number;

	valid_input = false;
	do {
		std::cout << "Enter a second number greater than first one (" << first_number << "): ";
		std::cin >> second_number;

		if (second_number > first_number) {
			valid_input = true;
		}
		else {
			std::cout << "Wrong input. The number must be greater than first number." << std::endl;
		}
	} while (!valid_input);

	valid_input = false;
	do {
		std::cout << "Enter a third number that is between of first and second numbers ("
				<< first_number << " < x < " << second_number << "): ";
		std::cin >> third_number;

		if (third_number > first_number && third_number < second_number) {
			valid_input = true;
		}
		else {
			std::cout << "Wrong input. The number must be between of first and second numbers." << std::endl;
		}
	} while (!valid_input);

	valid_input = false;
	do {
		std::cout << "Enter a fourth number that is between of first and second numbers and greater than third one ("
			<< first_number << " < "<< third_number << " < x < " << second_number << "): ";
		std::cin >> fourth_number;

		if (fourth_number > third_number && fourth_number < second_number) {
			valid_input = true;
		}
		else {
			std::cout << "Wrong input. The number must be between of first and second " 
					<< "numbers and greater than third one." << std::endl;
		}
	} while (!valid_input);

	std::cout << "Numbers: " << first_number << " < " << third_number << " < " << fourth_number << " < " << second_number << std::endl;

	return 0;
}