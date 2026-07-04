#include <iostream>

/*
У батька є зайві 71 гривні. Три сина просять у батька грошей.
Батько вирішив дати їм однакову суму. Яку максимальну суму 
він може їм дати і скільки у нього залишиться решти?
*/

int main() {
	float father_money = 71;
	int father_sons = 3;
	std::cout << "Father has $ " << father_money << "." << std::endl;
	std::cout << "Father has " << father_sons << " sons." << std::endl;

	int money_per_son = father_money / father_sons;
	father_money -= father_sons * money_per_son;

	std::cout << "Father give $ " << money_per_son << " to each son." << std::endl;
	std::cout << "Father has $ " << father_money << " after giveaway." << std::endl;

	return 0;
}