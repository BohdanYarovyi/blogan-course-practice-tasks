#include <iostream>

/*
У мене є 3 яблука. У Насті є 10 яблук. У Ігора 7. Скільки яблук всього?
Створіть 4 змінні, де кожна зберігає свою кількість яблук, і ще одну для загальної кількості. 
Виведіть на екран всі ці значення.
*/

int main() {
	int me			= 3;
	int anastasia	= 10;
	int ihor		= 7;
	int total		= me + anastasia + ihor;

	std::cout << "My apples: \t\t" << me << std::endl;
	std::cout << "Anastasia apples: \t" << anastasia << std::endl;
	std::cout << "Ihor apples: \t\t" << ihor << std::endl;
	std::cout << "Total: \t\t\t" << total << std::endl;
	return 0;
}