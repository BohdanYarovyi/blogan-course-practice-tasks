#include <iostream>

int main() {
	constexpr int MAX_SENTENCE_LENGTH = 50;

	char sentence[MAX_SENTENCE_LENGTH];

	std::cout << "Share some replic: ";
	std::cin.getline(sentence, MAX_SENTENCE_LENGTH);

	std::cout << "Your replic: " << sentence << std::endl;
	return 0;
}
