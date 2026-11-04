#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>

#include "Word.hpp"

struct TextReport
{
	std::map<Word,int> wordFrequency;
	std::set<Word> usedWords;
	std::vector<Word> oneTimeUsedWords;
	Word longestWord;

	TextReport();

	void printReport() const;
};

namespace TextReportTools
{
	TextReport makeReport(const char* text);
}