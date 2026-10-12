#include <iostream>

#include "fraction.hpp"

Fraction::Fraction(int numerator, int denominator)
	: m_numerator(numerator), m_denominator(denominator)
{
	Fraction::reduce();
}

Fraction operator*(const Fraction& object_1, const Fraction& object_2)
{
	int new_numerator = object_1.m_numerator * object_2.m_numerator;
	int new_denominator = object_1.m_denominator * object_2.m_denominator;

	return Fraction(new_numerator, new_denominator);
}

Fraction operator*(const Fraction& object, int value)
{
	return Fraction(object.m_numerator * value, object.m_denominator);
}

Fraction operator*(int value, const Fraction& object) 
{
	return Fraction(object.m_numerator * value, object.m_denominator);
}

int nod(int a, int b) {
	return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
}

void Fraction::reduce()
{
	int n = nod(m_numerator, m_denominator);
	m_numerator /= n;
	m_denominator /= n;
}

void Fraction::print() const
{
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}