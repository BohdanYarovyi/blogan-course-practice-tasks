#include <iostream>
#include <cassert>

/*
    В попередньому уроці ви писали функції MaxOf2, MaxOf3, MaxOf4 - які повертали максимальне значення із
    указаних параметрів. А тепер напишіть 3 функції Max, які приймають 2, 3 і 4 параметри і викличіть їх.
    Суть задачі - зробити перевантажену функцію Max, яка вміє працювати з 2,3 і 4 параметрами.

    При цьому напишіть ще функцію int Max(const int arr[], int size), яка приймає масив з його розміром і
    повертає найбільший елемент.
*/

int max(int a, int b);

int max(int a, int b, int c);

int max(int a, int b, int c, int d);

int max(int arr[], int size);

void run_tests();

int main()
{
	run_tests();
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	if (a > b)
	{
		return a > c ? a : c;
	}
	else
	{
		return b > c ? b : c;
	}
}

int max(int a, int b, int c, int d)
{
	int ab_biggest = max(a, b);
	int cd_biggest = max(c, d);

	return ab_biggest > cd_biggest ? ab_biggest : cd_biggest;
}

int max(int arr[], int size)
{
	int biggest = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (arr[i] > biggest)
		{
			biggest = arr[i];
		}
	}

	return biggest;
}

void run_tests() {
    // 1. Тести для max(int, int)
    assert(max(3, 5) == 5);
    assert(max(10, -2) == 10);
    assert(max(-4, -4) == -4); // однакові значення

    // 2. Тести для max(int, int, int)
    assert(max(1, 7, 3) == 7);
    assert(max(12, 5, 2) == 12);
    assert(max(-5, -2, -9) == -2);

    // 3. Тести для max(int, int, int, int)
    assert(max(1, 2, 8, 4) == 8);
    assert(max(10, 3, 5, 10) == 10); // дубльоване максимальне значення
    assert(max(-10, -20, -5, -30) == -5);

    // 4. Тести для max(int arr[], int size)
    int arr1[] = {1, 5, 3, 9, 2};
    assert(max(arr1, 5) == 9);

    int arr2[] = {-10, -3, -50};
    assert(max(arr2, 3) == -3);

    int arr3[] = {42}; // масив з одного елемента
    assert(max(arr3, 1) == 42);

    std::cout << "Усі тести успішно пройдено!" << std::endl;
}
