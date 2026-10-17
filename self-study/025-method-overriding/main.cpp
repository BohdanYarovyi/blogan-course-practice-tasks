#include <iostream>

#include "Parent.hpp"
#include "Child.hpp"

int main()
{
	Parent p(20);
	p.identify();
	Child c(20);
	c.identify();
	return 0;
}
