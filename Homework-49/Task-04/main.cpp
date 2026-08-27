#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

/*
	Не люблю я писати "std::cout << значення". Напишіть шаблонну функцію Show, яка приймає один параметр і виводить його значення на екран. Також перезавантажте шаблон, написавши шаблон функції Show, яка приймає 3 параметри: масив, його розмір, символ розділення елементів. Вона виводить всі його елементи на екран, виставляючи між ними символ-розділювач. Тобто якщо я викличу її ось так:
	Show(arr, 5, ' ')
	то елементи виведуться ось так "0 1 2 3 4". Якщо я викличу її ось так:
	Show(arr, 5, '-')
	то елементи виведуться ось так "0-1-2-3-4".
*/

template <typename T>
void show(T data);

template <typename T>
void show(T array[], int size, char separator);

void run_tests()
{
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // --- 1. ТЕСТИ ДЛЯ show(data) ---
    show(42);
    assert(buffer.str() == "42\n");
    buffer.str(""); buffer.clear();

    show(3.14);
    assert(buffer.str() == "3.14\n");
    buffer.str(""); buffer.clear();

    show('A');
    assert(buffer.str() == "A\n");
    buffer.str(""); buffer.clear();

    // --- 2. ТЕСТИ ДЛЯ show(array, size, separator) ---
    int int_arr[5] = {0, 1, 2, 3, 4};

    // Перевірка з пробілом ' '
    show(int_arr, 5, ' ');
    assert(buffer.str() == "0 1 2 3 4\n");
    buffer.str(""); buffer.clear();

    // Перевірка з дефісом '-'
    show(int_arr, 5, '-');
    assert(buffer.str() == "0-1-2-3-4\n");
    buffer.str(""); buffer.clear();

    // Перевірка з типом double та комою ','
    double dbl_arr[3] = {1.1, 2.2, 3.3};
    show(dbl_arr, 3, ',');
    assert(buffer.str() == "1.1,2.2,3.3\n");
    buffer.str(""); buffer.clear();

    std::cout.rdbuf(old_cout);

    std::cout << "Усі тести для show успішно пройдено!\n";
}

int main()
{
	run_tests();
	return 0;
}

template <typename T>
void show(T data)
{
	std::cout << data << std::endl;
}

template <typename T>
void show(T array[], int size, char separator)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i];

		if (i < size - 1)
		{
			std::cout << separator;
		}
	}
	std::cout << std::endl;
}
