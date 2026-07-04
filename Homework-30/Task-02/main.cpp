#include <iostream>

/*
Користувач вводить номер місяця. Ваша задача - проаналізувати це число і вивести на екран,
скільки днів в цьому місяці. Є місяці, в яких 30 днів, є місяці, в яких 31 день, а є лютий,
у якого може бути 28 або 29 днів.
Вважайте що в лютому завжди 28 днів.

Намагайтесь уникнути дублювання коду. Виконуйте одну дію для декількох case-міток підряд.
Наприклад так:
	case номер_січня:
	case номер_березня:
		В цьому місяці 31 день.
	І так далі.
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
		case 12:
			std::cout << "31 days" << std::endl;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			std::cout << "30 days" << std::endl;
			break;
		case 2:
			std::cout << "28 days" << std::endl;
			break;
		default:
			std::cout << "Such month doesn't exist" << std::endl;
	}
	return 0;
}