#include <iostream>

/*
Є наступні функції:
    void func1() {}
    void func2(int) {}
    void func3(double, long) {}
    void func4(int[], int) {}
    int func5() { return 0; }
    int* func6(int*, double) { return 0; }

Створіть на них вказівники і через них викличте їх.
*/

void func1() {}

void func2(int) {}

void func3(double, long) {}

void func4(int[], int) {}

int func5() { return 0; }

int* func6(int*, double) { return 0; }

int main()
{
	int a = 10;

	void (*pf_func1)() = func1;
	pf_func1();

	void (*pf_func2)(int) = func2;
	pf_func2(a);

	void (*pf_func3)(double, long) = func3;
	pf_func3(2.5, 10L);

	void (*pf_func4)(int*, int) = func4;
	pf_func4(&a, a);

	int (*pf_func5)() = func5;
	pf_func5();

	int* (*pf_func6)(int*, double) = func6;
	pf_func6(&a, 2.5);

	return 0;
}
