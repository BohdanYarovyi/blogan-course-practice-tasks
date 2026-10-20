#pragma once

#include <iostream>

template <typename T>
class Repository8 final
{
private:
	T array[8];

public:
	Repository8(const T array[8])
	{
		for (int i = 0; i < 8; i++)
		{
			this->array[i] = array[i];
		}
	}

	~Repository8() = default;

	void set(int index, const T& value)
	{
		array[index] = value;
	}

	const T& get(int index) const
	{
		return array[index];
	}

	void print() const
	{
		for (int i = 0; i < 8; i++)
		{
			std::cout << get(i) << ' ';
		}
		std::cout << '\n';
	}
};

template <>
class Repository8<bool> final
{
private:
	unsigned char data = 0;

public:
	Repository8<bool>(const bool data[8])
	{
		for (int i = 0; i < 8; i++)
		{
			set(i, data[i]);
		}
	}

	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value)
		{
			data = data | mask;
		}
		else
		{
			data = data & ~mask;
		}
	}

	bool get(int index) const
	{
		unsigned char mask = 1 << index;

		return data & mask;
	}

	void print() const
	{
		for (int i = 0; i < 8; i++)
		{
			std::cout << get(i) << ' ';
		}
		std::cout << '\n';
	}
};