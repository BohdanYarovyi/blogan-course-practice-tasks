#ifndef DOLLARS_H
#define DOLLARS_H

class Dollars
{
private:
	int value;

public:
	Dollars(int value);

	friend bool operator>(const Dollars& d1, const Dollars& d2);

	friend bool operator<(const Dollars& d1, const Dollars& d2);

	friend bool operator>=(const Dollars& d1, const Dollars& d2);

	friend bool operator<=(const Dollars& d1, const Dollars& d2);
};

#endif // DOLLARS_H
