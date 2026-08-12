#include <iostream>

/*
	Напишіть програму, яка перетворює температуру по Цельсію в температуру по Фаренгейту, використовуючи глобальні змінні celsiusTemperature та fahrenheitTemperature.

	Напишіть наступні функції:
		- double ConvertCelciusToFahrenheit(double degrees) - перетворює температуру C в F.
		- double ConvertFahrenheitToCelcius(double degrees) - перетворює температуру F в C.
		- double EnterCelciusTemperature() - просить у користувача і дає користувачу ввести температуру C і повертає це значення
		- void ShowTemperatures() - виводить температуру C та F на екран

	У функції main попросіть у користувача ввести температуру C. Повертаюче значення функції EnterCelciusTemperature присвойте глобальній змінній celsiusTemperature. Після цього перетворіть її у температуру по фаренгейту і присвойте значення глобальній змінній fahrenheitTemperature.

	Після цього виведіть на екран обидві температури завдяки ShowTemperatures.

	ПІДКАЗКА: формули перетворення:
		- C → F: (C * 9 / 5) + 32
		- F → C: (F - 32) * 5 / 9
 */

double celsius_temperature;
double fahrenheit_temperature;

double convert_celsius_to_fahrenheit(double degrees);

double convert_fahrenheit_to_celsius(double degrees);

double enter_celsius_temperature();

void show_temperatures();

int main() {
	celsius_temperature = enter_celsius_temperature();
	fahrenheit_temperature = convert_celsius_to_fahrenheit(celsius_temperature);
	show_temperatures();

	return  0;
}

double convert_celsius_to_fahrenheit(double degrees) {
	return (degrees * 9.0 / 5.0) + 32;
}

double convert_fahrenheit_to_celsius(double degrees) {
	return (degrees - 32) * 5.0 / 9.0;
}

double enter_celsius_temperature() {
	std::cout << "Enter a temperature in celsium degrees: ";
	double t;
	std::cin >> t;

	return t;
}

void show_temperatures() {
	std::cout << "Celsius: " << celsius_temperature << std::endl;
	std::cout << "Fahrenheit: " << fahrenheit_temperature << std::endl;
}
