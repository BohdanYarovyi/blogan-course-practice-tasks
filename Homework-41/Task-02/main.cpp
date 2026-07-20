#include <iostream>

/*
Напишіть програму, яка створює трьохвимірний масив типу float розмірами
2 на 3 на 4. Ініціалізуйте масив любими значеннями завдяки списковій ініціалізації 
і виведіть цей масив на екран так, як вам подобається.
*/

int main() {
	constexpr int OUTER_ARRAY_SIZE = 2;
	constexpr int MIDDLE_ARRAY_SIZE = 3;
	constexpr int INNER_ARRAY_SIZE = 4;

	float numbers[OUTER_ARRAY_SIZE][MIDDLE_ARRAY_SIZE][INNER_ARRAY_SIZE]
	{
		{{1.25, 2.75, 3.5, 4.125},		{5.6, 6.3, 7.9, 8.05},		{9.4, 10.15, 11.75, 12.6}},
		{{13.33, 14.8, 15.05, 16.9},	{17.45, 18.2, 19.6, 20.75}, {21.1, 22.85, 23.3, 24.95}},
	};

	for (int outer = 0; outer < OUTER_ARRAY_SIZE; outer++) {
		for (int middle = 0; middle < MIDDLE_ARRAY_SIZE; middle++) {
			for (int inner = 0; inner < INNER_ARRAY_SIZE; inner++) {
				std::cout << "numbers[" << outer << "][" << middle << "][" << inner << "] = " 
				<< numbers[outer][middle][inner] << std::endl;
			}
		}
	}
	
	return 0;
}