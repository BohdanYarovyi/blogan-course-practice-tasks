#pragma once

#include "ArrayException.hpp"

class ArrayInt
{
  private:
	int* array;
	int size;

  public:
	ArrayInt(int size)
		: size(size)
	{
		if (size <= 0)
		{
			throw ArrayException("Incorrect size of an array");
		}

  		array = new int[size] {0};
	}

	~ArrayInt()
	{
		delete[] array;
	}

	int& operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw ArrayException("Index out of bound");
		}

		return array[index];
	}
};
