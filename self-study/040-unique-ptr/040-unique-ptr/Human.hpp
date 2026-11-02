#include <iostream>
#include <string>
#include <memory>

class Human
{
private:
	std::string name;
	std::weak_ptr<Human> partner;

public:
	Human(const std::string& name)
		: name(name)
	{
		std::cout << "Human " << name << " was created." << std::endl;
	}

	~Human()
	{
		std::cout << "Human " << name << " was deleted." << std::endl;
	}

	friend bool partnerUp(const std::shared_ptr<Human>& p1, const std::shared_ptr<Human>& p2)
	{
		if (!p1 || !p2)
		{
			return false;
		}

		p1->partner = p2;
		p2->partner = p1;

		return true;
	}
};
