#include <iostream>

/*
Користувач вводить з клавіатури свій вік. Виведіть на екран, скільки йому буде через 10 років.
*/

int main() {
	int age;

	std::cout << "Do you want to find out how old you will be in 10 years?" << std::endl;
	std::cout << "Just let me know your age: ";
	std::cin >> age;
	std::cout << "In 10 years you will be " << age + 10 << " years old." << std::endl;
	std::cout << "Don't waste your time. Enjoy life!" << std::endl;

	return 0;
}