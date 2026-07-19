#include <iostream>

/*
Знайдіть суму всіх елементів масиву з першої задачі, та виведіть її на екран.
*/

int main() {
	constexpr int NUMBERS_SIZE	= 5;
	int numbers[NUMBERS_SIZE]	= {5, 10, 15, 20, 25};

	int sum = 0;

	for (int i = 0; i < NUMBERS_SIZE; i++) {
		sum += numbers[i];
	}

	std::cout << "Sum of numbers: " << sum << std::endl;

	return 0;
}