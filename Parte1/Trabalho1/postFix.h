/* nó da lista para armazenar valores reais */
typedef struct no No;
struct no
{
    float num;
    No * prox;
}; No;

typedef struct pilha Pilha;
struct pilha
{
    No* topo; /* aponta para o topo da pilha */
}; Pilha;


Pilha* pilha_cria(void);
void pilha_push (Pilha*p, float v);
void pilha_pop(Pilha*p);
void pilha_libera (Pilha* p);
float calculaPostFix(char vetor[]);
void pilha_atualiza(Pilha* p, float valor);