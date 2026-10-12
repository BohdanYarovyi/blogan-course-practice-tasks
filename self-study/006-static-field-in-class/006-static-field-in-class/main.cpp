#include <iostream>

class Anything
{
public:
	static int s_value;
};

int Anything::s_value = 3;

int main()
{
	Anything::s_value = 4;   
	std::cout << Anything::s_value << '\n';
	return 0;
}