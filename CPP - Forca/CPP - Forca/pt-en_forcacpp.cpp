#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "adicionaPalavra.hpp"
#include "chuta.hpp"
#include "imprimeCabecalho.hpp"
#include "imprimePalavra.hpp"
#include "leArquivo.hpp"
#include "letraExiste.hpp"
#include "naoAcertou.hpp"
#include "salvaArquivo.hpp"
#include "sorteiaPalavra.hpp"
#include "tentativaErrada.hpp"

using namespace std;

static string palavraSecreta;
static map<char, bool> chutou;
static vector<char> chutesErrados;

int main() {
	imprimeCabecalho();

	palavraSecreta = sorteiaPalavra();

	while (naoAcertou(palavraSecreta, chutou) && chutesErrados.size() < 5) {

		tentativaErrada(chutesErrados);
		imprimePalavra(palavraSecreta, chutou);
		chuta(chutou, chutesErrados, palavraSecreta);
	}

	cout << "Fim de jogo!" << endl;
	cout << "A palavra secreta era: " << palavraSecreta << endl;

	if (naoAcertou(palavraSecreta, chutou)) {
		cout << "Você perdeu! Pode tentar novamente mas não faço questão..."
			<< endl;
	}
	else {
		cout << "Parabéns, você acertou a palavra secreta!" << endl;

		cout << "Você deseja adicionar uma nova palavra? (S/N)" << endl;
		char resposta;
		cin >> resposta;

		if (resposta == 'S') {
			adicionaPalavra();
		}
	}
}