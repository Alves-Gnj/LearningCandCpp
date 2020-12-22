#include <cstdlib>
#include <ctime>
#include <fstream>
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
#include "naoEnforcou.hpp"
#include "salvaArquivo.hpp"
#include "sorteiaPalavra.hpp"
#include "tentativaErrada.hpp"

using namespace std;

string palavraSecreta;
map<char, bool> chutou;
vector<char> chutesErrados;

int main() {
  imprimeCabecalho();

  leArquivo();

  sorteiaPalavra();

  while (naoAcertou() && naoEnforcou()) {
    tentativaErrada();

    imprimePalavra();
    chuta();
  }

  cout << "Fim de jogo!" << endl;
  cout << "A palavra secreta era: " << palavraSecreta << endl;

  if (naoAcertou()) {
    cout << "Você perdeu! Pode tentar novamente mas não faço questão..."
         << endl;
  } else {
    cout << "Parabéns, você acertou a palavra secreta!" << endl;

    cout << "Você deseja adicionar uma nova palavra? (S/N)" << endl;
    char resposta;
    cin >> resposta;

    if (resposta == 'S') {
      adicionaPalavra();
    }
  }
}
