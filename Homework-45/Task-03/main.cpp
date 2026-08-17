#include <iostream>
#include <cstdlib>
#include <ctime>

/*
	Напишіть наступну гру: комп'ютер загадав випадкове число від 0 до 99 (включно). Вам
	дається 5 спроб відгадати це число. Якщо ви вгадали - ви виграли. Якщо ні - комп'ютер
	говорить, чи його число більше за ваше, чи менше (тобто дає підказку). Якщо проходить
	5 спроб, а ви так і не вгадали - ви програли.
*/

void set_random_seed();
int get_random_integer(int from, int to);

const int NUMBER_MIN = 0;
const int NUMBER_MAX = 99;

int main()
{
	std::cout << "computer: I guessed a number [" << NUMBER_MIN << " - " << NUMBER_MAX << "], try to guess it"
	          << std::endl;
	set_random_seed();
	int secret_number = get_random_integer(NUMBER_MIN, NUMBER_MAX + 1);
	int player_tries = 5;
	bool has_player_won = false;

	int user_number;
	for (int i = 0; i < player_tries && !has_player_won; i++)
	{
		std::cout << "try " << i + 1 << "/" << player_tries << " >> ";
		std::cin >> user_number;

		if (user_number > secret_number)
		{
			std::cout << "computer: No, my number is smaller. Try again =)" << std::endl;
		}
		else if (user_number < secret_number)
		{
			std::cout << "computer: No, my number is bigger. Try again =)" << std::endl;
		}
		else
		{
			has_player_won = true;
		}
	}

	if (has_player_won)
	{
		std::cout << "Congratulations! You won the computer." << std::endl;
	}
	else
	{
		std::cout << "You lost!" << std::endl;
	}

	return 0;
}

void set_random_seed()
{
	std::srand(std::time(nullptr));
}

int get_random_integer(int from, int to)
{
	return std::rand() % (from - to) + from;
}
