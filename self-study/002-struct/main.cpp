#include <iostream>

struct Employee
{
	short id;
	int age;
	double salary;
};

struct Company
{
	Employee CEO;
	int number_of_employees;
};

struct Triangle
{
	double length = 2.0;
	double width = 2.0;
};

int main()
{
	Employee john;
	john.id = 8;
	john.age = 27;
	john.salary = 32.17;

	Employee james;
	james.id = 9;
	james.age = 30;
	james.salary = 28.35;

	std::cout << "The employee with id " << john.id << " and age " << john.age << " earns " << john.salary << " dollars per month." << std::endl;
	std::cout << "The employee with id " << james.id << " and age " << james.age << " earns " << james.salary << " dollars per month." << std::endl;

	Triangle t1 = {};	// initiated with defaults
	std::cout << "Length: " << t1.length << " Width: " << t1.width << std::endl;

	Triangle t2 = {3.14, 9.8};	// initiated with values
	std::cout << "Length: " << t2.length << " Width: " << t2.width << std::endl;

	Company eva_inc = {james, 8'000};
	return 0;
}
