#ifndef AST_H
#define AST_H

// Tipos de nodos del AST
enum NodeType {
    NODE_PROGRAM,
    NODE_DECL_LIST,
    NODE_DECL,
    NODE_FUNC_DECL,
    NODE_VAR_DECL,
    NODE_VAR,
    NODE_PARAM,
    NODE_PARAM_LIST,
    NODE_BLOCK,
    NODE_STMT_LIST,
    NODE_STMT,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_SWITCH,
    NODE_CASE,
    NODE_DEFAULT,
    NODE_RETURN,
    NODE_ASSIGN,
    NODE_LVALUE,
    NODE_FUNC_CALL,
    NODE_ARG_LIST,
    NODE_INDEX,
    NODE_EXPR,
    NODE_LITERAL,
    NODE_TYPE,
    NODE_ACTION,
    NODE_EMPTY
};

typedef struct Node {
    int type;
    struct Node* left;
    struct Node* right;
    char* sval;
    int ival;
} Node;

Node* newNode(int type);
Node* newNode2(int type, Node* left, Node* right);
Node* newNodeS(int type, char* sval);
Node* newNodeI(int type, int ival);

#endif