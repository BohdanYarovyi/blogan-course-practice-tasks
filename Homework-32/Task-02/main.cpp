#include <iostream>

/*
Задача: вивести числа від 0 до того, яке ввів користувач.
Тобто спочатку попросіть в користувача ввести число,
ЯКЕ БІЛЬШЕ ЗА 0. Якщо він введе 0, або від'ємне - виведіть
повідомлення "Неправильне число". Якщо введе правильне - запускайте
цикл і виводьте числа від 0 до його числа (включно).
*/

int main() {
	int number;
	
	std::cout << "Enter an upper bound: ";
	std::cin >> number;

	if (number < 1) {
		std::cout << "Inputed number is wrong" << std::endl;
		return 1;
	}

	int i = 0;
	while (i <= number) {
		std::cout << i++ << std::endl;
	}

	return 0;
}