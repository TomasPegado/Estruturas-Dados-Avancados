#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "intercalador.h"

/* função de criação da lista: retorna uma lista vazia */
Node* criaLista(void){
    return NULL;
}

Node* insereOrd(Node* lista, int valor){
    Node* p = lista;
    Node* ult = NULL;

    if (p==NULL){
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->num = valor;
        novo->prox = p;
        return novo;
    }
    while (p!= NULL && valor > p->num){

        ult = p;
        p = p->prox;
    }
    if (p != NULL && valor != p->num){
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->num = valor;
        novo->prox = p;
        ult->prox = novo;
    }
    else if (p == NULL){
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->num = valor;
        novo->prox = p;
        ult->prox = novo;
    }
    return lista;
}

Node* insereNoFinal(Node* lista, int valor){

    Node* p = lista;
    Node* ult = NULL;
    while (p != NULL){
        ult = p;
        p = p->prox;
    }
    if (ult == NULL){
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->num = valor;
        novo->prox = p;
        return novo;
    }
    else {
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->num = valor;
        novo->prox = p;
        ult->prox = novo;
        return lista;
    }
}

Node* gera_lista(int tamanho){

    Node* lista = criaLista();
    for(int i = 0; i<tamanho; i++){
        // Gere um número aleatório entre 1 e 100
        int numeroAleatorio = (rand() % 100) + 1;
        lista = insereOrd(lista, numeroAleatorio);
    }
    return lista;
}

int tamanhoLista(Node* lista){

    Node* p = lista;
    int contador = 0;
    while (p != NULL){
        contador++;
    }
    return contador;
}

Node* intercalaLista(Node* lista1, Node* lista2){

    Node* listaIntercalada = criaLista();
    Node* p1 = lista1;
    Node* p2 = lista2;
    while(p1 != NULL || p2 != NULL){
        if (p1->num < p2->num){
            listaIntercalada = insereNoFinal(listaIntercalada, p1->num);
            p1 = p1->prox;
        }
        else if(p1->num > p2->num){
            listaIntercalada = insereNoFinal(listaIntercalada, p2->num);
            p2 = p2->prox;
        }
        else{
            listaIntercalada = insereNoFinal(listaIntercalada, p1->num);
            p1 = p1->prox;
            p2 = p2->prox;
        }
    }
    return listaIntercalada;
}

void imprimeLista(Node* lista){

    Node* p = lista;
    printf("{");
    while(p != NULL){
        printf("%d, ", p->num);
        p = p->prox;
    }
    printf("}\n");
}

void liberaLista(Node* lista){
    Node* p = lista;
    Node* aux;
    while (p!= NULL){
        aux = p;
        p=p->prox;
        free(aux);
    }
}
