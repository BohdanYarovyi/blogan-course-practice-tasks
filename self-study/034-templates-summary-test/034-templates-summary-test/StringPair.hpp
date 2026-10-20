#pragma once

#include "Pair.hpp"

template <typename T>
class StringPair : public Pair<char*, T>
{
public:
	StringPair(const char* string, T value)
		: Pair<char*, T>(string, value)
	{
	}
};