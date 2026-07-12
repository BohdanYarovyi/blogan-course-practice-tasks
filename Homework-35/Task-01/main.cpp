#include <iostream>

/*
Я на відео по теорії  показав код, де я виводжу числа 1, 2, 3, 4 і 5 на екран завдяки цьому циклу. 
Перепишіть цей код так, щоб він знаходив суму всіх цих чисел і в кінці виводив їх на екран.
*/

int main() {
	int sum = 0;

	for (int number : {1, 2, 3, 4, 5}) {
		sum += number;
	}

	std::cout << "The sum of numbers is " << sum << std::endl;
	return 0;
}