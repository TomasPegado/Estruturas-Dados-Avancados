#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um subconjunto para Union-Find
struct subset {
    int parent;
    int rank;
};

// Função para encontrar o conjunto de um elemento i
int find(struct subset subsets[], int i) {
    // Encontrar a raiz e fazer a raiz como pai de i (compressão de caminho)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Função para fazer a união de dois subconjuntos x e y
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Anexar árvore de menor rank sob a raiz da árvore de maior rank
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // Se ranks são iguais, faça um como raiz e incremente o rank por um
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Estrutura para representar uma aresta no grafo
struct Edge {
    int src, dest, weight;
};

// Função para comparar duas arestas de acordo com seus pesos
// Utilizada no qsort
int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}




