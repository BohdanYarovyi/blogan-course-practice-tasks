#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.hpp"

class Inventory
{
private:
	const int MAX_INVENTORY_LOAD = 100;
	const int MAX_INVENTORY_ITEMS = 20;
	Item** m_items;
	double m_weight;
	int m_items_count;

public:
	Inventory();

	~Inventory();

	bool add_item(const Item& item);

	Item* remove_item(int inventory_index, int quantity);

	const Item* find_item(int id) const;

	double get_weight() const;

	void print() const;
};

#endif // !INVENTORY_H
