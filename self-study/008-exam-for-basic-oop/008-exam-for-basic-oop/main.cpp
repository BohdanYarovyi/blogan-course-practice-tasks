#include <iostream>

#include "item.hpp"
#include "inventory.hpp"

int main() 
{
	Item i1 = {"Axe",				1,	3.400};
	Item i2 = {"Wood",				20, 1.500};
	Item i3 = {"Leather Jacket",	1,	4.200};
	Item i4 = {"Boots",				2,	3.700};
	Item i5 = {"Electronics",		15, 0.120};
	Item i6 = {"Potato",			30, 0.300};
	
	Inventory inventory = {};
	inventory.add_item(i1);
	inventory.add_item(i2);
	inventory.add_item(i3);
	inventory.add_item(i4);
	inventory.add_item(i5);
	inventory.add_item(i6);
	inventory.print();
	
	inventory.remove_item(3, 1);
	inventory.print();

	Item i7 = {"Ak-47", 1, 8.600};
	Item i8 = {"Plastik", 19, 0.450};
	inventory.add_item(i7);
	inventory.add_item(i8);
	inventory.print();

	inventory.remove_item(0, 1);
	inventory.print();

	Item i9 = {9, "Steal", 5, 5.000};
	Item i10 = {9, "Steal", 2, 5.000};
	inventory.add_item(i9);
	inventory.add_item(i10);
	inventory.print();
	return 0;
}