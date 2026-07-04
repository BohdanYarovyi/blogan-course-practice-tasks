#include <iostream>
#include <windows.h>
	
/*
Ось всі типи, які ви знаєте на даний момент, разом з ключовим словом unsigned:
	
	Цілочисельні типи:
	- short
	- unsigned short
	- int
	- unsigned int
	- long
	- unsigned long
	- long long
	- unsigned long long
	Дробові типи:
	- float
	- double
	- long double
	Символьні типи:
	- char
	- unsigned char
	- wchar_t
	- char16_t
	- char32_t
	Логічний тип:
	- bool

Виведіть на екран розмір кожного типу, щоб дізнатися, скільки пам'яті вони займають.
*/

int main() {
	SetConsoleOutputCP(CP_UTF8);

	std::cout << "┌───────────────────────┬──────┐"										<< std::endl;
	std::cout << "│ Name of type          │ Size │"										<< std::endl;
	std::cout << "├───────────────────────┼──────┤"										<< std::endl;
	std::cout << "│ Short                 │  " << sizeof(short)				<< "   │"	<< std::endl;
	std::cout << "│ Unsigned short        │  " << sizeof(unsigned short)	<< "   │"	<< std::endl;
	std::cout << "│ Int                   │  " << sizeof(int)				<< "   │"	<< std::endl;
	std::cout << "│ Unsigned int          │  " << sizeof(unsigned int)		<< "   │"	<< std::endl;
	std::cout << "│ Long                  │  " << sizeof(long)				<< "   │"	<< std::endl;
	std::cout << "│ Unsigned long         │  " << sizeof(unsigned long)		<< "   │"	<< std::endl;
	std::cout << "│ Long long             │  " << sizeof(long long)			<< "   │"	<< std::endl;
	std::cout << "│ Unsigned long long    │  " << sizeof(unsigned long long)<< "   │"	<< std::endl;
	std::cout << "├───────────────────────┼──────┤"										<< std::endl;
	std::cout << "│ Float                 │  " << sizeof(float)				<< "   │"	<< std::endl;
	std::cout << "│ Double                │  " << sizeof(double)			<< "   │"	<< std::endl;
	std::cout << "│ Long double           │  " << sizeof(long double)		<< "   │"	<< std::endl;
	std::cout << "├───────────────────────┼──────┤"										<< std::endl;
	std::cout << "│ Char                  │  " << sizeof(char)				<< "   │"	<< std::endl;
	std::cout << "│ Unsigned char         │  " << sizeof(unsigned char)		<< "   │"	<< std::endl;
	std::cout << "│ Wchar_t               │  " << sizeof(wchar_t)			<< "   │"	<< std::endl;
	std::cout << "│ Char16_t              │  " << sizeof(char16_t)			<< "   │"	<< std::endl;
	std::cout << "│ Char32_t              │  " << sizeof(char32_t)			<< "   │"	<< std::endl;
	std::cout << "├───────────────────────┼──────┤"										<< std::endl;
	std::cout << "│ Bool                  │  " << sizeof(bool)				<< "   │"	<< std::endl;
	std::cout << "└───────────────────────┴──────┘"										<< std::endl;
	return 0;
}