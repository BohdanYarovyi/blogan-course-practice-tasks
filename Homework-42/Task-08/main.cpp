#include <iostream>

/*
Користувач вводить речення. Перевірте, чи це паліндром (чи речення читається однаково зліва направо і справа наліво). Наприклад, речення "abc de ed cba" є паліндромом.
*/

int main() {
	constexpr int SENTENCE_MAX_LENGTH = 10;

	char sentence[SENTENCE_MAX_LENGTH];
	bool is_palindrome = true;
	std::cout << "Please, enter a palindrome: ";
	std::cin.getline(sentence, SENTENCE_MAX_LENGTH);

	int nominal_length;
	for (nominal_length = 0; sentence[nominal_length] != '\0'; nominal_length++) {
	}

	if (!nominal_length) {
		std::cout << "Your sentence is empty." << std::endl;
		return 1;
	}

	for (int i = 0; i < nominal_length / 2; i++) {
		char head = sentence[i];
		char tail = sentence[nominal_length - i - 1];

		if (head != tail) {
			is_palindrome = false;
			break;
		}
	}

	if (is_palindrome) {
		std::cout << "Your sentence is palindrome!" << std::endl;
	}
	else {
		std::cout << "Your sentence is not palindrome" << std::endl;
	}

	return 0;
}
