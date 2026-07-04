#include <iostream>

/*
Переробіть попередню задачу так, що код складається з трьох символів: '1', '2' та '3'. 
Користувач має ввести 3 символи. 
А далі все те саме, що в попередній задачі.
*/

int main() {
	constexpr char first_symbol	 = '1';
	constexpr char second_symbol = '2';
	constexpr char third_symbol	 = '3';

	char user_input_1;
	char user_input_2;
	char user_input_3;

	std::cout << "Enter a code of a safe that consists of 3 symbols: ";
	std::cin >> user_input_1 >> user_input_2 >> user_input_3;

	if (user_input_1 == first_symbol &&
		user_input_2 == second_symbol &&
		user_input_3 == third_symbol) {
		std::cout << "The doors is open" << std::endl;
	}
	else {
		std::cout << "The code is wrong!" << std::endl;
	}

	return 0;
}