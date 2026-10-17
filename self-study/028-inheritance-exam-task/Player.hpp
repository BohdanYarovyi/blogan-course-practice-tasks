#pragma once

#include "Creature.hpp"

class Player : public Creature
{
  protected:
	int level;

  public:
	Player(const char* name)
	    : Creature(name, '@', 10, 1, 0), level(1)
	{
	}

	void levelUp()
	{
		level++;
		damage++;
	}

	bool hasWon() const
	{
		return level >= 20;
	}

	int getLevel() const
	{
		return level;
	}
};
