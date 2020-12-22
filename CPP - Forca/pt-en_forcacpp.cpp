#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string palavraSecreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutesErrados;

bool letraExiste(char chute) {
  for (char letra : palavraSecreta) {
    if (chute == letra) {
      return true;
    }
  }

  return false;
}

bool naoAcertou() {
  for (char letra : palavraSecreta) {
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
  for (char letra : palavraSecreta) {
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

vector<string> leArquivo() {
  ifstream arquivo;
  arquivo.open("palavras.txt");

  if (arquivo.is_open()) {
    int quantidadePalavras;
    arquivo >> quantidadePalavras;

    vector<string> palavrasArquivo;

    for (int i = 0; i < quantidadePalavras; i++) {
      string palavraLida;
      arquivo >> palavraLida;
      palavrasArquivo.push_back(palavraLida);
    }
    arquivo.close();
    return palavrasArquivo;
  } else {
    cout << "Banco de palavras não foi localizado." << endl;
    exit(0);
  }
}

void sorteiaPalavra() {
  vector<string> palavras = leArquivo();

  srand(time(NULL));
  int indiceSorteado = rand() % palavras.size();

  palavraSecreta = palavras[indiceSorteado];
}

void salvaArquivo(vector<string> novaLista) {
  ofstream arquivo;
  arquivo.open("palavras.txt");

  if (arquivo.is_open()) {
    arquivo << novaLista.size() << endl;

    for (string palavra : novaLista) {
      arquivo << palavra << endl;
    }

    arquivo.close();
  } else {
    cout << "Banco de palavras não foi localizado." << endl;
    exit(0);
  }
}

void adicionaPalavra() {
  cout << "Digite a nova palavra usando letras maiúsculas:" << endl;
  string novaPalavra;
  cin >> novaPalavra;

  vector<string> listaPalavras = leArquivo();
  listaPalavras.push_back(novaPalavra);

  salvaArquivo(listaPalavras);
}

// principal

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
