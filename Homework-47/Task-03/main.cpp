#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Напишіть 3 вбудовані функції:
  int max_of_2(int a, int b) - повертає максимальне з двох значень. Використовуйте тернарний оператор.
  int max_of_3(int a, int b, int c) - повертає максимальне з трьох значень. Використовуйте if.
  int max_of_4(int a, int b, int c, int d) - повертає максимальне з чотирьох значень. Використовуйте функцію max_of_2.
*/

void set_random_seed();

int get_random_number(int from, int to);

int max_of_2(int a, int b);

int max_of_3(int a, int b, int c);

int max_of_4(int a, int b, int c, int d);

int main()
{
	int number_min = -100;
	int number_max = 100;
	set_random_seed();

	int a = get_random_number(number_min, number_max);
	int b = get_random_number(number_min, number_max);
	int c = get_random_number(number_min, number_max);
	int d = get_random_number(number_min, number_max);

	std::cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << "\n";
	std::cout << "Max of 2(a, b): " << max_of_2(a, b) << "\n";
	std::cout << "Max of 3(a, b, c): " << max_of_3(a, b, c) << "\n";
	std::cout << "Max of 4(a, b, c, d): " << max_of_4(a, b, c, d) << "\n";

	return 0;
}

inline int max_of_2(int a, int b)
{
	return a > b ? a : b;
}

inline int max_of_3(int a, int b, int c)
{
	if (a >= b)
	{
		return a >= c ? a : c;
	}
	else
	{
		return b > c ? b : c;
	}
}

int max_of_4(int a, int b, int c, int d)
{
	int ab_greatest = max_of_2(a, b);
	int cd_greatest = max_of_2(c, d);

	return ab_greatest > cd_greatest ? ab_greatest : cd_greatest;
}

void set_random_seed()
{
	std::srand(std::time(nullptr));
}

int get_random_number(int from, int to)
{
	return std::rand() % (to - from) + from;
}
