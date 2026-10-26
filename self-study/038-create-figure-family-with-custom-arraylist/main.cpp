#include <iostream>

#include "./../mylib/ArrayList.hpp"

int main()
{
	ArrayList<int> arr;
	arr.add(3);
	arr.add(5);
	arr.add(5);
	arr.add(-3);
	std::cout << arr << std::endl;

	std::cout << arr.get(1);

	arr.remove(0);
	arr.remove(2);
	arr.remove(0);
	arr.remove(0);
	arr.remove(0);
	std::cout << arr << std::endl;
}
