void liberaMapa();
void leMapa();
void alocaMemoria();
void imprimeMapa();


struct mapa
{
    char **matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;


int acabou();
void move(char direcao);