#include <iostream>

#include "Person.hpp"
#include "StudentOfCambridge.hpp"

int main()
{
	Person bob("Bob", 38);
	StudentOfCambridge jake("Jake", 19, 135);
	Person& person_jake = jake;

	std::cout << bob << std::endl;			// PERSON
	std::cout << jake << std::endl;			// STUDENT
	std::cout << person_jake << std::endl;	// STUDENT

	return 0;
}