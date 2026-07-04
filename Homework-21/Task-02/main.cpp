#include <iostream>

/*
Користувач вводить ціну товару, який він хоче купити.
На товарі пише ціна без урахування податків. Податок - 5% вартості товару.
Порахуйте податок, додайте його до вартості товару і виведіть ціну.
*/

int main() {
	const float TAX_IN_PERCENT = 5;
	
	float product_cost;
	std::cout << "Let me count final price with tax." << std::endl;
	std::cout << "What is cost of your product: ";
	std::cin >> product_cost;

	float product_price = product_cost + (product_cost / 100 * TAX_IN_PERCENT);
	std::cout << "The final price of your product is " << product_price << std::endl;
	return 0;
}