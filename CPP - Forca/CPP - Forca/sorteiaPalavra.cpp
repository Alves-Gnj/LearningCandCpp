#include "sorteiaPalavra.hpp"
#include "leArquivo.hpp"
#include <vector>
#include <ctime>

std::string sorteiaPalavra() {

	std::vector<std::string> palavras = leArquivo();

	srand(time(NULL));
	int indiceSorteado = rand() % palavras.size();

	return palavras[indiceSorteado];
}