#include <cstdlib>
#include <ctime>
#include <iostream>

/*
Якщо вам не подобаються назви стандартних функцій, то ви їх можете обгорнути у ваші функції,
що мають зрозумілі назви. Спробуйте так зробити із функціями std::srand(), std::rand() та std::time.
Напишіть власні три функції, які викликають ці функції, після чого напишіть ось такий код для
перевірки їх роботи:
    int main() {
        SetRandomSeed(GetCurrentCalendarTime());
        for (int i = 0; i < 5; i++) {
            std::cout << GetRandomInt(20, 40) << ' ';
        }
    }

Ваша програма має вивести 5 випадкових чисел в діапазоні від 20 до 40 включно.
*/

void set_random_seed(const long seed);

int get_random_int(const int from, const int to);

long get_current_calendar_time();

int main() {
	set_random_seed(get_current_calendar_time());
    for (int i = 0; i < 5; i++) {
        std::cout << get_random_int(20, 40) << ' ';
	}
	std::cout << std::endl;
	return 0;
}

void set_random_seed(const long seed) {
	std::srand(seed);
}

int get_random_int(const int from, const int to) {
	int random = std::rand();
	return from + random % (to - from);
}

long get_current_calendar_time() {
	return (long) std::time(nullptr);
}
