#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "intercalador.h"

int main(void){

    srand(time(NULL));
    printf("--------------------------------------\n");
    printf("Exercicio 2\n");
    Node* L1 = gera_lista(10);
    imprimeLista(L1);
    liberaLista(L1);

    return 0;
}


