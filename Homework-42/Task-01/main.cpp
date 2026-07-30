#include <iostream>

/*
Напишіть програму, в якій є 2 масиви-рядки. В першому записане слово "Hello", а в другому "World". Ця програма має створити 3 масив, розмір якого буде достатній, щоб вмістити в собі об'єднання цих двох рядків. Тобто в третьому масиві має бути значення "Hello World" але ви маєте задати йому таке значення наступним чином:
    - Спочатку скопіювавши вміст першого рядка.
    - Потім дописати пробіл.
    - Потім дописати вміст другого рядка.

Виведіть результуючий рядок на екран.
*/

int main() {
	constexpr int GREETING_LENGTH = 5;
	constexpr int OBJECT_LENGTH = 5;
	constexpr int SPACES = 1;
	constexpr int TERMINATE_CHAR = 1;

	char greeting[GREETING_LENGTH + TERMINATE_CHAR] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char object[OBJECT_LENGTH + TERMINATE_CHAR] = {'W', 'o', 'r', 'l', 'd', '\0'};
	char phrase[GREETING_LENGTH + OBJECT_LENGTH + SPACES + TERMINATE_CHAR];

	// copy greeting
	int phrase_index = 0;
	for (int i = 0; i < GREETING_LENGTH; i++) {
		phrase[phrase_index] = greeting[i];
		phrase_index++;
	}

	// put a whitespace
	phrase[phrase_index] = ' ';
	phrase_index++;

	// copy object
	for (int i = 0; i < OBJECT_LENGTH; i++) {
		phrase[phrase_index] = object[i];
		phrase_index++;
	}

	// put a terminate char
	phrase[phrase_index] = '\0';

	std::cout << "Greeting '" << greeting << "' with length " << GREETING_LENGTH << std::endl;
	std::cout << "Object '" << object << "' with length " << OBJECT_LENGTH << std::endl;
	std::cout << "Phrase '" << phrase << "' with length " << phrase_index << std::endl;
	return 0;
}
