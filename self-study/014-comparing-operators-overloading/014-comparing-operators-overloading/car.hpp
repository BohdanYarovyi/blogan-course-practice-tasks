#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

class Car
{
private:
	std::string company;
	std::string model;

public:
	Car(std::string company, std::string model);

	friend bool operator==(const Car& car_1, const Car& car_2);

	friend bool operator!=(const Car& car_1, const Car& car_2);

	friend bool operator<(const Car& car_1, const Car& car_2);

	friend std::ostream& operator<<(std::ostream& out, const Car& car);
};

#endif // !CAR_H
