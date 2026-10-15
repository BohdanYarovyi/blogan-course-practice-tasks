#include "StringUtility.hpp"

namespace StringUtility
{
	int getLength(const char* string)
	{
		int length = 0;
		while (string[length] != '\0')
		{
			length++;
		}

		return length;
	}

	char* copyString(const char* string)
	{
		int length = getLength(string);
		char* copy = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			copy[i] = string[i];
		}
		copy[length] = '\0';

		return copy;
	}
}