#include <iostream>

enum class Command_Type
{
	RAPID_MOVE,
	LINEAR_INTERPOLATION,
	DWELL,
	RETURN_TO_HOME,
	ABSOLUTE_POSITIONING,
	RELATIVE_POSITIONING,
	SPINDLE_ON,
	SPINDLE_STOP
};

struct Command
{
	const char* token;
	Command_Type command_type;
};

const Command SUPPORTED_COMMANDS[] =
{
    {"G0", Command_Type::RAPID_MOVE},
    {"G1", Command_Type::LINEAR_INTERPOLATION},
    {"G4", Command_Type::DWELL},
    {"G28", Command_Type::RETURN_TO_HOME},
    {"G90", Command_Type::ABSOLUTE_POSITIONING},
    {"M3", Command_Type::SPINDLE_ON},
    {"M5", Command_Type::SPINDLE_STOP},
};

int main()
{

	return 0;
}
