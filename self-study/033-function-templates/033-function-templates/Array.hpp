#pragma once

#include <iostream>

template <typename T> 
class Array final
{
protected:
	const int DEFAULT_LENGTH = 10;
	int length;
	T** array;

public:
	Array()
	{
		length = DEFAULT_LENGTH;
		array = new T*[length] {};
	}

	Array(int length)
	{
		if (length <= 0)
		{
			std::cout << "Array length wasn't provided. Default length was set (" << DEFAULT_LENGTH << ")\n";
			length = DEFAULT_LENGTH;
		}
		this->length = length;
		array = new T*[length] {};
	}

	~Array()
	{
		for (int i = 0; i < length; i++)
		{
			delete array[i];
		}
		delete[] array;
	}

	T*& operator[](int index)
	{
		return array[index];
	}
};