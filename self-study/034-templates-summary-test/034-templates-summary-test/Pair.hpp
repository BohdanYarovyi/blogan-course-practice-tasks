#pragma once

#include <iostream>

#include "./../../mylib/StringUtility.hpp"

template <typename T1, typename T2>
class Pair
{
protected:
	T1 first;
	T2 second;

public:
	Pair(T1 first, T2 second)
		: first(first), second(second)
	{
	}

	~Pair() = default;

	T1 getFirst() const
	{
		return first;
	}

	T2 getSecond() const
	{
		return second;
	}

	friend std::ostream& operator<<(std::ostream& out, const Pair<T1, T2>& pair)
	{
		out << "Pair(first=" << pair.first << ", second=" << pair.second << ")";
		return out;
	}
};

template <typename T>
class Pair<char*, T>
{
private:
	char* string;
	T second;

public:
	Pair(const char* string, T second)
		: second(second)
	{
		this->string = StringUtility::copy(string);
	}

	virtual ~Pair()
	{
		delete[] string;
	}

	const char* getFirst() const
	{
		return string;
	}

	T getSecond() const
	{
		return second;
	}

	friend std::ostream& operator<<(std::ostream& out, const Pair<char*, T>& pair)
	{
		out << "Pair(first=" << pair.string << ", second=" << pair.second << ")";
		return out;
	}
};