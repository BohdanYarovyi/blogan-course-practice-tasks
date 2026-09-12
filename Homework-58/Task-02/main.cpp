/*
Є наступний код. Спробуйте розписати на листочку для себе, в якій пам'яті будуть розміщатися всі дані і коли вони знищаться
	int b;

    void Function2(int* p)
    { }

    long d;

    void Function1()
    {
        int a;
        Function2(&a);
        static double c;
    }

    int main()
    {
        Function1();
        int arr[3];
        Function2(arr);

        return 0;
    }
*/

/* ВІДПОВІДЬ
    int    b - збережеться в файл .bss до усіх статичних ініціалізованих змінних
    long   d - збережеться в файл .bss до усіх статичних ініціалізованих змінних
    double c - збережеться в файл .bss до усіх статичних ініціалізованих змінних

    Stack виглядає:
    *main()
    *Function1()
    int a
    *Function2(int*)
    int* p
    int array[0]
    int array[1]
    int array[2]
    *Function2(int*)
    int* p
*/

int main()
{
	return 0;
}