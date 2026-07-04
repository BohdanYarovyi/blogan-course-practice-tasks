#include <iostream>
#include <cmath>

/*
Ну що, знову попрацюємо з колом? У кола є радіус 20. Знайдіть діаметр, площу і довжину кола.
Для цього у вас мають бути 4 змінні + 1 константа. Думаю, догадуєтесь яка. 
Застосуйте її і виведіть всі значення на екран.
*/

const float PI = 3.14f;

float countCircleLength(float radius) {
	return radius * 2 * PI;
}

float countCircleDiameter(float radius) {
	return radius * 2;
}

float countCircleSquare(float radius) {
	return PI * std::pow(radius, 2.0f);
}

int main() {
	float radius = 20.0f;
	
	float circle_C = countCircleLength(radius);
	float circle_D = countCircleDiameter(radius);
	float circle_S = countCircleSquare(radius);

	std::cout << "Circle:" << std::endl;
	std::cout << "\tradius	 = " << radius << std::endl;
	std::cout << "\tdiameter = " << circle_D << std::endl;
	std::cout << "\tlength	 = " << circle_C << std::endl;
	std::cout << "\tsquare	 = " << circle_S << std::endl;

	return 0;
}