#include <iostream>

/*
Користувач є власником заводу і вводить наступні дані:
	1. Кількість працівників на заводі
	2. Зарплату кожного працівника
	3. Кількість років, скільки працює завод
Порахуйте, скільки грошей власник вклав у завод за всі роки і виведіть суму на екран.
(Використовуються оператори = та *)
*/

int main() {
	const char MONTHS_IN_YEAR = 12;

	int workers_count;
	float common_salary;
	float factory_time_working;
	
	std::cout << "Enter the number of workers on your factory (unit): ";
	std::cin >> workers_count;
	std::cout << "Enter a common salary of worker on your factory (dollar): ";
	std::cin >> common_salary;
	std::cout << "How long is your factory working (year): ";
	std::cin >> factory_time_working;

	float month_outlay = workers_count * common_salary;
	float year_outlay = month_outlay * MONTHS_IN_YEAR;
	float total_outlay = factory_time_working * year_outlay;

	std::cout << "Outlay:" << std::endl;
	std::cout << " month: $" << month_outlay << std::endl;
	std::cout << " year:  $" << year_outlay << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << " all time: $" << total_outlay << std::endl;

	return 0;
}