#include <iostream>

/*
Давайте спробуємо модернізувати попередню задачу так, щоб у нас була крута функція, яка повертає рядок, який ввів користувач. У неї всередині має бути статичний символьний масив розміром 256 і кожний раз, коли ви її викликаєте, користувач вводить спочатку текст саме в нього, після чого виділяється пам'ять на кучі для динамічного рядка і в нього записуються всі ці символи. А в кінці функція повертає адресу цього рядка.

Тобто у вас є прототип:
`char* EnterString();`

Всередині відбувається наступне:
	char* EnterString()
	{
		static int BUFFER_SIZE = 256;
		static char buffer[BUFFER_SIZE];

		// 1. Користувач вводить текст в buffer.
		// 2. Визначається довжина buffer.
		// 3. Виділяється на кучі рядок з необхідною довжиною + нуль-символом.
		// 4. Символи з buffer копіюються в цей динамічний рядок.
		// 5. Функція повертає цей рядок.
	}

І тепер ви можете з легкістю писати наступне:
	std::cout << "Enter your name: ";
	const char* name = EnterString(); // Якщо я введу Demian, то name = "Demian" і має довжину 6

	std::cout << "Enter your surname: ";
	const char* surname = EnterString(); // Якщо я введу Bloganovich, то surname = "Bloganovich" і
	// має довжину 11

*/

char* enter_string();

int main()
{
	std::cout << "Enter your name: ";
	const char* name = enter_string();

	std::cout << "Enter your surname: ";
	const char* surname = enter_string();

	std::cout << "Welcome " << name << " " << surname << std::endl;
	return 0;
}

int get_length(char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	return length;
}

void copy_string(char* destination, const char* source)
{
	int i;
	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}

char* enter_string()
{
	const int BUFFER_SIZE = 256;
	const int TERMINATE_SYMBOL_LENGTH = 1;
	char buffer[BUFFER_SIZE] = {};

	std::cin.getline(buffer, BUFFER_SIZE);
	int length = get_length(buffer);

	char* string = new char[length + TERMINATE_SYMBOL_LENGTH];
	copy_string(string, buffer);
	
	return string;
}