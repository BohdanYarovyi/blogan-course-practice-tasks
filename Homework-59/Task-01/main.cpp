#include <iostream>

/*
 Напишіть функцію, яка приймає рядок і "обертає його". 
 Тобто, щоб результат був такий:
	char string[] = "Hello";
	Reverse(string);
	std::cout << string; // має бути "olleH"
*/

void reverse(char* str);

int main()
{
	char string[] = "Hello World";
	reverse(string);
	std::cout << string << std::endl;

	return 0;
}

template <typename T>
static void swap(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(char* str)
{
	char* end = str;
	while (*end++ != '\0') {}
	int length = end - str - 1;

	for (int i = 0; i < length / 2; i++)
	{
		swap(str + i, str + (length - i - 1));
	}
}