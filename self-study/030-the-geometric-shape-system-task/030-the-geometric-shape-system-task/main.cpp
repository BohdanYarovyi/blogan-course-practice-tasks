#include <iostream>

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"

int main()
{
	const int SHAPES_SIZE = 6;
	Shape* shapes[SHAPES_SIZE];
	shapes[0] = new Circle(4.78);
	shapes[1] = new Rectangle(8, 2.5);
	shapes[2] = new Triangle(7, 4, 10);
	shapes[3] = new Circle(0.333);
	shapes[4] = new Square(6.38);
	shapes[5] = new Triangle(9.3, 9.3, 9.3);

	Shape* largestAreaShape = shapes[0];
	for (int i = 0; i < SHAPES_SIZE; i++)
	{
		if (shapes[i]->area() > largestAreaShape->area())
		{
			largestAreaShape = shapes[i];
		}
	}
	std::cout << "The shape with largest area is:";
	largestAreaShape->print();
	
	for (int i = 0; i < SHAPES_SIZE; i++)
	{
		delete shapes[i];
	}

	return 0;
}