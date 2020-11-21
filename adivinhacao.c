#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Cabeçalho
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    // Sistema de número secreto random de 1 a 100
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativa = 1;
    int ganhou = 0;

    double pontos = 1000;

    while(ganhou == 0){

        printf("____________\n");
        printf("Tentativa %d.\n", tentativa);     
        printf("Qual eh o seu chute? ");
        scanf("%d", &chute);

        //Autenticação
        if(chute < 0) {
            printf("Nao pode chutar numeros negativos.\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);   
        int menor = (chute < numerosecreto);

        if (acertou) {
            printf("*************\n");
            printf("* Parabens! *\n");
            printf("*************\n\n");

            printf("Voce acertou em %d tentativas!\n", tentativa);

            printf("Viva sua vida.\n\n");
            ganhou = 1;

        } else {
            printf("Voce errou!\n");

            if (maior){
                printf("Seu numero foi MAIOR.\n");
                tentativa++;
            } else if (menor) {
                printf("Seu numero foi menor.\n");
                tentativa++;
            }
        }
        double pontosPerdidos = abs(chute-numerosecreto)/2.0;     
        pontos = pontos - pontosPerdidos;
    }
    
    printf("=== FIM DE JOGO ===\n");
    printf("Pontuacao: %.2f.\n", pontos);
    printf("===================\n\n");

}