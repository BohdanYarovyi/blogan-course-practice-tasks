#include <iostream>
const int ARRAY_SIZE = 5;

int global_empty_array[ARRAY_SIZE];

void printArray(int arr[], int size) {
	std::cout << "Array: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int local_empty_array[ARRAY_SIZE];

	printArray(global_empty_array, ARRAY_SIZE);
	printArray(local_empty_array, ARRAY_SIZE);
	return 0;
}
