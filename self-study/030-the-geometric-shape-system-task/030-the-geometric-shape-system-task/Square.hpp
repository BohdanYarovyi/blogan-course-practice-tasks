#pragma once

#include "Rectangle.hpp"

class Square final : public Rectangle
{
public:
	Square(double side)
		: Rectangle("Square", side, side)
	{
	}

};