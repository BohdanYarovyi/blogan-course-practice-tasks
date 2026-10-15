#include "Average.hpp"

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
	if (avg.elements == 0)
	{
		out << 0;
		return out;
	}

	out << (avg.sum / avg.elements);
	return out;
}
