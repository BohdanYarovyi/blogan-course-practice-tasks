#include <iostream>

/*
Зробіть аналогічну задачу до другої, тільки на цей раз у вас є 10 років і ви маєте визначити,
скільки це в секундах. Кількість констант і змінних визначте самі, ви уже достатньо самостійні, щоб впоратись з цим.
*/

const int DAYS_IN_YEAR		= 365;
const int HOURS_IN_DAY		= 24;
const int SECONDS_IN_HOUR	= 3600;

int main() {
	int years = 10;
	int seconds = years * DAYS_IN_YEAR * HOURS_IN_DAY * SECONDS_IN_HOUR;

	std::cout << "Given count of years " << years << " is " << seconds << " in seconds." << std::endl;

	return 0;
}