#include <iostream>

/*
Напишіть функцію, яка приймає два рядки і перевіряє, чи другий рядок є в першому. Якщо другий рядок знаходиться в першому, то вона повертає індекс елементу, з якого починається цей рядок в першому рядку. Якщо другого рядка немає в першому, то повертає -1. 
Тобто результат має виглядати ось так:
	const char sentence[] = "I have a dog. My dog's name is Joy";
	const char word[] = "dog";

	int foundIndex = Find(sentence, word);
	if (foundIndex != -1)
	{ } // слово знайдене, foundIndex = 9
	else
	{ } // слово не знайдене
*/

int find(const char* sentence, const char* word);

int main()
{	
	const char sentence[] = "I have a dodog. My dog's name is Joy";
	const char word[] = "dog";

	int found_index = find(sentence, word);
	if (found_index == -1)
	{
		std::cout << "We didn't find your word :(\n";
	}
	else
	{
		std::cout << "We successfully found your word. Its position at index " << found_index << " :)\n";
	}
	return 0;
}

int find(const char* sentence, const char* word)
{
	int sentence_length = 0;
	for (; sentence[sentence_length] != '\0'; sentence_length++);

	int word_length = 0;
	for (; word[word_length] != '\0'; word_length++);

	bool in_matching = false;
	int word_index = 0;
	int result_index = -1;
	for (int i = 0; i < sentence_length; i++)
	{
		if (sentence_length - i < word_length && !in_matching)
		{
			break;
		}

		if (sentence[i] == word[word_index])
		{
			if (!in_matching)
			{
				result_index = i;
				in_matching = true;
			}

			if (word[word_index + 1] == '\0')
			{
				break;
			}

			word_index++;
		}
		else if (in_matching)
		{
			in_matching = false;
			result_index = -1;
			i -= word_index;
			word_index = 0;
		}
	}

	return result_index;
}
