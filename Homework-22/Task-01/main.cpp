#include <iostream>

/*
Користувач вводить свій вік. 
Виведіть на екран повідомлення "Сьогодні вам (стільки-то) років".
Завдяки інкременту збільшіть змінну. 
Виведіть повідомлення "Через 1 рік вам буде (стільки-то) років".
Завдяки інкременту знову збільшіть змінну.
Виведіть повідомлення "Через 2 роки вам буде (стільки-то) років".
*/

int main() {
	int age;
	std::cout << "Enter your age: ";
	std::cin >> age;

	// today
	std::cout << "Today you are " << age << " years old." << std::endl;

	// in 1 year
	age++;
	std::cout << "In one year you will be " << age << " years old." << std::endl;

	// in 2 year
	age++;
	std::cout << "In two years you will be " << age << " years old." << std::endl;
	return 0;
}