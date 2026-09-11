#include <iostream>

/*
Створіть масив із 10 елементів. Створіть вказівники на його перший і останній елементи. Виведіть на екран різницю значень цих вказівників. У вас має бути значення 9. Розумієте чому?
*/

int main()
{
	const int ARRAY_SIZE = 10;
	int array[ARRAY_SIZE];

	int* first_element = array;
	int* last_element = array + ARRAY_SIZE - 1;

	int difference = last_element - first_element;
	std::cout << "Array difference: " << difference << std::endl;
	return 0;
}
