#include <iostream>
#include <windows.h>

/*
Переробіть попередню задачу так, щоб користувач вводить температуру по Фаренгейту
і вона виводилась по Цельсію і Кельвіну.

	Фаренгейт -> Цельсій
	t_celsius = (t_fahrenheit - 32) / 1.8

	Фаренгейт -> Кельвін
	t_kelvin = (t_fahrenheit - 32) / 1.8 + 273.15
*/

const float KELVIN_OFFSET			= 273.15f;
const float FAHRENHEIT_OFFSET		= 32.0f;
const float FAHRENHEIT_CORRELATION	= 1.8f;

float calculateCelsius(float t_fahrenheit) {
	return (t_fahrenheit - FAHRENHEIT_OFFSET) / FAHRENHEIT_CORRELATION;
}

float calculateKelvin(float t_fahrenheit) {
	return (t_fahrenheit - FAHRENHEIT_OFFSET) / FAHRENHEIT_CORRELATION + KELVIN_OFFSET;
}

int main() {
	SetConsoleOutputCP(CP_UTF8);

	float t_fahrenheit;
	float t_celsius;
	float t_kelvin;

	std::cout << "Enter temperature (°F): ";
	std::cin >> t_fahrenheit;

	t_celsius = calculateCelsius(t_fahrenheit);
	t_kelvin = calculateKelvin(t_fahrenheit);

	std::cout << "Temperature °F: " << t_fahrenheit << std::endl;
	std::cout << "Temperature °C: " << t_celsius << std::endl;
	std::cout << "Temperature  K: " << t_kelvin << std::endl;
	return 0;
}