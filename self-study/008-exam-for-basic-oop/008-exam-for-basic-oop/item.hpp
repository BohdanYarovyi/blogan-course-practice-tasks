#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
	static int m_id_provider;
	int m_id;
	char* m_name;
	int m_quantity;
	double m_weight;
	const double m_unit_weight;

public:
	Item(const char* name, int quantity, double unit_weight);

	Item(const Item& item);

	Item(int id, const char* name, int quantity, double unit_weight);

	~Item();

	void print() const;

	void add_quantity(int value);
	
	void remove_quantity(int value);
	
	int get_id() const;
	
	const char* get_name() const;
	
	double get_weight() const;
	
	int get_quantity() const;

	static bool equal(const Item& item_1, const Item& item_2);
};

#endif // !ITEM_H
