#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "");
    int idioma = 10;

    //Linguagem
    printf("\n\nSelect your language:\n");
    printf("[1] English\n[2] Portugues\n");
    while (idioma > 2 || idioma < 0)
    {
        printf("Select here: ");
        scanf("%d", &idioma);
        switch (idioma)
        {
        case 1:
            idioma = 1;
            printf("English Selected. \n\n");
            break;

        case 2:
            idioma = 2;
            printf("Portugues Selecionado. \n\n");
            break;

        default:
            printf("Select a valid number.\n");
            break;
        }
    }

    // Cabeçalho

    switch (idioma)
    {
    case 1:
        printf("\n\n");
        printf("********************************\n");
        printf("* Welcome to the Guessing Game *\n");
        printf("********************************\n");
        break;

    case 2:
        printf("\n\n");
        printf("******************************************\n");
        printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
        printf("******************************************\n");
        break;
    }

    // Sistema de número secreto random de 1 a 100
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    //Win Condition
    int chute;
    int tentativa = 1;
    int acertou = 0;

    // Dados do jogador
    int vidas = 0;
    double pontos = 100;

    //Dificuldade
    int nivel;
    switch (idioma)
    {
    case 1:
        printf("\nDifficulty Level:\n\n");
        printf("(1) Easy\n");
        printf("(2) Normal\n");
        printf("(3) Hard\n");
        printf("Pick a difficulty level: ");
        break;
    case 2:
        printf("\nEscolha o nivel de dificuldade:\n\n");
        printf("(1) Facil\n");
        printf("(2) Medio\n");
        printf("(3) Dificil\n");
        printf("Escolha: ");
        break;
    }

    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        vidas = 20;
        switch (idioma)
        {
        case 1:
            printf("Easy mode, you have %d tries.\n", vidas);
            break;
        case 2:
            printf("Nivel facil, voce tera %d vidas.\n", vidas);
            break;
        }
        break;

    case 2:

        vidas = 12;
        switch (idioma)
        {
        case 1:
            printf("Normal mode, you have %d tries.\n", vidas);
            break;
        case 2:
            printf("Nivel medio, voce tera %d vidas.\n", vidas);
            break;
        }
        break;

    case 3:
        vidas = 6;
        switch (idioma)
        {
        case 1:
            printf("Hard mode, you have %d tries.\n", vidas);
            break;
        case 2:
            printf("Nivel dificil, voce tera %d vidas.\n", vidas);
            break;
        }
        break;

    default:
        vidas = 0;
    }

    for (int i = 1; i <= vidas; i++)
    {

        printf("____________\n");
        switch (idioma)
        {
        case 1:
            printf("Round %d.\n", tentativa);
            printf("Guess the Secret Number! Pick a number from 0 to 100: ");
            break;
        case 2:
            printf("Tentativa %d.\n", tentativa);
            printf("Qual eh o seu chute? ");
            break;
        }

        scanf("%d", &chute);

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);
        int menor = (chute < numerosecreto);

        //Autenticação
        if (chute < 0)
        {
            switch (idioma)
            {
            case 1:
                printf("You can't pick a numbers below 0.\n");
                break;
            case 2:
                printf("Nao pode chutar numeros negativos.\n");
                break;
            }
            vidas++;
            continue;
        }

        if (acertou)
        {
            break;
        }
        else
        {
            switch (idioma)
            {
            case 1:
                printf("Wrong guess!\n");
                break;
            case 2:
                printf("Voce errou!\n");
                break;
            }

            if (maior)
            {
                switch (idioma)
                {
                case 1:
                    printf("Your number was HIGHER than the Secret Number.\n");
                    break;
                case 2:
                    printf("Seu numero foi MAIOR.\n");
                    break;
                }
                tentativa++;
            }
            else if (menor)
            {
                switch (idioma)
                {
                case 1:
                    printf("Your number was LOWER than the Secret Number.\n");
                    break;
                case 2:
                    printf("Seu numero foi MENOR.\n");
                    break;
                }
                tentativa++;
            }
        }
        double pontosPerdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
    }

    if (acertou)
    {
        switch (idioma)
        {
        case 1:
            printf("********************\n");
            printf("* CONGRATULATIONS! *\n");
            printf("********************\n\n");

            printf("You guessed in %d tries!\n", tentativa);

            printf("Now go live your life enough games ffs.\n\n");

            printf("=== GAME OVER ===\n");
            printf("Score: %.2f.\n", pontos);
            printf("=================\n\n");
            break;
        case 2:
            printf("*************\n");
            printf("* Parabens! *\n");
            printf("*************\n\n");

            printf("Voce acertou em %d tentativas!\n", tentativa);

            printf("Viva sua vida.\n\n");

            printf("=== FIM DE JOGO ===\n");
            printf("Pontuacao: %.2f.\n", pontos);
            printf("===================\n\n");
            break;
        }
    }
    else
    {
        switch (idioma)
        {
        case 1:
            printf("\nYou Lost!\n");
            printf("=== GAME OVER ===\n");
            break;
        case 2:
            printf("\nVoce perdeu!\n");
            printf("=== FIM DE JOGO ===\n");
            break;
        }
    }
}