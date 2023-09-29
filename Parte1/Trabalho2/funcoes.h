typedef struct Node {
    int height;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(void);
void insert(Node** root, int height);
void findCompetitorA(Node* root, Node**a, int* count);
void findCompetitorC(Node* root, Node**c, int* count);
void find2Competitors(Node* root, int heightB, Node** a, Node** c, int* countA, int* countC);