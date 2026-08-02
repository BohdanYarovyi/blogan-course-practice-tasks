#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Напишіть наступні функції:
    - int SumAllElements(const int arr[], int size) - повертає суму всіх елементів масиву
    - int GetAverage(const int arr[], int size) - повертає середнє арифметичне усіх елементів масиву

Ця задача є доповненням до попередньої. У вас є 3 масиви, які мають випадкові значення.
Виведіть на екран інформацію про них наступним чином:
    Елементи масиву #1: x x x x
    Сума елементів масиву #1: x
    Середнє арифметичне масиву #1: x

    Елементи масиву #2: x x x x
    Сума елементів масиву #2: x
    Середнє арифметичн2е масиву #2: x

    Елементи масиву #3: x x x x
    Сума елементів масиву #3: x
    Середнє арифметичне масиву #3: x

УВАГА: функція GetAverage має в середині себе викликати функцію SumAllElements
(бо без суми, ви не дізнаєтесь середнє арифметичне).
*/

void initialize(int arr[], int size, int min, int max);

void show(int arr[], int size, int array_index);

void set_random_seed(const long seed);

int get_random_int(const int from, const int to);

long get_current_calendar_time();

int sum(int arr[], int array_size);

float avg(int arr[], int array_size);

int main() {
	const int ARRAY_SIZE = 10;

	int arr1[ARRAY_SIZE];
	int arr2[ARRAY_SIZE];
	int arr3[ARRAY_SIZE];

	set_random_seed(get_current_calendar_time());
	initialize(arr1, ARRAY_SIZE, 0, 100);
	initialize(arr2, ARRAY_SIZE, 0, 100);
	initialize(arr3, ARRAY_SIZE, 0, 100);

	show(arr1, ARRAY_SIZE, 1);
	show(arr2, ARRAY_SIZE, 2);
	show(arr3, ARRAY_SIZE, 3);

	return 0;
}

void show(int arr[], int size, int array_index) {
	std::cout << "Елементи масиву #" << array_index << ": ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "Сума елементів масиву #" << array_index << ": ";
	std::cout << sum(arr, size) << std::endl;

	std::cout << "Середнє арифметичне масиву #" << array_index << ": ";
	std::cout << avg(arr, size) << std::endl;
	std::cout << std::endl;
}

void initialize(int arr[], int size, int min, int max) {
	for (int i = 0; i < size; i++) {
		arr[i] = get_random_int(min, max);
	}
}

void set_random_seed(const long seed) {
	std::srand(seed);
}

int get_random_int(const int from, const int to) {
	int random = std::rand();
	return from + random % (to - from);
}

long get_current_calendar_time() {
	return (long) std::time(nullptr);
}

int sum(int arr[], int array_size) {
	int sum = 0;
	for (int i = 0; i < array_size; i++) {
		sum = arr[i];
	}

	return sum;
}

float avg(int arr[], int array_size) {
	int array_sum = sum(arr, array_size);
	return (float) array_sum / array_size;
}
