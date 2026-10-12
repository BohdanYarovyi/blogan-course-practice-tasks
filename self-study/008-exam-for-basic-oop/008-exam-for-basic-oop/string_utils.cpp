#include "string_utils.hpp"

namespace String_Utils
{
	int get_string_length(const char* string)
	{
		int size = 0;
		while (string[size] != '\0')
		{
			size++;
		}

		return size;
	}

	char* create_copy(const char* string, int length)
	{
		char* copy = new char[length + 1];
		for (size_t i = 0; i < length; i++)
		{
			copy[i] = string[i];
		}
		copy[length] = '\0';

		return copy;
	}

	bool are_string_equal(const char* str_1, const char* str_2)
	{
		int index = 0;
		while (true)
		{
			if (str_1[index] != str_2[index])
			{
				return false;
			}

			if (str_1[index] == '\0')
			{
				return true;
			}

			index++;
		}
	}
}