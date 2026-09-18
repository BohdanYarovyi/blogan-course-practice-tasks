#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Користувач вводить розміри двовимірного масиву.
Напишіть і перевірте наступні функції:
	`void Initialize(int** arr, int rows, int columns)` - заповнює масив випадковими значеннями
	`void Show(const int* const* arr, int rows, int columns)` - виводить масив на екран
*/

void initialize(int** arr, int rows, int columns);

void show(const int* const* arr, int rows, int columns);

int main()
{
	int rows;
	int columns;

	std::cout << "rows: ";
	std::cin >> rows;
	std::cout << "columns: ";
	std::cin >> columns;

	int** array = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[columns]{0};
	}

	show(array, rows, columns);
	initialize(array, rows, columns);
	show(array, rows, columns);

	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	return 0;
}

void initialize(int** arr, int rows, int columns)
{
	static bool is_random_seed_set = false;
	if (!is_random_seed_set)
	{
		is_random_seed_set = true;
		unsigned int timestamp = static_cast<unsigned int>(std::time(nullptr));
		std::srand(timestamp);
	}

	for (int i = 0; i < rows; i++) {
		int* row = arr[i];
		for (int k = 0; k < columns; k++) {
			row[k] = std::rand();
		}
	}
}

void show(const int* const* arr, int rows, int columns)
{
	std::cout << "Array: [\n";
	for (int i = 0; i < rows; i++)
	{
		std::cout << "  [";
		for (int k = 0; k < columns; k++)
		{
			std::cout << *(*(arr + i) + k);

			if (k < columns - 1)
			{
				std::cout << ", ";
			}
		}

		std::cout << "]";
		if (i < rows - 1)
		{
			std::cout << ",";
		}
		std::cout << "\n";
	}
	std::cout << "]\n";
}
