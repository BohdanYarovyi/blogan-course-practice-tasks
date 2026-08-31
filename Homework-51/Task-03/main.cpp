#include <iostream>

/*
Напишіть наступну функцію:
template <typename T>
bool IsSorted(const T array[], int size) - вона перевіряє чи масив відсортований

Напишіть програму, в якій є масив із 5 елементів. Спочатку вони ініціалізовані нулем. Далі користувач вводить всі 5 значень з клавіатури. Перевірте чи масив відсортований. Якщо ні - виведіть відповідне повідомлення, відсортуйте його функцією з задачі 2, і виведіть відсортований масив.
*/
template <typename T>
bool is_sorted(const T array[], int size);

template <typename T>
void selection_sort(T *arr, int size, bool is_ascending_order = true);

template <typename T>
void init_array(T *arr, int size);

template <typename T>
void show_array(T *arr, int size);

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Тест 1: Масив int (за зростанням — за замовчуванням)
    int int_arr[] = { 64, -25, 12, 0, 22, 11 };
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);

    std::cout << "--- Test 1: int (Ascending) ---\n";
    std::cout << "Before: ";
    show_array(int_arr, int_size);

    selection_sort(int_arr, int_size);

    std::cout << "After:  ";
    show_array(int_arr, int_size);
    std::cout << "\n";

    // Тест 2: Масив double (за спаданням)
    double double_arr[] = { 3.14, -1.0, 2.71, 0.0, 9.81 };
    int double_size = sizeof(double_arr) / sizeof(double_arr[0]);

    std::cout << "--- Test 2: double (Descending) ---\n";
    std::cout << "Before: ";
    show_array(double_arr, double_size);

    selection_sort(double_arr, double_size, false);

    std::cout << "After:  ";
    show_array(double_arr, double_size);
    std::cout << "\n";

    // Тест 3: Масив char (за зростанням)
    char char_arr[] = { 'z', 'a', 'm', 'b', 'k' };
    int char_size = sizeof(char_arr) / sizeof(char_arr[0]);

    std::cout << "--- Test 3: char (Ascending) ---\n";
    std::cout << "Before: ";
    show_array(char_arr, char_size);

    selection_sort(char_arr, char_size, true);

    std::cout << "After:  ";
    show_array(char_arr, char_size);
    std::cout << "\n";
    return 0;
}

template <typename T>
bool is_sorted(const T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}

	return true;
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
	std::cout << "] - " << (is_sorted(arr, size) ? "sorted" : "unsorted") << '\n';
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
