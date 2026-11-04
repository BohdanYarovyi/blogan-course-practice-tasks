#include "Word.hpp"

Word::Word(char* value, int length)
: value(value), length(length)
{ 
}

Word::Word(const Word& other)
	: length(other.length)
{
	value = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		value[i] = other.value[i];
	}
	value[length] = '\0';
}

bool Word::operator<(const Word& other) const
{
	if (!value) return other.value;

	int index = 0;
	while (true)
	{
		if (value[index] != other.value[index])
		{
			return value[index] < other.value[index];
		}

		if (value[index] == '\0')
		{
			return false;
		}
		index++;
	}
}

Word& Word::operator=(const Word& other)
{
	if (this == &other) return *this;

	delete[] value;

	length = other.length;
	value = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		value[i] = other.value[i];
	}
	value[length] = '\0';

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Word& word)
{
	return out << word.value;		
}