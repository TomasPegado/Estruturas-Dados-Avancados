#include "funcoes.h"
#include <stdio.h>

int main() {
    // Chaves que serao inseridas na arvore B - ajustadas para 21 chaves conforme solicitado
    int chaves[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210 };
    int n = sizeof(chaves) / sizeof(chaves[0]); // Isso ira contar corretamente o numero de chaves

    t_no* raiz = NULL;

    // Inserir chaves na Arvore e imprimir a Arvore apos cada insercao
    for (int i = 0; i < n; i++) {
        insere(&raiz, chaves[i]);
        printf("Arvore B apos insercao de %d em ordem simetrica:\n", chaves[i]);
        imprime_simetrico(raiz);
        printf("\n");
    }

    // Testes da funcao imprime_intervalo
    printf("Testando a funcao imprime_intervalo:\n");
    imprime_intervalo(raiz, 30, 120);
    printf("\n");
    imprime_intervalo(raiz, 85, 160);
    printf("\n");
    imprime_intervalo(raiz, 10, 210); // Ajustado para cobrir todas as chaves inseridas
    printf("\n");
    imprime_intervalo(raiz, 190, 220);
    printf("\n");
    imprime_intervalo(raiz, 5, 15);
    printf("\n");

    return 0;
}
