#include <iostream>
#include <cmath>

#include "MyException.hpp"

double mySqrt(double a)
{
	if (a < 0.0)
		throw MyException(1, "Can not take sqrt of negative number");

	return std::sqrt(a);
}

int main()
{
    std::cout << "Enter a number: ";
    double a;
    std::cin >> a;

    try // шукаємо винятки, які генеруються в блоці try, і відправляємо їх для обробки в блок(и) catch
    {
        double d = mySqrt(a);
        std::cout << "The sqrt of " << a << " is " << d << '\n';
    }
    catch (const MyException& e) // обробка винятків типу const char*
    {
        std::cerr << "Error: " << e << std::endl;
    }
    catch (...)
    {
        std::cerr << "Abnormal termination" << std::endl;
    }

    return 0;
}
