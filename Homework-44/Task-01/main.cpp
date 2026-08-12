#include <ctime>
#include <iostream>
#include <cstdlib>

/*
    Створіть глобальну змінну int sum = 0. В ній буде зберігатися сума якихось чисел.
    Створіть 3 функції:
        - void Initialize(int arr[], int size) - заповнює масив випадковими значеннями
        - void Show(const int arr[], int size) - виводить елементи масиву на екран
        - int Sum(const int arr[], int size) - повертає суму всіх елементів масиву

    У функції main створіть 2 масиви різного розміру. Заповніть їх випадковими числами і виведіть на екран.

    Після цього додайте до глобальної змінної sum спочатку суму елементів першого масиву, а потім другого.

    Напишіть функцію void ShowSum(), яка виводить значення суми на екран наступним повідомленням:
        "Загальна сума всіх масивів = X"
 */

const int MIN_RANDOM_VALUE = 5;
const int MAX_RANDOM_VALUE = 30;

void initialize(int arr[], int size);

void show(const int arr[], int size);

int array_sum(const int arr[], int size);

void show_sum();

int sum;

int main() {
	int array1_size = 6;
	int array2_size = 14;

	int array1[array1_size];
	int array2[array2_size];

	initialize(array1, array1_size);
	initialize(array2, array2_size);

	show(array1, array1_size);
	show(array2, array2_size);

	sum += array_sum(array1, array1_size);
	sum += array_sum(array2, array2_size);

	show_sum();

	return  0;
}

void initialize(int arr[], int size) {
	{
		long current_time = std::time(nullptr);
		std::srand(current_time);
	}

	for (int i = 0; i < size; i++) {
		int r = std::rand();
		arr[i] = r % (MAX_RANDOM_VALUE - MIN_RANDOM_VALUE) + MIN_RANDOM_VALUE;
	}
}

void show(const int arr[], int size) {
	std::cout << "Array[" << size << "] -> ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i];

		if (i < size - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

int array_sum(const int arr[], int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}

void show_sum() {
	std::cout << "Загальна сума всіх масивів = " << sum << std::endl;
}
