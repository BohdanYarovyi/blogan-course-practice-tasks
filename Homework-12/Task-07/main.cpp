#include <iostream>
#include <iomanip>

/*
Зробіть обернену задачу до попередньої. Там буде інша (обернена формула).
Кількість градусів по Фаренгейту задайте самостійно.
*/

float exchangeToCelsius(float fahrenheit) {
	float d = 1.8f;
	return (fahrenheit - 32) / d;
}

int main() {
	float temperatureF;
	float temperatureC;

	temperatureF = 75.0f;
	temperatureC = exchangeToCelsius(temperatureF);

	std::cout << std::fixed << std::setprecision(2);
	std::cout << temperatureC << " C = " << temperatureF << " F" << std::endl;
	return 0;
}