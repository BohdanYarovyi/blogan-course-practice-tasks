#include <iostream>

/*
Напишіть функцію, яка приймає рядок і символ, який треба найти в ньому. Вона повертає кількість символів, які є в цьому рядку. 
Тобто, щоб результат був такий:
	const char string[] = "Hello World";
	int countL = CountChars(string, 'l');
	std::cout << countL; // має бути 3
*/

int count_chars(const char arr[], char a);

int main()
{
	const char string[] = "Hello World";
	int countL = count_chars(string, 'l');
	std::cout << countL; // має бути 3
	return 0;
}

int count_chars(const char* arr, char a)
{
	int count = {};
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == a) 
		{
			count++;
		}
	}

	return count;
}