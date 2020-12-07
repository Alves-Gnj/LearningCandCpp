#include <stdio.h>
#include <stdlib.h>

int main()
{
    // matriz de 5x10
    char mapa[5][10];

    FILE *f;
    f = fopen("mapa.txt", "r");
    if (f == 0)
    {
        printf("Erro na leitura do mapa.\n");
        exit(1);
    }

    for (int i = 0, i < 4, i++)
    {
        fscanf(f, "%s", mapa[i]);
    }
}