#include <iostream>

#include "Person.hpp"
#include "Employee.hpp"
#include "Manager.hpp"

int main()
{		
	Person robbin = {"Robbin", 34};
	Employee jake = {"Jake", 45, 5400, "Programmer"};
	Manager tommy = {"Tommy", 43, 3800, "Project Manager", 5};

	robbin.print();
	jake.printEmployee();
	tommy.printManager();
}