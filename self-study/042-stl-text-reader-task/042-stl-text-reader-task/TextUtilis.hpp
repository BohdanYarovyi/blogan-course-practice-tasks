#pragma once

#include <vector>

#include "Word.hpp"

namespace TextUtils
{
	std::vector<Word> splitByWords(const char* text);
}