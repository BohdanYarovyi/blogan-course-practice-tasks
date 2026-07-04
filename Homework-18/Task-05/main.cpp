#include <iostream>
#include <windows.h>

/*
Програма містить значення температури за перші два дні. Це числа -15 та -17.
Користувач вводить ще 2 значення температури. Виведіть на екран середню температуру за 4 дні.
(Використовуються оператори =, - та /)
*/
 
int main() {
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int temperature1 = -15;
	int temperature2 = -17;
	int temperature3;
	int temperature4;

	std::cout << "The system already has two values of the temperature for first two days." << std::endl;
	std::cout << "Please, provide the rest two values. Enter the temperature of the last two days." << std::endl;
	std::cout << "First day: " << temperature1 << " °C" << std::endl;
	std::cout << "Second day: " << temperature2 << " °C" << std::endl;
	std::cout << "Third day: ";
	std::cin >> temperature3;
	std::cout << "Forth day: ";
	std::cin >> temperature4;

	int total_temperature = temperature1 + temperature2 + temperature3 + temperature4;
	float average_temperature = total_temperature / 4.0;
	std::cout << "Avarage temperature in nearest 4 days was " << average_temperature << " °C." << std::endl;

	return 0;
}