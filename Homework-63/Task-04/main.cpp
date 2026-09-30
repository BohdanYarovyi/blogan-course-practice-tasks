#include <cstdio>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>

/*
    Є наступна структура:
    struct String
    {
        char* str = nullptr;
        int size = 0;
    };

    Ця структура містить в собі "розумний" рядок, в якого ви завжди можете дізнатися розмір. str завжди указує на масив на кучі. Напишіть наступні функції:

    void Show(const String& string)
    - виводить рядок на екран. Якщо рядок пустий, то нічого не виводить.

    void EnterString(String& string)
    - дає користувачу ввести рядок з клавіатури (можете скористатися функцією EnterString із попередніх практичних уроків).

    bool IsEmpty(const String& string)
    - повертає true, якщо рядок пустий.

    bool AreTheSame(const String& string1, const String& string2)
    - повертає true, якщо рядки однакові.

    void Concatenate(String& destination, const String& source)
    - дописує до кінця рядка destination рядок source, перевиділяючи пам'ять.

    void Copy(String& destination, const String& source)
    - переписує рядок destination рядком source, перевиділяючи пам'ять.

    void Remove(String& string, char ch)
    void Remove(String& string, const String& substring)
    - перша функція видаляє символ із string (лише один символ, а не всі).
    - друга функція видаляє рядок substring із рядка string (лише один рядок, а не всі входження).

    Перевірте всі функції.
*/

struct String
{
   	char* str = nullptr;
    int size = 0;
};

void show(const String& str);

String* enter_string();

bool is_empty(const String& string);

bool are_same(const String& string_1, const String& string_2);

void concat(String& distination, const String& source);

void copy(String& destination, const String& source);

void remove(String& string, char c);

void remove(String& string, const String& substring);

int main()
{

}

void show(const String& str)
{
	if (str.size == 0)
	{
		return;
	}

	std::cout << str.str;
}

String* enter_string()
{
	String* text = new String;
	text->str = new char[256];
	std::cin.getline(text->str, 256);

	int len = 0;
	while (text->str[len] != '\0')
	{
		text->size = ++len;
	}

	return text;
}

bool is_empty(const String& string)
{
	return string.size == 0;
}

bool are_same(const String& string_1, const String& string_2)
{
	if (string_1.size != string_2.size)
	{
		return false;
	}

	for (int i = 0; i < string_1.size; i++)
	{
		if (string_1.str[i] != string_2.str[i])
		{
			return false;
		}
	}

	return true;
}

void concat(String& destination, const String& source)
{
	int size = destination.size + source.size + 1;
	char* old_str = destination.str;
	destination.str = new char[size];

	for (int i = 0; i < destination.size; i++)
	{
		destination.str[i] = old_str[i];
	}
	for (int i = 0; i < source.size; i++)
	{
		destination.str[destination.size + i] = source.str[i];
	}
	destination.str[size - 1] = '\0';
	destination.size = size;

	delete[] old_str;
}

void copy(String& destination, const String& source)
{
	delete[] destination.str;
	destination.str = new char[source.size + 1];
	destination.size = source.size;

	for (int i = 0; i < source.size; i++)
	{
		destination.str[i] = source.str[i];
	}
	destination.str[source.size + 1] = '\0';
}

void remove(String& string, char c)
{
	bool has_char = false;
	for (int i = 0; i < string.size; i++)
	{
		if (string.str[i] == c)
		{
			has_char = true;
			break;
		}
	}

	if (!has_char)
	{
		return;
	}

	char* new_str = new char[string.size];
	bool skipped = false;
	for (int i = 0; i < string.size; i++)
	{
		if (string.str[i] == c && !skipped)
		{
			skipped = true;
			continue;
		}

		new_str[i - skipped] = string.str[i];
	}
	string.size--;
	new_str[string.size] = '\0';
	delete[] string.str;
	string.str = new_str;
}

void remove(String& string, const String& substring)
{
	int index_of_part = -1;
	// find the first index of entering
	{
		bool is_matching = false;
		for (int i = 0; i < string.size && string.size - i > substring.size; i++)
		{
			if (is_matching)
			{
				for (int k = 0; k < substring.size; k++)
				{
					if (string.str[i + k] != substring.str[k])
					{
						is_matching = false;
						continue;
					}
				}
				index_of_part = i;
			}
			else
			{
				if (string.str[i] == substring.str[0])
				{
					is_matching = true;
					i--;
				}
			}
		}
	}

	if (index_of_part == -1)
	{
		return;
	}

	int new_string_size = string.size - substring.size;
	char* new_string = new char[new_string_size + 1];
	int new_string_index = 0;
	for (int i = 0; i < string.size; i++)
	{
		if (i == index_of_part)
		{
			i += substring.size;
		}

		new_string[new_string_index] = string.str[i];
		new_string_index++;
	}
	new_string[new_string_size] = '\0';
	delete[] string.str;
	string.str = new_string;
	string.size = new_string_size;
}
