#include <iostream>

/*
	int variable = 10;
	const double CONSTANT = 20.0;
	char array[3] = { 'a', 'b', 'c'};
	int* pointer = &variable;
	const int CONST_ARRAY[4] = { 1, 2, 3, 4 };
	const char* names[2] = { "Demian", "Helena" };
	void (*function)(int, double) = nullptr;
	int** pp = &pointer;
*/

int main()
{
	int variable = 10;
	const double CONSTANT = 20.0;
	char array[3] = {'a', 'b', 'c'};
	int* pointer = &variable;
	const int CONST_ARRAY[4] = { 1, 2, 3, 4 };
	const char* names[2] = { "Demian", "Helena" };
	void (*function)(int, double) = nullptr;
	int** pp = &pointer;

	int& ref_variable = variable;
	const double& REF_CONSTANT = CONSTANT;
	char (&ref_array)[3] = array;
	int*& ref_pointer = pointer;
	const int (&REF_CONST_ARRAY)[4] = CONST_ARRAY;
	const char* (&ref_names)[2] = names;
	void (*&ref_function)(int, double) = function;
	int**& ref_pp = pp;

	return 0;
}