#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Спробуйте написати функцію, яка приймає масив і сортує його елементи в порядку зростання.
Наприклад якщо є масив:
    10 8 3 5 1 9
то функція має відсортувати елементи в ньому ось так:
    1 3 5 8 9 10

Мої уроки 51, 52, 53, 55 присвячені різним алгоритмам сортування. Але не раджу раніше часу туди заглядати.
Спробуйте самі придумати алгоритм сортування таких значеннь. Якщо не вийде - загугліть якийсь алгоритм
в інтернеті. Спробуйте його зрозуміти. Перевірте, чи він у вас працює. А коли прийде час, то доберетеся до
моїх уроків по сортуванню.
*/

long get_current_time();

void set_seed(int seed);

int get_random_int(int from, int to);

void fill_array(int array[], int size, int element_bot_bound, int element_top_bound);

void print_array(int array[], int array_size);

void sort(int array[], int array_size);

int main() {
	const int ARRAY_SIZE = 10;
	const int BOT_RANDOM_BOUND = 0;
	const int TOP_RANDOM_BOUND = 40;

	int seed = (int)get_current_time();
	set_seed(seed);

	int array[ARRAY_SIZE];

	fill_array(array, ARRAY_SIZE, BOT_RANDOM_BOUND, TOP_RANDOM_BOUND);
	print_array(array, ARRAY_SIZE);
	sort(array, ARRAY_SIZE);
	print_array(array, ARRAY_SIZE);

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

void print_array(int array[], int array_size) {
	std::cout << "Array: ";

	for (int i = 0; i < array_size; i++) {
		std::cout << array[i] << ' ';
	}

	std::cout << std::endl;
}

void sort(int array[], int array_size) {
	for (int i = 0; i < array_size - 1; i++) {
		for (int j = 0; j < array_size - i - 1; j++) {
			int element1 = array[j];
			int element2 = array[j + 1];

			if (element1 > element2) {
				array[j] = element2;
				array[j + 1] = element1;
			}
		}
	}
}
