#ifndef DOLLARS_H
#define DOLLARS_H

class Dollars
{
private:
	int m_dollars;

public:
	Dollars(int value);

	int get_value() const;
};

Dollars operator+(const Dollars& object_1, const Dollars& object_2);

#endif // !DOLLARS_H
