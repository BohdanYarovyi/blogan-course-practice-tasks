#include <iostream>
#include <cstdlib>
#include <ctime>


/*
	Ще одна математична задача, тільки простіша. У вас є схожа структура:
	struct Point
	{
    	int x;
     	int y;
	};

	Напишіть наступну функцію:

	int GetCoordinateSystemPart(const Point& point)
	  - перевіряє, в якій чверті координатної сітки знаходиться точка. Повертає:
	  - 1, якщо в першій    (коли x > 0 i y > 0)
	  - 2, якщо в другій    (коли x < 0 i y > 0)
	  - 3, якщо в третій    (коли x < 0 i y < 0)
	  - 4, якщо в четвертій (коли x > 0 i y < 0)
	  - 0, якщо точка лежить на осях

	Створіть масив із 10 точок. Задавайте їм випадкові значення від -5 до 5. Для кожної точки викличіть цю функцію, щоб дізнатися, де вона лежить.
*/

struct Point
{
	int x;
	int y;
};

int get_coordinate_system_part(const Point& point);

int get_random(int from, int to)
{
	static bool is_initiated = false;
	if (!is_initiated)
	{
		is_initiated = true;
		unsigned int timestamp = static_cast<unsigned int>(std::time(nullptr));
		std::srand(timestamp);
	}

	return std::rand() % (to - from + 1) + from;
}

void show_point(const Point& point)
{
	std::cout << "Point [" << point.x << ":" << point.y << "] locates on ";
	const int coordinate_system_part = get_coordinate_system_part(point);

	switch (coordinate_system_part)
	{
		case 0: std::cout << "the axes"; break;
		case 1: std::cout << "the top-right part"; break;
		case 2: std::cout << "the top-left part"; break;
		case 3: std::cout << "the bottom-left part"; break;
		case 4: std::cout << "the bottom-right part"; break;
	}
	std::cout << std::endl;
}

int main()
{
	Point* points = new Point[10];
	for (int i = 0; i < 10; i++)
	{
		int random_x = get_random(-5, 5);
		int random_y = get_random(-5, 5);
		points[i] = {random_x, random_y};
	}

	for (int i = 0; i < 10; i++) {
		show_point(points[i]);
	}

	delete[] points;
	return 0;
}

int get_coordinate_system_part(const Point& point)
{
	if (point.x > 0 && point.y > 0)
	{
		return 1;
	}
	else if (point.x < 0 && point.y > 0)
	{
		return 2;
	}
	else if (point.x < 0 && point.y < 0)
	{
		return 3;
	}
	else if (point.x > 0 && point.y < 0)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}
