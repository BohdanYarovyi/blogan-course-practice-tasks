#include <iostream>
#include <cstdlib>
#include <ctime>

void initialize(int arr[], int size);
void show(int arr[], int size);

int main()
{
	// 0 ... RAND_MAX
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	const int SIZE = 10;
	int arr[SIZE];

	initialize(arr, SIZE);
	show(arr, SIZE);

	return 0;
}

void initialize(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = std::rand();
	}
}

void show(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
