#include <iostream>

/*
Створіть масив типу char з іменем alphabet розміром 26. Це масив має містити в собі всі букви англійського алфавіту.
Завдяки циклу for заповніть його буквами від A до Z. Ви можете створити змінну, яка буде спочатку рівна A,
а в кожній ітерації дійде до останньої букви. Після заповнення виведіть через інший цикл for усі елементи масиву
на екран в один рядок без проміжку. 
Вивід має бути ось такий:
	All letters from English alphabet: ABCDEFG...XYZ
*/

int main() {
	constexpr int ENGLISH_ALPHABET_SIZE = 26;
	constexpr char FIRST_ENGLISH_ALPHABET_LETTER = 'A';

	char alphabet[ENGLISH_ALPHABET_SIZE];

	for (int i = 0; i < ENGLISH_ALPHABET_SIZE; i++) {
		alphabet[i] = FIRST_ENGLISH_ALPHABET_LETTER + i;
	}
	
	std::cout << "All letters from English alphabet: ";
	for (int i = 0; i < ENGLISH_ALPHABET_SIZE; i++) {
		std::cout << alphabet[i];
	}

	return 0;
}