#include <iostream>

/*
    Порацюємо з числами Фібоначчі. Правило чисел Фібоначчі просте: кожне наступне число - це сума двох попередніх чисел Фібоначчі. Послідовність чисел Фібоначчі починається з 0 і 1. Отже згідно правилу Фібоначчі перші 10 чисел Фібоначчі будуть наступними:
    0 1 1 2 3 5 8 13 21 34

    Приступаємо до самої задачі. Створіть глобальний масив int fibonacciNumbers, який складається з 20 елементів (для цього можете і глобальну константу створити).

    Напишіть наступні функції:
        - void InitializeFibonacci() - заповнює глобальний масив першими 20 числами Фібоначчі.
        - void ShowFibonacci() - виводить глобальний масив на екран.

    Викличіть ці функції у функції main.
 */

const int FIBONACCI_NUMBERS_LENGTH = 20;

void initialize_fibonacci();

void show_fibonacci();

int fibonacci_numbers[FIBONACCI_NUMBERS_LENGTH];

int main() {
	initialize_fibonacci();
	show_fibonacci();
	return  0;
}

void initialize_fibonacci() {
	if (FIBONACCI_NUMBERS_LENGTH <= 2) {
		std::cout << "Fibonacci numbers length is too end." << std::endl;
		return;
	}

	fibonacci_numbers[0] = 0;
	fibonacci_numbers[1] = 1;

	for (int i = 2; i < FIBONACCI_NUMBERS_LENGTH; i++) {
		fibonacci_numbers[i] = fibonacci_numbers[i - 1] + fibonacci_numbers[i - 2];
	}
}

void show_fibonacci() {
	std::cout << "Fibonacci numbers: [";
	for (int i = 0; i < FIBONACCI_NUMBERS_LENGTH; i++) {
		std::cout << fibonacci_numbers[i];

		if (i < FIBONACCI_NUMBERS_LENGTH - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
}
