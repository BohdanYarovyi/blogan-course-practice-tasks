#include <iostream>

/*
Комп'ютер загадав число 50. Він постійно питає у вас, яке число він загадав.
Ви постійно вводите число. Якщо число не вірне - виводиться повідомлення "Невірно".
Якщо вірне - виводиться повідомлення "Вірно". Спробуйте написати такий код, який використовує
один цикл while, один оператор if і лише один continue. Ну і звісно можна використовувати будь-яку
кількість cout, cin та створювати будь-яку кількість змінних.
*/

int main() {
	constexpr int SECRET = 50;
	
	int user_number;

	while (true) {
		std::cout << "computer: What number I guesed? ";
		std::cin >> user_number;

		if (user_number != SECRET) {
			std::cout << "The input is wrong. Try again!" << std::endl;
			continue;
		}

		std::cout << "Yes. You guesed the number. It was really " << SECRET << std::endl;
		break;
	}

	return 0;
}