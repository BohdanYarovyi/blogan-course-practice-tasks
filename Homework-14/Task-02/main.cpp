#include <iostream>

/*
Користувач вводить з клавіатури 2 дробових числа. Виведіть на екран їх суму.
*/

int main() {
	float number1;
	float number2;

	std::cout << "You must enter two float number splitted with whitespace: ";
	std::cin >> number1 >> number2;

	std::cout << "Sum of your number is " << number1 + number2 << std::endl;
	return 0;
}