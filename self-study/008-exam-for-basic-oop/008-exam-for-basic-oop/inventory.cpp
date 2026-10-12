#include <iostream>

#include "inventory.hpp"

namespace
{
	bool contains(const Item& item, const Item* const* items, int items_size);

	int find_item_index(const Item& item, const Item* const* items, int items_size);

	int find_free_index(const Item* const* items, int items_size);
}

Inventory::Inventory()
{
	m_items = new Item*[MAX_INVENTORY_ITEMS] {nullptr};
	m_items_count = 0;
	m_weight = 0;
}

Inventory::~Inventory()
{
	for (int i = 0; i < MAX_INVENTORY_ITEMS; i++)
	{
		delete m_items[i];
	}
	delete[] m_items;
}

bool Inventory::add_item(const Item& item)
{
	bool has_free_load = item.get_weight() + m_weight <= MAX_INVENTORY_LOAD;
	bool item_contains = contains(item, m_items, MAX_INVENTORY_ITEMS);

	if (item_contains && has_free_load)
	{
		int index = find_item_index(item, m_items, MAX_INVENTORY_ITEMS);
		m_items[index]->add_quantity(item.get_quantity());
		m_weight += item.get_weight();

		return true;
	}
	else if (has_free_load)
	{
		bool has_available_space = m_items_count < MAX_INVENTORY_ITEMS;
		if (has_available_space)
		{
			int free_index = find_free_index(m_items, MAX_INVENTORY_ITEMS);
			m_items[free_index] = new Item(item);
			m_weight += item.get_weight();
			m_items_count++;

			return true;
		}
	}

	return false;
}

Item* Inventory::remove_item(int inventory_index, int quantity)
{
	if (quantity <= 0)
	{
		return nullptr;
	}
	
	if (inventory_index < 0 || inventory_index >= MAX_INVENTORY_ITEMS)
	{
		return nullptr;
	}

	if (m_items[inventory_index] == nullptr)
	{
		return nullptr;
	}

	if (quantity >= m_items[inventory_index]->get_quantity())
	{
		Item* removed_item = m_items[inventory_index];
		m_items[inventory_index] = nullptr;
		m_items_count--;
		m_weight -= removed_item->get_weight();

		return removed_item;
	}

	Item* inventory_item = m_items[inventory_index];
	Item* removed_item = new Item(*inventory_item);
	int remainder = inventory_item->get_quantity() - quantity;

	inventory_item->remove_quantity(quantity);
	removed_item->remove_quantity(remainder);
	m_weight -= removed_item->get_weight();

	return removed_item;
}

const Item* Inventory::find_item(int id) const
{
	for (int i = 0; i < MAX_INVENTORY_ITEMS; i++)
	{
		const Item* item_p = m_items[i];

		if (item_p != nullptr && item_p->get_id() == id)
		{
			return item_p;
		}
	}

	return nullptr;
}

double Inventory::get_weight() const
{
	return m_weight;
}

void Inventory::print() const
{
	std::cout << "Inventory: Weight = " << m_weight << " Items = " << m_items_count << "\n";
	std::cout << "[\n";
	for (int i = 0; i < MAX_INVENTORY_ITEMS; i++)
	{
		std::cout << "  [" << i + 1 << "] ";
		const Item* item_p = m_items[i];
		if (item_p == nullptr)
		{
			std::cout << "Empty\n";
		}
		else
		{
			item_p->print();
		}
	}
	std::cout << "]\n";
}

namespace
{
	bool contains(const Item& item, const Item* const* items, int items_size)
	{
		for (int i = 0; i < items_size; i++)
		{
			const Item* inventory_item = items[i];
			if (inventory_item == nullptr)
			{
				continue;
			}

			if (Item::equal(item, *inventory_item))
			{
				return true;
			}
		}

		return false;
	}

	int find_item_index(const Item& item, const Item* const* items, int items_size)
	{
		for (int i = 0; i < items_size; i++)
		{
			const Item* item_p = items[i];
			if (item_p != nullptr && Item::equal(item, *item_p))
			{
				return i;
			}
		}

		return -1;
	}

	int find_free_index(const Item* const* items, int items_size) 
	{
		for (int i = 0; i < items_size; i++)
		{
			if (items[i] == nullptr)
			{
				return i;
			}
		}

		return -1;
	}
}
