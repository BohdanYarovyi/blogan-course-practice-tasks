#include <iostream>

/*
Перепишіть функцію із задачі 2 ось таким способом:
template <typename T>
void SelectionSort(T array[], int size, int first, int last, bool isAscendingOrder = true)

В ній добавлені 2 нові параметри first і last. Це індекси першого і останнього елементу із діапазону елементів, який треба відсортувати в масиві. Тобто якщо масив має розмір 10, і ви викликаєте ось так цю функцію:
SelectionSort(arr, 10, 2, 6, false)
то функція має відсортувати лише елементи 2,3,4,5,6, причому по спаданню.
*/

template <typename T>
void selection_sort(T *arr, int size, int first, int last, bool is_ascending_order = true);

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

	selection_sort(arr, ARRAY_SIZE, 2, 6);
	show_array(arr, ARRAY_SIZE);

	selection_sort(arr, ARRAY_SIZE, 2, 6, false);
	show_array(arr, ARRAY_SIZE);
}

template <typename T>
void selection_sort(T *arr, int size, int first, int last, bool is_ascending_order)
{
	for (int lead = first; lead < last; lead++)
	{
		for (int i = lead + 1; i < last + 1; i++)
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