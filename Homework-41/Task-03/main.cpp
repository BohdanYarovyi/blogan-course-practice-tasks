#include <iostream>

/*
Напишіть програму, яка створює чотирьохвимірний масив типу char розмірами 2 на 3 на 4 на 5.
Завдяки циклам ініціалізуйте всі значення масиву символами, починаючи з англійської букви 'a'. 
Тобто в масиві перший елемент має мати значення 'a', другий 'b', третій 'c' і так далі.
Виведіть цей масив на екран в рядок в наступному вигляді:
'a' 'b' 'c' 'd' ...
*/

int main() {
	constexpr int FIRST_DIMENSION_ARRAY_SIZE = 2;
	constexpr int SECOND_DIMENSION_ARRAY_SIZE = 3;
	constexpr int THIRD_DIMENSION_ARRAY_SIZE = 4;
	constexpr int FORTH_DIMENSION_ARRAY_SIZE = 5;
	constexpr int ENGLISH_ALPHABET_SIZE = 26;
	constexpr char ASCCI_NUMBER_OF_FIRST_ENGLISH_ALPHABET_LETTER = 97;
		
	char letters[FIRST_DIMENSION_ARRAY_SIZE][SECOND_DIMENSION_ARRAY_SIZE][THIRD_DIMENSION_ARRAY_SIZE][FORTH_DIMENSION_ARRAY_SIZE];

	int current_letter = 0;
	for (int i1 = 0; i1 < FIRST_DIMENSION_ARRAY_SIZE; i1++) {
		for (int i2 = 0; i2 < SECOND_DIMENSION_ARRAY_SIZE; i2++) {
			for (int i3 = 0; i3 < THIRD_DIMENSION_ARRAY_SIZE; i3++) {
				for (int i4 = 0; i4 < FORTH_DIMENSION_ARRAY_SIZE; i4++) {
					letters[i1][i2][i3][i4] = ASCCI_NUMBER_OF_FIRST_ENGLISH_ALPHABET_LETTER + current_letter;
					current_letter++;

					if (current_letter == ENGLISH_ALPHABET_SIZE) {
						current_letter = 0;
					}
				}
			}
		}
	}

	for (int i1 = 0; i1 < FIRST_DIMENSION_ARRAY_SIZE; i1++) {
		for (int i2 = 0; i2 < SECOND_DIMENSION_ARRAY_SIZE; i2++) {
			for (int i3 = 0; i3 < THIRD_DIMENSION_ARRAY_SIZE; i3++) {
				for (int i4 = 0; i4 < FORTH_DIMENSION_ARRAY_SIZE; i4++) {
					std::cout << "letters[" << i1 << "][" << i2 << "][" << i3 << "][" << i4 << "] = "
					<< letters[i1][i2][i3][i4] << std::endl;
				}
			}
		}
	}
	return 0;
}