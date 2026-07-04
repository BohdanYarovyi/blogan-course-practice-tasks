#include <iostream>

/*
Виведіть на екран 2 рядки:
	
	\n - new line
	\t - tab

Використовуючи 2 std::cout i 2 RAW-рядка
*/

int main() {
	std::cout << R"(\n - new line)" << std::endl;
	std::cout << R"(\t - tab)" << std::endl;

	return 0;
}