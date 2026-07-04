#include <iostream>

/*
Користувач вводить 3 числа:
	1. Відстань від міста A до міста B
	2. Відстань від міста B до міста C
	3. Відстань від міста C до міста D
Порахуйте загальну відстань і виведіть її на екран.
(Використовуйте оператори = та +)
*/

int main() {
	int distance_AB;
	int distance_BC;
	int distance_CD;

	std::cout << "Enter the distance between city A and city B: ";
	std::cin >> distance_AB;
	std::cout << "Enter the distance between city B and city C: ";
	std::cin >> distance_BC;
	std::cout << "Enter the distance between city C and city D: ";
	std::cin >> distance_CD;

	int total_distance = distance_AB + distance_BC + distance_CD;
	std::cout << "The total distance A -> B -> C -> D is " << total_distance << "." << std::endl;
	return 0;
}