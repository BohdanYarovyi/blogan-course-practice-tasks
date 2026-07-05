#include <iostream>

/*
Покращимо попередню задачу. Представимо, що гравець вже має якісь координа.
Наприклад x = 0 і y = 0. Перед виводом меню повідомте користувачу, які координати має його герой. 
Якщо користувач обирає переміститись вверх - збільшуйте 'y' на 1. Якщо вниз - зменшуйте
'y' на 1. Якщо вліво - зменшуйте 'x' на 1. Якщо вправо - збільшуйте 'x' на 1.
*/

int main() {
	constexpr int MOVE_UP		= 1;
	constexpr int MOVE_RIGHT	= 2;
	constexpr int MOVE_DOWN		= 3;
	constexpr int MOVE_LEFT		= 4;
	constexpr int STOP			= 5;

	int character_x = 0;
	int character_y = 0;
	int current_option;

	do {
		std::cout << "Caracter position: x = " << character_x << "\ty = " << character_y << std::endl;
		std::cout << "  " << MOVE_UP	<< " - Move up\n";
		std::cout << "  " << MOVE_RIGHT << " - Move right\n";
		std::cout << "  " << MOVE_DOWN	<< " - Move down\n";
		std::cout << "  " << MOVE_LEFT	<< " - Move left\n";
		std::cout << "  " << STOP		<< " - Stop\n";
		std::cout << "Option: ";
		std::cin >> current_option;

		switch (current_option) {
			case MOVE_UP: {
				character_y++;
				
				std::cout << "The caracter moved up\n";
				break;
			}
			case MOVE_RIGHT: {
				character_x++;
				
				std::cout << "The caracter moved right\n";
				break;
			}
			case MOVE_DOWN: {
				character_y--;

				std::cout << "The caracter moved down\n";
				break;
			}
			case MOVE_LEFT: {
				character_x--;

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