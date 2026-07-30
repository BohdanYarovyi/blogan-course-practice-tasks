#include <iostream>

/*
Користувач вводить будь-який текст, аж до 256 символів. Наприклад, він може ввести декілька речень. Вважається, що він вводить граматично правильно. Виведіть на екран кількість слів у його тексті.
*/

int main() {
	constexpr int MAX_TEXT_LENGTH = 256;

	char text[MAX_TEXT_LENGTH];
	int word_count = 0;

	std::cout << "Enter a text (till 256 characters): ";
	std::cin.getline(text, MAX_TEXT_LENGTH);

	bool is_in_center_of_word = false;
	for (int i = 0; text[i] != '\0'; i++) {
		char symbol = text[i];

		switch (symbol) {
			case ' ':
			case '-':
			case '+':
			case ',':
			case '.':
			case '<':
			case '>':
			case '\"':
		    case '\t': {
			    is_in_center_of_word = false;
			    break;
		    }
		    default: {
			    if (!is_in_center_of_word) {
				    is_in_center_of_word = true;
				    word_count++;
			    }
		    }
		}
	}

	std::cout << "Your text contains " << word_count << " word(s)." << std::endl;

	return 0;
}
