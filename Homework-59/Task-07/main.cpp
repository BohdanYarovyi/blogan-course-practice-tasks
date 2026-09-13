#include <iostream>

/*
Напишіть функцію, яка приймає два рядка і перевіряє, чи вони мають однакові символи.
*/

bool is_equal(const char* str1, const char* str2);

int main()
{
	const char* str1 = "Hello";
	const char* str2 = "Hello";
	bool is_equal_rows = is_equal(str1, str2);
	std::cout << "Str1 and str2 is: " << is_equal_rows << std::endl;
	return 0;
}

bool is_equal(const char* str1, const char* str2)
{
	while (true)
	{
		if (*str1 == '\0' || *str2 == '\0')
		{
			return *str1 == *str2;
		}
		
		if (*str1 != *str2)
		{
			return false;
		}

		str1++;
		str2++;
	}
}
