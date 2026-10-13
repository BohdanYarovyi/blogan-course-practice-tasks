#include "string_utils.hpp"

namespace String_Utils
{
	int length(const char* string)
	{
		int size = 0;
		while (string[size] != '\0')
		{
			size++;
		}

		return size;
	}
	
	bool are_string_equal(const char* s1, const char* s2)
	{
		int index = 0;
		while (true)
		{
			if (s1[index] != s2[index]) return false;
			if (s1[index] == '\0') return true;
			index++;
		}
	}

	char* copy_string(const char* string)
	{
		int l = length(string);
		char* new_string = new char[l + 1];
		for ( int i = 0; i < l; i++)
		{
			new_string[i] = string[i];
		}
		new_string[l] = '\0';

		return new_string;
	}
}