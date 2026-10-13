#ifndef GRADE_MAP
#define GRADE_MAP

#include <iostream>

class Grade_Map
{
private:
	struct Student_Grade
	{
		char* name;
		int grade;

		Student_Grade(const char* name, int grade);

		~Student_Grade();
	};

	const int MAX_SIZE;
	Student_Grade** pairs;
	int count_of_elements;

public:
	Grade_Map(int size);

	~Grade_Map();

	int& operator[](const char* name);

	friend std::ostream& operator<<(std::ostream& out,  const Grade_Map& map);
};

#endif // GRADE_MAP