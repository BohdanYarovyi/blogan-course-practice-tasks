#include <iostream>

/*
    Попрацюємо з датами. Є наступна структура:

    struct Date
    {
        int day;
        int month;
        int year;
    };

    Напишіть наступні функції:

    bool IsLeapYear(const Date& date)
    - повертає true, якщо рік високосний.

    Date GetDateDifference(const Date& date1, const Date& date2)
    - повертає різницю двох дат (скільки днів, місяців і років між ними).

    const char* GetMonthName(const Date& date)
    - повертає назву місяця за його числом у даті. Тобто якщо число 2, значить повертає "February".

    bool IsCorrectDate(const Date& date)
    - В поля структури дати можна записати некоректні значення (від'ємні значення в любе поле, 0 в любе поле окрім року. Також при певному місяці не може бути кількість днів більша за певну. Наприклад в лютому кількість днів має бути обов'язково менша за 29, а якщо рік високосний, то менша за 30).

    int GetDaysInDate(const Date& date)
    - повертає дату в днях (дні + місяці в днях + роки). Врахуйте можливість того, що рік може бути високосним.

    int GetDaysInMonth(int monthIndex, bool isLeapYear)
    - повертає кількість днів в указаному місяці (по його індексу, який починається з 1). Функція враховує високосність року завдяки другому параметру.

    Створіть наступну структуру:
    struct Holiday
    {
    Date date;       // дата свята
    char name[100];  // назва свята
    };

    Створіть масив із 5 елементів типу Holiday, заповніть їх списковою ініціалізацією. Свята вибирайте, які хочете. Напишіть наступну функцію:

    bool IsHoliday(const Date& date, const Holiday holidays[], int holidaysCount)
    - повертає true, якщо указана дата є святом.

    Перевірте всі написані вами функції.
*/

const char DAYS_COUNT_OF_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const char* MONTH_NAMES[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"};

struct Date
{
	int day;
	int month;
	int year;
};

struct Holiday
{
	Date date;
	char name[100];
};

bool is_leap_year(const Date& date);

Date get_date_difference(const Date& date_1, const Date& date_2);

char* get_month_name(const Date& date);

bool is_correct_date(const Date& date);

int get_days_in_date(const Date& date);

int get_days_in_month(int month_index, bool is_leap_year);

bool is_holiday(const Date& date, const Holiday holidays[], int holidays_count);

bool is_equal_dates(const Date& date_1, const Date& date_2);

void print_date(const Date& date)
{
	std::cout << date.day << "." << date.month << "." << date.year << std::endl;
}

int main()
{
	Date d1 = {24, 8, 2021};
	Date d2 = {1, 6, 2022};
	Date dd = get_date_difference(d1, d2);
	print_date(dd);
	return 0;
}

bool is_leap_year(const Date& date)
{
	return date.year % 4 == 0 &&
	       date.year % 100 != 0
	      || date.year % 400 == 0;
}

Date get_date_difference(const Date& date_1, const Date& date_2)
{
	// I won't solve a bad defined task
	return {};
}

char* get_month_name(const Date& date)
{
	const char* name = MONTH_NAMES[date.month];
	int i;
	for (i = 0; name[i] != '\0'; i++);

	char* copy_name = new char[i];
	for (int n = 0; n < i; n++)
	{
		copy_name[n] = name[n];
	}

	return copy_name;
}

bool is_correct_date(const Date& date)
{
	if (date.year < 0)
	{
		return false;
	}

	if (date.month < 0 || date.month > 11)
	{
		return false;
	}
	bool is_leap = is_leap_year(date);
	int days_count = get_days_in_month(date.month, is_leap);

	if (date.day < 1 || date.day > days_count)
	{
		return false;
	}

	return true;
}

int get_days_in_date(const Date& date)
{
	// I won't solve a bad defined task
	return 0;
}

int get_days_in_month(int month_index, bool is_leap_year)
{
	if (month_index == 1 && is_leap_year)
	{
		return DAYS_COUNT_OF_MONTH[1] + 1;
	}

	return DAYS_COUNT_OF_MONTH[month_index];
}

bool is_holiday(const Date& date, const Holiday holidays[], int holidays_count)
{
	for (int i = 0; i < holidays_count; i++)
	{
		if (is_equal_dates(date, holidays[i].date))
		{
			return true;
		}
	}

	return false;
}

bool is_equal_dates(const Date& date_1, const Date& date_2)
{
	return date_1.day == date_2.day &&
	       date_1.month == date_2.month &&
	       date_1.year == date_2.year;
}
