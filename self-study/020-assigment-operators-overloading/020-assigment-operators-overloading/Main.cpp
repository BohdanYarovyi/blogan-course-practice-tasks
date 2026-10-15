#include "Drob.hpp"

int main()
{
    Drob sixSeven(6, 7);
    Drob d;
    d = sixSeven; // викликається перевантажений оператор присвоювання
    std::cout << d;
    
    return 0;
}