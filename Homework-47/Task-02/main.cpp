#include <iostream>
#include <numbers>

/*
Напишіть вбудовану функцію, яка рахує площу кола. Параметр - радіус. Повернення значення - площа.
*/

double get_circle_square(double radius);

int main()
{
	double r = 4.5;

	double circle_square = get_circle_square(r);
	std::cout << "Radius " << r << "\n";
	std::cout << "Square " << circle_square << "\n";

	return 0;
}

inline double get_circle_square(double radius)
{
	return std::numbers::pi * radius * radius;
}
