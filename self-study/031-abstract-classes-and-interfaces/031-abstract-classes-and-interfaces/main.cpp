#include <iostream>

#include "EmailNotification.hpp"
#include "PushNotification.hpp"

int main()
{
	EmailNotification letter("bogdan.yarovoy.01@gmail.com", "Hello bohdan", "Hello bohdan! I just want to wish you luck. Call mt later please.");
	std::cout << letter.serialize() << std::endl;

	PushNotification phoneNotification("bohdan-24", "Monobank", "You have a lot of money");
	std::cout << phoneNotification.serialize() << std::endl;

}