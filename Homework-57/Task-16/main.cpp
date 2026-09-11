#include <iostream>
#include <cassert>

/*
Створіть вказівник на функцію із задачі 15. Перепишіть код задачі 15 так, щоб функція викликалась через цей вказівник.
*/

template <typename T>
const T* find(const T* begin, const T* end, const T* value);

int main()
{
	int arr1[] = {5, 3, 8, 1, 9, 2, 7}; // 7 елементів, індекси 0..6

	const int* (*fp_find)(const int*, const int*, const int*) = find<int>;

    // Тест 1: значення є в масиві
    int target1 = 9;
    const int* result1 = fp_find(arr1, arr1 + 6, &target1); // end = останній елемент (індекс 6), включно
    assert(result1 != nullptr);
    assert(result1 == &arr1[4]);
    assert(*result1 == 9);
    std::cout << "Test 1 (found) passed\n";

    // Тест 2: значення відсутнє
    int target2 = 100;
    const int* result2 = fp_find(arr1, arr1 + 6, &target2);
    assert(result2 == nullptr);
    std::cout << "Test 2 (not found) passed\n";

    // Тест 3: значення на першій позиції
    int target3 = 5;
    const int* result3 = fp_find(arr1, arr1 + 6, &target3);
    assert(result3 == &arr1[0]);
    std::cout << "Test 3 (first element) passed\n";

    // Тест 4: значення на останній позиції — ключовий тест на "включно"
    int target4 = 7; // останній елемент масиву (індекс 6)
    const int* result4 = fp_find(arr1, arr1 + 6, &target4);
    assert(result4 != nullptr); // якщо тут nullptr — значить end трактується як exclusive, помилка
    assert(result4 == &arr1[6]);
    std::cout << "Test 4 (last element, inclusive check) passed\n";

    // Тест 5: масив з одного елемента (begin == end)
    int single = 42;
    int target5 = 42;
    const int* result5 = fp_find(&single, &single, &target5);
    assert(result5 == &single);
	std::cout << "Test 5 (single element, begin == end) passed\n";

    // Тест 6: дублікати — перше входження
    int arr4[] = {1, 5, 5, 5, 2};
    int target7 = 5;
    const int* result7 = fp_find(arr4, arr4 + 4, &target7);
    assert(result7 == &arr4[1]);
    std::cout << "Test 6 (duplicates, first occurrence) passed\n";

    std::cout << "All tests passed!\n";

    return 0;
}

template <typename T>
const T* find(const T* begin, const T* end, const T* value)
{
	for (const T* p = begin; p <= end; p++)
	{
		if (*p == *value)
		{
			return p;
		}
	}

	return nullptr;
}
