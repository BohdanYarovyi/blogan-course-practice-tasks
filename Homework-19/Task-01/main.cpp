#include <iostream>
#include <windows.h>

/*
Користувач вводить температуру по Цельсію. Переведіть її у Фаренгейти і Кельвіни.
Формули беріть з інтернету. Там формули не маленькі, тому проаналізуйте пріоритет операторів у них. 
Точність має бути правильна. Перевіряйте правильність результатів вашої програми з онлайн-калькуляторами. 
Якщо значення збігаються - ваша програма працює вірно.
	
	Цельсій -> Фаренгейт
	tFahrenheit = 1.8 * tCelsius + 32

	Цельсій -> Кельвін
	tKelvin = tCelsius + 273.15
*/

const float KELVIN_OFFSET			= 273.15f;
const float FAHRENHEIT_OFFSET		= 32.0f;
const float FAHRENHEIT_CORRELATION	= 1.8f;

float calculateKelvin(float celsius) {
	return celsius + KELVIN_OFFSET;
}

float calculateFahrenheit(float celsius) {
	return FAHRENHEIT_CORRELATION * celsius + FAHRENHEIT_OFFSET;
}

int main() {
	SetConsoleOutputCP(CP_UTF8);

	float t_celsius;
	float t_fahrenheit;
	float t_kelvin;
	
	std::cout << "Enter temperature (°C): ";
	std::cin >> t_celsius;

	t_fahrenheit = calculateFahrenheit(t_celsius);
	t_kelvin = calculateKelvin(t_celsius);

	std::cout << "Temperature °C: " << t_celsius << std::endl;
	std::cout << "Temperature °F: " << t_fahrenheit << std::endl;
	std::cout << "Temperature  K: " << t_kelvin << std::endl;
	return 0;
}