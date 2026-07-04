#include <iostream>

/*
Є 2 змінні:
	- temperatureC (температура по Цельсію)
	- temperatureF (температура по Фаренгейту)
temperatureC = 23.5 градусів. Знайдіть, скільки це в Фаренгейтах. Для цього знайдіть формулу перетворення
градусів Цельсія в Фаренгейт і застосуйте її, присвоївши результат другій змінній.
Виведіть обидві змінні на екран повідомленням:
(стільки-то)C = (стільки-то)F
*/

float exchangeToFahrenheit(float celsius) {
	float d = 1.8f;
	return celsius * d + 32;
}

int main() {
	float temperatureC;
	float temperatureF;

	temperatureC = 23.5f;
	temperatureF = exchangeToFahrenheit(temperatureC);

	std::cout << temperatureC << " C = " << temperatureF << " F" << std::endl;
	return 0;
}