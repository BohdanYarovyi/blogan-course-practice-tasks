#include <iostream>

/*
	А зможете вирішити проблему із задачі 2, тільки для двовимірних масивів? Нагадаю, як ми писали функції для двовимірних масивів на кучі і на стеку:

	// Функція для масивів на кучі:
	void Show(const int* const* arr, int rows, int columns);

	// Функція для масивів на стеку:
	void Show(const int arr[][розмір], int rows);

	У функції для масивів на стеку є недолік - ми постійно мали писати конкретний літерал в кількість стовпчиків такого масиву, наприклад ось так:
	void Show(const int arr[][2], int rows);
	void Show(const int arr[][3], int rows);

	Зможете виправити цю функцію так, щоб у нас була одна функція для всіх двовимірних масивів на стеку, і щоб цей код спрацював?

	int main()
	{
	// масиви на стеку
	int arr1[2][3] = {};
	int arr2[5][4] = {};

	// масив на кучі
	int** arr3 = new int* [2];
	for (int i = 0; i < 2; i++)
	arr3[i] = new int[3];

	Show(arr1);        // версія #1 для стеку
	Show(arr2);        // версія #1 для стеку
	Show(arr3, 2, 3); // версія #2 для кучі

	return 0;
	}

	Вам так само треба буде скористатися шаблонами.
*/

void show(const int* const* arr, const int rows, const int columns);

template <int r, int c>
void show(const int(&arr)[r][c]);

int main()
{
	// масиви на стеку
	int arr1[2][3] = {};
	int arr2[5][4] = {};

	// масив на кучі
	int** arr3 = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		arr3[i] = new int[3];
	}

	show(arr1);			// версія #1 для стеку
	show(arr2);			// версія #1 для стеку
	show(arr3, 2, 3);	// версія #2 для кучі

	for (int i = 0; i < 2; i++)
	{
		delete[] arr3[i];
	}
	delete[] arr3;

	return 0;
}

void show(const int* const* arr, const int rows, const int columns)
{
	std::cout << "Array (" << rows << ")(" << columns << ")\n";
	std::cout << "[\n";
	for (int r = 0; r < rows; r++)
	{
		std::cout << "  [";
		for (int c = 0; c < columns; c++)
		{
			std::cout << arr[r][c];

			if (c < columns - 1)
			{
				std::cout << ", ";
			}
		}

		if (r < rows - 1)
		{
			std::cout << "],\n";
		}
		else
		{
			std::cout << "]\n";
		}
	}
	std::cout << "]\n";
}

template <int r, int c>
void show(const int(&arr)[r][c])
{
	std::cout << "Array (" << r << ")(" << c << ")\n";
	std::cout << "[\n";
	for (int ri = 0; ri < r; ri++)
	{
		std::cout << "  [";
		for (int ci = 0; ci < c; ci++)
		{
			std::cout << arr[ri][ci];

			if (ci < c - 1)
			{
				std::cout << ", ";
			}
		}

		if (ri < r - 1)
		{
			std::cout << "],\n";
		}
		else
		{
			std::cout << "]\n";
		}
	}
	std::cout << "]\n";
}