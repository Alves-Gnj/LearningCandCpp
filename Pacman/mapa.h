struct mapa
{
    char **matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

struct posicao
{
    int x;
    int y;
};
typedef struct posicao POSICAO;

void liberaMapa(MAPA *m);
void alocaMemoria(MAPA *m);
void leMapa(MAPA *m);
void imprimeMapa(MAPA *m);
void encontraPlayer(MAPA *m, POSICAO *p, char c);

