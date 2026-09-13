#include <iostream>

/*
Напишіть функцію, яка приймає масив вказівників на рядки і сортує його. 
Тобто, щоб результат був такий:
	const int NAMES_COUNT = 5;
	const char* names[NAMES_COUNT] = { "Demian", "Aleksandr", "Zillo", "Olga", "Helena" };
	Sort(names, NAMES_COUNT);

	Show(names, NAMES_COUNT); // має бути:
	// Aleksandr
	// Demian
	// Helena
	// Olga
	// Zillo
*/

void sort(const char** names, const int names_count);

void show(const char** names, const int names_count);

int main()
{
	const int NAMES_COUNT = 7;
	const char* names[NAMES_COUNT] = {"Demian", "Alexonder", "Alexander", "Zillo", "Olga", "Helena", "Alex"};

	sort(names, NAMES_COUNT);
	show(names, NAMES_COUNT);

	return 0;
}

/*
	returns:
		> 0 - when str1 is greater than str2
		< 0 - when str1 is lower than str2
		0 - when str1 and str2 are equal
*/
static int compare(const char* str1, const char* str2)
{
	char a = *str1;
	char b = *str2;

	if (a == '\0')
	{
		return 1;
	}
	if (b == '\0')
	{
		return -1;
	}

	if (a == b)
	{
		return compare(str1 + 1, str2 + 1);
	}

	return b - a;
}

static void swap(const char** name, const int index_1, const int index_2)
{
	const char* tmp = *(name + index_1);
	*(name + index_1) = *(name + index_2);
	*(name + index_2) = tmp;
}

void sort(const char** names, const int names_count)
{
	for (int i = 0; i < names_count; i++)
	{
		for (int k = 0; k < names_count - 1 - i; k++)
		{
			const char* name1 = names[k];
			const char* name2 = names[k + 1];
			
			if (compare(name1, name2) < 0)
			{
				swap(names, k, k + 1);
			}
		}
	}
}

void show(const char** names, const int names_count)
{
	std::cout << "names [";
	for (int i = 0; i < names_count; i++)
	{
		const char* name = names[i];

		while (*name != '\0')
		{
			std::cout << *name;
			name++;
		}
		if (i < names_count - 1) 
		{
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}
