#include <iostream>

/*
Равлик знаходиться в пункті А. Відстань, яку він пройшов - 0.
Виведіть відстань.
Наступного дня равлик проповз 17 метрів. Додайте її до відстані.
Виведіть відстань.
Наступного дня равлик проповз 13 метрів. Додайте її до відстані.
Виведіть відстань.
На останній день равлик проповз 8 метрів. Додайте її до відстані.
Виведіть відстань.
*/

int main() {
	int distance = 0;

	// day 1
	std::cout << "Day 1:" << std::endl;
	std::cout << "  The snail located in side A." << std::endl;
	std::cout << "  Total distance: " << distance << std::endl;

	// day 2
	distance += 17;
	std::cout << "Day 2:" << std::endl;
	std::cout << "  The snail has covered 17 meters." << std::endl;
	std::cout << "  Total distance: " << distance << std::endl;

	// day 3
	distance += 13;
	std::cout << "Day 3:" << std::endl;
	std::cout << "  The snail has covered 13 meters." << std::endl;
	std::cout << "  Total distance: " << distance << std::endl;

	// day 4
	distance += 8;
	std::cout << "Day 4:" << std::endl;
	std::cout << "  The snail has covered 8 meters." << std::endl;
	std::cout << "  Total distance: " << distance << std::endl;

	return 0;
}