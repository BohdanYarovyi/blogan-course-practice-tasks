#include <iostream>

/*
Є змінна int a = 10. Створіть на неї КОНСТАНТНИЙ вказівник. А також створіть ЗМІННИЙ вказівник на цей вказівник. Спробуйте через нього вивести значення a.
*/

int main()
{
	int a = 10;

	int* const p_a = &a;
	int* const* pp_a = &p_a;

	std::cout << **pp_a << std::endl;

	return 0;
}
