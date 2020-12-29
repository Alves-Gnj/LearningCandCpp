#include "chuta.hpp"
#include "letraExiste.hpp"

#include <iostream>

void chuta(std::map<char, bool>& chutou, std::vector<char>& chutesErrados, std::string& palavraSecreta) {
	std::cout << "Seu chute: ";
	char chute;
	std::cin >> chute;

	chutou[chute] = true;

	if (letraExiste(chute, palavraSecreta)) {
		std::cout << ">> Você acertou." << std::endl;
	}
	else {
		std::cout << ">> ERROU!" << std::endl;
		chutesErrados.push_back(chute);
	}
	std::cout << std::endl;
}