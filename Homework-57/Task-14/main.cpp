#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <sstream>

/*
У нас були функціх initialize(...) та show(...), які заповнювали та виводили масив на екран. Перепишіть їх так, щоб вони виглядали наступним чином:
    void initialize(int* begin, int* end, int min = 0, int max = 100)
    void show(const int* begin, const int* end, char delimiter = ' ', char end_character = '\n')

Замість відправлення масиву з його розмірами, ви тепер можете відправляти адресу початку і кінця масиву.
Тобто ось так:
    int arr[5];
    initialize(arr, arr + 5);
    show(arr, arr + 5);

Перевірте, чи воно у вас працює нормально.
*/

void initialize(int* begin, int* end, int min = 0, int max = 100);

void show(const int* begin, const int* end, char delimiter = ' ', char end_character = '\n');

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Тест 1: initialize заповнює весь масив значеннями в межах дефолтного [0, 100]
    int arr1[5];
    initialize(arr1, arr1 + 5);
    for (int i = 0; i < 5; ++i)
    {
        assert(arr1[i] >= 0 && arr1[i] <= 100);
    }
    std::cout << "Test 1 (default range [0, 100]) passed\n";

    // Тест 2: initialize з кастомним діапазоном
    int arr2[10];
    initialize(arr2, arr2 + 10, 5, 15);
    for (int i = 0; i < 10; ++i)
    {
        assert(arr2[i] >= 5 && arr2[i] <= 15);
    }
    std::cout << "Test 2 (custom range [5, 15]) passed\n";

    // Тест 3: show з дефолтним delimiter/end_character
    int arr3[] = {1, 2, 3, 4, 5};
    std::ostringstream oss1;
    std::streambuf* old_buf = std::cout.rdbuf(oss1.rdbuf());
    show(arr3, arr3 + 5);
    std::cout.rdbuf(old_buf);

    assert(oss1.str() == "array [1 2 3 4 5]\n");
    std::cout << "Test 3 (default delimiter/end_character): \"" << oss1.str() << "\" passed\n";

    // Тест 4: show з кастомним delimiter і end_character
    std::ostringstream oss2;
    old_buf = std::cout.rdbuf(oss2.rdbuf());
    show(arr3, arr3 + 5, ',', '!');
    std::cout.rdbuf(old_buf);

    assert(oss2.str() == "array [1,2,3,4,5]!");
    std::cout << "Test 4 (custom delimiter/end_character): \"" << oss2.str() << "\" passed\n";

    // Тест 5: граничний випадок — порожній діапазон (begin == end)
    std::ostringstream oss3;
    old_buf = std::cout.rdbuf(oss3.rdbuf());
    show(arr3, arr3); // begin == end
    std::cout.rdbuf(old_buf);

    assert(oss3.str() == "array []\n");
    std::cout << "Test 5 (empty range, begin == end) passed\n";

    // Тест 6: масив з одного елемента (delimiter не повинен з'явитись взагалі)
    int single[] = {42};
    std::ostringstream oss4;
    old_buf = std::cout.rdbuf(oss4.rdbuf());
    show(single, single + 1, ',', '\n');
    std::cout.rdbuf(old_buf);

    assert(oss4.str() == "array [42]\n");
    std::cout << "Test 6 (single element, no trailing delimiter) passed\n";

    std::cout << "All tests passed!\n";

    return 0;
}

void initialize(int* begin, int* end, int min, int max)
{
	#ifndef SET_RANDOM_SEED
	#define SET_RANDOM_SEED
	std::srand(std::time(nullptr));
	#endif

	for (int* p = begin; p < end; p++)
	{
		*p = std::rand() % (max - min - 1) + min;
	}
}

void show(const int* begin, const int* end, char delimiter, char end_character)
{
	std::cout << "array [";
	for (const int* p = begin; p < end; p++)
	{
		std::cout << *p;

		if (p < end - 1)
		{
			std::cout << delimiter;
		}
	}
	std::cout << "]" << end_character;
}
