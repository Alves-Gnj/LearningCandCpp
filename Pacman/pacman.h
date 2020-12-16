#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);
int direcaoValida(char direcao);
void fantasmas();
int praOndeFantasmaVai(int xAtual, int yAtual, int* xDestino, int* yDestino);