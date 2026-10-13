#ifndef DOLLARS_H
#define DOLLARS_H

class Dollars
{
private:
	int value;

public:
	Dollars(int value);

	Dollars operator-() const;

	int get_value() const;
};

#endif // !DOLLARS_H
