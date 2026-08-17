#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

/*
    Спробуємо зробити обернену гру: ви вводите любе число від 0 до 99. Комп'ютер має
    його відгадати. Для цього напишіть алгоритм генерації випадкових чисел в діапазоні від
    0 до 99, в якому комп'ютер буде постійно генерувати випадкове число, поки не
    наткнеться на ваше. Але не забувайте, що функція rand може повернути те саме число,
    яке генерувала раніше. Не рахуйте це за спробу відгадати ваше число. Придумайте
    алгоритм, який буде рахувати кількість спроб БЕЗ ДУБЛІКАТІВ чисел. Наприклад, якщо
    ви загадали число 73, а комп'ютер назвав ось ці числа:
    2 9 4 2 10 54 84 93 9 4 4 54 74
    то він потратив 8 спроб (всі дублікати я відкинув). Ось це число і треба вивести на
    екран.

    (зроблю краще. Зроблю так, щоб я загадував числ, а комп'ютер вгадував. При цьому програма говорить комп'ютеру, чи загадане число більше чи менше, і він враховує це все у наступній спробі).
*/

void set_random_seed();
int get_random_integer(int from, int to);
int ask_user_secret();
void user_timeout();

const int NUMBER_MIN = 0;
const int NUMBER_MAX = 99;

int main()
{
	// initializing
	set_random_seed();

	std::cout << "computer: Let's play Hi-Lo, but I will guess your number." << std::endl;
	int user_secret = ask_user_secret();
	int computer_tries = 0;
	int computer_range_bottom = NUMBER_MIN;
	int computer_range_top = NUMBER_MAX;

	while (true)
	{
		int computer_number = get_random_integer(computer_range_bottom, computer_range_top);
		std::cout << "computer: I think it is " << computer_number << ". Right?" << std::endl;

		if (computer_number > user_secret)
		{
			std::cout << "Noo. My number is smaller)" << std::endl;
			computer_range_top = computer_number - 1;
			user_timeout();
		}
		else if (computer_number < user_secret)
		{
			std::cout << "No, my number is bigger)" << std::endl;
			computer_range_bottom = computer_number + 1;
			user_timeout();
		}
		else
		{
			std::cout << "Congratulations! You have guessed my number! It was " << user_secret << ".\n";
			break;
		}

		computer_tries++;
	}

	std::cout << "You have spent " << computer_tries << " for gessing secret number.\n";
	return 0;
}

void set_random_seed()
{
	std::srand(std::time(nullptr));
}

int get_random_integer(int from, int to)
{
	return std::rand() % (to - from + 1) + from;
}

int ask_user_secret()
{
	std::cout << "Give your secret number: ";
	int secret;

	do
	{
		std::cin >> secret;

		if (secret < NUMBER_MIN || secret > NUMBER_MAX)
		{
			std::cout << "Guessed number must be in range [" << NUMBER_MIN << ", " << NUMBER_MAX << "]"
			          << std::endl;
			std::cout << "Try again: ";
		}
		else
		{
			std::cin.ignore(std::numeric_limits<int>::max(), '\n'); // прибираємо залишковий \n
			return secret;
		}
	} while (true);
}

void user_timeout()
{
	std::cout << "Press any key to continue...";
	char name[10];
	std::cin.getline(name, 10);
}
