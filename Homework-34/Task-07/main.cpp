#include <iostream>

/*
Виведіть на екран букви англійського алфавіту від букви A до букви Z.
*/

int main() {
	constexpr int number_of_english_letters = 26;
	constexpr int first_english_capital_letter_index = 65;
	constexpr int first_english_small_letter_index = 97;

	for (int i = 0; i < number_of_english_letters; i++) {

		std::cout << "[" << first_english_capital_letter_index + i << "]" << " ";
		std::cout << static_cast<char>(first_english_capital_letter_index + i) << " ";
		std::cout << static_cast<char>(first_english_small_letter_index + i) << " ";
		std::cout << "[" << first_english_small_letter_index + i << "]" << " ";
		std::cout << std::endl;
	}

	//for (int i = 0; i < number_of_english_letters; i++) {
	//	std::cout << static_cast<char>(first_english_small_letter_index + i) << " ";
	//}
	
	return 0;
}