#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma fila
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Função para criar uma fila de determinada capacidade
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Função para verificar se a fila está cheia
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Função para verificar se a fila está vazia
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Função para adicionar um item à fila
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Função para remover um item da fila
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Função para obter o item da frente da fila
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->array[queue->front];
}
