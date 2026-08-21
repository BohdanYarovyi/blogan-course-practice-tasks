#include <iostream>

/*
Напишіть функцію void DebugMessage(const char message[] = "Debug Message"), яка виводить на екран указане повідомлення. Викличте її у функції main 3 рази, два з яких використовуйте значення за замовчуванням.
*/

void debug_message(const char message[] = "Debug Message");

int main()
{
	debug_message();
	debug_message("Hello world");
	debug_message();
	return 0;
}

void debug_message(const char message[])
{
	for (int i = 0; message[i] != '\0'; i++)
	{
		std::cout << message[i];
	}
	std::cout << "\n";
}
