#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human
{
private:
	std::string name;
	int age;

public:
	Human(std::string name = "", int age = 0)
		: name(name), age(age)
	{
	}

	std::string getName() const
	{
		return name;
	}

	void setName(std::string name)
	{
		this->name = name;
	}

	int getAge() const
	{
		return age;
	}

	void setAge(int age)
	{
		this->age = age;
	}
};

#endif // !HUMAN_H
