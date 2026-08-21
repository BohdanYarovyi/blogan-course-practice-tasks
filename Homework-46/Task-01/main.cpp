#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    Напишіть функцію void GeneratePassword(char password[], int arraySize, int length = 8) в якій:
     1. password - масив з пустими символами, куди має згенеруватися випадковий пароль
     2. arraySize - розмір масиву password, завдяки якому буде виконуватися перевірка за вихід за межі масиву
     3. length - довжина згенерованого паролю

    Ця функція має брати всі букви із таблиці ASCII (великі і малі англійські букви) і заповнити ними ваш масив. Якщо у вас є масив із 13 символів і ви указуєте length як 10, то масив має заповнитися ось так:
    "DUbLd0EQbq\0\0\0"

    Викличіть цю функцію 3 рази:
    - для масиву із 20 символів згенеруйте пароль довжиною в 20 символів
    - для масиву із 15 символів згенеруйте пароль довжиною в 5 символів
    - для масиву із 10 символів згенеруйте пароль довжиною в 8 символів (значення за замовчуванням)
*/
void set_random_seed();
int get_random_int(int from, int to);
void generate_password(char password[], int array_size, int length = 8);
char get_random_letter(int random_number);
void show_random_password(char password[], int array_size);

const int ENG_ALPHABET_SIZE = 26;

const int FIRST_CAPITAL_LETTER_INDEX = 65;

const int FIRST_LOWERCASE_LETTER_INDEX = 97;

int main()
{
	set_random_seed();
	const char PASSWORD_1_SIZE = 20;
	const char PASSWORD_2_SIZE = 15;
	const char PASSWORD_3_SIZE = 10;

	char password_1[PASSWORD_1_SIZE];
	char password_2[PASSWORD_2_SIZE];
	char password_3[PASSWORD_3_SIZE];

	generate_password(password_1, PASSWORD_1_SIZE, 20);
	generate_password(password_2, PASSWORD_2_SIZE, 5);
	generate_password(password_3, PASSWORD_3_SIZE);

	show_random_password(password_1, PASSWORD_1_SIZE);
	show_random_password(password_2, PASSWORD_2_SIZE);
	show_random_password(password_3, PASSWORD_3_SIZE);

	return 0;
}

void set_random_seed()
{
	std::srand(std::time(nullptr));
}

int get_random_int(int from, int to)
{
	return std::rand() % (from - to) + from;
}

void generate_password(char password[], int array_size, int length)
{
	if (length > array_size)
	{
		std::cout << "Array size must be more than array length!\n";
		return;
	}

	for (int s = 0, l = 0; s < array_size; s++)
	{
		if (l < length)
		{
			int random = get_random_int(0, ENG_ALPHABET_SIZE * 2);
			char random_letter = get_random_letter(random);
			password[s] = random_letter;
		}
		else
		{
			password[s] = '\0';
		}
	}
}

char get_random_letter(int random_number)
{
	int char_index = random_number % (ENG_ALPHABET_SIZE * 2);

	if (char_index < ENG_ALPHABET_SIZE)
	{
		return FIRST_CAPITAL_LETTER_INDEX + char_index;
	}
	else
	{
		return FIRST_LOWERCASE_LETTER_INDEX + (char_index - ENG_ALPHABET_SIZE);
	}
}

void show_random_password(char password[], int array_size)
{
	for (int i = 0; i < array_size; i++)
	{
		std::cout << password[i];
	}
	std::cout << "\n";
}
