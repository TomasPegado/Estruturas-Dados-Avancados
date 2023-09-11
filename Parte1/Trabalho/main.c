#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "postFix.h"
#include "intercalador.h"

int main(void){

    printf("-------------------------------------\n");
    printf("Exercicio 1\n");
    char vetor1[] = "3 2 7 * + 1 -";
    float resultado1 = calculaPostFix(vetor1);
    printf("3 2 7 * + 1 - = %.1f\n", resultado1);

    char vetor2[] = "2 3 4 1 + * -";
    float resultado2 = calculaPostFix(vetor2);
    printf("2 3 4 1 + * - = %.1f\n", resultado2);

    char vetor3[] = "5 1 2 + 4 * + 3 -";
    float resultado3 = calculaPostFix(vetor3);
    printf("5 1 2 + 4 * + 3 - = %.1f\n", resultado3);

    char vetor4[] = "7 5 6 2 / 8 * + 3 + *";
    float resultado4 = calculaPostFix(vetor4);
    printf("7 5 6 2 / 8 * + 3 + * = %.1f\n", resultado4);

    char vetor5[] = "2 1 / 4 2 * + 6 5 - 8 2 / + +";
    float resultado5 = calculaPostFix(vetor5);
    printf("2 1 / 4 2 * + 6 5 - 8 2 / + + = %.1f\n\n", resultado5);

    printf("--------------------------------------\n");
    printf("Exercicio 2\n");
    Node* L1 = gera_lista(10);
    Node* L2 = gera_lista(10);
    imprimeLista(L1);
    imprimeLista(L2);
    srand(time(NULL));
    int numeroAleatorio = (rand() % 100) + 1;
    int numeroAleatorio2 = (rand() % 100) + 1;
    printf("%d %d\n", numeroAleatorio, numeroAleatorio2);

    return 0;
}