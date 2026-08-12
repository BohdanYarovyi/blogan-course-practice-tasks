#include <iostream>

/*
    Спробуємо вперше попрацювати з декількома файлами. Створіть файл Math.cpp. В ньому будуть знаходитися функції по роботі з математикою. Створіть спочатку у цьому файлі глобальну константу:

    const double PI = 3.14159

    Далі створіть наступні функції:
        - double CalculateCircleArea(double radius) - рахує площу кола за указаним радіусом.
        - double CalculateCircleLength(double radius) - рахує довжину кола за указаним радіусом.

    Обидві функції використовують константу PI.

    Далі створіть уже знайомий нам файл Main.cpp, в якому буде знаходитися функція main. Ваша задача в ній вивести площу і довжину кола з радіусом 12. Очевидно, що у функції main ви маєте використовувати функції із іншого файлу.

    Можете спробувати також вивести значення константи PI у функції main. У вас виникне помилка, якщо ви спробуєте оголосити цю константу в Main.cpp. А чому така помилка - шукайте в інтернеті.

    ПІДКАЗКА 1: вам треба оголосити константу і функції у файлі Main.cpp
    ПІДКАЗКА 2: Формули обрахунку площі і довжини кола:
        S = PI * R * R
        L = 2 * PI * R
 */


double calculate_circle_area(double radius);

double calculate_circle_length(double radius);

int main() {
	int radius = 12;
	double area = calculate_circle_area(radius);
	double length = calculate_circle_length(radius);

	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Area: " << area << std::endl;
	std::cout << "Length: " << length << std::endl;

	return  0;
}
