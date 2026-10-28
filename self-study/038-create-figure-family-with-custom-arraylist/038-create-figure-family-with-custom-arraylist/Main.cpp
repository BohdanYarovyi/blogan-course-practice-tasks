#include <iostream>
#include <string>

#include "./../../mylib/collection/ArrayList.hpp"
#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

int main()
{
	try
	{
		ArrayList<Shape*> shapes;
		shapes.add(new Circle(2.50));
		shapes.add(new Rectangle(2.6, 3.85));
		shapes.add(new Triangle(4.2, 3.60, 4.2));

		for (int i = 0; i < shapes.getSize(); i++)
		{
			shapes.get(i)->print();
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}