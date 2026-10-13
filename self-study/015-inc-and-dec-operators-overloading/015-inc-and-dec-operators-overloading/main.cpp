#include <iostream>

#include "number.hpp"

int main()
{
    Number number(6);

    std::cout << number;
    std::cout << ++number; // викликається Number::operator++();
    std::cout << number++; // викликається Number::operator++(int);
    std::cout << number;
    std::cout << --number; // викликається Number::operator--();
    std::cout << number--; // викликається Number::operator--(int);
    std::cout << number;

    return 0;
}