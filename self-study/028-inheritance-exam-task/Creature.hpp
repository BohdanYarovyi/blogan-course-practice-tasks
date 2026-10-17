#ifndef CREATURE_H
#define CREATURE_H

#include "./../mylib/StringUtility.hpp"

class Creature
{
  protected:
	char* name;
	char icon;
	int health;
	int damage;
	int gold;

  public:
	Creature(const char* name, char icon, int health, int damage, int gold)
		: icon(icon), health(health), damage(damage), gold(gold)
	{
		this->name = StringUtility::copy(name);
	}

	~Creature()
	{
		delete[] name;
	}

	void reduceHealth(int value)
	{
		health -= value;
	}

	void addGold(int value)
	{
		gold += value;
	}

	bool isDead() const
	{
		return health <= 0;
	}

	const char* getName() const
	{
		return name;
	}

	char getIcon() const
	{
		return icon;
	}

	int getHealth() const
	{
		return health;
	}

	int getDamage() const
	{
		return damage;
	}

	int getGold() const
	{
		return gold;
	}
};

#endif // CREATURE_H
