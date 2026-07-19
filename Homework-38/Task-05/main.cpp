#include <iostream>

/*
Виведіть табличку множення на екран для чисел від 1 до 9. 
Тобто має бути приблизно ось так:
	1 x 1 = 1
	1 x 2 = 2
	...
	1 x 9 = 9
	---------
	2 x 1 = 2
	2 x 2 = 4
	...
	2 x 9 = 18
	---------
	...
*/

int main() {
	constexpr int START	 = 1;
	constexpr int END	 = 10;

	for (int i = START; i < END; i++) {
		for (int j = START; j < END; j++) {
			std::cout << i << " x " << j << " = " << i * j << std::endl;
		}

		std::cout << "-----------" << std::endl;
	}

	return 0;
}