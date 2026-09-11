#include <iostream>

/*
Ви можете порівнювати адреси даних в C++.
Є наступний код:
    int a = 10;
    int* p = &a;

Перевірте, чи p == &a.
*/

int main()
{
	int a = 10;
	int *p_a = &a;

	std::cout << "p_a == &a ? " << (p_a == &a) << std::endl;
	return 0;
}
