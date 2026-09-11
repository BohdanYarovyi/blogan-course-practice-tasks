#include <iostream>
#include <ctime>
#include <cstdlib>

/*
Є 3 змінні одного типу, наприклад int. Ініціалізуйте їх випадковим значенням. Завдяки ОДНОМУ вказівнику виведіть їх значення на екран, а також їх адресу завдяки вказівнику.
*/

int main()
{
	std::srand(std::time(nullptr));
	int a = std::rand();
	int b = std::rand();
	int c = std::rand();

	int *p_viwer = &a;
	std::cout << "p_viwer = " << p_viwer << std::endl;
	std::cout << "a value = " << *p_viwer << std::endl;

	p_viwer = &b;
	std::cout << "p_viwer = " << p_viwer << std::endl;
	std::cout << "b value = " << *p_viwer << std::endl;

	p_viwer = &c;
	std::cout << "p_viwer = " << p_viwer << std::endl;
	std::cout << "c value = " << *p_viwer << std::endl;

	return 0;
}
