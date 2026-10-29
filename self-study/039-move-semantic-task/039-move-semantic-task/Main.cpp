#include <iostream>
#include <utility>

#include "Buffer.hpp"

template <typename T>
void swap(T& a, T& b)
{
	T tmp = std::move(a);		// copy	constructor
	a = std::move(b);			// copy operator=
	b = std::move(tmp);		// copy operator=
}

Buffer makeBuffer(bool conditional)
{
	Buffer geru(67);
	Buffer pros(69);
	
	if (conditional)
	{
		return geru;
	}
	else
	{
		return pros;
	}
}

int main()
{
	Buffer alpha = {8};
	Buffer beta = {10};

	std::cout << "Alpha: " << alpha.get() << std::endl;
	std::cout << "Beta: " << beta.get() << std::endl;

	swap(alpha, beta);
	std::cout << "Alpha: " << alpha.get() << std::endl;
	std::cout << "Beta: " << beta.get() << std::endl;
}