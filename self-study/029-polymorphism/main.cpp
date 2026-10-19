#include <iostream>

#include "Parent.hpp"
#include "Child.hpp"

int main()
{
	Child c;
	Parent& parent = c;
    std::cout << "rParent is a " << parent.getName() << '\n';

	return 0;
}
