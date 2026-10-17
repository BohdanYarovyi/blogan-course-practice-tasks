#pragma once

#include "Creature.hpp"

class Monster : public Creature
{
  public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

  private:
	struct MonsterData
	{
		const char* name;
		const char icon;
		const int health;
		const int damage;
		const int gold;
	};

	static const MonsterData monsterData[Type::MAX_TYPES];

  public:
	Monster(Type type)
	    : Creature(monsterData[type].name,
		           monsterData[type].icon,
		           monsterData[type].health,
		           monsterData[type].damage,
		           monsterData[type].gold
		)
	{
	}
};
