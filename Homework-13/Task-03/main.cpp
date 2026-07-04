#include <iostream>

/*
Скільки це 19 дюймів в сантиметрах? Створіть 2 змінні і одну константу. 
Перша змінна - кількість дюймів. Друга - кількість сантиметрів. От її і треба порахувати. 
Для цього треба константи INCH_IN_CM. Знайдіть її значення в інтернеті.
*/

const float INCH_IN_CM = 0.3937008f;

int main() {
	int inches = 19;
	int cantimeters = inches / INCH_IN_CM;

	std::cout << "Given inches " << inches << "'' is " << cantimeters << " cm." << std::endl;
	
	return 0;
}