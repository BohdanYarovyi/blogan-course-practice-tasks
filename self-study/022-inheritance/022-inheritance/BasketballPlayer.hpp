#ifndef BASKETBALL_PLAYER_H
#define BASKETBALL_PLAYER_H

#include "Human.hpp"

class BasketballPlayer : public Human
{
private:
	double gameAverage;
	int points;

public:
	BasketballPlayer(double gameAverage = 0, int points = 0)
		: gameAverage(gameAverage), points(points)
	{
	}
};

#endif // !BASKETBALL_PLAYER_H
