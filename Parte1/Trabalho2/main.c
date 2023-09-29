#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


int main(void){

    Node* abb = createNode();
    Node* A = createNode();
    Node* C = createNode();
    int countA = 0; int countC = 0;

    insert(abb, 120);
    insert(abb, 112);
    insert(abb, 137);
    insert(abb, 95);
    insert(abb, 115);
    insert(abb, 107);
    insert(abb, 118);
    insert(abb, 125);
    insert(abb, 150);

    find2Competitors(abb, 112, A, C, &countA, &countC);

    printf("Competidor A: %d, Competidor C: %d", A->height, C->height);
}