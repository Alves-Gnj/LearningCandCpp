#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Cabeçalho
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    int numerosecreto = 42;

    int chute;
    int tentativa = 1;
    int ganhou = 0;

    while(ganhou == 0){

        printf("***\n");
        printf("Tentativa %d.\n", tentativa);     
        printf("Qual eh o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d.\n", chute);

        //Autenticação
        if(chute < 0) {
            printf("Nao pode chutar numeros negativos.\n");
            tentativa--;
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);   
        int menor = (chute < numerosecreto);

        if (acertou) {
            printf("*******\n");
            printf("Parabens! Voce acertou em %d tentativas!\n", tentativa);
            printf("Viva sua vida.\n");
            ganhou = 1;

        } else {
            printf("*******\n");
            printf("Voce errou!\n");
            printf("Nao desanime, tente outra vez!\n");
            tentativa++;

            if (maior){
                printf("Seu numero foi MAIOR.\n");
            } else if (menor) {
                printf("Seu numero foi menor.\n");
            }
        }
    }
    printf("***************\n");
    printf("* FIM DE JOGO *\n");
    printf("***************\n");
}