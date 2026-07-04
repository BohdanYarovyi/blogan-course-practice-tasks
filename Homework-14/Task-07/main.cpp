#include <iostream>

/*
Користувач вводить кількість курей, свиней і корів. Виведіть на екран,
скільки всього є тварин і скільки у них ніг разом.
*/

int main() {
	const int COW_PAW_COUT = 4;
	const int PIG_PAW_COUT = 4;
	const int CHICKEN_PAW_COUT = 2;
	int cows;
	int pigs;
	int chickens;

	std::cout << "Do you have pets? I need count all of my cattle. Just enter counts when I ask. Ok?)" << std::endl;
	std::cout << "How many cows do I have? ";
	std::cin >> cows;
	std::cout << "How many pigs do I have? ";
	std::cin >> pigs;
	std::cout << "How many chickens do I have? ";
	std::cin >> chickens;

	int totalAmount = cows + pigs + chickens;
	int totalLegs = cows * COW_PAW_COUT + pigs * PIG_PAW_COUT + CHICKEN_PAW_COUT * chickens;
	std::cout << "Ohh yee. I have a good news. Now numbers are bigger than in previous time." << std::endl;
	std::cout << "It means that we have addition)" << std::endl;
	std::cout << "Now we have " << totalAmount << " heads in total." << std::endl;
	std::cout << "All cattles have " << totalLegs << " legs in sum." << std::endl;

	return 0;
}