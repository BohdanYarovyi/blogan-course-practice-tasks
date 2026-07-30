#include <iostream>

/*
Створіть масив із 100 символів. Попросіть в користувача ввести в нього речення (тобто використовуйте cin.getline). Виведіть на екран обернену версію цього рядка. Наприклад, якщо користувач введе "Hello world", то має вивестися "dlroW olleH".
*/

int main() {
	constexpr int MAX_SENTENCE_LENGTH = 100;

	char user_sentence[MAX_SENTENCE_LENGTH];

	std::cout << "Hello user! Please, input some sentence (max 100 characters), and I will reverse it."
	          << std::endl;
	std::cout << "sentence: ";
	std::cin.getline(user_sentence, MAX_SENTENCE_LENGTH);

	char c;
	int sentence_length = 0;
	while (true) {
		c = user_sentence[sentence_length];
		if (c == '\0') {
			break;
		}

		sentence_length++;
	}

	for (int i = 0; i < sentence_length / 2; i++) {
		int tail = sentence_length - i - 1;

		char temp = user_sentence[tail];
		user_sentence[tail] = user_sentence[i];
		user_sentence[i] = temp;
	}

	std::cout << "Reversed user input: " << user_sentence << std::endl;
	return 0;
}
