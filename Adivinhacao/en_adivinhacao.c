#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "English");

    // Cabeçalho
    printf("\n\n");
    printf("********************************\n");
    printf("* Welcome to the Guessing Game *\n");
    printf("********************************\n");

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
    printf("\nDifficulty Level:\n\n");
    printf("(1) Easy\n");
    printf("(2) Normal\n");
    printf("(3) Hard\n");
    printf("Pick a difficulty level: ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        vidas = 20;
        printf("Easy mode, you have %d tries.\n", vidas);
        break;

    case 2:
        vidas = 12;
        printf("Normal mode, you have %d tries.\n", vidas);
        break;

    case 3:
        vidas = 6;
        printf("Hard mode, you have %d tries.\n", vidas);
        break;

    default:
        vidas = 0;
    }

    for (int i = 1; i <= vidas; i++)
    {

        printf("____________\n");
        printf("Round %d.\n", tentativa);
        printf("Guess the Secret Number! Pick a number from 0 to 100: ");
        scanf("%d", &chute);

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);
        int menor = (chute < numerosecreto);

        //Autenticação
        if (chute < 0)
        {
            printf("You can't pick a numbers below 0.\n");
            vidas++;
            continue;
        }

        if (acertou)
        {
            break;
        }
        else
        {
            printf("Wrong guess!\n");

            if (maior)
            {
                printf("Your number was HIGHER than the Secret Number.\n");
                tentativa++;
            }
            else if (menor)
            {
                printf("Your number was LOWER than the Secret Number.\n");
                tentativa++;
            }
        }
        double pontosPerdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
    }

    if (acertou)
    {
        printf("********************\n");
        printf("* CONGRATULATIONS! *\n");
        printf("********************\n\n");

        printf("You guessed in %d tries!\n", tentativa);

        printf("Now go live your life enough games ffs.\n\n");

        printf("=== GAME OVER ===\n");
        printf("Score: %.2f.\n", pontos);
        printf("=================\n\n");
    }
    else
    {
        printf("\nYou Lost!\n");
        printf("=== GAME OVER ===\n");
    }
}