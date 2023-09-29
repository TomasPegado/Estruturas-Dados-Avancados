#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void) {
    Node* abb = createNode();
    Node* A = createNode();
    Node* C = createNode();

    // Inserindo nos na arvore
    insert(&abb, 120);
    insert(&abb, 112);
    insert(&abb, 137);
    insert(&abb, 95);
    insert(&abb, 115);
    insert(&abb, 107);
    insert(&abb, 118);
    insert(&abb, 125);
    insert(&abb, 150);
    insert(&abb, 96);
    insert(&abb, 143);
    insert(&abb, 102);
    insert(&abb, 148);
    insert(&abb, 106);
    insert(&abb, 132);
    insert(&abb, 128);
    insert(&abb, 111);
    insert(&abb, 145);
    insert(&abb, 99);
    insert(&abb, 123);

    int heights[] = { 112, 148, 107, 125, 137 };

    // Simulando 5 competicoes
    for (int i = 0; i < 5; i++) {
        int countA = 0, countC = 0;

        find2Competitors(abb, heights[i], &A, &C, &countA, &countC);

        // Imprimindo os resultados de cada competicoo
        if (A != NULL && C != NULL) {
            printf("Para a altura %d -> Competidor A: %d e %d nos visitados, Competidor C: %d e %d nos visitados\n", heights[i], A->height, countA, C->height, countC);
        }
        else {
            printf("Erro para a altura %d: Um ou ambos os competidores n�o foram encontrados.\n", heights[i]);
        }
    }

    return 0;
}