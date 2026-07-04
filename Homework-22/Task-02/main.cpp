#include <iostream>

/*
Спробуйте виконати попередню задачу так, щоб інкремент використовувався 
в середині виразу std::cout.
*/

int main() {
	int age;
	std::cout << "Enter your age: ";
	std::cin >> age;

	// today
	std::cout << "Today you are " << age << " years old." << std::endl;

	// in 1 year
	std::cout << "In one year you will be " << age++ << " years old." << std::endl;

	// in 2 year
	std::cout << "In two years you will be " << age++ << " years old." << std::endl;
	return 0;
}