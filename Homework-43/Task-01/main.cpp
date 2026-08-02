#include <iostream>

/*
Напишіть функцію "void ShowHello()", що виводить на екран слово "Hello".
Викличіть її 5 разів, використовуючи цикл.
*/

void show_hello();

int main() {
	for (int i = 0; i < 5; i++) {
		show_hello();
	}
	return 0;
}

void show_hello() {
	std::cout << "Hello world!" << std::endl;
}
