#include <iostream>

/*
Напишіть функцію:
    template <typename T>
    void swap(T* a, T* b);

Ця функція міняє місцями значення двох змінних.

Перевірте її на ось цьому коді:
    int a = 10;
    int b = 20;

    swap(a, b);
    std::cout << a << '\n'; // має бути 20
    std::cout << b << '\n'; // має бути 10
*/

template <typename T>
void swap(T* a, T* b);

int main()
{
	int a = 10;
    int b = 20;

    swap(&a, &b);
    std::cout << a << '\n'; // має бути 20
	std::cout << b << '\n'; // має бути 10

	return 0;
}

template <typename T>
void swap(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}
