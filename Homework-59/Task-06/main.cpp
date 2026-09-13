#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Є масив чисел розміром 10 на 10. 
Напишіть для нього наступні функції:
	Initialize - заповнює масив випадковими значеннями
	Show       - виводить масив на екран
	Sum        - повертає суму всіх елементів масиву
*/

namespace Random
{
	
	int get_random_number(const int min = 0, const int max = 100);

	int get_random_number(const int min, const int max)
	{
		static bool seeded = false;
		if (!seeded)
		{
			std::srand(std::time(nullptr));
			seeded = true;
		}

		return std::rand() % (max - min + 1) + min;
	}

}

const int ROWS = 10;

const int COLUMNS = 10;

void initialize(int (*array)[COLUMNS]);

void show(const int (*array)[COLUMNS]);

int sum(const int (*array)[COLUMNS]);

int main()
{
	int array[ROWS][COLUMNS];
	initialize(array);
	show(array);
	int a = sum(array);

	std::cout << "Sum of elements: " << a << std::endl;
	return 0;
}

void initialize(int (*array)[COLUMNS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int k = 0; k < COLUMNS; k++)
		{
			array[i][k] = Random::get_random_number();
		}
	}
}

void show(const int(*array)[COLUMNS])
{
	std::cout << "numbers [";
	for (int i = 0; i < ROWS; i++)
	{
		std::cout << "(" << i << ")[";
		for (int k = 0; k < COLUMNS; k++)
		{
			std::cout << array[i][k];

			if (k < COLUMNS - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]";

		if (i < ROWS - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}

int sum(const int(*array)[COLUMNS])
{
	int sum = 0;

	for (int i = 0; i < ROWS; i++)
	{
		for (int k = 0; k < COLUMNS; k++)
		{
			sum += *(*(array + i) + k);	// explicit access to the element
		}
	}
	return sum;
}
