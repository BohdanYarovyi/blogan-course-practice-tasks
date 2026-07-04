#include <iostream>

/*
Користувач вводить 2 числа:
	1. Суму грошей, яка є у нього на рахунку
	2. Суму грошей, яка є на рахунку в його друга
Порахуйте, на скільки сума друга більша за суму користувача і виведіть різницю на екран.
Сума друга обов'язково має бути більшою.
(Використовуйте оператори = та -)
*/

int main() {
	float user_money;
	float friend_money;

	std::cout << "How many money do you have? -> ";
	std::cin >> user_money;
	std::cout << "How many money does your friend have? -> ";
	std::cin >> friend_money;

	float difference = friend_money - user_money;

	std::cout << "You have less money than your friend." << std::endl;
	std::cout << "The difference between you and your friend about $" << difference << "." << std::endl;
	return 0;
}