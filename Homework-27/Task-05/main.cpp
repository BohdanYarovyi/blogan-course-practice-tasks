#include <iostream>

/*
Об'єднайте умови першої і четвертої задач. Тобто число має входити в діапазон [-100...100] і при цьому НЕ дорівнювати числам 2, 5 і 8.
*/

int main() {
	int number;
	std::cout << "Enter a number between [-100 - 100]: ";
	std::cin >> number;

	if (number >= -100 && 
		number <= 100 && 
		number != 2 && 
		number != 5 && 
		number != 8) {
		std::cout << "The number is correct." << std::endl;
	}
	else {
		std::cout << "The number is not correct." << std::endl;
	}

	return 0;
}