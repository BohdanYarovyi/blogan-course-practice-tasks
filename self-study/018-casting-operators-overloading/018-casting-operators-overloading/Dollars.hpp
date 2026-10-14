#ifndef DOLLARS_H
#define DOLLARS_H

class Cents;

class Dollars
{
private: 
	int value;

public:
	Dollars(int value);

	operator int();

	operator Cents();
};

#endif // !DOLLARS_H
