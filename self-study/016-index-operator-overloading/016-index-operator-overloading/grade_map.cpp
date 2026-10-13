#include <iostream>

#include "grade_map.hpp"
#include "string_utils.hpp"

Grade_Map::Student_Grade::Student_Grade(const char* name, int grade)
	: grade(grade)
{
	char* n = String_Utils::copy_string(name);
	this->name = n;
}

Grade_Map::Student_Grade::~Student_Grade()
{
	delete[] name;
}

Grade_Map::Grade_Map(int size)
	: MAX_SIZE(size)
{
	pairs = new Student_Grade*[size] {nullptr};
	count_of_elements = 0;
}

Grade_Map::~Grade_Map()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		delete pairs[i];
	}
	delete[] pairs;
}

int& Grade_Map::operator[](const char* name)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Student_Grade* grade_p = pairs[i];

		if (grade_p == nullptr) continue;
		if (String_Utils::are_string_equal(grade_p->name, name))
		{
			return grade_p->grade;
		}
	}

	if (count_of_elements < MAX_SIZE)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			Student_Grade*& grade_p = pairs[i];
			
			if (grade_p == nullptr)
			{
				grade_p = new Student_Grade(name, 0);
				count_of_elements++;

				return grade_p->grade;
			}
		}
	}
	else
	{
		std::cout << "No any space for new element left." << std::endl;
		// assert
	}
}

std::ostream& operator<<(std::ostream& out, const Grade_Map& map)
{
	out << "Grade Map (size=" << map.MAX_SIZE << ", elements=" << map.count_of_elements << ") {\n";
	for (int i = 0; i < map.MAX_SIZE; i++)
	{
		out << "  [" << i + 1 << "] ";
		Grade_Map::Student_Grade* pair_p = map.pairs[i];

		if (pair_p == nullptr)
		{
			out << "empty\n";
		}
		else
		{
			out << pair_p->name << " : " << pair_p->grade << "\n";
		}
	}
	out << "}\n";

	return out;
}