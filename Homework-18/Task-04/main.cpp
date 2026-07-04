#include <iostream>

/*
Користувач вводить наступні дані:
	1. Скільки грошей в нього є
	2. Скільки членів сім'ї у нього є
Він має кожному члену сім'ї дати рівну суму грошей. Виведіть число на екран.
(Використовуються оператори = та /)
*/

int main() {
	float money;
	int family_members;
	
	std::cout << "How much money do you have? -> ";
	std::cin >> money;
	std::cout << "How many members does your family have? -> ";
	std::cin >> family_members;

	float member_money = money / family_members;

	std::cout << "You must split up your money, and give $" << member_money << " to each member of your family." << std::endl;

	return 0;
}