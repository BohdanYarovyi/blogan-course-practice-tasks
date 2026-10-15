#ifndef DROB_H
#define DROB_H

#include <iostream>

class Drob
{
private:
	int numerator;
	int denominator;

public:
	Drob(int numerator = 0, int denominator = 1);

	Drob(const Drob& other);

	friend std::ostream& operator<<(std::ostream& out, const Drob& drob);
};

#endif // !DROB_H
