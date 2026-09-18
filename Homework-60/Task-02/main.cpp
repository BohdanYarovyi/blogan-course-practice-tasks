#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Користувач вводить розмір двох масивів. Створіть ці масиви на кучі, заповніть їх випадковими значеннями, після чого створіть на кучі третій масив, розмір якого - це сума розмірів двох інших масивів. Після цього заповніть його значеннями цих двох масивів і виведіть на екран всі 3 масиви. Не забудьте видалити масиви після роботи з ними.

У вас мають бути наступні функції:
	`int EnterSize()` - дає користувачу ввести розмір і перевіряє, щоб він не ввів значення 0 і менше
	`int* CreateArray(int size)` - створює масив указаного розміру і повертає його
	`void Inititalize(int* arr, int size)` - заповнює масив випадковими значеннями
	`void Show(const int* arr, int size)` - виводить масив на екран
	`void Delete(int* arr)` - видаляє масив
	`int* CreateConcatenatedArray(const int* arr1, int size1, const int* arr2, int size2, int* concatenatedSize)` - функція створює цей третій масив, повертаючи його адресу і записуючи його розмір в останній параметр
*/

int enter_size();

int* create_array(int size);

void initialize(int* arr, int size);

void show(const int* arr, int size);

void delete_array(int* arr);

int* create_concatenated_array(const int* arr_1, int size_1, const int* arr_2, int size_2, int* concatenated_size);

int main()
{
	int size_1 = enter_size();
	int size_2 = enter_size();
	int* array_1 = create_array(size_1);
	int* array_2 = create_array(size_2);
	initialize(array_1, size_1);
	initialize(array_2, size_2);
	int concatenated_size = {};
	int* concatenated = create_concatenated_array(array_1, size_1, array_2, size_2, &concatenated_size);

	show(array_1, size_1);
	show(array_2, size_2);
	show(concatenated, concatenated_size);

	delete_array(array_1);
	delete_array(array_2);
	delete_array(concatenated);

	return 0;
}

int enter_size()
{
	std::cout << "Give the size of an array: ";
	int size;
	while (true)
	{
		std::cin >> size;

		if (size > 0)
		{
			break;
		}
		else
		{
			std::cout << "Error: Size must be greater than 0.\n";
			std::cout << "One more try: ";
		}
	}

	return size;
}

int* create_array(int size)
{
	return new int[size]{};
}

void initialize(int* arr, int size)
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

void delete_array(int* arr)
{
	delete[] arr;
}

int* create_concatenated_array(const int* arr_1, int size_1, const int* arr_2, int size_2, int* concatenated_size)
{
	*concatenated_size = size_1 + size_2;
	int* concatenated = new int[*concatenated_size];
	int index = 0;

	for (int i = 0; i < size_1; i++, index++)
	{
		concatenated[index] = arr_1[i];
	}

	for (int i = 0; i < size_2; i++, index++)
	{
		concatenated[index] = arr_2[i];
	}

	return concatenated;
}
