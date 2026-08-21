#include <iostream>

/*
    Напишіть функцію void DrawRectangle(char ch = '*', int rows = 5, int columns = 5). Вона виводить прямокутник указаних розмірів, заповнений указаним символом.

    Викличте цю функцію 4 рази:
     - без використання значень за замовчуванням
     - з використанням одного значенням за замовчуванням
     - з використанням двох значень за замовчуванням
     - з використанням трьох значень за замовчуванням
*/

void draw_rectangle(char ch = '*', int rows = 5, int columns = 5);

int main()
{
	draw_rectangle('^', 5, 9);
	draw_rectangle('O', 10);
	draw_rectangle('+');
	draw_rectangle();

	return 0;
}

void draw_rectangle(char ch, int rows, int columns)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			std::cout << ch;
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
