#include <iostream>

/*
Користувач вводить скільки грошей він отримав за місяць, а потім скільки з них він витратив.
Виведіть на екран решту.
*/

int main() {
	float salary;
	float consumption;

	std::cout << "Enter your monthly salary: ";
	std::cin >> salary;
	std::cout << "Do you spend a lot of your money per month?" << std::endl;
	std::cout << "Let's count how much you save every month. Enter monthly consumption: ";
	std::cin >> consumption;
	std::cout << salary << " - " << consumption << " = " << salary - consumption << std::endl;
	
	return 0;
}