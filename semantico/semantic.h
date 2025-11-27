#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"

/* Estructuras de la tabla de simbolos */

typedef struct VarEntry {
    char* name;
    char* type;
    int isArray;
    int dimensions;
} VarEntry;

typedef struct FuncEntry {
    char* name;
    char* returnType;
    int paramCount;
    char** paramTypes;
} FuncEntry;

/* Prototipos de funciones públicas para el análisis semántico */

void initSemantic();
void runSemantic(Node* root);
void semanticError(const char* msg);

#endif