#include <iostream>

/*
Створіть змінну типу short з іменем distance, яка зберігає відстань в метрах між двома людьми.
Вона рівна значенню 2. 
Виведіть її значення на екран в повідомленні:
	Distance between me and you (ваша змінна)m.
*/

int main() {
	short distance = 2;
	std::cout << "Distance between me and you " << distance << "m." << std::endl;
	return 0;
}