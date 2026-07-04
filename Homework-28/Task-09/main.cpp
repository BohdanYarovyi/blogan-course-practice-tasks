#include <iostream>

/*
Ви пишете розумну програму, яка включає світло в тій кімнаті, яку вкаже користувач. 
Ви питаєте в нього число:
"Введіть число щоб увімкнути світло:"
	"1 - ванна"
	"2 - спальня"
	"3 - кухня"
	"4 - коридор"
Користувач вводить число і програма виводить повідомлення про те, яка кімната загорілась.
*/

int main() {
	int number;

	std::cout << "Enter a number to light a room: " << std::endl;
	std::cout << "\t1 - bathroom" << std::endl;
	std::cout << "\t2 - badroom" << std::endl;
	std::cout << "\t3 - kitchen" << std::endl;
	std::cout << "\t4 - corridor" << std::endl;
	std::cout << ">> ";
	std::cin >> number;

	if (number == 1) {
		std::cout << "The bathroom was lighted" << std::endl;
	}
	else if (number == 2) {
		std::cout << "The badroom was lighted" << std::endl;
	}
	else if (number == 3) {
		std::cout << "The kitchen was lighted" << std::endl;
	}
	else if (number == 4) {
		std::cout << "The corridor was lighted" << std::endl;
	} else {
		std::cout << number << " is not bind for any other room" << std::endl;
	}

	return 0;
}