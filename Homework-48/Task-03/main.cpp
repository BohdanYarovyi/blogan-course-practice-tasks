#include <iostream>
#include <cassert>

/*
	Напишіть наступні функції:
	double CalculateArea(double side) - повертає площу квадрата по указаній стороні
	double CalculateArea(double length, double width) - повертає площу прямокутника по указаним сторонам
*/

double calculate_area(double side);

double calculate_area(double length, double width);

void run_tests();

int main()
{
	run_tests();
	return 0;
}

double calculate_area(double side)
{
	return side * side;
}

double calculate_area(double length, double width)
{
	return length * width;
}

bool is_close(double a, double b, double epsilon = 1e-6) {
    return std::abs(a - b) < epsilon;
}

void run_tests() {
    // 1. Тести для calculate_area(side) — площа квадрата
    assert(is_close(calculate_area(5.0), 25.0));
    assert(is_close(calculate_area(2.5), 6.25));
    assert(is_close(calculate_area(0.0), 0.0)); // крайній випадок: сторона 0

    // 2. Тести для calculate_area(length, width) — площа прямокутника
    assert(is_close(calculate_area(4.0, 5.0), 20.0));
    assert(is_close(calculate_area(2.5, 4.0), 10.0));
    assert(is_close(calculate_area(3.0, 0.0), 0.0));  // крайній випадок: одна зі сторін 0
    assert(is_close(calculate_area(7.2, 3.5), 25.2));

    std::cout << "Усі тести для calculate_area успішно пройдено!" << std::endl;
}
