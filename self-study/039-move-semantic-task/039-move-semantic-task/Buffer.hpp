#pragma once

#include <iostream>

class Buffer
{
private:
	int* number;

public:
	Buffer()
	{
		this->number = NULL;
		std::cout << "Buffer was created with NULL\n";
	}

	Buffer(int number)
	{
		this->number = new int(number);
		std::cout << "Buffer was created with value " << number << "\n";
	}

	Buffer(const Buffer& other)
	{
		number = other.number ? new int(*other.number) : nullptr;
		std::cout << "Buffer was created by copying\n";
	}

	Buffer(Buffer&& other) noexcept
		: number(other.number)
	{
		other.number = nullptr;
		std::cout << "Buffer was created by moving\n";
	}

	~Buffer()
	{
		delete number;
		std::cout << "Buffer was destroyed\n";
	}

	Buffer& operator=(const Buffer& other)
	{
		if (&other == this)
		{
			return *this;
		}

		delete number;
		number = other.number ? new int(*other.number) : nullptr;

		std::cout << "Buffer was copied by operator=\n";
		return *this;
	}

	Buffer& operator=(Buffer&& other) noexcept
	{
		if (&other == this)
		{
			return *this;
		}

		delete number;

		number = other.number;
		other.number = nullptr;
		std::cout << "Buffer was moved by operator=\n";

		return *this;
	}

	int get()
	{
		if (!number) 
		{
			return 0;
		}
		
		return *number;
	}
};