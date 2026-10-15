#include <iostream>

#include "BasketballPlayer.hpp"

int main()
{
	BasketballPlayer anton;
	anton.setName("Anton");
	std::cout << anton.getName();
}