// C_Cpp.clang_format_fallbackStyle

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mapa.h"
#include "pacman.h"

MAPA m;
POSICAO player;

int praOndeFantasmaVai(int xAtual, int yAtual, int* xDestino, int* yDestino) {
  int opcoes[4][2] = {
      {xAtual, yAtual + 1},
      {xAtual + 1, yAtual},
      {xAtual, yAtual - 1},
      {xAtual - 1, yAtual},
  };

  srand(time(0));
  for (int i = 0; i < 10; i++) {
    int posicao = rand() % 4;

    if (podeAndar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
      *xDestino = opcoes[posicao][0];
      *yDestino = opcoes[posicao][1];

      return 1;
    }
  }
  return 0;
}

void fantasmas() {
  MAPA copia;
  copiaMapa(&copia, &m);

  for (int i = 0; i < m.linhas; i++) {
    for (int j = 0; j < m.colunas; j++) {
      if (copia.matriz[i][j] == FANTASMA) {
        int xDestino;
        int yDestino;
        int encontrou = praOndeFantasmaVai(i, j, &xDestino, &yDestino);

        if (encontrou) {
          andaNoMapa(&m, i, j, xDestino, yDestino);
        }
      }
    }
  }
  liberaMapa(&copia);
}

int acabou() {
  POSICAO pos;
  int playerVivo = encontraPlayer(&m, &pos, PLAYER);
  return !playerVivo;
}

int direcaoValida(char direcao) {
  return direcao == 'a' || direcao == 's' || direcao == 'd' || direcao == 'w';
}

void move(char direcao) {
  if (!direcaoValida(direcao)) {
    return;
  }

  int proximox = player.x;
  int proximoy = player.y;

  switch (direcao) {
    case ESQUERDA:
      proximoy--;
      break;

    case CIMA:
      proximox--;
      break;

    case BAIXO:
      proximox++;
      break;

    case DIREITA:
      proximoy++;
      break;
  }

  if (!podeAndar(&m, PLAYER, proximox, proximoy)) return;

  andaNoMapa(&m, player.x, player.y, proximox, proximoy);

  player.x = proximox;
  player.y = proximoy;
}

int main() {
  leMapa(&m);
  encontraPlayer(&m, &player, PLAYER);

  do {
    imprimeMapa(&m);
    char comando;
    scanf(" %c", &comando);
    move(comando);
    fantasmas();

  } while (!acabou());

  liberaMapa(&m);
}