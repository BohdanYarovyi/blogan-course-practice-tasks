#include <iostream>
#include <cassert>

/*
Напишіть наступну функцію:
    int sum_sequence(int* first, int* last) - функція приймає вказівники на перший та останній елементи послідовності, проходить по цій послідовності, рахує суму значень та повертає результат.

Перевірте функцію на масиві з 10 елементів:
- Порахуйте суму всіх 10 елементів
- Порахуйте суму елементів з індексу 2 до 8
- Порахуйте суму елементів з індексу 4 до 6
*/

int sum_sequence(int* first, int* last);

int main()
{
    int arr[] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10}; // 10 елементів, індекси 0..9

    // Тест 1: сума всіх 10 елементів
    int sum_all = sum_sequence(&arr[0], &arr[9]);
    int expected_all = 5+3+8+1+9+2+7+4+6+10; // = 55
    assert(sum_all == expected_all);
    std::cout << "Test 1 (all elements): sum = " << sum_all << " passed\n";

    // Тест 2: сума елементів з індексу 2 до 8 включно
    int sum_2_8 = sum_sequence(&arr[2], &arr[8]);
    int expected_2_8 = 8+1+9+2+7+4+6; // = 37
    assert(sum_2_8 == expected_2_8);
    std::cout << "Test 2 (index 2..8): sum = " << sum_2_8 << " passed\n";

    // Тест 3: сума елементів з індексу 4 до 6 включно
    int sum_4_6 = sum_sequence(&arr[4], &arr[6]);
    int expected_4_6 = 9+2+7; // = 18
    assert(sum_4_6 == expected_4_6);
    std::cout << "Test 3 (index 4..6): sum = " << sum_4_6 << " passed\n";

    // Тест 4: граничний випадок — first == last (один елемент)
    int sum_single = sum_sequence(&arr[5], &arr[5]);
    assert(sum_single == arr[5]); // = 2
    std::cout << "Test 4 (single element, first == last): sum = " << sum_single << " passed\n";

    std::cout << "All tests passed!\n";

    return 0;
}

int sum_sequence(int* first, int* last)
{
	int sum = 0;
	const int size = last - first;
	for (int i = 0; i <= size; i++)
	{
		sum += *(first + i);
	}

	return sum;
}
