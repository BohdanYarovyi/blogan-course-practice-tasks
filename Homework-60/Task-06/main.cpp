#include <iostream>

/*
Є початковий символьний масив із 256 елементів. Попросіть в користувача ввести в нього текст. Після цього знайдіть довжину цього тексту і створіть динамічний масив, куди скопіюйте всі елементи з вашого масиву (до нуль-символу). 

Скористайтеся наступними функціями:
	`void EnterText(char* buffer)` - дає користувачу ввести текст в указаний масив
	`int Length(const char* str)` - повертає довжину рядка (кількість символів до нуль-символа)
	`char* CreateString(int size)` - створює пустий рядок за указаним розміром (розмір: це довжина + нуль-символ)
	`void Copy(char* destination, const char* source)` - копіює другий рядок в перший

Виведіть на екран обидва масиви, вони мають показувати однаковий текст.
*/

void enter_text(char* buffer);

int get_length(const char* str);

char* create_string(int size);

void copy (char* destination, const char* source);

const int MAX_CHAR_BUFFER_SIZE = 256;

int main()
{
	std::cout << "Hello, could you enter any text pls? >> ";
	char buffer[MAX_CHAR_BUFFER_SIZE] = {};
	enter_text(buffer);

	int input_length = get_length(buffer);
	char* normalized_str = create_string(input_length);
	copy(normalized_str, buffer);

	std::cout << "Buffer: " << buffer << std::endl; 
	std::cout << "Normalized: " << normalized_str << std::endl; 

	delete[] normalized_str;
	return 0;
}

void enter_text(char* buffer)
{
	std::cin.getline(buffer, MAX_CHAR_BUFFER_SIZE);
}

int get_length(const char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	return length + 1;
}

char* create_string(int size)
{
	return new char[size];
}

void copy(char* destination, const char* source)
{
	int index = 0;
	while (source[index] != '\0')
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
}