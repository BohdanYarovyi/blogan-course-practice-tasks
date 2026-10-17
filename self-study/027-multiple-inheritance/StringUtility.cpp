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

    char* copy(const char* string)
    {
	    int l = getLength(string);
	    char* copy = new char[l + 1];
	    for (int i = 0; i < l; i++)
	    {
			copy[i] = string[i];
	    }
	    copy[l] = '\0';

	    return copy;
    }
}
