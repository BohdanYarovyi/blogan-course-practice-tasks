#include <iostream>
#include <memory>

#include "Fraction.hpp"

class Item
{
public:
	Item()
	{
		std::cout << "Item was created by constructor\n";
	}

	~Item()
	{
		std::cout << "Item was destroyed\n";
	}

	void printHello()
	{
		std::cout << "Hello\n";
	}
};

void printFraction(const Fraction* const ptr)
{
	if (ptr)
		std::cout << *ptr;
}

int main()
{
	std::unique_ptr fraction = std::make_unique<Fraction>(7, 9);

	printFraction(fraction.get());

	return 0;
}