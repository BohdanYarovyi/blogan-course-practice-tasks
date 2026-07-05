#include <iostream>

/*
Ви вже робили задачі, де реалізували ввід пунктів меню. Але проблема була у тому,
що користувач міг вводити лише один і все. А тепер ви знаєте цикли, а отже можете
зробити такі меню, в яких користувач може вводити пункти декілька разів.

Так от, є наступне меню:
	1 - Переміститись вверх
	2 - Переміститись вправо
	3 - Переміститись вниз
	4 - Переміститись вліво
	5 - Зупинитися

Виведіть користувачу меню і дайте йому можливість обрати його 
(мається на увазі дати йому можливість ввести число).
Проаналізуйте його вибір і виведіть на екран повідомлення "Герой перемістився вверх",
"Герой перемістився вправо" і так далі. Після цього пункт меню має знову з'являтись, 
даючи користувачу можливість знову обрати напрямок руху.
*/

int main() {
	constexpr int MOVE_UP		= 1;
	constexpr int MOVE_RIGHT	= 2;
	constexpr int MOVE_DOWN		= 3;
	constexpr int MOVE_LEFT		= 4;
	constexpr int STOP			= 5;
	
	int current_option;

	do {
		std::cout << "  " << MOVE_UP	<< " - Move up\n";
		std::cout << "  " << MOVE_RIGHT << " - Move right\n";
		std::cout << "  " << MOVE_DOWN	<< " - Move down\n";
		std::cout << "  " << MOVE_LEFT	<< " - Move left\n";
		std::cout << "  " << STOP		<< " - Stop\n";
		std::cout << "Option: ";
		std::cin >> current_option;

		switch (current_option) {
			case MOVE_UP: {
				std::cout << "The caracter moved up\n";
				break;
			}
			case MOVE_RIGHT: {
				std::cout << "The caracter moved right\n";
				break;
			}
			case MOVE_DOWN: {
				std::cout << "The caracter moved down\n";
				break;
			}
			case MOVE_LEFT: {
				std::cout << "The caracter moved left\n";
				break;
			} 
			case STOP: {
				std::cout << "The caracter stopped for break\n";
				break;
			}
			default: {
				std::cout << "Such option doesn't exist. Please, use menu items to move the caracter\n";
				break;
			}		
		}
	} while (current_option != STOP);
			
	return 0;
}