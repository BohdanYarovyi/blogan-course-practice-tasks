#include <iostream>

/*
Користувач вводить з клавіатури свій улюблений символ. Виведіть його на екран 5 разів.
*/

int main() {
	char favoriteCharacter;
	
	std::cout << "Enter yout favorite character and I will multiply it: ";
	std::cin >> favoriteCharacter;

	std::cout << favoriteCharacter << "\n";
	std::cout << favoriteCharacter << "\n";
	std::cout << favoriteCharacter << "\n";
	std::cout << favoriteCharacter << "\n";
	std::cout << favoriteCharacter << "\n";
	return 0;
}