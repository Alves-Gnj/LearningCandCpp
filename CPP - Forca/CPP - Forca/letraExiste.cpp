#include "letraExiste.hpp"

bool letraExiste(char chute, std::string& palavraSecreta) {
	for (char letra : palavraSecreta) {
		if (chute == letra) {
			return true;
		}
	}

	return false;
}