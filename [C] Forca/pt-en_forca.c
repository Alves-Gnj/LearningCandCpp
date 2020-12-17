#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

// Variaveis globais
char palavraSecreta[TAMANHO_PALAVRA];
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

    int erros = chutesErrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '),
           (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '),
           (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '),
           (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

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

void adicionaPalavra()
{
    char quer;

    printf("Você gostaria de adicionar uma nova palavra? (S/N)\n");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra?\n");
        scanf("%s", novaPalavra);

        FILE *f;
        f = fopen("palavras.txt", "r+");
        if (f == 0)
        {
            printf("Desculpe, banco de dados indisponivel.\n\n");
            exit(1);
        }

        //guarda no qtd o valor de entradas+1 e depois o fseek atualiza o número no arquivo
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

void escolhePalavra()
{
    FILE *f;

    f = fopen("palavras.txt", "r");
    if (f == 0)
    {
        printf("Desculpe, banco de dados indisponivel.\n");
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

int chutesErrados()
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
    return erros;
}

int enforcou()
{
    return chutesErrados() >= 5;
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

    if (acertou())
    {
        printf("\n\n***************************\n");
        printf("* VOCE ACERTOU, PARABENS! *\n");
        printf("***************************\n\n");
        printf("A palavra era * %s * e voce conseguiu!\n\n", palavraSecreta);
    }
    else
    {
        printf("\n\n***************\n");
        printf("* VOCE PERDEU *\n");
        printf("***************\n\n");
        printf("A palavra era * %s *\n\n", palavraSecreta);
    }

    adicionaPalavra();
}