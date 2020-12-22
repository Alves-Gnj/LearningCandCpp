#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutesErrados;

bool letraExiste(char chute) {
  for (char letra : PALAVRA_SECRETA) {
    if (chute == letra) {
      return true;
    }
  }

  return false;
}

bool naoAcertou() {
  for (char letra : PALAVRA_SECRETA) {
    if (!chutou[letra]) {
      return true;
    }
  }
  return false;
}

bool naoEnforcou() { return chutesErrados.size() < 5; }

void imprimeCabecalho() {
  cout << "**************************" << endl;
  cout << "*** JOGO DA FORCA (BR) ***" << endl;
  cout << "**************************" << endl;
  cout << endl;
}

void tentativaErrada() {
  cout << "Chutes errados: ";
  for (char letra : chutesErrados) {
    cout << letra << " ";
  }
  cout << endl;
}

void imprimePalavra() {
  for (char letra : PALAVRA_SECRETA) {
    if (chutou[letra]) {
      cout << letra << " ";
    } else {
      cout << "_ ";
    }
  }
  cout << endl;
}

void chuta() {
  cout << "Seu chute: ";
  char chute;
  cin >> chute;

  chutou[chute] = true;

  if (letraExiste(chute)) {
    cout << ">> Você acertou." << endl;
  } else {
    cout << ">> ERROU!" << endl;
    chutesErrados.push_back(chute);
  }
  cout << endl;
}

// principal

int main() {
  imprimeCabecalho();

  while (naoAcertou() && naoEnforcou()) {
    tentativaErrada();

    imprimePalavra();
    chuta();
  }

  cout << "Fim de jogo!" << endl;
  cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;

  if (naoAcertou()) {
    cout << "Você perdeu! Pode tentar novamente mas não faço questão..."
         << endl;
  } else {
    cout << "Parabéns, você acertou a palavra secreta!" << endl;
  }
}
