#include <iostream>
#include <cstdlib>
#include <ctime>

/*
	Користувач вводить кількість випадкових чисел, які він хоче побачити.
	Після цього він вводить діапазон, в якому хоче, щоб ці випадкові числа були.

	Виведіть на екран ці числа. Врахуйте всі можливі помилки. Наприклад він може
	ввести від'ємну кількість, або він може спочатку ввести максимальне значення, а
	потім мінімальне в діапазоні.
*/

const int RAND_RANGE_MIN = -RAND_MAX / 2;
const int RAND_RANGE_MAX = RAND_MAX / 2;

void set_random_seed();
int get_random(int from, int to);
int get_user_count();
int get_bot_bound();
int get_top_bound();

int main()
{
	int count = get_user_count();
	if (count == 0)
	{
		return 1;
	}

	int from = get_bot_bound();
	int to = get_top_bound();

	for (int i = 0; i < count; i++)
	{
		std::cout << i + 1 << ".\t" << get_random(from, to) << std::endl;
	}
	return 0;
}

void set_random_seed()
{
	std::srand(std::time(nullptr));
}

int get_random(int from, int to)
{
	return std::rand() % (to - from) + from;
}

int get_user_count()
{
	std::cout << "What count of random numbers you want to get? " << std::endl;
	std::cout << ">> ";
	int count;
	std::cin >> count;

	if (count <= 0)
	{
		std::cout << "The count of random numbers must be at least 1" << std::endl;
		return 0;
	}

	return count;
}

int get_bot_bound()
{
	std::cout << "Enter a bottom bound of random numbers: ";
	int bound;
	std::cin >> bound;

	if (bound < RAND_RANGE_MIN || bound > RAND_RANGE_MAX)
	{
		std::cout << "Inserted bound is not in bounds. There was set default MINIMUM value: "
		    << RAND_RANGE_MIN << std::endl;
		return RAND_RANGE_MIN;
	}

	return bound;
}

int get_top_bound()
{
	std::cout << "Enter a top bound of random numbers: ";
	int bound;
	std::cin >> bound;

	if (bound < RAND_RANGE_MIN || bound > RAND_RANGE_MAX)
	{
		std::cout << "Inserted bound is not in bounds. There was set default MAXIMUM value: "
		    << RAND_RANGE_MAX << std::endl;
		return RAND_RANGE_MAX;
	}

	return bound;
}
