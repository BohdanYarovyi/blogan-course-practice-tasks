#ifndef PARENT_H
#define PARENT_H

class Parent
{
private:
	int id;

public:
	Parent(int id = 0)
		: id(id)
	{
	}

	int getId() const
	{
		return id;
	}
};

#endif PARENT_H