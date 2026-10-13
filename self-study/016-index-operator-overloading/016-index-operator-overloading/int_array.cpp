#include "int_array.hpp"

Int_Array::Int_Array()
	: array {}
{
}

int& Int_Array::operator[](int index)
{
	return array[index];
}

std::ostream& operator<<(std::ostream& out, const Int_Array& array)
{
	out << "Array (l=10) [";
	for (int i = 0; i < 10; i++)
	{	
		out << array.array[i];

		if (i < 9)
		{
			out << ", ";
		}
	}
	out << "]";

	return out;
}
