#include <iostream>

/*
Нехай користувач введе два значення з клавіатури. Запишіть їх в дві змінні. Після цього виведіть на екран їх сумму, але використовуйте лише вказівники на ці змінні.
*/

void get_user_number(int *p_number);

void show(int* number);

int main()
{
	int* p_number1;
	int* p_number2;

	get_user_number(p_number1);
	get_user_number(p_number2);

	show(p_number1);
	show(p_number2);

	return 0;
}

void get_user_number(int *p_number)
{
	int user_number;
	while (true)
	{
		std::cout << ">> ";
		std::cin >> user_number;

		if (user_number <= 0)
		{
			std::cout << "The number must be greater than 0." << std::endl;
			continue;
		}

		break;
	}

	*p_number = user_number;
}

void show(int *number)
{
	std::cout << *number << std::endl;
}
