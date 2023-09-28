#include <stdlib.h>
#include <string.h>
#include "postFix.h"

Pilha* pilha_cria(void){

    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p==NULL) exit(1);

    p->topo = NULL;
    return p;
}

void pilha_push (Pilha*p, float v){ /* insere um elemento no topo da pilha*/

    No* n = (No*)malloc(sizeof(No));
    if (n==NULL){
        exit(1);
    }
    n->num = v;
    n->prox = p->topo;
    p->topo = n;
}

void pilha_pop(Pilha*p){ /* retiro o elemento do inicio lista*/

    No* t = p->topo;
    p->topo = p->topo->prox;
    free(t);
}

void pilha_libera (Pilha* p) /*Libera todos os elementos da lista e depois libera a pilha*/
{
    No *t, *q = p->topo;
    while (q!=NULL)
    {
        t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void pilha_atualiza(Pilha* p, float valor){
    pilha_pop(p);
    pilha_pop(p);
    pilha_push(p, valor);
}

float calculaPostFix(char vetor[]){

    int tam = strlen(vetor);
    float valor;
    Pilha* p = pilha_cria();
    for(int i=0; i<tam; i++){
        if (vetor[i] >= 48 && vetor[i] <= 57)
            pilha_push(p, vetor[i] - '0');
        else if(vetor[i] == '+'){
            valor = p->topo->num + p->topo->prox->num;
            pilha_atualiza(p, valor);
        }
        else if(vetor[i] == '-'){
            valor = p->topo->num - p->topo->prox->num;
            pilha_atualiza(p, valor);
        }
        else if(vetor[i] == '*'){
            valor = p->topo->num * p->topo->prox->num;
            pilha_atualiza(p, valor);
        }
        else if(vetor[i] == '/'){
            valor = p->topo->num / p->topo->prox->num;
            pilha_atualiza(p, valor);
        }
    }
    float resultado = p->topo->num;
    pilha_libera(p);
    return resultado;
}