#include <iostream>

/*
Уявімо що є двері і користувач має ввести код, щоб їх відкрити. Правильний код - 123.
Користувач вводить код:
	- якщо він правильний - виводиться повідомлення "Двері відкриті". 
	- якщо ні - "Не вірний код".
*/

int main() {
	constexpr int code = 123;
	int userInput;

	std::cout << "Enter a code of a safe: ";
	std::cin >> userInput;

	if (code == userInput) {
		std::cout << "The doors is open" << std::endl;
	}
	else {
		std::cout << "The code is wrong!" << std::endl;
	}

	return 0;
}