#include <iostream>

/*
Попросіть користувача ввести любий символ. Після того, як він його ввів,
попросіть ввести кількість стовпчиків і кількість рядків. Користувач обов'язково
має ввести числа, які більші за 0. Тобто завдяки циклам do while напишіть алгоритми
вводу, з яких програма не вийде, поки не буде введене додатнє число.

Після цього виведіть на екран відповідний прямокутник із вказаним користувачем символів.

Наприклад користувач вводить символ "А", а потім числа "3" (рядки) і "5" (стовпчиків).
Вивід буде наступним:
	ААААА
	ААААА
	ААААА
*/

int main() {
	constexpr int FIRST_ASCII_SYMBOL_TO_USE = 33;
	constexpr int LAST_ASCII_SYMBOL_TO_USE  = 126;

	int rows;
	int columns;
	char symbol;

	// input symbol
	bool is_symbol_valid = false;
	std::cout << "Enter a symbol to draw a rectangle: ";
	do {
		std::cin >> symbol;

		if (symbol > FIRST_ASCII_SYMBOL_TO_USE && symbol < LAST_ASCII_SYMBOL_TO_USE) {
			is_symbol_valid = true;
		}
		else {
			std::cout << "Uncorrect input: The symbol to draw must be in range of " 
			<< FIRST_ASCII_SYMBOL_TO_USE << " - " << LAST_ASCII_SYMBOL_TO_USE << " in ASCCI" << std::endl;
			std::cout << "Try again: ";
		}
	} while (!is_symbol_valid);

	// input size
	bool is_size_valid = false;
	std::cout << "Enter a number of columns and rows (<columns> <rows>): ";
	do {
		std::cin >> columns >> rows;

		if (columns > 0 && rows > 0) {
			is_size_valid = true;
		}
		else {
			std::cout << "Uncorrect input: Size of rows and columns must be greater than 0." << std::endl;
			std::cout << "Try again: ";
		}
	} while (!is_size_valid);

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			std::cout << symbol;
		}

		std::cout << std::endl;
	}

	return 0;
}