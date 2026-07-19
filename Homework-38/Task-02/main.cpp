#include <iostream>

/*
2. Спробуйте вивести на екран трикутник з висотою 5 рядків.
Ось такий:
	*
	**
	***
	****
	*****
*/

int main() {
	constexpr int rows = 5;
	constexpr char s = '*';

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < r + 1; c++) {
			std::cout << s;
		}

		std::cout << std::endl;
	}
	return 0;
}