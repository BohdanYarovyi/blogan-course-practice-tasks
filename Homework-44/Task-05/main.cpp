#include <iostream>

/*
    Переробимо попередню задачу. Представимо, що я хочу вивести значення константи PI у файлі Main.cpp. Для цього у файлі Math.cpp додайте функцію double Pi(), яка повертає значення цієї константи. Скористайтеся нею у функції main.

    Також додайте до файлу Math.cpp СТАТИЧНУ функцію double RadiusSquare(double radius), яка повертає квадрат радіуса. Використайте її у функції CalculateCircleArea.
 */

double calculate_circle_area(double radius);

double calculate_circle_length(double radius);

double pi();

int main() {
	int radius = 12;
	double pi_value = pi();
	double area = calculate_circle_area(radius);
	double length = calculate_circle_length(radius);

	std::cout << "Radius: " << radius 	<< std::endl;
	std::cout << "PI: " 	<< pi_value << std::endl;
	std::cout << "Area: " 	<< area 	<< std::endl;
	std::cout << "Length: " << length 	<< std::endl;

	return  0;
}
