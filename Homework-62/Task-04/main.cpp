#include <iostream>

/*
	Є дві функції:
	const T& Min(const T arr[], int size)
	T& Min(T arr[], int size)

	Обидві повертають посилання на елемент з мінімальним значенням в масиві. Зможете викликати їх обох у функції main?
*/

template <typename T>
const T& min(const T arr[], int size);

template <typename T>
T& min(T arr[], int size);

int main()
{
	int arr[10] = {44, -13, 82, 2, 0, 60, 53, 7, -6, 0};
	const int const_arr[10] = {44, -13, 82, 2, 0, 60, 53, 7, -6, 0};

	int& result_non_const = min(arr, 10);
	const int& result_const = min(const_arr, 10);

	std::cout << "Result non const: " << result_non_const << std::endl;
	std::cout << "Result const: " << result_const << std::endl;

	return 0;
}

template <typename T>
const T& min(const T arr[], int size)
{
	int min_index = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[min_index] > arr[i])
		{
			min_index = i;
		}
	}

	return arr[min_index];
}

template <typename T>
T& min(T arr[], int size)
{
	int min_index = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[min_index] > arr[i])
		{
			min_index = i;
		}
	}

	return arr[min_index];
}
