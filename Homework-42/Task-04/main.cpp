#include <iostream>

/*
Щоб не повторювати умову з попередньої задачі, буду тепер пойстійно казати "Користувач вводить речення". Це означає, що у вас має бути масив з достатньої кількості символів (наприклад 100) і ви маєте вводити це речення завдяки cin.getline. Так от...

Користувач вводить речення, після цього вводить два символи. Перший - той, який він хоче замінити в рядку. Другий - той, на який треба замінити. Наприклад, якщо користувач введе речення "Hello World", а потім символи 'l' та 'M', ваш рядок має стати ось таким:
	"HeMMo WorMd"
*/

int main() {
	constexpr int TEXT_MAX_LENGTH = 100;

	char text[TEXT_MAX_LENGTH];
	char replaceble_letter;
	char new_letter;

	std::cout << "Enter text: ";
	std::cin.getline(text, TEXT_MAX_LENGTH);
	std::cout << "Give a letter which you replace: ";
	std::cin >> replaceble_letter;
	std::cout << "Give new letter instead '" << replaceble_letter << "': ";
	std::cin >> new_letter;

	for (int i = 0; text[i] != '\0'; i++) {
		char letter = text[i];

		if (letter == replaceble_letter) {
			text[i] = new_letter;
		}
	}

	std::cout << "Edited sentence: " << text << std::endl;
	return 0;
}
