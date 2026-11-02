#include <iostream>
#include <memory>

#include "Fraction.hpp"
#include "Human.hpp"

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
	//std::unique_ptr fraction = std::make_unique<Fraction>(7, 9);

	//printFraction(fraction.get());

	std::shared_ptr<Human> anton = std::make_shared<Human>("Anton");
	std::shared_ptr<Human> ivan = std::make_shared<Human>("Ivan");
	partnerUp(anton, ivan);

	return 0;
}