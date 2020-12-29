#include "tentativaErrada.hpp"

#include <iostream>

namespace forca {
	void tentativaErrada(const std::vector<char>& chutesErrados) {
		std::cout << "Chutes errados: ";
		for (char letra : chutesErrados) {
			std::cout << letra << " ";
		}
		std::cout << std::endl;
	}
}