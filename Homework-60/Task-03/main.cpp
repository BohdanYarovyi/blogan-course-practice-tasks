#include <iostream>

/*
Напишіть програму, яка спочатку має вказівник на масив, значення якого nullptr. А також є змінна size, яка рівна 0 і відповідає за розмір масиву. 

В програми є наступне меню:
	* Показати масив з розміром
	* Додати новий елемент в кінець масиву (користувач вводить значення)
	* Видалити елемент з масиву (користувач вводить значення)

Тобто ви маєте написати програму, яка буде збільшувати і зменшувати динамічний масив за проханням користувача. Врахуйте наступну помилку: користувач не може видалити елемент, якщо масив уже пустий.
*/

void show_menu();

int get_user_choise();

bool does_option_exist(int option);

void use_option(int option, int** array, int* size);

void show(int* array, int size);

void add(int** array_ptr, int* size_ptr);

void remove(int** array_ptr, int* size_ptr);

bool contains(int e, int* array, int size);

const int PROGRAM_OPTIONS_COUNT = 4;
const int PROGRAM_OPTIONS[PROGRAM_OPTIONS_COUNT] = {1, 2, 3, 0};

int main()
{
	int  size  = 0;
	int* array = nullptr;

	while (true)
	{
		show_menu();
		int user_choise = get_user_choise();
		if (user_choise == 0)
		{
			break;
		}
		else
		{
			use_option(user_choise, &array, &size);
			std::cout << std::endl;
		}
	}

	return 0;
}

void show_menu()
{
	std::cout << "- Menu -\n";
	std::cout << " [1] Show an array and its size\n";
	std::cout << " [2] Add new element\n";
	std::cout << " [3] Remove element\n";
	std::cout << " [0] Leave\n";
}

int get_user_choise()
{
	std::cout << ">> ";
	int choise;
	while (true)
	{
		std::cin >> choise;

		if (does_option_exist(choise))
		{
			break;
		}
		else
		{
			std::cout << "Option " << choise << " doesn't exist. Please, choose an existing option leasten in the menu.\n";
		}
	}

	return choise;
}

bool does_option_exist(int option)
{
	for (int i = 0; i < PROGRAM_OPTIONS_COUNT; i++)
	{
		if (option == PROGRAM_OPTIONS[i])
		{
			return true;
		}
	}

	return false;
}

void use_option(int option, int** array, int* size)
{
	switch (option)
	{
		case 1: show(*array, *size); break;
		case 2: add(array, size); break;
		case 3: remove(array, size); break;
		default: std::cout << "Option haven't defined yet.\n";
	}
}

void show(int* array, int size)
{
	std::cout << "array(" << size << ") [";
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i];

		if (i < size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}

void add(int** array_ptr, int* size_ptr)
{
	std::cout << "add >> ";
	int e;
	std::cin >> e;

	int new_size = *size_ptr + 1;
	int* new_arrray = new int[new_size];

	for (int i = 0; i < *size_ptr; i++)
	{
		new_arrray[i] = (*array_ptr)[i];
	}
	new_arrray[new_size - 1] = e;

	delete[] *array_ptr;
	*array_ptr = new_arrray;
	*size_ptr = new_size;
}

void remove(int** array_ptr, int* size_ptr)
{
	if (*size_ptr == 0)
	{
		std::cout << "The array is empty\n";
		return;
	}

	std::cout << "remove >> ";
	int e;
	std::cin >> e;

	if (!contains(e, *array_ptr, *size_ptr))
	{
		std::cout << "Array doesn't contain " << e << std::endl;
		return;
	}

	int new_size = *size_ptr - 1;
	int* new_array = new int[new_size];

	bool element_skipped = false;
	int index = 0;
	for (int i = 0; i < *size_ptr; i++)
	{
		if (!element_skipped && (*array_ptr)[i] == e)
		{
			element_skipped = true;
			continue;
		}
		
		new_array[index] = (*array_ptr)[i];
		index++;
	}

	delete[] *array_ptr;
	*array_ptr = new_array;
	*size_ptr = new_size;
}

bool contains(int e, int* array, int size)
{
	for (int i = 0; i < size; i++) 
	{
		if (array[i] == e)
		{
			return true;
		}
	}

	return false;
}