#include <iostream>
#include <Windows.h>

/*
Виведіть на екран французьке речення "Connerie complete.".
*/

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	std::cout << "C'est une connerie complète !" << std::endl;

	return 0;
}