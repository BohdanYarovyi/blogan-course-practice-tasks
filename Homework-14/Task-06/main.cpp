#include <iostream>

/*
Користувач вводить 2-цифрове додатнє число. Виведіть на екран цифри цього числа.
*/

int main() {
	int number;
	std::cout << "I need 2-digit number. Give me some: ";
	std::cin >> number;
	
	std::cout << "First digit is " << number / 10 << std::endl;
	std::cout << "Second digit is " << number % 10 << std::endl;
	std::cout << "Am I right?" << std::endl;
	return 0;
}