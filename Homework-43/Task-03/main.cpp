#include <iostream>

/*
Напишіть функцію "DrawLine".
Вона приймає два параметри:
    - символ, що треба намалювати
    - кількість разів, скільки треба намалювати цих символів.

Функція малює лінію з цих символів. Викличіть її таким чимном,
щоб намалювати наступні фігури:
+++++
+++++
+++++
+++++

###
###
###
###
*/

void draw_line(const char paint_char, const int count);

void draw_rectangle(const char paint_char, const int width, const int height);

int main() {
	draw_rectangle('+', 5, 4);
	std::cout << std::endl;
	draw_rectangle('#', 3, 4);
	return 0;
}

void draw_line(const char paint_char, const int count) {
	for (int i = 0; i < count; i++) {
		std::cout << paint_char;
	}
	std::cout << std::endl;
}

void draw_rectangle(const char paint_char, const int width, const int height) {
	for (int row = 0; row < height; row++) {
		draw_line(paint_char, width);
	}
}
