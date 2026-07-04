#include <iostream>

/*
Представимо що є двері і користувач має ввести код, щоб їх відкрити. Правильний код - 123. 
Користувач вводить код і якщо він правильний - виводиться повідомлення "Двері відкриті". Інакше "Невірний код".
*/

int main() {
	const int CODE = 123;

	int number;

	std::cout << "Enter a code: ";
	std::cin >> number;

	std::cout << (number == CODE ? "The doors have been opened" : "Wrong code") << std::endl;

	return 0;
}