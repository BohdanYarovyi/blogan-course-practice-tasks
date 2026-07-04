#include <iostream>

/*
Створіть змінну типу unsigned int з іменем currentTimeInHours. Її значення - теперішня година. 
Наприклад у мене зараз 17:08, отже я в неї записую значення 17. 
Виведіть повідомлення:
	Time: (ваша_змінна):00

Після вивиоду повідомлення поміняйте її значення на 18. 
Виведіть повідомлення:
	Time: (ваша_змінна):00
*/

int main() {
	unsigned int currentTimeInHours = 11;
	std::cout << "Time: " << currentTimeInHours << ":00" << std::endl;
	currentTimeInHours = 18;
	std::cout << "Time: " << currentTimeInHours << ":00" << std::endl;
	return 0;
}