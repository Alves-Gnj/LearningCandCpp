#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Cabeçalho
    printf("\n\n");
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    // Sistema de número secreto random de 1 a 100
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    //Win Condition
    int chute;
    int tentativa = 1;
    int acertou;

    // Dados do jogador
    int vidas = 0;
    double pontos = 100;

    //Dificuldade
    int nivel;
    printf("\nEscolha o nivel de dificuldade:\n\n");
    printf("(1) Facil\n");
    printf("(2) Medio\n");
    printf("(3) Dificil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        vidas = 20;
        printf("Nivel facil, voce tera %d vidas.\n", vidas);
        break;

    case 2:
        vidas = 12;
        printf("Nivel medio, voce tera %d vidas.\n", vidas);
        break;

    case 3:
        vidas = 6;
        printf("Nivel dificil, voce tera %d vidas.\n", vidas);
        break;

    default:
        vidas = 0;
    }

    for (int i = 1; i <= vidas; i++)
    {

        printf("____________\n");
        printf("Tentativa %d.\n", tentativa);
        printf("Qual eh o seu chute? ");
        scanf("%d", &chute);

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);
        int menor = (chute < numerosecreto);

        //Autenticação
        if (chute < 0)
        {
            printf("Nao pode chutar numeros negativos.\n");
            vidas++;
            continue;
        }

        if (acertou)
        {
            break;
        }
        else
        {
            printf("Voce errou!\n");

            if (maior)
            {
                printf("Seu numero foi MAIOR.\n");
                tentativa++;
            }
            else if (menor)
            {
                printf("Seu numero foi MENOR.\n");
                tentativa++;
            }
        }
        double pontosPerdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
    }

    if (acertou)
    {
        printf("*************\n");
        printf("* Parabens! *\n");
        printf("*************\n\n");

        printf("Voce acertou em %d tentativas!\n", tentativa);

        printf("Viva sua vida.\n\n");

        printf("=== FIM DE JOGO ===\n");
        printf("Pontuacao: %.2f.\n", pontos);
        printf("===================\n\n");
    }
    else
    {
        printf("\nVoce perdeu!\n");
        printf("=== FIM DE JOGO ===\n");
    }
}