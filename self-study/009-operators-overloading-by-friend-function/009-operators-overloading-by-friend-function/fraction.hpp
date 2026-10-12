#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator, int denominator);

	friend Fraction operator*(const Fraction& object_1, const Fraction& object_2);

	friend Fraction operator*(const Fraction& object, int value);
	
	friend Fraction operator*(int value, const Fraction& object);

	void reduce();

	void print() const;
};

#endif // !FRACTION_H
