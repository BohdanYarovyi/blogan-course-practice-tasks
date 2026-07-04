#include <iostream>

/*
Переробіть задачку №5 так, щоб виводився не діапазон чисел, а їх сума.
*/

int main() {
	int lower_bound;
	int upper_bound;

	std::cout << "Enter two bounds [lower_bound upper_bound]: ";
	std::cin >> lower_bound >> upper_bound;

	if (lower_bound > upper_bound) {
		int tmp = upper_bound;
		upper_bound = lower_bound;
		lower_bound = tmp;
	}

	int index = lower_bound;
	long long sum = 0;
	while (index <= upper_bound) {
		sum += index;
		index++;
	}

	std::cout << "The sum of numbers in range [" << lower_bound << " - " << upper_bound << "]: " << sum << std::endl;

	return 0;
}