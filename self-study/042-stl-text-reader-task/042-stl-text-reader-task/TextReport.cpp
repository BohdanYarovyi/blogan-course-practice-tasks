#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "Word.hpp"
#include "TextReport.hpp"
#include "TextUtilis.hpp"

TextReport::TextReport()
	: longestWord(nullptr, 0)
{
}

void TextReport::printReport() const
{
	{ // to 5 frequence words
		std::map<Word,int>::const_iterator it = wordFrequency.cbegin();

		std::cout << "Word frequency: {";
		bool printComma = false;
		while (it != wordFrequency.cend())
		{
			if (printComma)
			{
				std::cout << ", ";
			}

			std::cout << it->first << "=" << it->second;
			printComma = true;
			it++;
		}
		std::cout << "}\n\n";
	}

	{ // all used words
		std::set<Word>::const_iterator it = usedWords.cbegin();

		std::cout << "Used words: ";
		bool printComma = false;
		while (it != usedWords.cend())
		{
			if (printComma)
			{
				std::cout << ", ";
			}

			std::cout << *it;
			printComma = true;
			it++;
		}
		std::cout << "\n\n";
	}

	{ // only once used words
		std::vector<Word>::const_iterator it = oneTimeUsedWords.cbegin();

		std::cout << "Only once used words: ";
		bool printComma = false;
		while (it != oneTimeUsedWords.cend())
		{
			if (printComma)
			{
				std::cout << ", ";
			}

			std::cout << *it;
			printComma = true;
			it++;
		}
		std::cout << "\n\n";
	}

	{ // longest words
		if (longestWord.value)
		{
			std::cout << "Longest word is '" << longestWord << "' and has " << longestWord.length << " letters.\n";
		}
		else
		{
			std::cout << "No one word" << std::endl;
		}
	}
}

namespace TextReportTools
{
	TextReport makeReport(const char* text)
	{
		std::vector<Word> words = TextUtils::splitByWords(text);
		TextReport report = {};

		for (int i = 0; i < words.size(); i++)
		{
			Word word = words[i];

			{ // word frequency
				report.wordFrequency[word] += 1;
			}

			{ // used words
				report.usedWords.insert(word);
			}

			{ // longest word
				if (report.longestWord.length < word.length)
				{
					report.longestWord = word;
				}
			}
		}

		{ // only once used words
			std::map<Word,int>::const_iterator it = report.wordFrequency.cbegin();

			while (it != report.wordFrequency.cend())
			{
				if (it->second == 1)
				{
					report.oneTimeUsedWords.push_back(it->first);
				}

				it++;
			}
		}

		{ // remove from map less used words till 5 

			while (report.wordFrequency.size() > 5)
			{
				std::map<Word,int>::const_iterator it = report.wordFrequency.cbegin();
				std::map<Word,int>::const_iterator lowestFrequencyWord = it;
				while (it != report.wordFrequency.cend())
				{
					if (lowestFrequencyWord->second > it->second)
					{
						lowestFrequencyWord = it;
					}

					it++;
				}
				report.wordFrequency.erase(lowestFrequencyWord);
			}
		}

		return report;
	}
}