#include <iostream>

/*
Користувач вводить будь-який текст, аж до 256 символів. Наприклад, він може ввести декілька речень. Вважається, що він вводить граматично правильно. Замініть кожну першу літеру кожного слова в тексті такою ж але великою. Наприклад, речення "I am working today" має виглядати так "I Am Working Today".
*/

int main() {
	constexpr int MAX_TEXT_LENGTH = 256;
	constexpr int COMMON_LETTER_ASCII_RANGE_BOT = 97;
	constexpr int COMMON_LETTER_ASCII_RANGE_TOP = 122;


	char text[MAX_TEXT_LENGTH];
	std::cout << "Enter text here: ";
	std::cin.getline(text, MAX_TEXT_LENGTH);

	bool is_prev_was_whitespace = true;
	for (int i = 0; text[i] != '\0'; i++) {
		char c = text[i];

		if (c == ' ') {
			is_prev_was_whitespace = true;
			continue;
		}

		if (c >= COMMON_LETTER_ASCII_RANGE_BOT && c <= COMMON_LETTER_ASCII_RANGE_TOP && is_prev_was_whitespace) {
			text[i] = (char) (text[i] - 32);
		}

		is_prev_was_whitespace = false;
	}

	std::cout << text << std::endl;
	return 0;
}
