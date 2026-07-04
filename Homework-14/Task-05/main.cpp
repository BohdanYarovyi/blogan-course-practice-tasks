#include <iostream>

/*
Користувач з клавіатури вводить свій вік. Виведіть на екран, скільки це в секундах.
*/


int main() {
	const int DAYS_IN_YEAR = 365;
	const int HOURS_IN_DAY = 24;
	const int SECONDS_IN_HOUR = 3600;
	int age;
	std::cout << "Do you want to know your age in seconds?" << std::endl;
	std::cout << "How old are you? ";
	std::cin >> age;
	std::cout << "You already are living in this university about " << age * DAYS_IN_YEAR * HOURS_IN_DAY * SECONDS_IN_HOUR << " seconds." << std::endl;
	return 0;
}