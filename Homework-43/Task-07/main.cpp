#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Напишіть функцію, яка приймає два масиви і перевіряє, чи однакові вони. Однакові масиви ті, які мають однаковий розмір і однакові елементи. Нахай функція буде виглядати ось так:
    bool Compare(const int arr1, int size1, const int arr2, int size2)

Перевірте її. Сміливо можете використовувати функції з попередніх задач, адже функції створені для того,
щоб не повторювати один і той самий код.
*/

long get_current_time();

void set_seed(int seed);

int get_random_int(int from, int to);

void fill_array(int array[], int size, int element_bot_bound, int element_top_bound);

bool is_arrays_equal(int array1[], int array1_size, int array2[], int array2_size);

void print_array(int array[], int array_size);

int main() {
	const int ARRAY_SIZE = 2;
	const int BOT_RANDOM_BOUND = 0;
	const int TOP_RANDOM_BOUND = 2;

	int seed = (int)get_current_time();
	set_seed(seed);

	int array1[ARRAY_SIZE];
	int array2[ARRAY_SIZE];

	fill_array(array1, ARRAY_SIZE, BOT_RANDOM_BOUND, TOP_RANDOM_BOUND);
	fill_array(array2, ARRAY_SIZE, BOT_RANDOM_BOUND, TOP_RANDOM_BOUND);

	bool is_equal = is_arrays_equal(array1, ARRAY_SIZE, array2, ARRAY_SIZE);

	std::cout << "Array 1: ";
	print_array(array1, ARRAY_SIZE);
	std::cout << std::endl;

	std::cout << "Array 2: ";
	print_array(array2, ARRAY_SIZE);
	std::cout << std::endl;

	if (is_equal) {
		std::cout << "Arrays is equal" << std::endl;
	}
	else {
		std::cout << "Arrays is NOT equal" << std::endl;
	}

	return 0;
}

long get_current_time() {
	return std::time(nullptr);
}

void set_seed(int seed) {
	std::srand(seed);
}

int get_random_int(int from, int to) {
	int random_number = std::rand();

	return rand() % (to - from) + from;
}

void fill_array(int array[], int size, int element_bot_bound, int element_top_bound) {
	for (int i = 0; i < size; i++) {
		array[i] = get_random_int(element_bot_bound, element_top_bound);
	}
}

bool is_arrays_equal(int array1[], int array1_size, int array2[], int array2_size) {
	if (array1_size != array2_size) {
		return false;
	}

	for (int i = 0; i < array1_size; i++) {
		int element1 = array1[i];
		int element2 = array2[i];

		if (element1 != element2) {
			return false;
		}
	}

	return true;
}

void print_array(int array[], int array_size) {
	for (int i = 0; i < array_size; i++) {
		std::cout << array[i] << ' ';
	}

	std::cout << std::endl;
}
