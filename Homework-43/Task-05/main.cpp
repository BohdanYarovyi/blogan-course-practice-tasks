#include <iostream>
#include <ctime>
#include <stdlib.h>

/*
Напишіть 2 функції:
    - void Initialize(int arr[], int size, int min, int max) - функція приймає масив
    з його розміром і ініціалізовує його випадковими числами від min до max (включноі).
    - void Show(const int arr[], int size) - виводить на екран усі елементи масиву в рядок.
*/

void initialize(int arr[], int size, int min, int max);

void show(const int arr[], int size);

void set_random_seed(const long seed);

int get_random_int(const int from, const int to);

long get_current_calendar_time();

int main() {
	constexpr int ARRAY_SIZE = 10;
	int arr[ARRAY_SIZE];

	set_random_seed(get_current_calendar_time());
	initialize(arr, ARRAY_SIZE, 20, 90);
	show(arr, ARRAY_SIZE);

	return 0;
}

void initialize(int arr[], int size, int min, int max) {
	for (int i = 0; i < size; i++) {
		arr[i] = get_random_int(min, max);
	}
}

void show(const int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
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
