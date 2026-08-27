#include <iostream>

/*
    Напишіть наступні перевантажені функції:
    void ShowType(char)            - виводить на екран текст "type: char"
    void ShowType(unsigned char)   - виводить на екран текст "type: unsigned char"
    void ShowType(signed char)     - виводить на екран текст "type: signed char"
    void ShowType(short)           - виводить на екран текст "type: short"
    void ShowType(unsigned short)  - виводить на екран текст "type: unsigned short"
    void ShowType(int)             - виводить на екран текст "type: int"
    void ShowType(unsigned int)    - виводить на екран текст "type: unsigned int"
    void ShowType(float)           - виводить на екран текст "type: float"
    void ShowType(double)          - виводить на екран текст "type: double"
    void ShowType(long double)     - виводить на екран текст "type: long double"
    void ShowType(bool)            - виводить на екран текст "type: bool"

    І додайте аналогічні функції, які приймають масив, ось одна із таких функцій (їх має бути також 11):
    void ShowType(int[])            - виводить на екран текст "int[]"

    Викличіть декілька цих функцій з різними параметрами: зі значеннями конкретного типу, з масивом конкретного типу, з виразом "'S' + 'g' + 2.3 + 5.8f".
*/

void show_type(char);

void show_type(unsigned char);

void show_type(signed char);

void show_type(short);

void show_type(unsigned short);

void show_type(int);

void show_type(unsigned int);

void show_type(float);

void show_type(double);

void show_type(long double);

void show_type(bool);

void show_type(char[]);

void show_type(unsigned char[]);

void show_type(signed char[]);

void show_type(short[]);

void show_type(unsigned short[]);

void show_type(int[]);

void show_type(unsigned int[]);

void show_type(float[]);

void show_type(double[]);

void show_type(long double[]);

void show_type(bool[]);

int main()
{
	show_type(11);
	show_type("My word is strong!");
	show_type('S' + 'g' + 2.3 + 5.8f);
	return 0;
}

void show_type(char)
{
	std::cout << "type: char\n";
}

void show_type(unsigned char)
{
	std::cout << "type: unsigned char\n";
}

void show_type(signed char)
{
	std::cout << "type: signed char\n";
}

void show_type(short)
{
	std::cout << "type: short\n";
}

void show_type(unsigned short)
{
	std::cout << "type: unsigned short\n";
}

void show_type(int)
{
	std::cout << "type: int\n";
}

void show_type(unsigned int)
{
	std::cout << "type: unsigned int\n";
}

void show_type(float)
{
	std::cout << "type: float\n";
}

void show_type(double)
{
	std::cout << "type: double\n";
}

void show_type(long double)
{
	std::cout << "type: long double\n";
}

void show_type(bool)
{
	std::cout << "type: bool\n";
}

void show_type(char[])
{
	std::cout << "type: char[]\n";
}

void show_type(unsigned char[])
{
	std::cout << "type: unsigned char[]\n";
}

void show_type(signed char[])
{
	std::cout << "type: signed char[]\n";
}

void show_type(short[])
{
	std::cout << "type: short[]\n";
}

void show_type(unsigned short[])
{
	std::cout << "type: unsigned short[]\n";
}

void show_type(int[])
{
	std::cout << "type: int[]\n";
}

void show_type(unsigned int[])
{
	std::cout << "type: unsigned int[]\n";
}

void show_type(float[])
{
	std::cout << "type: float[]\n";
}

void show_type(double[])
{
	std::cout << "type: double[]\n";
}

void show_type(long double[])
{
	std::cout << "type: long double[]\n";
}

void show_type(bool[])
{
	std::cout << "type: bool[]\n";
}
