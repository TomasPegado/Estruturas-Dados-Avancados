#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "intercalador.h"

int main(void){
    srand(time(NULL));

    printf("--------------------------------------\n");
    printf("Exercicio 2\n");
    Node* l1 = criaLista();
    Node* l2 = criaLista();
    while (tamanhoLista(l1) < 10 && tamanhoLista(l2) <10){
        int numeroAleatori1 = (rand() % 100) + 1;
        l1 = insereNoFinal(l1, numeroAleatori1);
        int numeroAleatori2 = (rand() % 100) + 1;
        l2 = insereNoFinal(l2, numeroAleatori2);
    }
    Node* l3 = intercalaLista(l1, l2);
    
    imprimeLista(l1);
    imprimeLista(l2);
    imprimeLista(l3);
    
    liberaLista(l1);
    liberaLista(l2);
        


    return 0;
}


