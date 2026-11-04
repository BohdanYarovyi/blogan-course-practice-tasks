#pragma once

#include <iostream>

struct Word
{
	char* value;
	int length;

	Word(char* value, int length);

	Word(const Word& other);

	~Word()
	{
		delete[] value;
	}

	bool operator<(const Word& other) const;

	Word& operator=(const Word& other);

	friend std::ostream& operator<<(std::ostream& out, const Word& word);
};