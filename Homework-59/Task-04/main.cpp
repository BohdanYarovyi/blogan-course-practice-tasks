#include <iostream>

/*
Напишіть функцію, яка приймає рядок і повертає кількість цифр в ньому.
*/

int count_digit(const char* str);

int main()
{
	const char* string = "In 2023, the company reported 47 new offices across 12 countries, employing over 3800 people. Revenue grew by 15 percent, reaching $92 million by the end of Q3. The team also launched 6 products and filed 21 patents that year.";
	int digits = count_digit(string);
	std::cout << digits << std::endl;
	return 0;
}

int count_digit(const char* str)
{
	int counter = 0;
	while (*str++ != '\0')
	{
		if (*str >= 48 && *str <= 57)
		{
			counter++;
		}
	}

	return counter;
}