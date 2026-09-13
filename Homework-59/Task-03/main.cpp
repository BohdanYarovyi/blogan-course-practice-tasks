#include <iostream>

/*
Напишіть функцію, яка приймає рядок і повертає кількість букв у ньому.
*/

int get_length(const char* str);

int main()
{
	const char* text = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since 1966, when designers at Letraset and James Mosley, the librarian at St Bride Printing Library in London, took a 1914 Cicero translation and scrambled it to make dummy text for Letraset's Body Type sheets.";
	int length = get_length(text);
	std::cout << length << std::endl;
	return 0;
}

int get_length(const char* str)
{
	if (str == nullptr)
	{
		return 0;
	}

	int i;
	for (i = 0; str[i] != '\0'; i++);

	return i;
}