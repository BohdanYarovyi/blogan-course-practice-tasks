#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <iostream>

class Int_Array
{
private:
	int array[10];

public:
	Int_Array();

	int& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const Int_Array& array);
};

#endif // INT_ARRAY_H