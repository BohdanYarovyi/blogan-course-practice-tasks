#include <iostream>

/*
Користувач вводить число. Виведіть на екран кількість цифр цього числа.
*/

int main() {
	int user_number;
	
	std::cout << "Enter a number: ";
	std::cin >> user_number;

	int counter = 0;
	for (int i = user_number; i != 0;) {
		if (i / 10 != 0 || i % 10 != 0) {
			counter++;
		}
		
		i = i / 10;
	}

	std::cout << "The entered number " << user_number << " has " << counter << " digits" << std::endl; 

	return 0;
}