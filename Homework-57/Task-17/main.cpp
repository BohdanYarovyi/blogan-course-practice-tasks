#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

/*
Напишіть функцію сортування вибіркою (Selection Sort), її прототип має виглядати ось так:
	void sort(int* begin, int* end)
*/

void sort(int* begin, int* end);

void swap(int* first, int* second);

bool is_sorted_ascending(int* begin, int* end) // begin..end включно
{
    for (int* p = begin; p < end; ++p)
    {
        if (*p > *(p + 1))
            return false;
    }
    return true;
}

int main()
{
	// Тест 1: звичайний невідсортований масив
    int arr1[] = {5, 3, 8, 1, 9, 2, 7};
    int expected1[] = {1, 2, 3, 5, 7, 8, 9};
    sort(arr1, arr1 + 6); // end включно — останній елемент, індекс 6

    for (int i = 0; i < 7; ++i)
    {
        assert(arr1[i] == expected1[i]);
    }
    std::cout << "Test 1 (basic unsorted array) passed\n";

    // Тест 2: вже відсортований масив (нічого міняти не треба)
    int arr2[] = {1, 2, 3, 4, 5};
    int expected2[] = {1, 2, 3, 4, 5};
    sort(arr2, arr2 + 4);

    for (int i = 0; i < 5; ++i)
    {
        assert(arr2[i] == expected2[i]);
    }
    std::cout << "Test 2 (already sorted) passed\n";

    // Тест 3: масив у зворотньому порядку (найгірший випадок для selection sort)
    int arr3[] = {9, 7, 5, 3, 1};
    int expected3[] = {1, 3, 5, 7, 9};
    sort(arr3, arr3 + 4);

    for (int i = 0; i < 5; ++i)
    {
        assert(arr3[i] == expected3[i]);
    }
    std::cout << "Test 3 (reverse sorted) passed\n";

    // Тест 4: масив з дублікатами
    int arr4[] = {4, 2, 4, 1, 2, 3};
    int expected4[] = {1, 2, 2, 3, 4, 4};
    sort(arr4, arr4 + 5);

    for (int i = 0; i < 6; ++i)
    {
        assert(arr4[i] == expected4[i]);
    }
    std::cout << "Test 4 (duplicates) passed\n";

    // Тест 5: масив з одного елемента (begin == end)
    int arr5[] = {42};
    sort(arr5, arr5);
    assert(arr5[0] == 42);
    std::cout << "Test 5 (single element, begin == end) passed\n";

    // Тест 6: масив з двох елементів у неправильному порядку
    int arr6[] = {2, 1};
    int expected6[] = {1, 2};
    sort(arr6, arr6 + 1);

    assert(arr6[0] == expected6[0]);
    assert(arr6[1] == expected6[1]);
    std::cout << "Test 6 (two elements) passed\n";

    // Тест 7: всі елементи однакові
    int arr7[] = {5, 5, 5, 5};
    sort(arr7, arr7 + 3);
    for (int i = 0; i < 4; ++i)
    {
        assert(arr7[i] == 5);
    }
    std::cout << "Test 7 (all identical values) passed\n";

    // Тест 8: масив з від'ємними числами
    int arr8[] = {-3, 5, -1, 0, -8, 2};
    int expected8[] = {-8, -3, -1, 0, 2, 5};
    sort(arr8, arr8 + 5);

    for (int i = 0; i < 6; ++i)
    {
        assert(arr8[i] == expected8[i]);
    }
    std::cout << "Test 8 (negative numbers) passed\n";

    // Тест 9: більший масив зі "стрес-тестом" через is_sorted_ascending
    int arr9[] = {23, 1, 45, 6, 78, 12, 34, 90, 5, 67};
    sort(arr9, arr9 + 9);
    assert(is_sorted_ascending(arr9, arr9 + 9));
    std::cout << "Test 9 (larger array, stress check) passed\n";

    std::cout << "All tests passed!\n";

    return 0;
}

void sort(int* begin, int* end)
{
	for (int* p = begin; p <= end; p++)
	{
		int* p_element = p;
		int* p_min = p;
		for (int* p_candidate = p + 1; p_candidate <= end; p_candidate++)
		{
			p_min = *p_min > *p_candidate ? p_candidate: p_min;
		}

		swap(p_element, p_min);
	}
}

void swap(int* first, int* second)
{
	int tmp = *first;
	*first = *second;
	*second = tmp;
}
