#include <iostream>

#include "item.hpp"
#include "string_utils.hpp"

int Item::m_id_provider = 1;

Item::Item(const char* name, int quantity, double unit_weight)
	: m_quantity(quantity), m_unit_weight(unit_weight)
{
	int name_length = String_Utils::get_string_length(name);
	
	m_name = String_Utils::create_copy(name, name_length);
	m_id = m_id_provider++;
	m_weight = unit_weight * quantity;
}

Item::Item(const Item& item)
	: m_id(item.m_id), m_unit_weight(item.m_unit_weight), m_quantity(item.m_quantity), m_weight(item.m_weight)
{
	int name_length = String_Utils::get_string_length(item.m_name);
	m_name = String_Utils::create_copy(item.m_name, name_length);
}

Item::Item(int id, const char* name, int quantity, double unit_weight)
	: m_id(id), m_quantity(quantity), m_unit_weight(unit_weight)
{
	int name_length = String_Utils::get_string_length(name);
	m_name = String_Utils::create_copy(name, name_length);
	m_weight = unit_weight * quantity;
}

Item::~Item()
{
	delete[] m_name;
}

void Item::print() const
{
	std::cout << "Item[id=" << m_id << ", name=" << m_name << ", quantity=" << m_quantity << ", weight=" << m_weight << "]\n";
}

void Item::add_quantity(int value)
{
	if (value <= 0) return;

	m_quantity += value;
	m_weight = m_quantity * m_unit_weight;
}

void Item::remove_quantity(int value)
{
	if (value <= 0 || m_quantity < value) return;

	m_quantity -= value;
	m_weight = m_quantity * m_unit_weight;
}

int Item::get_id() const
{
	return m_id;
}

const char* Item::get_name() const
{
	return m_name;
}

double Item::get_weight() const
{
	return m_weight;
}

int Item::get_quantity() const
{
	return m_quantity;
}

bool Item::equal(const Item& item_1, const Item& item_2)
{
	if (item_1.m_id != item_2.m_id) return false;
	if (!String_Utils::are_string_equal(item_1.m_name, item_2.m_name)) return false;

	return true;
}