#pragma once

#include <stdexcept>
#include <iostream>

class Fraction
{
  private:
	int numerator;
	int denominator;

  public:
	Fraction(int numerator, int denominator)
	{
		if (!denominator)
		{
			throw std::runtime_error("Denominator cannot be zero");
		}

		this->numerator = numerator;
		this->denominator = denominator;
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
	{
		return out << fraction.numerator << "/" << fraction.denominator;
	}

	static Fraction create()
	{
		int numerator = 0;
		int denominator = 0;
		std::cout << "Input numerator: ";
		std::cin >> numerator;
		std::cout << "Input denominator: ";
		std::cin >> denominator;

		return Fraction(numerator, denominator);
	}
};
