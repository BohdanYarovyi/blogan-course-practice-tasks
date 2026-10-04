#include <iostream>
#include <cmath>

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

}	// namespace Strign_Utils

enum class GCode_Dirrective_Type
{	
	NOT_DEFINED,
	G0,
	G1,
	M3,
	M5
};

enum class GCode_Address
{	
	NOT_DEFINED,
	X,
	Y,
	Z,
	F,
	S
};

struct GCode_Parameter
{
	GCode_Address address;
	double value;
};

struct GCode_Command
{
	GCode_Dirrective_Type dirrective_type;
	GCode_Parameter* parameters;
	int parameters_count;
};

// void interpret_gcode(const char* const* gcode, int rows);

GCode_Command* parse_gcode(const char* const* gcode, int rows);

int main()
{
	const int GCODE_ROWS_COUNT = 10; 
	const char** gcode = new const char*[GCODE_ROWS_COUNT]
	{
		"G0 X0 Y0 Z5",
		"G1 Z0 F100",
		"M3 S1000",
		"G1 X50 Y0 F200",
		"G1 X50 Y30",
		"G1 X0 Y30",
		"G1 X0 Y0",
		"G0 Z5",
		"M5",
		"G0 X0 Y0"
	};	
	GCode_Command* commands = parse_gcode(gcode, GCODE_ROWS_COUNT);

	for (int i = 0; i < GCODE_ROWS_COUNT; i++)
	{
		GCode_Command c = commands[i];
		std::cout << "Directive: " << static_cast<int>(c.dirrective_type) << std::endl;
		std::cout << "Parameters: " << std::endl;
		for (int i = 0; i < c.parameters_count; i++)
		{
			std::cout << "  address=" << static_cast<int>(c.parameters[i].address) << " value=" << c.parameters[i].value << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}

GCode_Dirrective_Type resolve_gcode_directive(const char* g_row)
{
	int count = 0;
	while (g_row[count] != ' ' && g_row[count] != '\0')
	{
		count++;
	}

	char* token = new char[count + 1];
	for (int i = 0; i < count; i++)
	{
		token[i] = g_row[i];
	}
	token[count] = '\0';


	if (String_Utils::equals(token, "G0"))
	{
		return GCode_Dirrective_Type::G0;
	}
	else if (String_Utils::equals(token, "G1"))
	{
		return GCode_Dirrective_Type::G1;
	}
	else if (String_Utils::equals(token, "M3"))
	{
		return GCode_Dirrective_Type::M3;
	}
	else if (String_Utils::equals(token, "M5"))
	{
		return GCode_Dirrective_Type::M5;
	}
	else
	{
		return GCode_Dirrective_Type::NOT_DEFINED;
	}
}

GCode_Parameter parse_param(const char* param)
{
	GCode_Parameter result = {};
	int length = String_Utils::get_length(param);
	char address = param[0];
	char* number = String_Utils::substring(param, 1, length);

	result.value = String_Utils::to_int(number);
	switch (address)
	{
		case 'X': result.address = GCode_Address::X; break;
		case 'Y': result.address = GCode_Address::Y; break;
		case 'Z': result.address = GCode_Address::Z; break;
		case 'F': result.address = GCode_Address::F; break;
		case 'S': result.address = GCode_Address::S; break;
		default: result.address = GCode_Address::NOT_DEFINED;
	}

	delete[] number;
	return result;
}

GCode_Parameter* get_parameters(const char* g_row, int& count_of_parameters)
{
	char** parameters = String_Utils::split(g_row, ' ', count_of_parameters);
	count_of_parameters -= 1;
	GCode_Parameter* result = new GCode_Parameter[count_of_parameters];

	for (int i = 0; i < count_of_parameters; i++)
	{
		char* p = parameters[i + 1];
		result[i] = parse_param(p);
	}

	// clean up
	for (int i = 0; i < count_of_parameters + 1; i++)
	{
		delete[] parameters[i];
	}
	delete[] parameters;

	return result;
}

GCode_Command* parse_gcode(const char* const* gcode, int rows)
{
	GCode_Command* commands = new GCode_Command[rows] {};
	
	for (int i = 0; i < rows; i++)
	{
		const char* g_row = gcode[i];
		int parameters_count;
		commands[i].dirrective_type = resolve_gcode_directive(g_row);
		commands[i].parameters = get_parameters(g_row, parameters_count);
		commands[i].parameters_count = parameters_count;
	}

	return commands;
}