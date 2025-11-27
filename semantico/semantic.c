#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h" 

#define MAX_VARS 500
#define MAX_FUNCS 200

static VarEntry vars[MAX_VARS];
static int varCount = 0;
static FuncEntry funcs[MAX_FUNCS];
static int funcCount = 0;
static char currentFunctionType[32];

void semanticError(const char* msg) {
    fprintf(stderr, "Error Semantico: %s\n", msg);
    // exit(1); 
}

void initSemantic() {
    varCount = 0;
    funcCount = 0;
    strcpy(currentFunctionType, "");
}

VarEntry* findVar(char* name) {
    for(int i=0; i<varCount; i++) {
        if(strcmp(vars[i].name, name) == 0) return &vars[i];
    }
    return NULL;
}

void insertVar(char* name, char* type, int isArray, int dimensions) {
    if(findVar(name)) {
        // printf("DEBUG: Variable %s ya existe\n", name);
        return; 
    }
    vars[varCount].name = strdup(name);
    vars[varCount].type = strdup(type);
    vars[varCount].isArray = isArray;
    vars[varCount].dimensions = dimensions;
    varCount++;
}

FuncEntry* findFunc(char* name) {
    for(int i=0; i<funcCount; i++) {
        if(strcmp(funcs[i].name, name) == 0) return &funcs[i];
    }
    return NULL;
}

/* --- Prototipos --- */
const char* evalExpr(Node* n);
void analyzeStmt(Node* n);
void analyzeStmtList(Node* n);
void registerVarDecl(Node* n);

/* --- Evaluadores --- */

const char* evalLValue(Node* n) {
    if(!n) return "void";
    if(n->type == NODE_LVALUE) {
        if(!n->left || !n->left->sval) return "error";
        VarEntry* v = findVar(n->left->sval);
        if(!v) {
            printf("DEBUG: evalLValue - Variable '%s' no encontrada\n", n->left->sval);
            char buf[100];
            sprintf(buf, "Variable '%s' no declarada", n->left->sval);
            semanticError(buf);
            return "error";
        }
        return v->type;
    }
    return "error";
}

const char* evalExpr(Node* n) {
    if(!n) return "void";

    if(n->type == NODE_LITERAL) {
        if(n->sval) {
             if(strcmp(n->sval,"true")==0 || strcmp(n->sval,"false")==0) return "bool";
             
             // --- CORRECCION 1: Retornar el TIPO, no el VALOR ---
             // Detectamos si es float por el punto, sino es int
             if(strchr(n->sval, '.') != NULL) return "float";
             return "int"; 
        }
        return "int"; 
    }

    if(n->type == NODE_LVALUE) return evalLValue(n);

    if(n->type == NODE_EXPR) {
        const char* t1 = evalExpr(n->left);
        if(!n->right) { 
             if(n->sval && strcmp(n->sval,"!")==0) return "bool";
             return t1;
        }
        const char* t2 = evalExpr(n->right); 
        
        if(strcmp(n->sval,"+")==0 || strcmp(n->sval,"-")==0 || 
           strcmp(n->sval,"*")==0 || strcmp(n->sval,"/")==0 || strcmp(n->sval,"%")==0) {
            if(strcmp(t1,"error")==0 || strcmp(t2,"error")==0) return "error";
            if(strcmp(t1,"float")==0 || strcmp(t2,"float")==0) return "float";
            if(strcmp(t1,"int")==0 && strcmp(t2,"int")==0) return "int";
            semanticError("Tipos incompatibles en operacion aritmetica");
            return "error"; 
        }
        return "bool"; 
    }

    if(n->type == NODE_FUNC_CALL) {
        if(!n->left || !n->left->sval) return "error";
        FuncEntry* f = findFunc(n->left->sval);
        if(!f) return "int"; 
        return f->returnType;
    }
    return "error";
}

/* --- Análisis de Sentencias --- */

