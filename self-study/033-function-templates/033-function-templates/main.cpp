#include <iostream>

#include "Array.hpp"
#include "Repository.hpp"
#include "Repository8.hpp"

int main()
{
	Array<int> integers(5);
	integers[3] = new int(853);
	for (int i = 0; i < 5; i++)
	{
		if (integers[i])
		{
			std::cout << *integers[i] << std::endl;
		}
		else
		{
			std::cout << "nullptr" << std::endl;
		}
	}

	std::cout << std::endl << std::endl;

	Repository<int> repo(5);
	repo.print();

	Repository<double> repod(0.332);
	repod.print();

	std::cout << std::endl << std::endl;

	int iarray[8] = {1, 2, 3, 4 ,5 ,6 ,7 ,8};
	Repository8<int> numbers(iarray);
	numbers.print();

	bool barray[8] = {true, true, false, false, true, false, false, false};
	Repository8<bool> truth(barray);
	truth.set(6, true);
	truth.set(7, true);
	truth.print();

	std::cout << std::endl << std::endl;

	int* pTime = new int(129938423);
	Repository<int*> time(pTime);
	time.print();
	delete pTime;

	return 0;
}