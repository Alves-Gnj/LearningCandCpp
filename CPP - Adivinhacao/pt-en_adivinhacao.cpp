// utf-8 no terminal: chcp 65001

#include <iostream>
using namespace std;
#include <locale.h>

#include <cstdlib>
#include <ctime>

int main() {
  setlocale(LC_ALL, "Portuguese_Brasil");

  cout << "**************************************" << endl;
  cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
  cout << "**************************************" << endl;

  cout << "Escolha o seu nível de dificuldade:" << endl;
  cout << "Fácil (F), Médio (M), Difícil (D)" << endl;

  char dificuldade;
  cin >> dificuldade;

  int numeroDeTentativas;

  if (dificuldade == 'F') {
    numeroDeTentativas = 15;
  } else if (dificuldade = 'M') {
    numeroDeTentativas = 10;
  } else {
    numeroDeTentativas = 5;
  }

  srand(time(NULL));
  const int NUMERO_SECRETO = rand() % 100;

  cout << "número secreto: "<< NUMERO_SECRETO << endl;

  bool naoAcertou = true;
  int tentativas = 0;

  double pontos = 1000.0;

  for (tentativas = 1; tentativas <= numeroDeTentativas; tentativas++) {
    int chute;
    cout << "Tentativa " << tentativas << endl;
    cout << "Qual é o seu chute?" << endl;
    cin >> chute;

    double pontosPerdidos = abs(chute - NUMERO_SECRETO) / 2.0;
    pontos -= pontosPerdidos;

    cout << "O valor do seu chute foi: " << chute << "." << endl;
    bool acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;

    if (acertou) {
      cout << "Parabéns!" << endl;
      naoAcertou = false;
      break;
    } else if (maior) {
      cout << "Seu chute foi maior." << endl;
    } else {
      cout << "Seu chute foi menor" << endl;
    }
  }

  cout << "Fim de jogo!" << endl;

  if (naoAcertou) {
    cout << "Você perdeu, tente novamente!" << endl;
  } else {
    cout << "Você acertou em " << tentativas << " tentativas." << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Seu placar final foi de " << pontos << " pontos." << endl;
  }
}