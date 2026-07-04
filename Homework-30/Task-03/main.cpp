#include <iostream>

/*
Переробіть попередню задачу так, щоб коли користувач вводить 2 (обрав лютий), задайте додаткове питання, чи рік високосний.
Якщо так - виведіть 29 днів. Інакше 28. Для цього вам треба використати if всередині case-мітки.
*/

int main() {
	int month;

	std::cout << "Enter a number of month [1-12]: ";
	std::cin >> month;

	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {
			std::cout << "31 days" << std::endl;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11: {
			std::cout << "30 days" << std::endl;
			break;
		}
		case 2: {
			bool leap_year = false;
			std::cout << "Is it leap year now? (1 - yes, 0 - no): ";
			std::cin >> leap_year;
			std::cout << (leap_year ? "29" : "28") << " days" << std::endl;
			break;
		}
		default: {
			std::cout << "Such month doesn't exist" << std::endl;
		}
	}
	return 0;
}