void analyzeStmt(Node* n) {
    if(!n) return;

    switch(n->type) {
        case NODE_VAR_DECL:
            registerVarDecl(n);
            break;
            
        case NODE_ASSIGN: {
            const char* t1 = evalLValue(n->left);
            const char* t2 = evalExpr(n->right);
            if(strcmp(t1,"error")==0 || strcmp(t2,"error")==0) return;
            if(strcmp(t1,t2) != 0) {
                if(strcmp(t1,"float")==0 && strcmp(t2,"int")==0) return;
                char buf[100];
                sprintf(buf, "Asignacion incompatible: se esperaba '%s', se recibio '%s'", t1, t2);
                semanticError(buf);
            }
            break;
        }
        case NODE_RETURN: {
            if(n->left) {
                const char* tr = evalExpr(n->left);
                if(strcmp(tr, currentFunctionType) != 0) {
                     if(strcmp(currentFunctionType,"float")==0 && strcmp(tr,"int")==0) return;
                     char buf[100];
                     sprintf(buf, "Retorno invalido: funcion '%s', retorno '%s'", currentFunctionType, tr);
                     semanticError(buf);
                }
            }
            break;
        }
        
        case NODE_IF: {
            const char* tCond = evalExpr(n->left);
            // --- CORRECCION 2: Permitir int o bool como condicion ---
            if(strcmp(tCond, "bool") != 0 && strcmp(tCond, "int") != 0) {
                printf("DEBUG: Condicion IF es de tipo '%s'\n", tCond);
                semanticError("Condicion de IF debe ser booleana o entera");
            }
            if(n->right) {
                analyzeStmt(n->right->left); 
                if(n->right->right) analyzeStmt(n->right->right);
            }
            break;
        }
            
        case NODE_WHILE: {
            const char* tCond = evalExpr(n->left);
            // --- CORRECCION 2: Permitir int o bool como condicion ---
            if(strcmp(tCond, "bool") != 0 && strcmp(tCond, "int") != 0) {
                printf("DEBUG: Condicion WHILE es de tipo '%s'\n", tCond);
                semanticError("Condicion de WHILE debe ser booleana o entera");
            }
            analyzeStmt(n->right);
            break;
        }

        case NODE_FOR:
            if(n->left) analyzeStmt(n->left); 
            if(n->right) {
                Node* cond = n->right->left;
                if(cond) {
                    const char* tCond = evalExpr(cond);
                    // --- CORRECCION 2: Permitir int o bool como condicion ---
                    if(strcmp(tCond, "bool") != 0 && strcmp(tCond, "int") != 0) {
                        printf("DEBUG: Condicion FOR es de tipo '%s'\n", tCond);
                        semanticError("Condicion de FOR debe ser booleana o entera");
                    }
                }
                analyzeStmt(n->right->right);
            }
            break;
             
        case NODE_BLOCK:
        case NODE_STMT_LIST:
            analyzeStmtList(n->left ? n->left : n);
            break;
        default:
            if(n->left) analyzeStmt(n->left);
            if(n->right) analyzeStmt(n->right);
            break;
    }
}

void analyzeStmtList(Node* n) {
    while(n && n->type == NODE_STMT_LIST) {
        analyzeStmt(n->left);
        n = n->right;
    }
    if(n) analyzeStmt(n);
}

void registerVarDecl(Node* n) {
    if(!n || !n->left || !n->left->sval) return;
    char* typeStr = n->left->sval; 
    Node* list = n->right; 
    
    while(list) {
        if (list->type == NODE_VAR) {
            Node* varItem = list->left; 
            if (varItem && varItem->type == NODE_VAR) {
                 Node* infoId = varItem->left;   
                 // Node* initAssign = varItem->right; // (No usado en esta version simple)
                 if (infoId && infoId->type == NODE_VAR) infoId = infoId->left;
                 if (infoId && infoId->sval) {
                      insertVar(infoId->sval, typeStr, 0, 0);
                 }
            }
        }
        list = list->right;
        if (list && list->type != NODE_VAR) list = NULL;
    }
}

void analyzeFuncBody(Node* n) {
    if(!n) return;
    if(n->sval && strcmp(n->sval, "main") == 0) {
        strcpy(currentFunctionType, n->left->sval); 
        analyzeStmtList(n->right->left); 
    } 
    else if(n->type == NODE_FUNC_DECL) {
         Node* header = n->left;
         if(header && header->left) {
            strcpy(currentFunctionType, header->left->sval);
            analyzeStmtList(n->right->left);
         }
    }
}

void analyzeDeclList(Node* n) {
    while(n && n->type == NODE_DECL_LIST) {
        Node* decl = n->left;
        if(decl->type == NODE_VAR_DECL) registerVarDecl(decl);
        n = n->right;
    }
}

void runSemantic(Node* root) {
    if(!root) return;
    printf("Ejecutando Analisis Semantico...\n");
    if(root->type == NODE_PROGRAM) {
        Node* list = root->left;
        while(list) {
            Node* decl = (list->type == NODE_DECL_LIST) ? list->left : list;
            if(decl && decl->type == NODE_VAR_DECL) registerVarDecl(decl);
            if(list->type == NODE_DECL_LIST) list = list->right; else list = NULL;
        }
        list = root->left;
        while(list) {
            Node* decl = (list->type == NODE_DECL_LIST) ? list->left : list;
            if(decl && decl->type == NODE_FUNC_DECL) analyzeFuncBody(decl);
            if(list->type == NODE_DECL_LIST) list = list->right; else list = NULL;
        }
    } else {
        analyzeStmt(root);
    }
    printf("Analisis Semantico Finalizado.\n");
}