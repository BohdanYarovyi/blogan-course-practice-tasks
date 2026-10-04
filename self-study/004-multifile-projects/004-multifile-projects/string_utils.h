#pragma once

namespace String_Utils
{

	int get_length(const char* str);

	bool equals(const char* str_1, const char* str_2);

	char** split(const char* str, char split_by, int& result_size);

	int to_int(const char* str);

	char* substring(const char* source, int from, int to);

} // namespace String_Utils