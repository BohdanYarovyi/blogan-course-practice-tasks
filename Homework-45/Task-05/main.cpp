#include <cstdlib>
#include <ctime>
#include <iostream>

/*
    Напишіть гру "Камінь-Ножиці-Папір". У вас програма питає, яку "зброю" ви загадали,
    потім генерує випадково цю зброю для комп'ютера. Після цього показує ваші обидві
    зброї і каже, хто переміг (чи нічия). Зробіть так, щоб переміг той, хто переміг 2 рази
    (тобто до 3 раундів має бути).
*/

void set_random_seed();
int get_random_weapon();
bool is_winner(int winner_weapon, int looser_weapon);

const int MIN_WEAPON_INDEX = 1;

const int MAX_WEAPON_INDEX = 3;

const int WIN_COMBINATION_COUNT = 3;

const int WIN_COMBINATIONS[WIN_COMBINATION_COUNT][2] = {
    {1, 2},
    {2, 3},
    {3, 1},
};

int main()
{
	const int MAX_SCORE = 2;

	int user_score = 0;
	int bot_score = 0;

	set_random_seed();
	std::cout << "computer: Let's play rock-scissors-paper. Guess the weapon!\n";
	while (user_score < MAX_SCORE && bot_score < MAX_SCORE)
	{
		int user_weapon;
		int bot_weapon;
		std::cout << "1 - ROCK\n";
		std::cout << "2 - SCISSORS\n";
		std::cout << "3 - PAPER\n";
		std::cout << ">> ";
		std::cin >> user_weapon;
		bot_weapon = get_random_weapon();

		std::cout << "Computer " << bot_weapon << " - " << user_weapon << " You\n";
		if (is_winner(user_weapon, bot_weapon))
		{
			std::cout << "You won 1 point\n";
			user_score++;
		}
		else if (is_winner(bot_weapon, user_weapon))
		{
			std::cout << "Computer won 1 point\n";
			bot_score++;
		}
		std::cout << "-- SCORE\n";
		std::cout << "-- Computer: " << bot_score << "\n";
		std::cout << "-- You:      " << user_score << "\n";
		std::cout << '\n';
	}

	if (user_score > bot_score)
	{
		std::cout << "Congratulations. You are a winner!\n";
	}
	else
	{
		std::cout << "This time the computer is better than you!\n";
	}
	return 0;
}

void set_random_seed()
{
	std::srand(std::time(nullptr));
}

int get_random_weapon()
{
	return std::rand() % (MAX_WEAPON_INDEX - MIN_WEAPON_INDEX + 1) + MIN_WEAPON_INDEX;
}

bool is_winner(int winner_weapon, int looser_weapon)
{
	for (int i = 0; i < WIN_COMBINATION_COUNT; i++)
	{
		bool winner_has_weapon = WIN_COMBINATIONS[i][0] == winner_weapon;
		bool looser_has_weapon = WIN_COMBINATIONS[i][1] == looser_weapon;

		if (winner_has_weapon && looser_has_weapon)
		{
			return true;
		}
	}

	return false;
}
