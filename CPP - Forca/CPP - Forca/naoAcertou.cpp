#include "naoAcertou.hpp"

bool naoAcertou(std::string& palavraSecreta, const std::map<char, bool>& chutou) {
	for (char letra : palavraSecreta) {
		if (chutou.find(letra) == chutou.end() || !chutou.at(letra)) {
			return true;
		}
	}
	return false;
}
