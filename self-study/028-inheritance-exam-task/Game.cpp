#include <iostream>

#include "./../mylib/Random.hpp"
#include "Monster.hpp"
#include "Player.hpp"
#include "Game.hpp"

void greetPlayer(const Player& p)
{
	std::cout << "Welcome " << p.getName() << std::endl;
}

void executeDefeat(const Player& p)
{
	std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold." << std::endl;
}

void executeWin(const Player& p)
{
	std::cout << "You won! You have " << p.getGold() << " gold." << std::endl;
}

Monster getRandomMonster()
{
	int r = Random::getRandomNumber(0, Monster::Type::MAX_TYPES - 1);
	Monster::Type randomType = static_cast<Monster::Type>(r);

	return Monster(randomType);
}

void describeMonster(const Monster& m)
{
	std::cout << "You have to fight " << m.getName() << "(" << m.getIcon() << ")" << std::endl;
}

bool askUserRunOrFight()
{
	std::cout << "[R]un or [F]ight: ";
	char c;
	std::cin >> c;

	if (c == 'r')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool run(Player& p, Monster& m)
{
	int CHANCE_TO_RUN = 50;
	int random = Random::getRandomNumber();

	if (random <= CHANCE_TO_RUN)
	{
		return true;
	}
	else
	{
		std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage." << std::endl;
		p.reduceHealth(m.getDamage());

		return false;
	}
}

bool fight(Player& p, Monster& m)
{
	std::cout << "You attak with " << p.getDamage() << " damage." << std::endl;
	m.reduceHealth(p.getDamage());

	if (m.isDead())
	{
		std::cout << "The " << m.getName() << " was defeat. You get " << m.getGold() << " gold." << std::endl;
		p.addGold(m.getGold());
		p.levelUp();
		std::cout << "You have level up. You are " << p.getLevel() << " level now." << std::endl;

		return true;
	}
	else
	{
		std::cout << m.getName() << " attak you with " << m.getDamage() << " damage." << std::endl;
		p.reduceHealth(m.getDamage());

		return false;
	}
}

void play()
{
	Player p("Maybyes");
	Monster m = getRandomMonster();
	bool requireNewEnemy = false;

	greetPlayer(p);
	describeMonster(m);
	while (true)
	{
		if (p.isDead())
		{
			executeDefeat(p);
			return;
		}
		if (p.hasWon())
		{
			executeWin(p);
			return;
		}

		if (requireNewEnemy)
		{
			m = getRandomMonster();
			describeMonster(m);
			requireNewEnemy = false;
		}

		bool choosedRun = askUserRunOrFight();
		if (choosedRun)
		{
			requireNewEnemy = run(p, m);
		}
		else
		{
			requireNewEnemy = fight(p, m);
		}
	}
}
