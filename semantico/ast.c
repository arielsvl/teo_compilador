#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h" 

Node* newNode(int type) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->type = type;
    n->left = NULL;
    n->right = NULL;
    n->sval = NULL;
    n->ival = 0;
    return n;
}

Node* newNode2(int type, Node* left, Node* right) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->type = type;
    n->left = left;
    n->right = right;
    n->sval = NULL;
    n->ival = 0;
    return n;
}

Node* newNodeS(int type, char* sval) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->type = type;
    n->left = NULL;
    n->right = NULL;
    n->sval = strdup(sval); 
    n->ival = 0;
    return n;
}

Node* newNodeI(int type, int ival) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->type = type;
    n->left = NULL;
    n->right = NULL;
    n->ival = ival;
    n->sval = NULL;
    return n;
}