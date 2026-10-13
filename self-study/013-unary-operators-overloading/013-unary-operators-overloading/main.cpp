#include <iostream>

#include "dollars.hpp"

int main()
{
    const Dollars dollars1(7);
    std::cout << "My debt is " << (-dollars1).get_value() << " dollars.\n";

    return 0;
}