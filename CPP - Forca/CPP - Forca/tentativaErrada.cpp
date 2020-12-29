#include "tentativaErrada.hpp"

#include <iostream>

void tentativaErrada(const std::vector<char>& chutesErrados) {
	std::cout << "Chutes errados: ";
	for (char letra : chutesErrados) {
		std::cout << letra << " ";
	}
	std::cout << std::endl;
}