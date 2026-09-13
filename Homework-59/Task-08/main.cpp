#include <iostream>

/*
Напишіть функцію, яка приймає рядок і видаляє в ньому всі входження указаного символу. 
Тобто результат має виглядати ось так:
	char string[] = "Hello World";
	Remove(string, 'l');
	std::cout << string; // має бути "Heo Word"
*/

void remove(char* str, const char delete_char);

int main()
{
	char string[] = "Hello World";
	remove(string, 'l');
	std::cout << string;
	return 0;
}

void remove(char* str, const char char_to_remove)
{
	int length = 0;
	while (*(str + length) != '\0')
	{
		length++;
	}

	int deleted_chars = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(str + i) == char_to_remove)
		{
			deleted_chars++;
		}
		else
		{
			*(str + i - deleted_chars) = *(str + i);
		}
	}
	*(str + length - deleted_chars) = '\0';
}
