#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int height;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(void){
    return NULL;
}

void insert(Node* root, int height){

    if (root == NULL){
        Node* root = (Node*)malloc(sizeof(Node));
        root->height = height;
        root ->left = root->right = NULL;
    }
    else if ( height < root->height)
        insert(root->left, height);
    else
        insert(root->right, height);
}

void findCompetitorA(Node* root, Node*a, int* count){

    if (root == NULL) return NULL;
    if (root->right == NULL){
        a = root;
        *count += 1;
    }
    else{
        *count += 1;
        findCompetitorA(root->right, a, count);
    }
}

void findCompetitorC(Node* root, Node*c, int* count){

    if (root == NULL) return NULL;
    if (root->left == NULL){
        c = root;
        *count += 1;
    }
    else{
        *count += 1;
        findCompetitorC(root->left, c, count);
    }
}

void find2Competitors(Node* root, int heightB, Node* a, Node* c, int* countA, int* countC){

    if (root == NULL) return NULL;

    else if (heightB < root->height)
        find2Competitors(root->left, heightB, a, c, countA, countC);
    
    else if (heightB > root->height)
        find2Competitors(root->right, heightB, a, c, countA, countC);

    else {
        findCompetitorA(root->left, a, countA);
        findCompetitorC(root->right, c, countC);
    }
}   
