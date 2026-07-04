#include <iostream>
#include <string>

/*
Виведіть на екран своє ім'я завдяки одному рядку коду (використовуючи std::cout),
після цього напишіть ще один рядок коду, який виводить на екран призвіще (використовуючи std::cout).
*/

int main() {
	std::string name = "Bohdan";
	std::string surname = "Yarovyi";

	std::cout << name << std::endl;
	std::cout << surname << std::endl;
	return 0;
}