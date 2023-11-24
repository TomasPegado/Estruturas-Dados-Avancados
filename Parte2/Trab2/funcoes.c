// funcoes.c

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

t_no* cria_no() {
    t_no* novo = (t_no*)malloc(sizeof(t_no));
    if (novo) {
        novo->ndesc = 0;
        for (int i = 0; i < MAX + 1; i++) {
            novo->ramo[i] = NULL;
        }
    }
    return novo;
}

void insere(t_no** raiz, int chave) {
    t_no* r = *raiz;
    if (r == NULL) {
        r = cria_no();
        r->chave[0] = chave;
        r->ndesc = 1;
        *raiz = r;
        return;
    }
    if (r->ndesc == MAX) {
        t_no* s = cria_no();
        *raiz = s;
        s->ramo[0] = r;
        divide_no(s, 0, r);
        insere_no_nao_cheio(s, chave);
    }
    else {
        insere_no_nao_cheio(r, chave);
    }
}

void divide_no(t_no* x, int i, t_no* y) {
    t_no* novo = cria_no();
    novo->ndesc = MIN;

    for (int j = 0; j < MIN; j++) {
        novo->chave[j] = y->chave[j + MIN];
    }

    if (y->ramo[0]) {
        for (int j = 0; j < MIN + 1; j++) {
            novo->ramo[j] = y->ramo[j + MIN];
            y->ramo[j + MIN] = NULL;
        }
    }

    y->ndesc = MIN;
    for (int j = x->ndesc; j >= i; j--) {
        x->ramo[j + 1] = x->ramo[j];
    }
    x->ramo[i + 1] = novo;

    for (int j = x->ndesc - 1; j >= i; j--) {
        x->chave[j + 1] = x->chave[j];
    }

    x->chave[i] = y->chave[MIN - 1];
    y->ndesc--;

    x->ndesc++;
}


void insere_no_nao_cheio(t_no* x, int chave) {
    int i = x->ndesc - 1;

    if (x->ramo[0] == NULL) {
        while (i >= 0 && chave < x->chave[i]) {
            x->chave[i + 1] = x->chave[i];
            i--;
        }

        x->chave[i + 1] = chave;
        x->ndesc++;
    }
    else {
        while (i >= 0 && chave < x->chave[i]) {
            i--;
        }
        i++;

        if (x->ramo[i]->ndesc == MAX) {
            divide_no(x, i, x->ramo[i]);
            if (chave > x->chave[i]) {
                i++;
            }
        }
        insere_no_nao_cheio(x->ramo[i], chave);
    }
}

void imprime_simetrico(t_no* n) {
    if (n != NULL) {
        for (int i = 0; i < n->ndesc; i++) {
            if (n->ramo[i] != NULL) {
                imprime_simetrico(n->ramo[i]);
            }
            printf("%d ", n->chave[i]);
        }
        imprime_simetrico(n->ramo[n->ndesc]); // Chama para o último ponteiro de nó filhos
    }
}


void imprime_intervalo(t_no* n, int lim_inf, int lim_sup) {
    if (n == NULL) return;

    int i;
    for (i = 0; i < n->ndesc && n->chave[i] < lim_inf; i++) {
        // Não faz nada aqui, apenas avança o índice até encontrar uma chave que seja maior ou igual a lim_inf
    }

    for (; i < n->ndesc && n->chave[i] <= lim_sup; i++) {
        // Se existir um ramo antes da chave e estivermos no início do intervalo ou após, imprime o intervalo do ramo
        if (i == 0 || n->chave[i - 1] < lim_inf) {
            if (n->ramo[i]) imprime_intervalo(n->ramo[i], lim_inf, lim_sup);
        }
        // Imprime a chave se ela estiver dentro do intervalo [lim_inf, lim_sup]
        printf("%d ", n->chave[i]);
    }
    // Após o loop, se o último ramo deve ser explorado, faça isso recursivamente
    if (i < MAX + 1 && n->ramo[i]) {
        imprime_intervalo(n->ramo[i], lim_inf, lim_sup);
    }
}



