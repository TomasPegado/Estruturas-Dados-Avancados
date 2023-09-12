/* nó da lista para armazenar valores inteiros */
typedef struct node Node;
struct node
{
    int num;
    Node* prox;
}; Node;

Node* criaLista(void);
Node* insereOrd(Node* lista, int valor);
Node* insereNoFinal(Node* lista, int valor);
Node* gera_lista(int tamanho);
Node* intercalaLista(Node* lista1, Node* lista2);
void imprimeLista(Node* lista);
void liberaLista(Node* lista);
int tamanhoLista(Node* lista);




