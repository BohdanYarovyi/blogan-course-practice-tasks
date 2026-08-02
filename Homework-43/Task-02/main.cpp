#include <iostream>

/*
Напишіть функції "void HelloDemian()" та "void HelloKassy()".
- Перша функція виводить текст "Hello Demian"
- друга функція виводить текст "Hello Kassy"

Викличіть їх так, щоб на екрані було наступне:
	Hello Demian
	Hello Kassy
	Hello Kassy
	Hello Demian
	Hello Kassy
*/

void hello_demian();

void hello_kassy();

int main() {
	hello_demian();
	hello_kassy();
	hello_kassy();
	hello_demian();
	hello_kassy();
	return 0;
}

void hello_demian() {
	std::cout << "Hello Demian" << std::endl;
}

void hello_kassy() {
	std::cout << "Hello Kassy" << std::endl;
}
