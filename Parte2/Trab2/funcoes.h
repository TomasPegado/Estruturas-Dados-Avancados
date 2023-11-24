// funcoes.h

#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX 4
#define MIN 2

// Definicao de um no da arvore B
typedef struct no {
    int ndesc;                    // Numero de chaves no no
    int chave[MAX];               // As chaves
    struct no* ramo[MAX + 1];     // Ponteiros para os nos filhos
} t_no;

// Prototipos de funcoes
t_no* cria_no();
void insere(t_no** raiz, int chave);
void divide_no(t_no* x, int i, t_no* y);
void insere_no_nao_cheio(t_no* x, int chave);
void imprime_simetrico(t_no* n);
void imprime_intervalo(t_no* n, int lim_inf, int lim_sup);

#endif // FUNCOES_H
