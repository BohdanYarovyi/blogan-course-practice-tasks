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

void enter_text(char* buffer);

char* concatenate(const char* str_1, const char* str_2);

const int CHAR_BUFFER_MAX_SIZE = 256;

int main()
{
	char text_1[CHAR_BUFFER_MAX_SIZE];
	char text_2[CHAR_BUFFER_MAX_SIZE];
	enter_text(text_1);
	enter_text(text_2);
	char* str = concatenate(text_1, text_2);

	std::cout << str << std::endl;

	delete[] str;

	return 0;
}

void enter_text(char* buffer)
{
	std::cout << "Enter text: ";
	std::cin.getline(buffer, CHAR_BUFFER_MAX_SIZE);
}

int get_length(const char* str)
{
	int length = 0;
	while (*(str + length) != '\0')
	{
		length++;
	}

	return length;
}

char* concatenate(const char* str_1, const char* str_2)
{
	const int length_1 = get_length(str_1);
	const int length_2 = get_length(str_2);
	const int length_new = length_1 + length_2 + 1;

	char* str_new = new char[length_new];
	for (int i = 0; i < length_1; i++)
	{
		str_new[i] = str_1[i];
	}
	for (int i = 0; i < length_2; i++)
	{
		str_new[length_1 + i] = str_2[i];
	}
	str_new[length_new - 1] = '\0';

	return str_new;
}
