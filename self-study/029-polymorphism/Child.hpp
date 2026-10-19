#pragma once

#include "Parent.hpp"

class Child : public Parent
{
  public:
	virtual const char* getName() override
	{
		return "Child";
	}
};
