#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

// Variaveis globais
char palavraSecreta[20];
char chutes[26];
int chutesDados = 0;

void abertura()
{
    printf("*****************\n");
    printf("* Jogo da Forca *\n");
    printf("*****************\n\n");
}

void chuta()
{
    char chute;
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra)
{

    int achou = 0;

    for (int j = 0; j < chutesDados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        int achou = jaChutou(palavraSecreta[i]);

        if (achou)
        {
            printf("%c ", palavraSecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }

    printf("\n");
}

void escolhePalavra()
{
    FILE *f;

    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Desculpe, banco de dados indisponivel.")
        exit(1);
    }

    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras);

    srand(time(0));
    int randomico = rand() % qtdPalavras;

    for (int i = 0; i < randomico; i++)
    {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

int acertou()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        if (!jaChutou(palavraSecreta[i]))
        {
            return 0;
        }
    }
    return 1;
}

int enforcou()
{
    int erros = 0;
    for (int i = 0; i < chutesDados; i++)
    {
        int existe = 0;
        for (int j = 0; j < strlen(palavraSecreta); j++)
        {
            if (chutes[i] == palavraSecreta[j])
            {
                existe = 1;
                break;
            }
        }
        if (!existe)
            erros++;
    }
    return erros >= 5;
}

int main()
{
    escolhePalavra();
    abertura();

    do
    {
        desenhaForca();
        chuta();

    } while (!acertou() && !enforcou());
}