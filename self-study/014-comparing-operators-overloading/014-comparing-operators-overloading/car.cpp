#include "car.hpp"

Car::Car(std::string company, std::string model)
	: company(company), model(model)
{
}

bool operator==(const Car& car_1, const Car& car_2)
{
	if (car_1.company != car_2.company) return false;
	if (car_1.model != car_2.model) return false;

	return true;
}

bool operator!=(const Car& car_1, const Car& car_2)
{
	if (car_1.company == car_2.company) return false;
	if (car_1.model == car_2.model) return false;

	return true;
}

bool operator<(const Car& car_1, const Car& car_2)
{
	return car_1.company < car_2.company;
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
	return out << "(" << car.company << ", " << car.model << ")";
}