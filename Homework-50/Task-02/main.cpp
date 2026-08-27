#include <iostream>
#include <cassert>
#include <sstream>
#include <cmath>

/*
Зробіть попередні 4 функції з задачі 2 шаблонними.
*/

template <typename T>
void find_and_tell_result(const T array[], int size, T value);

template <typename T>
int find_index(const T array[], int size, T value);

template <typename T>
bool find(const T array[], int size, T value);

template <typename T>
bool find(const T array[], int size, const T key_numbers[], int count);

void run_tests()
{
    // --- 1. ТЕСТИ ДЛЯ INT ---
    const int int_arr[5] = {10, 20, 30, 40, 50};

    assert(find_index(int_arr, 5, 30) == 2);
    assert(find_index(int_arr, 5, 99) == -1);

    assert(find(int_arr, 5, 10) == true);
    assert(find(int_arr, 5, 100) == false);

    const int int_keys_valid[2] = {20, 50};
    const int int_keys_invalid[2] = {20, 99};
    assert(find(int_arr, 5, int_keys_valid, 2) == true);
    assert(find(int_arr, 5, int_keys_invalid, 2) == false);

    // --- 2. ТЕСТИ ДЛЯ DOUBLE ---
    const double double_arr[4] = {1.1, 2.2, 3.3, 4.4};

    assert(find_index(double_arr, 4, 3.3) == 2);
    assert(find_index(double_arr, 4, 9.9) == -1);

    assert(find(double_arr, 4, 1.1) == true);
    assert(find(double_arr, 4, 5.5) == false);

    const double double_keys_valid[2] = {4.4, 1.1};
    assert(find(double_arr, 4, double_keys_valid, 2) == true);

    // --- 3. ТЕСТИ ДЛЯ CHAR ---
    const char char_arr[4] = {'a', 'b', 'c', 'd'};

    assert(find_index(char_arr, 4, 'c') == 2);
    assert(find_index(char_arr, 4, 'z') == -1);

    assert(find(char_arr, 4, 'a') == true);
    assert(find(char_arr, 4, 'x') == false);

    const char char_keys_valid[3] = {'d', 'b', 'a'};
    assert(find(char_arr, 4, char_keys_valid, 3) == true);

    // --- 4. ТЕСТ ДЛЯ find_and_tell_result (ПЕРЕХОПЛЕННЯ ПОТОКУ) ---
    {
        std::stringstream buffer;
        std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

        find_and_tell_result(int_arr, 5, 30);
        assert(!buffer.str().empty());
        buffer.str(""); buffer.clear();

        find_and_tell_result(char_arr, 4, 'z');
        assert(!buffer.str().empty());
        buffer.str(""); buffer.clear();

        std::cout.rdbuf(old_cout);
    }

    std::cout << ">>> Усі тести для шаблонного пошуку успішно пройдено!\n";
}

int main()
{
	run_tests();
	return 0;
}

template <typename T>
void find_and_tell_result(const T array[], int size, T value)
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

template <typename T>
int find_index(const T array[], int size, T value)
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

template <typename T>
bool find(const T array[], int size, T value)
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

template <typename T>
bool find(const T array[], int size, const T key_numbers[], int count)
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
