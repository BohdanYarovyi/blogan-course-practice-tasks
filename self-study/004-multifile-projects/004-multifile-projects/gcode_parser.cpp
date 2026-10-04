#include "string_utils.h"
#include "gcode_parser.h"

namespace GCode_Parser
{
	
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

} // namespace GCode_Parser