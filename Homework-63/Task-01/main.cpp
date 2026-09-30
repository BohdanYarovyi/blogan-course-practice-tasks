#include <cstdlib>
#include <iostream>
#include <cmath>

/*
    Це математична задача. Щоб виконати її, ви маєте знати, що таке вектори в математиці, і які операції над ними можна здійснювати. У вас є наступна структура:
    struct Vector
    {
        double x;
        double y;
    };

    Напишіть наступні функції:

    double Length(const Vector& vector)
    - рахує довжину вектора

    Vector Add(const Vector& vector1, const Vector& vector2)
    - додає два вектори, повертає результат.

    Vector Substract(const Vector& vector1, const Vector& vector2)
    - віднімає від першого вектору другий, повертає результат.

    void Normalize(Vector& vector)
    - нормалізовує вектор

    bool IsUnitVector(const Vector& vector)
    - повертає true, якщо вектор одиничний

    Створіть масив із декількох векторів і перевірте ці функції.
*/
struct Vector
{
	double x;
	double y;
};

double length(const Vector& vector);

Vector add(const Vector& vector_1, const Vector& vector_2);

Vector substract(const Vector& vector_1, const Vector& vector_2);

void normalize(Vector& vector);

bool is_unit_vector(const Vector& vector);

int main()
{
	Vector v1 = { 3.0, 4.0 };
    Vector v2 = { 1.0, 2.0 };

    std::cout << "Length v1: " << length(v1) << " (Expected: 5)\n";

    Vector sum = add(v1, v2);
    std::cout << "Add: (" << sum.x << ", " << sum.y << ") (Expected: 4, 6)\n";

    Vector diff = substract(v1, v2);
    std::cout << "substract: (" << diff.x << ", " << diff.y << ") (Expected: 2, 2)\n";

    std::cout << "Is v1 unit? " << std::boolalpha << is_unit_vector(v1) << " (Expected: false)\n";

    normalize(v1);
    std::cout << "After Normalize v1: (" << v1.x << ", " << v1.y << ")\n";
    std::cout << "Length after Normalize: " << length(v1) << "\n";
    std::cout << "Is v1 unit now? " << is_unit_vector(v1) << " (Expected: true)\n";
}

double length(const Vector& vector)
{
	double dx = vector.x * vector.x;
	double dy = vector.y * vector.y;

	return std::sqrt(dx + dy);
}

Vector add(const Vector& vector_1, const Vector& vector_2)
{
	Vector result;
	result.x = vector_1.x + vector_2.x;
	result.y = vector_1.y + vector_2.y;

	return result;
}

Vector substract(const Vector& vector_1, const Vector& vector_2)
{
	Vector result;
	result.x = vector_1.x - vector_2.x;
	result.y = vector_1.y - vector_2.y;

	return result;
}

void normalize(Vector& vector)
{
	double vector_length = length(vector);
	if (vector_length == 0.0)
	{
		return;
	}

	double proportionality_coefficient = 1.0 / vector_length;

	vector.x = vector.x * proportionality_coefficient;
	vector.y = vector.y * proportionality_coefficient;
}

bool is_unit_vector(const Vector& vector)
{
	double l = length(vector);
	return std::abs(l - 1.0) < 0.0001 ;
}
