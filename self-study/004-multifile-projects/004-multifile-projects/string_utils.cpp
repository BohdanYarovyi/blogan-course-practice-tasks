#include <cmath>

#include "string_utils.h"

namespace String_Utils
{

	int get_length(const char* str)
	{
		int length = 0;
		while (str[length] != '\0')
		{
			length++;
		}

		return length;
	}

	bool equals(const char* str_1, const char* str_2)
	{
		int index = 0;
		while (true)
		{	
			if (str_1[index] == '\0' && str_2[index] == '\0')
			{
				return true;
			}

			if (str_1[index] != str_2[index])
			{
				return false;
			}

			index++;
		}
	}

	char** split(const char* str, char split_by, int& result_size)
	{
		int parts_count = 0;
		{
			bool last_was_delimeter = true;
			for (int i = 0; str[i] != '\0'; i++)
			{
				char c = str[i];
				if (c == split_by && !last_was_delimeter)
				{
					parts_count++;
					last_was_delimeter = true;
				}
				else if (c != split_by)
				{
					last_was_delimeter = false;

				}
			}
			if (!last_was_delimeter) {
				parts_count++;
			}
		}

		char** result = new char*[parts_count];

		int offset = 0;
		int part_index = 0;
		int row_length = get_length(str);
		for (int index = 0; index <= row_length; index++)
		{
			if (str[index] == split_by || str[index] == '\0')
			{
				int buffer_length = index - offset;
				if (buffer_length == 0)
				{
					offset = index + 1;
					continue;
				}

				char* buffer = new char[buffer_length + 1];

				for (int k = 0; k < buffer_length; k++)
				{
					buffer[k] = str[offset + k];
				}
				buffer[buffer_length] = '\0';

				result[part_index++] = buffer;
				offset = index + 1;
			}
		}

		result_size = parts_count;
		return result;
	}

	int to_int(const char* str)
	{
		const int ASCII_ZERO_INDEX = 48;
		int result = 0;
		int length = get_length(str);

		for (int i = 0; i < length; i++)
		{
			result += (str[i] - ASCII_ZERO_INDEX) * pow(10, length - i - 1);
		}

		return result;
	}

	char* substring(const char* source, int from, int to)
	{
		char* result = new char[to - from + 1];
		int result_index = 0;
		for (int i = from; i < to; i++)
		{
			result[result_index] = source[i];
			result_index++;
		}
		result[result_index] = '\0';

		return result;
	}

} // namespace String_Utils