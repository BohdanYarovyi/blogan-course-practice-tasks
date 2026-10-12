#ifndef STRING_UTILS_H
#define STRING_UTILS_H

namespace String_Utils
{
	int get_string_length(const char* string);

	char* create_copy(const char* string, int length);

	bool are_string_equal(const char* str_1, const char* str_2);
}

#endif // !STRING_UTILS_H
