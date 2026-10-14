#ifndef CENTS_H
#define CENTS_H

class Dollars;

class Cents
{
private:
	int value;

public:
	Cents(int value);

	operator int();

	operator Dollars();
};

#endif // !CENTS_H
