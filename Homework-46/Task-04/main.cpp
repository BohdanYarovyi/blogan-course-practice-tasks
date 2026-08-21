#include <iostream>

/*
    Напишіть функцію void MakeSandwich(const char bread[] = "Whole Wheat", const char filling[] = "Ham & Cheese")
    яка приймає назву хліба і начинку та виводить повідомлення, який сендвіч зроблений (самі придумайте, як ви хочете виводити повідомлення).

    Викличте цю функцію 3 рази:
    - без використання значень за замовчуванням
    - з використанням одного значенням за замовчуванням
    - з використанням двох значень за замовчуванням
*/

void make_sandwich(const char* bread = "Whole Wheat",const char* filling = "Ham & Cheese");

int main()
{
	make_sandwich("White bread", "Cherry Jam");
	std::cout << '\n';
	make_sandwich("Hlebets");
	std::cout << '\n';
	make_sandwich();
	std::cout << '\n';

	return 0;
}

void make_sandwich(const char* bread, const char* filling)
{
	std::cout << "The sandwich was made with:\n";
	std::cout << " bread - " << bread << "\n";
	std::cout << " filling - " << filling << "\n";
}
