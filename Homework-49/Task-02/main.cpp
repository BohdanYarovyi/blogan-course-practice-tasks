#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

/*
    Напишіть шаблон функції Min, яка приймає 2 параметри і повертає менший з них. Перевірте її працездатність у 3 типах: int, double, char.

    Після цього перезавантажте цей шаблон, написавши функцію Min, яка приймає 4 параметри: 2 масиви одного типу з їх розмірами. Вона шукає найменший елемент з них двох і повертає його. Перевірте її на декількох масивах різних типів. Масиви заповнюйте випадковими значеннями завдяки функції Initialize із теоретичного уроку.
*/

void init_random();

template <typename T>
T min(T a, T b);

template <typename T>
T min(T a[], T b[], int a_size, int b_size);

template <typename T>
void initial_array(T array[], int size);

const int RANDOM_MIN = 1;
const int RANDOM_MAX = 100;

template <typename T>
void print_array(const T array[], int size)
{
    std::cout << "[ ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

// Допоміжна функція порівняння дробових чисел (для double)
bool is_close(double a, double b, double epsilon = 1e-6)
{
    return std::abs(a - b) < epsilon;
}

// Блок тестування
void run_tests()
{
	init_random();

    // --- 1. ТЕСТИ ДЛЯ min(a, b) ---
    // Перевірка типу int
    assert(min(10, 20) == 10);
    assert(min(-5, 0) == -5);
    assert(min(7, 7) == 7);

    // Перевірка типу double
    assert(is_close(min(5.5, 2.3), 2.3));
    assert(is_close(min(-1.1, -0.5), -1.1));

    // Перевірка типу char (порівняння за ASCII-кодами)
    assert(min('z', 'a') == 'a');
    assert(min('B', 'b') == 'B');

    std::cout << ">>> Усі тести для min(a, b) успішно пройдено!\n\n";

    // --- 2. ТЕСТИ ДЛЯ min(a[], b[], a_size, b_size) З РАНДОМОМ ---

    // Тест з масивами int
    int int_arr1[5];
    int int_arr2[4];
    initial_array(int_arr1, 5);
    initial_array(int_arr2, 4);

    std::cout << "int_arr1: "; print_array(int_arr1, 5);
    std::cout << "int_arr2: "; print_array(int_arr2, 4);
    std::cout << "Мінімум у двох масивах int: " << min(int_arr1, int_arr2, 5, 4) << "\n\n";

    // Тест з масивами double
    double double_arr1[3];
    double double_arr2[3];
    initial_array(double_arr1, 3);
    initial_array(double_arr2, 3);

    std::cout << "double_arr1: "; print_array(double_arr1, 3);
    std::cout << "double_arr2: "; print_array(double_arr2, 3);
    std::cout << "Мінімум у двох масивах double: " << min(double_arr1, double_arr2, 3, 3) << "\n\n";

    // Тест з масивами char
    char char_arr1[4];
    char char_arr2[4];
    initial_array(char_arr1, 4);
    initial_array(char_arr2, 4);

    std::cout << "char_arr1: "; print_array(char_arr1, 4);
    std::cout << "char_arr2: "; print_array(char_arr2, 4);
    std::cout << "Мінімум у двох масивах char: " << min(char_arr1, char_arr2, 4, 4) << "\n\n";

    std::cout << ">>> Усі масиви успішно створено та протестовано!\n";
}

int main()
{
	run_tests();
	return 0;
}

void init_random()
{
	std::srand(std::time(nullptr));
}

template <typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

template <typename T>
T min(T a[], T b[], int a_size, int b_size)
{
	T smallest_value = a[0];

	for (int i = 0; i < a_size; i++)
	{
		smallest_value = a[i] < smallest_value ? a[i] : smallest_value;
	}

	for (int i = 0; i < b_size; i++)
	{
		smallest_value = b[i] < smallest_value ? b[i] : smallest_value;
	}

	return smallest_value;
}

template <typename T>
void initial_array(T array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int r_number = std::rand() % (RANDOM_MAX - RANDOM_MIN + 1) + RANDOM_MIN;
		array[i] = static_cast<T>(r_number);
	}
}
