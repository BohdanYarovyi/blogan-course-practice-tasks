#include <iostream>

/*
Відстань = 15 кілометрів. Знайдіть, скільки це в міліметрах. 
Використайте 3 константи:
	1. Кількість метрів в кілометрі.
	2. Кількість сантиметрів в метрі.
	3. Кількість міліметрів в сантиметрі.
Можна створити декілька змінних, щоб краще читався код. Наприклад distanceInM (відстань в метрах).
*/

const int METERS_IN_KM	 = 1000;
const int CM_IN_METER	 = 100;
const int MM_IN_CM		 = 10;


int main() {
	int distance = 15;	// km
	int distance_in_mm = distance * METERS_IN_KM * CM_IN_METER * MM_IN_CM;

	std::cout << "Given distance in kilometers: " << distance << " km" << std::endl;
	std::cout << "Given distance in milimiters: " << distance_in_mm<< " mm" << std::endl;
	return 0;
}