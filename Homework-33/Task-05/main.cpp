 #include <iostream>
 #include <windows.h>

/*
Давайте зробимо нашу гру ще крутішою. Розмістимо в грі локації. Наприклад школу, склад і церкву.
Представимо, що ось це карта:

	x
	^
	|
	|	ШШШ
	|	ШШШ
	|	ШШШ
	|					ЦЦЦЦЦ
	|					ЦЦЦЦЦ
	|			К
	|	СС
	|	СС
	|	
  --+----------------------------------> y
	|

	Буква 'К' - це координата гравця.
	Буква 'С' - це координата складу.
	Буква 'Ш' - це координата школи.
	Буква 'Ц' - це координата церкви.

#########################################################################################################################
Переміщуючи свого персонажа, гравець може потрапити в одну з цих локацій. Як це реалізувати?
Вирішити, які координати має кожна локація. А точніше визначити координати кутів кожної локації,
а потім перевіряти координати користувача з цими координатами. Так, буде багато коду в умовах if.

Код має бути схожий на наступну схему:

do {
	Показати місцезнаходження гравця (в координатах).
	if (гравець знаходиться в школі) {
		Вивести повідомлення "Ви в школі"
	}
	if (гравець знаходиться в церкві) {
		Вивести повідомлення "Ви в церкві"
	}
	if (гравець знаходиться в складі) {
		Вивести повідомлення "Ви в складі"
	}

	Вивести меню руху гравця
	Дати гравцю ввести напрямок

	switch (вибір пункту меню) {
		case вверх:
			перемістити гравця вверх (змінивши координати)
			break;
		case вправо:
			перемістити гравця вправо (змінивши координати)
			break;
		case вниз:
			перемістити гравця вниз (змінивши координати)
			break;
		case вліво:
			перемістити гравця вліво (змінивши координати)
			break;
		case зупинка:
			break;
	}

} while (поки персонаж не зупинився);
*/

