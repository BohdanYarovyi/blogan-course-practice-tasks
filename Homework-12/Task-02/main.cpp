#include <iostream>

/*
Створіть 2 змінні типу int з іменем peopleInUSA, peopleInUkraine. Їх значення - це кількість людей в США і Україні відповідно.
Загугліть ці значення в інтернеті і присвойте цим змінним їх. 
Виведіть на екран наступне повідомлення:
	Number of people in USA = (змінна1).
	Number of people in Ukraine = (змінна2).
*/

int main() {
	int peopleInUSA = 349'035'494;
	int peopleInUkraine = 39'535'849;

	std::cout << "Number of people in USA = " << peopleInUSA << "." << std::endl;
	std::cout << "Number of people in Ukraine = " << peopleInUkraine << "." << std::endl;
	return 0;
}