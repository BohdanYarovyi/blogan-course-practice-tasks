#include <iostream>
#include <cassert>

/*
    Напишіть шаблон функції Swap, яка приймає два масиви одного типу і міняє значення їх елементів місцями. Вона приймає 3 параметри: масив1, масив2, розмір. Масиви мають мати однаковий розмір. Перевірте її працездатність.

    Спробуйте написати функцію Swap, яка просто приймає 2 параметри і міняє їх значення місцями. В попередніх уроках я розповідав, що просто так два значення не переставиш місцями, якщо ви передаєте їх у функцію. Спробуйте згадати, чого.
*/

template <typename T>
void swap(T a[], T b[], int size);

// Допоміжна функція для порівняння двох масивів
template <typename T>
bool are_arrays_equal(const T a[], const T b[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Спеціалізація порівняння для double (з урахуванням похибки)
bool are_double_arrays_equal(const double a[], const double b[], int size, double epsilon = 1e-6)
{
    for (int i = 0; i < size; ++i)
    {
        if (std::abs(a[i] - b[i]) >= epsilon) return false;
    }
    return true;
}

void run_tests()
{
    // 1. Тест для int
    int int_a[3] = {1, 2, 3};
    int int_b[3] = {8, 9, 10};

    swap(int_a, int_b, 3);

    int expected_int_a[3] = {8, 9, 10};
    int expected_int_b[3] = {1, 2, 3};

    assert(are_arrays_equal(int_a, expected_int_a, 3));
    assert(are_arrays_equal(int_b, expected_int_b, 3));

    // 2. Тест для double
    double double_a[2] = {1.5, 2.5};
    double double_b[2] = {7.1, 8.2};

    swap(double_a, double_b, 2);

    double expected_double_a[2] = {7.1, 8.2};
    double expected_double_b[2] = {1.5, 2.5};

    assert(are_double_arrays_equal(double_a, expected_double_a, 2));
    assert(are_double_arrays_equal(double_b, expected_double_b, 2));

    // 3. Тест для char
    char char_a[4] = {'a', 'b', 'c', 'd'};
    char char_b[4] = {'w', 'x', 'y', 'z'};

    swap(char_a, char_b, 4);

    char expected_char_a[4] = {'w', 'x', 'y', 'z'};
    char expected_char_b[4] = {'a', 'b', 'c', 'd'};

    assert(are_arrays_equal(char_a, expected_char_a, 4));
    assert(are_arrays_equal(char_b, expected_char_b, 4));

    std::cout << "Усі тести для swap(a, b, size) успішно пройдено!\n";
}

int main()
{
	run_tests();
	return 0;
}

template <typename T>
void swap(T a[], T b[], int size)
{
	for (int i = 0; i < size; i++)
	{
		T temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
