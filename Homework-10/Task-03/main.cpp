#include <iostream>

/*
Виведіть на екран ось такий текст:

	It's lesson #10,
	and it's about RAW-strings.
	I'm doing my homework and everything looks easy.

	Використовуйте лише 1 std::cout. Весь текст находиться в ОДНОМУ RAW-рядку.
*/

int main() {
	std::cout << R"(
It's lesson #10,
and it's about RAW-strings.
I'm doing my homework and everything looks easy.
	)" << std::endl;

	return 0;
}