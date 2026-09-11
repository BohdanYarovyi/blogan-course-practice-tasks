#include <iostream>
#include <cassert>

/*
Перезавантажте функцію swap із попередньої задачі так, щоб вона міняла місцями значення масивів з однаковим розміром.

Ось її прототип:
    template <typename T>
    void swap(T arr1[], T arr2[], int size);

Ну і перевірте її.
*/

template <typename T>
void swap(T* a, T* b);

template <typename T>
void swap(T* arr1, T* arr2, int size);

int main()
{
    // Тест 1: масиви int
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {10, 20, 30, 40, 50};
    int expected_a[] = {10, 20, 30, 40, 50};
    int expected_b[] = {1, 2, 3, 4, 5};

    swap(a, b, 5);

    for (int i = 0; i < 5; ++i)
    {
        assert(a[i] == expected_a[i]);
        assert(b[i] == expected_b[i]);
    }
    std::cout << "Test 1 (int) passed\n";

    // Тест 2: масиви double
    double x[] = {1.1, 2.2, 3.3};
    double y[] = {9.9, 8.8, 7.7};
    double expected_x[] = {9.9, 8.8, 7.7};
    double expected_y[] = {1.1, 2.2, 3.3};

    swap(x, y, 3);

    for (int i = 0; i < 3; ++i)
    {
        assert(x[i] == expected_x[i]);
        assert(y[i] == expected_y[i]);
    }
    std::cout << "Test 2 (double) passed\n";

    // Тест 3: граничний випадок, розмір масиву = 1
    char c1[] = {'X'};
    char c2[] = {'Y'};

    swap(c1, c2, 1);

    assert(c1[0] == 'Y');
    assert(c2[0] == 'X');
    std::cout << "Test 3 (edge case, size = 1) passed\n";

    // Тест 4: масив із однаковими значеннями (елементи не мають змінитись за суттю, тільки помінятись місцями)
    int p[] = {7, 7, 7};
    int q[] = {7, 7, 7};

    swap(p, q, 3);

    for (int i = 0; i < 3; ++i)
    {
        assert(p[i] == 7);
        assert(q[i] == 7);
    }
    std::cout << "Test 4 (identical values) passed\n";

    std::cout << "All tests passed!\n";

    return 0;
}

template <typename T>
void swap(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template <typename T>
void swap(T* arr1, T* arr2, int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(arr1 + i, arr2 + i);
	}
}
