#include <iostream>
#include <cassert>
#include <sstream>

/*
	Напишіть наступні варіанти функцій лінійного пошуку в масиві:

	1. void FindAndTellResult(const int array[], int size, int value) - шукає і виводить інформацію про знаходження елементу на екран. Тобто якщо елемент є, то так і каже. Якщо немає - так і каже.
	2. int FindIndex(const int array[], int size, int value) - шукає значення в масиві і повертає індекс елементу, який має це значення. Якщо значення немає - повертає значення -1.
	3. bool Find(const int array[], int size, int value) - шукає значення в масиві. Якщо є - повертає true, інакше - false.
	4. bool Find(const int array[], int size, const int keyNumbers[], int count) - шукає кожний елемент масиву keyNumbers в масиві array. Якщо всі елементи є (порядок не важливий) - повертає true. Якщо хоча б одного елементу немає - повертає false.
*/

void find_and_tell_result(const int array[], int size, int value);

int find_index(const int array[], int size, int value);

bool find(const int array[], int size, int value);

bool find(const int array[], int size, const int key_numbers[], int count);

void run_tests()
{
    const int arr[6] = {10, 25, -5, 42, 0, 42};
    const int size = 6;

    // --- 1. ТЕСТИ ДЛЯ find_and_tell_result ---
    {
        std::stringstream buffer;
        std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

        // Перевірка, коли елемент існує
        find_and_tell_result(arr, size, 25);
        assert(!buffer.str().empty()); // Перевіряємо, що функція щось вивела
        buffer.str(""); buffer.clear();

        // Перевірка, коли елемента немає
        find_and_tell_result(arr, size, 99);
        assert(!buffer.str().empty());
        buffer.str(""); buffer.clear();

        std::cout.rdbuf(old_cout);
    }

    // --- 2. ТЕСТИ ДЛЯ find_index ---
    assert(find_index(arr, size, 10) == 0);   // Перший елемент
    assert(find_index(arr, size, -5) == 2);   // Від'ємний елемент
    assert(find_index(arr, size, 42) == 3);   // Перше входження дубльованого числа
    assert(find_index(arr, size, 100) == -1); // Відсутній елемент

    // --- 3. ТЕСТИ ДЛЯ find (пошук одного значення) ---
    assert(find(arr, size, 42) == true);
    assert(find(arr, size, 0) == true);
    assert(find(arr, size, 777) == false);

    // --- 4. ТЕСТИ ДЛЯ find (пошук масиву ключів key_numbers) ---
    const int valid_keys1[3] = {25, 42, 10};
    assert(find(arr, size, valid_keys1, 3) == true);

    const int valid_keys2[1] = {-5};
    assert(find(arr, size, valid_keys2, 1) == true);

    const int invalid_keys1[3] = {25, 99, 10}; // 99 немає в масиві
    assert(find(arr, size, invalid_keys1, 3) == false);

    const int invalid_keys2[2] = {55, 66}; // Жодного немає
    assert(find(arr, size, invalid_keys2, 2) == false);

    std::cout << ">>> Усі тести для лінійного пошуку успішно пройдено!\n";
}

int main()
{
	run_tests();
	return 0;
}

void find_and_tell_result(const int array[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			std::cout << "The value was found!\n";
			break;
		}
	}

	std::cout << "Didn't find the element.\n";
}

int find_index(const int array[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			return i;
		}
	}

	return -1;
}

bool find(const int array[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			return true;
		}
	}

	return false;
}

bool find(const int array[], int size, const int key_numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		bool is_element_exists = false;
		for (int j = 0; j < size; j++)
		{
			if (key_numbers[i] == array[j])
			{
				is_element_exists = true;
				break;
			}
		}

		if (!is_element_exists)
		{
			return false;
		}
	}

	return true;
}
