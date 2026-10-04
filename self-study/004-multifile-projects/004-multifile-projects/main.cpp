#include <iostream>

#include "gcode_parser.h"

void print_parsed_gcode(const GCode_Parser::GCode_Command* commands, int rows);

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
	GCode_Parser::GCode_Command* commands = GCode_Parser::parse_gcode(gcode, GCODE_ROWS_COUNT);
	print_parsed_gcode(commands, GCODE_ROWS_COUNT);
	
	return 0;
}

void print_parsed_gcode(const GCode_Parser::GCode_Command* commands, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		GCode_Parser::GCode_Command c = commands[i];
		std::cout << "Directive: " << static_cast<int>(c.dirrective_type) << std::endl;
		std::cout << "Parameters: " << std::endl;
		for (int i = 0; i < c.parameters_count; i++)
		{
			std::cout << "  address=" << static_cast<int>(c.parameters[i].address) << " value=" << c.parameters[i].value << std::endl;
		}
		std::cout << std::endl;
	}
}