int main() {
	SetConsoleOutputCP(CP_UTF8);

	// options
	constexpr int MOVE_UP		= 1;
	constexpr int MOVE_RIGHT	= 2;
	constexpr int MOVE_DOWN		= 3;
	constexpr int MOVE_LEFT		= 4;
	constexpr int STOP			= 5;
	
	// objects
	constexpr char WAREHOUSE_BODY	= 'W';
	constexpr int WAREHOUSE_A_X		= 1;
	constexpr int WAREHOUSE_A_Y		= 3;
	constexpr int WAREHOUSE_B_X		= 3;
	constexpr int WAREHOUSE_B_Y		= 5;

	constexpr char SCHOOL_BODY		= 'S';
	constexpr int SCHOOL_A_X		= 6;
	constexpr int SCHOOL_A_Y		= 3;
	constexpr int SCHOOL_B_X		= 9;
	constexpr int SCHOOL_B_Y		= 6;

	constexpr char CHURCH_BODY		= 'C';
	constexpr int CHURCH_A_X		= 4;
	constexpr int CHURCH_A_Y		= 19;
	constexpr int CHURCH_B_X		= 6;
	constexpr int CHURCH_B_Y		= 24;

	constexpr int MAP_HEIGHT		= 10;
	constexpr int MAP_WIDTH			= 40;

	constexpr char DESERT_BODY		= '.';

	constexpr char CHARACTER_BODY	= '&';
	int character_x = 4;
	int character_y = 11;
	char current_location = DESERT_BODY;
	int current_option;

	do {
		
		{ // map
			int h_i = MAP_HEIGHT;
			while (h_i >= 0) {
				int w_i = 0;
				while (w_i <= MAP_WIDTH) {
					

					if (w_i > 0 && h_i > 0) {
						if (w_i == character_y && h_i == character_x) {
							std::cout << CHARACTER_BODY;
						}
						else if (w_i >= WAREHOUSE_A_Y && w_i < WAREHOUSE_B_Y &&
								 h_i >= WAREHOUSE_A_X && h_i < WAREHOUSE_B_X) {
							std::cout << WAREHOUSE_BODY;
						}
						else if (w_i >= SCHOOL_A_Y && w_i < SCHOOL_B_Y &&
								 h_i >= SCHOOL_A_X && h_i < SCHOOL_B_X) {
							std::cout << SCHOOL_BODY;
						}
						else if (w_i >= CHURCH_A_Y && w_i < CHURCH_B_Y &&
								 h_i >= CHURCH_A_X && h_i < CHURCH_B_X) {
							std::cout << CHURCH_BODY;
						}
						else {
							std::cout << DESERT_BODY;
						}
					}
					else if (w_i == 0 && h_i != 0) {
						std::cout << "|";
					} 
					else if (h_i == 0 && w_i != 0) {
						std::cout << "-";
					}
					else {
						std::cout << "+";
					}
					w_i++;
				}
				std::cout << std::endl;

				h_i--;
			}
		}
		
		{ // options
			
			switch (current_location) {
				case DESERT_BODY: {
					std::cout << "location: Пустеля" << std::endl;
					break;
				}
				case WAREHOUSE_BODY: {
					std::cout << "location: Склад" << std::endl;
					break;
				}	
				case SCHOOL_BODY: {
					std::cout << "location: Школа" << std::endl;
					break;
				}	
				case CHURCH_BODY: {
					std::cout << "location: Церква" << std::endl;
					break;
				}	
			}

			std::cout << "position: x = " << character_x << "  y = " << character_y << std::endl;
			std::cout << "  " << MOVE_UP	<< " - Move up\n";
			std::cout << "  " << MOVE_RIGHT << " - Move right\n";
			std::cout << "  " << MOVE_DOWN	<< " - Move down\n";
			std::cout << "  " << MOVE_LEFT	<< " - Move left\n";
			std::cout << "  " << STOP		<< " - Stop\n";
			std::cout << "Option: ";
			std::cin >> current_option;
		
			switch (current_option) {
				case MOVE_UP: {
					if (character_x + 1 < MAP_HEIGHT) {
						character_x++;
						std::cout << "The caracter moved up\n";
					}
					else {
						std::cout << "Warn: You cannot move across bounds.\n";
					}

					break;
				}
				case MOVE_RIGHT: {
					if (character_y + 1 < MAP_WIDTH) {
						character_y++;
						std::cout << "The caracter moved right\n";
					}
					else {
						std::cout << "Warn: You cannot move across bounds.\n";
					}

					break;
				}
				case MOVE_DOWN: {
					if (character_x - 1 > 0) {
						character_x--;
						std::cout << "The caracter moved down\n";
					}
					else {
						std::cout << "Warn: You cannot move across bounds.\n";
					}

					break;
				}
				case MOVE_LEFT: {
					if (character_y - 1 > 0) {
						character_y--;
						std::cout << "The caracter moved left\n";
					}
					else {
						std::cout << "Warn: You cannot move across bounds.\n";
					}
					
					break;
				} 
				case STOP: {
					std::cout << "The caracter stopped in: ";
					switch (current_location) {
						case DESERT_BODY: {
							std::cout << "Пустеля" << std::endl;
							break;
						}
						case WAREHOUSE_BODY: {
							std::cout << "Склад" << std::endl;
							break;
						}	
						case SCHOOL_BODY: {
							std::cout << "Школа" << std::endl;
							break;
						}	
						case CHURCH_BODY: {
							std::cout << "Церква" << std::endl;
							break;
						}	
					}
					break;
				}
				default: {
					std::cout << "Such option doesn't exist. Please, use menu items to move the caracter\n";
					break;
				}		
			}
		}

		{ // location checking
			if (character_x >= WAREHOUSE_A_X && character_x < WAREHOUSE_B_X &&
				character_y >= WAREHOUSE_A_Y && character_y < WAREHOUSE_B_Y) {
				current_location = WAREHOUSE_BODY;
			}
			else if (character_x >= SCHOOL_A_X && character_x < SCHOOL_B_X &&
					 character_y >= SCHOOL_A_Y && character_y < SCHOOL_B_Y) {
				current_location = SCHOOL_BODY;
			}
			else if (character_x >= CHURCH_A_X && character_x < CHURCH_B_X &&
					 character_y >= CHURCH_A_Y && character_y < CHURCH_B_Y) {
				current_location = CHURCH_BODY;
			}
			else {
				current_location = DESERT_BODY;
			}
		}
	} while (current_option != STOP);

	return 0;
}