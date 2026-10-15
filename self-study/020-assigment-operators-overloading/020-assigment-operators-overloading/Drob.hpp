#ifndef DROB_H
#define DROB_H

#include <iostream>
#include <cassert>

class Drob
{
private:
    int numerator;
    int denominator;

public:
    // Конструктор за замовчуванням
    Drob(int numerator=0, int denominator=1) :
        numerator(numerator), denominator(denominator)
    {
        assert(denominator != 0);
    }

    // Конструктор копіювання
    Drob(const Drob &copy) :
        numerator(copy.numerator), denominator(copy.denominator)
    {
        // Немає необхідності виконувати перевірку denominator тут, тому що ця перевірка вже виконана в конструкторі за замовчуванням
        std::cout << "Copy constructor worked here!\n"; // просто, щоб показати, що це працює
    }

    // Перевантаження оператора присвоювання
    Drob& operator= (const Drob &drob)
    {
        // Виконуємо копіювання значень
        numerator = drob.numerator;
        denominator = drob.denominator;

        // Повертаємо поточний об'єкт, щоб мати можливість з'єднати в ланцюжок виконання декількох операцій присвоювання
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Drob &d1);

};

#endif // !DROB_H
