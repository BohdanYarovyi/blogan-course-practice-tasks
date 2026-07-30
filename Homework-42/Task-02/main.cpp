#include <iostream>

/*
Створіть масив із 100 символів. Його вміст вводить користувач. Користувач може ввести декілька слів (тобто використовуйте cin.getline). Виведіть на екран довжину цього рядка (не розмір). Довжина - це індекс нуль-символа.
*/

int main() {
	constexpr int TEXT_SIZE = 100;

	char text[TEXT_SIZE];

	std::cout << "Hello User. I have been waiting for you so long. Please, tell me a Joke =)" << std::endl;
	std::cout << "Joke: ";
	std::cin.getline(text, TEXT_SIZE);

	int text_length = 0;
	while (true) {
		char c = text[text_length];
		if (c == '\0') {
			break;
		}

		text_length++;
	}

	std::cout << "The user's text length is " << text_length << std::endl;

	return 0;
}
