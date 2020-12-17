#ifndef _PACMAN_H_
#define _PACMAN_H_

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

int acabou();
void move(char direcao);
int direcaoValida(char direcao);
void fantasmas();
int praOndeFantasmaVai(int xAtual, int yAtual, int* xDestino, int* yDestino);
void explodePilula();
void explodePilula2(int x, int y, int somaX, int somaY, int qtd);

#endif