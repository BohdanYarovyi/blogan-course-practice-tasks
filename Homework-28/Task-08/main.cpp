#include <iostream>
#include <windows.h>

/*
Переробіть попередню задачу так, щоб програма точніше описувала причину заборони видачі паспорта.
Тобто якщо користувачу немає 16 - виводиться повідомлення "Вам немає 16 років". 
Якщо користувач живе не в Україні, то виводиться повідомлення "Ви не живете в Україні".
*/

int main() {
	// enable unicode code page in console
	SetConsoleOutputCP(CP_UTF8);

	bool is_adult;
	bool is_in_ukraine;
	bool is_allowed_to_get_passport = true;

	std::cout << "Чи є Вам 16 років? (1 - так, 0 - ні): ";
	std::cin >> is_adult;
	std::cout << "Чи проживаєте Ви в Україні? (1 - так, 0 - ні): ";
	std::cin >> is_in_ukraine;

	if (!is_adult) {
		std::cout << "Вам немає 16 років" << std::endl;
		is_allowed_to_get_passport = false;
	}

	if (!is_in_ukraine) {
		std::cout << "Ви не проживаєте в Україні" << std::endl;
		is_allowed_to_get_passport = false;
	}

	if (is_allowed_to_get_passport) {
		std::cout << "Ви можете отримати паспорт громадянина України" << std::endl;
	}

	return 0;
}