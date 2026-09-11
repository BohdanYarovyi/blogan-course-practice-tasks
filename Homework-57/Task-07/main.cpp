#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Створіть наступні масиви:
    int arr1[2];
    int arr2[3];
    int arr3[4];

Виведіть на екран їх адреси НЕ ВИКОРИСТОВУЮЧИ вказівники.

Далі створіть вказівники на ці масиви. Заповніть через них ці масиви випадковими значеннями. А далі завдяки вказівникам, виведіть на екран усі елементи цих масивів.
*/

void init_random();

void set_random_array(int* arr, int size);

void show(int* arr, int size);

int main()
{
	init_random();

	const int ARR1_SIZE = 2;
	const int ARR2_SIZE = 3;
	const int ARR3_SIZE = 4;

	int arr1[ARR1_SIZE];
	int arr2[ARR2_SIZE];
	int arr3[ARR3_SIZE];
	std::cout << "arr1 - " << arr1 << std::endl;
	std::cout << "arr2 - " << arr2 << std::endl;
	std::cout << "arr3 - " << arr3 << std::endl;

	int* p_arr1 = arr1;
	int* p_arr2 = arr2;
	int* p_arr3 = arr3;

	set_random_array(p_arr1, ARR1_SIZE);
	set_random_array(p_arr2, ARR2_SIZE);
	set_random_array(p_arr3, ARR3_SIZE);

	show(p_arr1, ARR1_SIZE);
	show(p_arr2, ARR2_SIZE);
	show(p_arr3, ARR3_SIZE);
}

void init_random()
{
	std::srand(std::time(NULL));
}

void set_random_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = std::rand();
	}
}

void show(int* arr, int size)
{
	std::cout << "array [";
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i);

		if (i < size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}
