#include <iostream>
#include "imprimePalavra.hpp"

void imprimePalavra(std::string& palavraSecreta, std::map<char, bool>& chutou) {
	for (char letra : palavraSecreta) {
		if (chutou[letra]) {
			std::cout << letra << " ";
		}
		else {
			std::cout << "_ ";
		}
	}
	std::cout << std::endl;
}