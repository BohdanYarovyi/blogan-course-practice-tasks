#include <iostream>

/*
Переробіть попередню задачу так, щоб не треба було питати в користувача, чи високосний рік.
Замість цього краще одразу запитайте в користувача, який зараз рік, а потім запитайте, який місяць його цікавить.
А в case-мітці Лютого місяця  використайте оператор if і формулу визначення високосного року. Формулу загугліть.
*/

int main() {
	int year;
	int month;

	std::cout << "Enter a current year and number of month (yyyy mm): ";
	std::cin >> year >> month;

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
			std::cout << ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28) << " days" << std::endl;
			break;
		}
		default: {
			std::cout << "Such month doesn't exist" << std::endl;
		}
	}

	return 0;
}