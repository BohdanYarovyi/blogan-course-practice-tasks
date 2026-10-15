#ifndef AVERAGE_H
#define AVERAGE_H

#include <cstdint>
#include <iostream>

class Average
{
private:
	std::int32_t sum;
	std::int8_t  elements;

public:
	Average()
		: sum(0), elements(0)
	{
	}

	Average& operator+=(int value)
	{
		sum += value;
		elements++;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Average& avg);

};

#endif // !AVERAGE_H
