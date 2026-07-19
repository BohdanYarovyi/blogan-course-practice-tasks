#include <iostream>

/*
Створіть масив типу double з іменем temperatures розміром 3. Напишіть три рядки,
в який вручну задайте кожному елементу наступні значення:
	17.3
	18.5
	17.9
*/

int main() {
	constexpr int TEMPERATURES_ARRAY_SIZE = 3;

	double temperatures[TEMPERATURES_ARRAY_SIZE];

	temperatures[0] = 17.3;
	temperatures[2] = 18.5;
	temperatures[1] = 17.9;

	return 0;
}