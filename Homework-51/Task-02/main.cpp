#include <iostream>
#include <ctime>

/*
Напишіть наступну функцію:
	template <typename T>
	void SelectionSort(T array[], int size, bool isAscendingOrder = true) - сортує масив алгоритмом сортування вибіркою.

Третій параметр функції: якщо true - сортування по зростанню. Якщо false - сортування по спаданню.
Перевірте цю функцію на декількох масивах різного типу.
*/

template <typename T>
void selection_sort(T *arr, int size, bool is_ascending_order = true);

template <typename T>
void init_array(T *arr, int size);

template <typename T>
void show_array(T *arr, int size);

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	const int ARRAY_SIZE = 10;
	int arr[ARRAY_SIZE];

	init_array(arr, ARRAY_SIZE);
	show_array(arr, ARRAY_SIZE);

	selection_sort(arr, ARRAY_SIZE);
	show_array(arr, ARRAY_SIZE);

	selection_sort(arr, ARRAY_SIZE, false);
	show_array(arr, ARRAY_SIZE);
}

template <typename T>
void selection_sort(T *arr, int size, bool is_ascending_order)
{
	for (int lead = 0; lead < size - 1; lead++)
	{
		for (int i = lead + 1; i < size; i++)
		{
			bool found_smaller = arr[i] < arr[lead];
			if (found_smaller == is_ascending_order)
			{
				std::swap(arr[lead], arr[i]);
			}
		}
	}
}

template <typename T>
void init_array(T *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = static_cast<T>(std::rand() % 10 + 1);
	}
}

template <typename T>
void show_array(T* arr, int size)
{
	std::cout << "[";
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
