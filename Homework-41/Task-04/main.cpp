#include <iostream>

/*
Напишіть програму, яка створює двовимірний масив розміром 5 на 4. 5 - це кількість студентів,
4 - це кількість шкільних предметів. Завдяки списковій ініціалізації запишіть кожному студенту
відповідні оцінки по кожному предмету. Нехай діапазон буде від 1 до 12 балів. Виведіть на екран
середню оцінку по предметам всіх студентів окремо. Для цього вам треба завдяки циклу порахувати 
ці оцінки 5 разів (бо студентів 5).
Можна вивести наступним чином:
	Середня оцінка студента #0: 8.3
	Середня оцінка студента #1: 10.4
	і так далі.
*/

int main() {
	constexpr int STUDENT_COUNT = 5;
	constexpr int SCHOOL_SUBJECT_COUNT = 4;

	float student_marks[STUDENT_COUNT][SCHOOL_SUBJECT_COUNT] {
		{4.5, 3.8, 5.0, 4.2},
		{3.2, 4.7, 4.0, 5.0},
		{5.0, 5.0, 4.8, 4.9},
		{2.8, 3.4, 3.0, 3.9},
		{4.1, 3.6, 1.4, 3.8}
	};

	for (int student = 0; student < STUDENT_COUNT; student++) {
		float sum_of_marks = 0;
		
		for (int subject_mark = 0; subject_mark < SCHOOL_SUBJECT_COUNT; subject_mark++) {
			sum_of_marks += student_marks[student][subject_mark];
		}

		float avarage_mark = sum_of_marks / SCHOOL_SUBJECT_COUNT;
		std::cout << "The avarage mark of the student #" << student << " is " << avarage_mark << std::endl; 		
	}
	return 0;
}