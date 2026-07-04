#include <iostream>

/*
Треба порахувати перимметр квадрата зі стороною 4. Створіть змінну side = 4. Також створіть змінну perimeter,
значення якої рахується завдяки змінній side.
Виведіть на екран повідомлення, яке говорить, яка довжина і периметр у квадрата.
*/

int main() {
	int side = 4;
	int perimeter = side * 4;
	std::cout << "Quadrat side: " << side << std::endl;
	std::cout << "Quadrat perimeter: " << perimeter << std::endl;
	return 0;
}