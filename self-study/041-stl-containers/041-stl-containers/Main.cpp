#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>

int main()
{
	{ // vector
		std::vector<int> vect;
		for (int i = 0; i < 5; i++)
		{
			vect.push_back(10 - i);
		}

		for (int i = 0; i < vect.size(); i++)
		{
			std::cout << vect[i] << ' ';
		}
		std::cout << '\n';
	}

	{ // deque
		std::deque<int> deq;
		for (int i = 0; i < 4; i++)
		{
			deq.push_back(i);
			deq.push_front(10 - i);
		}

		for (int i = 0; i < deq.size(); i++)
		{
			std::cout << deq[i] << ' ';
		}
		std::cout << '\n';
	}

	{ // iterator
		std::vector<int> myVector;
		for (int i = 0; i < 5; i++)
		{
			myVector.push_back(i);
		}
	
		std::vector<int>::const_iterator it = myVector.cbegin();
		while (it != myVector.cend())
		{
			std::cout << *it << ' ';
			it++;
		}
		std::cout << '\n';
	}

	{ // list
		std::list<int> myList;
		for (int i = 0; i < 15; i++)
		{
			myList.push_back(i);
		}

		std::list<int>::const_iterator it = myList.cbegin();
		while (it != myList.cend())
		{
			std::cout << *it << ' ';
			it++;
		}
		std::cout << '\n';
	}

	{ // set
		std::set<int> mySet;
		mySet.insert(8);
		mySet.insert(3);
		mySet.insert(-4);
		mySet.insert(9);
		mySet.insert(2);

		std::set<int>::const_iterator it = mySet.cbegin();
		while (it != mySet.cend())
		{
			std::cout << *it << ' ';
			it++;
		}
		std::cout << '\n';
	}

	{ // map
		std::map<int, std::string> myMap;
		myMap.insert(std::make_pair(3, "Cat"));
		myMap.insert(std::make_pair(2, "Dog"));
		myMap.insert(std::make_pair(5, "Chicken"));
		myMap.insert(std::make_pair(4, "Lion"));
		myMap.insert(std::make_pair(1, "Spider"));

		std::map<int,std::string>::const_iterator it = myMap.cbegin();
		while (it != myMap.cend())
		{
			std::cout << it->first << "=" << it->second << ' ';
			it++;
		}
		std::cout << '\n';
	}

	{ // min_element() і max_element()
		std::list<int> list;
		for (int i = 0; i < 6; i++)
		{
			list.push_back(i);
		}

		std::list<int>::const_iterator it = list.cbegin();
		std::list<int>::const_iterator min = std::min_element(it, list.cend());
		std::list<int>::const_iterator max = std::max_element(it, list.cend());

		std::cout << "min: " << *min << '\n';
		std::cout << "max: " << *max << '\n';
	}

	{ // find() і list::insert()
		std::list<double> list;
		for (int i = 0; i < 10; i++)
		{
			list.push_back(i + 1);
		}

		std::list<double>::const_iterator five = std::find(list.cbegin(), list.cend(), 5);
		list.insert(five, 4.5);

		for (std::list<double>::const_iterator it = list.cbegin(); it != list.cend(); it++)
		{
			std::cout << *it << ' ';
		}
		std::cout << '\n';
	}

	{ // sort() і reverse()
		std::vector<int> vect;
		vect.push_back(4);
		vect.push_back(8);
		vect.push_back(-3);
		vect.push_back(3);
		vect.push_back(-8);
		vect.push_back(12);
		vect.push_back(5);

		std::sort(vect.begin(), vect.end());

		std::vector<int>::const_iterator it = vect.cbegin();
		while (it != vect.cend())
		{
			std::cout << *it << ' ';
			it++;
		}
		std::cout << '\n';

		std::reverse(vect.begin(), vect.end());
		it = vect.cbegin();
		while (it != vect.cend())
		{
			std::cout << *it << ' ';
			it++;
		}
		std::cout << '\n';

	}
}