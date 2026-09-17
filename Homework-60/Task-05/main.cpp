#include <iostream>

/*
Попрацюємо з динамічними рядками. У вас є два символьні масиви на стеку розмірами 256. Попросіть в користувача двічі ввести якийсь текст. Перший запишіть в перший масив, другий в другий. 

Скористайтеся наступними функціями:
	`void EnterText(char* buffer)` - дає користувачу ввести текст в указаний масив
	`char* Concatenate(const char* string1, const char* string2)` - об'єднує два рядка в третій і повертає адресу на нього

Функція має працювати так, щоб ось цей код працював:
	// Допустимо, що string1 = "Hello", string2 = "World".
	char* temp = Concatenate(string1, " ");     // temp = "Hello "
	char* result = Concatenate(temp, string2); // result = "Hello World"
	delete[] temp;
	std::cout << result; // "Hello World"
*/

int main()
{

	return 0;
}