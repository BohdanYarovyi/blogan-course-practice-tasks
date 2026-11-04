#include <vector>
#include <cassert>

#include "TextUtilis.hpp"
#include "Word.hpp"

namespace TextUtils
{
	constexpr char CAPITAL_LETTER_ASCII_CODE_BEGIN = 'A';

	constexpr char CAPITAL_LETTER_ASCII_CODE_END = 'Z';

	constexpr char LOWERCASE_LETTER_ASCII_CODE_BEGIN = 'a';

	constexpr char LOWERCASE_LETTER_ASCII_CODE_END = 'z';

	static char* cut(const char* text, int beginIndex, int endIndex)
	{
		assert(text);
		assert(beginIndex >= 0);
		assert(endIndex > beginIndex);

		int size = endIndex - beginIndex;
		char* result = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			result[i] = text[beginIndex + i];
		}
		result[size] = '\0';

		return result;
	}

	static bool isLetter(char c)
	{
		return c >= CAPITAL_LETTER_ASCII_CODE_BEGIN 
			&& c <= CAPITAL_LETTER_ASCII_CODE_END
			|| c >= LOWERCASE_LETTER_ASCII_CODE_BEGIN 
			&& c <= LOWERCASE_LETTER_ASCII_CODE_END;
	}

	std::vector<Word> splitByWords(const char* text)
	{
		assert(text);

		std::vector<Word> result;
		int currentIndex = 0;
		int newWordLength = 0;
		while (true)
		{
			char current = text[currentIndex];

			if (current == '\0')
			{
				if (newWordLength > 0)
				{
					char* word = cut(text, currentIndex - newWordLength, currentIndex);
					result.push_back({word, newWordLength});
				}
				break;
			}

			if (isLetter(current))
			{
				newWordLength++;
			}
			else
			{
				if (newWordLength > 0)
				{
					char* word = cut(text, currentIndex - newWordLength, currentIndex);
					result.push_back({word, newWordLength});
				}

				newWordLength = 0;
			}

			currentIndex++;
		}

		return result;
	}
}