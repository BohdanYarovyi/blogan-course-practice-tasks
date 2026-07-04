#include <iostream>

/*
Користувач вводить час, який зараз у нього показує на годиннику. Тобто він вводить
кількість годин і кількість хвилин. Виведіть на екран, скільки це в хвилинах разом.
*/

int main() {
	const int MINUTES_IN_HOUR = 60;
	const int SECONDS_IN_MINUTE = 60;
	int hours;
	int minutes;

	std::cout << "Enter current hours on the clock: ";
	std::cin >> hours;
	std::cout << "Enter current minutes on the clock: ";
	std::cin >> minutes;
	
	minutes += hours * MINUTES_IN_HOUR;
	int seconds = minutes * SECONDS_IN_MINUTE; 
	std::cout << seconds << " seconds left from noon." << std::endl;
	return 0;
}