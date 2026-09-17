#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Користувач вводить розмір одновимірного масиву. Створіть масив на кучі цього розміру, заповніть його випадковими значеннями і виведіть на екран. Не забудьте видалити масив після роботи з ним.

У вас мають бути наступні функції:
	`int* CreateArray(int size)` - повертає адресу масиву указаного розміру
	`void Inititalize(int* arr, int size)` - заповнює масив випадковими значеннями
	`void Show(const int* arr, int size)` - виводить масив на екран
*/

int* create_array(int size);

void initialize_with_random(int* arr, int size);

void show(const int* arr, int size);

int main()
{
	std::cout << "Hello user. I want to create an array with random numbers." 
		<< " I need just array's size, so could you help me please? Just give me your favorite number: ";
	int size;
	std::cin >> size;

	int* numbers = create_array(size);
	initialize_with_random(numbers, size);
	show(numbers, size);

	delete[] numbers;
	return 0;
}

int* create_array(int size)
{
	return new int[size] {};
}

void initialize_with_random(int* arr, int size)
{
	static bool random_seed_set = false;
	if (!random_seed_set)
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		random_seed_set = true;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = std::rand();
	}
}

void show(const int* arr, int size)
{
	std::cout << "array [";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];

		if (i < size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}