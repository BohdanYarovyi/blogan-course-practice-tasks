#pragma once

namespace GCode_Parser
{

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

	GCode_Command* parse_gcode(const char* const* gcode, int rows);

} // namespace GCode_Parser