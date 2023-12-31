#include <stdio.h>
#include <stdlib.h>
#include "filas.h"
#include "kruskal.h"

// Estrutura para um nó em uma lista de adjacências
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// Estrutura para a lista de adjacências
struct AdjList {
    struct AdjListNode* head;
};

// Estrutura do Grafo
struct Graph {
    int V;
    int E; // Adicionado para manter a contagem de arestas
    struct AdjList* array;
};

// Função para criar um novo nó de adjacência
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com V vértices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = 0; // Inicializa o contador de arestas como 0

    // Criar um array de listas de adjacências. Tamanho do array será V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Inicializar cada lista de adjacências como vazia, fazendo head como NULL
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // Adicionar aresta do vértice src ao vértice dest com um certo peso
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Como o grafo é não direcionado, adicione uma aresta de dest a src também
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;

    // Incrementa a contagem de arestas do grafo
    graph->E++;
}


// Função para o BFS
void BFS(struct Graph* graph, int startVertex) {
    // Vetor para manter o controle dos vértices visitados
    int visited[graph->V];
    // Vetor para armazenar o percurso
    int path[graph->V];
    int path_index = 0;

    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
        path[i] = -1; // Inicialize o percurso com -1
    }

    // Criar uma fila para o BFS
    struct Queue* queue = createQueue(graph->V);

    // Marque o nó de partida como visitado e enfileire
    visited[startVertex] = 1;
    enqueue(queue, startVertex);
    printf("Visitando %d...\n", startVertex);
    path[path_index++] = startVertex; // Adicione ao percurso

    while (!isEmpty(queue)) {
        // Desenfileire um vértice da fila
        int currentVertex = dequeue(queue);

        // Obter todos os vértices adjacentes ao vértice desenfileirado
        struct AdjListNode* temp = graph->array[currentVertex].head;
        printf("Explorado do vértice %d: ", currentVertex);

        while (temp) {
            int adjVertex = temp->dest;

            // Se um vértice adjacente não foi visitado, então marque-o como visitado e enfileire
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
                printf("%d ", adjVertex);
                path[path_index++] = adjVertex; // Adicione ao percurso
            }
            temp = temp->next;
        }
        printf("\n");
    }

    // Imprimir o percurso completo
    printf("Percurso da BFS: ");
    for (int i = 0; i < path_index; i++) {
        if (path[i] != -1) {
            printf("%d ", path[i]);
        }
    }
    printf("\n");

    // Liberar a fila
    free(queue);
}

// Função para coletar todas as arestas do grafo
struct Edge* CollectEdges(struct Graph* graph, int* numEdges) {
    int V = graph->V;
    int E = 0;
    // Supomos que o número máximo de arestas é V(V-1)/2 que é o caso de um grafo completo
    struct Edge* edges = malloc(sizeof(struct Edge) * V * (V - 1) / 2);
    
    for (int v = 0; v < V; ++v) {
        struct AdjListNode* temp = graph->array[v].head;
        while (temp != NULL) {
            if (v < temp->dest) { // Isso garante que cada aresta seja contabilizada apenas uma vez
                edges[E].src = v;
                edges[E].dest = temp->dest;
                edges[E].weight = temp->weight;
                E++;
            }
            temp = temp->next;
        }
    }

    *numEdges = E; // Atualizar o número de arestas
    return edges;
}

// Função para construir a Árvore Geradora Mínima usando o algoritmo de Kruskal
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];  // Isto irá armazenar o resultado MST
    int e = 0;  // Índice usado para result[]
    int i = 0;  // Índice usado para arestas ordenadas

    // Passo 1: Ordenar todas as arestas em ordem não decrescente de seus pesos
    struct Edge* edges = CollectEdges(graph, &e); 
    qsort(edges, e, sizeof(edges[0]), compareEdges);

    // Alocar memória para criar V subconjuntos
    struct subset *subsets = (struct subset*) malloc(V * sizeof(struct subset));

    // Criar V subconjuntos com elementos únicos
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Número de arestas a serem tomadas é igual a V-1
    i = 0; // Índice para as arestas ordenadas
    while (e < V - 1 && i < graph->E) {
        // Passo 2: Pegar a menor aresta e incrementar o índice para a próxima iteração
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // Se a inclusão dessa aresta não causa ciclo, inclua-a no resultado
        // e incremente o índice do resultado para a próxima aresta
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Caso contrário, descarte a próxima_edge
    }

    // Variável para armazenar o custo total da MST
    int totalCost = 0;

    // Imprimir os conteúdos da árvore geradora mínima
    printf("Arestas na Árvore Geradora Mínima:\n");
    for (i = 0; i < e; ++i) {
        printf("(%d -- %d == %d)\n", result[i].src, result[i].dest, result[i].weight);
        totalCost += result[i].weight;
    }
    printf("Custo total da Árvore Geradora Mínima: %d\n", totalCost);

    // Libere a memória alocada para os subconjuntos
    free(subsets);
    // Libere a memória alocada para o array de arestas, se necessário
    free(edges);
}

int main(void) {
    int V = 10; // O grafo tem 10 vértices
    struct Graph* graph = createGraph(V);

    // Adicionar as arestas conforme identificado no grafo da imagem
    addEdge(graph, 1, 10, 1); 
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 8, 3);
    addEdge(graph, 1, 5, 4);
    addEdge(graph, 1, 9, 3);
    addEdge(graph, 3, 2, 4);
    addEdge(graph, 3, 10, 4);
    addEdge(graph, 3, 8, 2);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 3, 6, 1);
    addEdge(graph, 3, 9, 4);
    addEdge(graph, 2, 10, 1);
    addEdge(graph, 10, 9, 4);
    addEdge(graph, 10, 8, 2);
    addEdge(graph, 8, 5, 4);
    addEdge(graph, 8, 9, 1);
    addEdge(graph, 5, 4, 2);
    addEdge(graph, 5, 7, 2);
    addEdge(graph, 4, 7, 2);
    addEdge(graph, 7, 6, 3);

    printf("Questao1:\n");
    // Chamar o BFS
    BFS(graph, 1); // Começando do vértice 0


    printf("\nQuestao2:\n");
    // Chamar o KruskalMST
    KruskalMST(graph);

    return 0;
}


