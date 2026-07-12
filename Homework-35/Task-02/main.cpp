#include <iostream>

/*
Збільшіть діапазон значень з попередньої задачі до 1...10 і виведіть на екран лише парні числа.
*/

int main() {
	for (int element : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
		if (element % 2 == 0) {
			std::cout << element << std::endl;
		}
	}

	return 0;
}