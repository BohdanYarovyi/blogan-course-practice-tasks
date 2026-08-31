#include <iostream>
#include <cassert>

/*
	Напишіть функцію:
	template <typename T>
	void BubbleSort(T array[], int size, bool isAscendingOrder = true) - сортує масив алгоритмом сортування бульбашкою.

	Третій параметр функції: якщо true - сортування по зростанню. Якщо false - сортування по спаданню.
	Перевірте цю функцію на декількох масивах різного типу.
*/

template <typename T>
void bubble_sort(T array[], int size, bool is_ascending_order = true);

template <typename T>
void show_array(T *arr, int size);

template <typename T>
bool compare_arrays(const T* arr1, const T* arr2, int size);

int main()
{
	// Тест 1: int — за зростанням (значення за замовчуванням)
	{
		int input[] = { 45, -10, 89, 0, 12, -3 };
		const int expected[] = { -10, -3, 0, 12, 45, 89 };
		const int size = sizeof(input) / sizeof(input[0]);

		std::cout << "--- Test 1: int (Ascending) ---\n";
		std::cout << "Before:   ";
		show_array(input, size);

		bubble_sort(input, size);

		std::cout << "After:    ";
		show_array(input, size);
		std::cout << "Expected: ";
		show_array(expected, size);

		assert(compare_arrays(input, expected, size));
		std::cout << "[PASSED]\n\n";
	}

	// Тест 2: double — за спаданням
	{
		double input[] = { 5.55, 1.23, 9.99, -4.1, 0.0 };
		const double expected[] = { 9.99, 5.55, 1.23, 0.0, -4.1 };
		const int size = sizeof(input) / sizeof(input[0]);

		std::cout << "--- Test 2: double (Descending) ---\n";
		std::cout << "Before:   ";
		show_array(input, size);

		bubble_sort(input, size, false);

		std::cout << "After:    ";
		show_array(input, size);
		std::cout << "Expected: ";
		show_array(expected, size);

		assert(compare_arrays(input, expected, size));
		std::cout << "[PASSED]\n\n";
	}

	// Тест 3: char — за зростанням
	{
		char input[] = { 'k', 'a', 'z', 'b', 'm', 'f' };
		const char expected[] = { 'a', 'b', 'f', 'k', 'm', 'z' };
		const int size = sizeof(input) / sizeof(input[0]);

		std::cout << "--- Test 3: char (Ascending) ---\n";
		std::cout << "Before:   ";
		show_array(input, size);

		bubble_sort(input, size, true);

		std::cout << "After:    ";
		show_array(input, size);
		std::cout << "Expected: ";
		show_array(expected, size);

		assert(compare_arrays(input, expected, size));
		std::cout << "[PASSED]\n\n";
	}

	std::cout << "All tests successfully passed!\n";
	return 0;
}

template <typename T>
void bubble_sort(T array[], int size, bool is_ascending_order)
{
	// 45, -10, 89, 0, 12, -3 
	for (int i = 0; i < size; i++)
	{
		for (int e = 0; e < size - i - 1; e++) 
		{
			if (array[e] > array[e + 1] == is_ascending_order)
			{
				std::swap(array[e], array[e + 1]);
			}
		}
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

template <typename T>
bool compare_arrays(const T* arr1, const T* arr2, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}
	return true;
}