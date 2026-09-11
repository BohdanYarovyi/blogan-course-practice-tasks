#include <iostream>

/*
Є наступні дані:
    int a = 10;
    double b = 23.5;
    char c = 'G';
    const long d = 20L;

Створіть вказівники на ці дані і виведіть їх значення на екран через ці вказівники.
*/

int main()
{
	int a = 10;
	double b = 23.5;
	char c = 'G';
	const long d = 20L;

	int *p_a = &a;
	double *p_b = &b;
	char *p_c = &c;
	const long *p_d = &d;

	std::cout << "p_a = " << p_a << std::endl;
	std::cout << "*p_a = " << *p_a << std::endl;

	std::cout << "p_b = " << p_b << std::endl;
	std::cout << "*p_b = " << *p_b << std::endl;

	std::cout << "p_c = " << static_cast<void*>(p_c) << std::endl;
	std::cout << "*p_c = " << *p_c << std::endl;

	std::cout << "p_d = " << p_d << std::endl;
	std::cout << "*p_d = " << *p_d << std::endl;
	return 0;
}
