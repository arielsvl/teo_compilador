#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"

#define MAX_CODE 2048
#define MAX_SYMBOLS 500

static Instruction code[MAX_CODE];
static int ip = 0; // Puntero de instrucción

// --- Tabla de Símbolos ---
typedef struct { char* name; int addr; } Symbol;
static Symbol symbols[MAX_SYMBOLS];
static int symbolCount = 0;

// Busca o crea una variable y devuelve su dirección de memoria
int get_symbol_addr(char* name) {
    for(int i=0; i<symbolCount; i++) {
        if(strcmp(symbols[i].name, name) == 0) return symbols[i].addr;
    }
    symbols[symbolCount].name = strdup(name);
    symbols[symbolCount].addr = symbolCount;
    return symbolCount++;
}

// --- Emitir Instrucción ---
void emit(int op, int arg) {
    if(ip >= MAX_CODE) { fprintf(stderr, "Error: Programa muy largo\n"); exit(1); }
    code[ip].op = op;
    code[ip].arg = arg;
    ip++;
}

// --- Generador Recursivo ---
void gen(Node* n) {
    if(!n) return;

    switch(n->type) {
        case NODE_PROGRAM:
        case NODE_DECL_LIST:
        case NODE_STMT_LIST:
        case NODE_BLOCK:
             if(n->left) gen(n->left);
             if(n->right) gen(n->right);
             break;

        // --- Corrección: Manejo Seguro de Literales ---
        case NODE_LITERAL:
            if (n->sval) {
                // Es un texto, bool o float simulado
                if(strcmp(n->sval, "true")==0) emit(OP_PUSH, 1);
                else if(strcmp(n->sval, "false")==0) emit(OP_PUSH, 0);
                else emit(OP_PUSH, atoi(n->sval));
            } else {
                // Es un entero puro (T_NUMBER)
                emit(OP_PUSH, n->ival);
            }
            break;

        // --- Corrección: Declaración con Inicialización (int a = 5;) ---
        case NODE_VAR: {
            // Estructura del parser: 
            // n->left es otro NODE_VAR (que tiene el ID), n->right es NODE_ASSIGN (si hay init)
            
            char* varName = NULL;
            // Buscar el nombre de la variable en la estructura anidada
            if (n->left && n->left->type == NODE_VAR) {
                if (n->left->left && n->left->left->sval) {
                    varName = n->left->left->sval;
                }
            } else if (n->left && n->left->sval) {
                // Caso simple (por si la estructura varía)
                varName = n->left->sval;
            }

            // Si hay inicialización (ej: = 5)
            if (n->right && n->right->type == NODE_ASSIGN) {
                // Generamos el código para el valor (el 5)
                if (n->right->right) gen(n->right->right);
                
                // Guardamos el valor en la variable
                if (varName) {
                    emit(OP_STORE, get_symbol_addr(varName));
                }
            }
            break;
        }

        // --- Corrección: Uso de Variable (Lectura) ---
        case NODE_LVALUE: 
            if(n->left && n->left->sval) {
                int addr = get_symbol_addr(n->left->sval);
                emit(OP_LOAD, addr);
            }
            break;

        // --- Corrección: Asignación (Escritura) ---
        case NODE_ASSIGN:
            // Si left es NULL, es parte de una declaración y ya lo manejó NODE_VAR. Ignorar.
            if (n->left == NULL) return;

            // 1. Generar valor (derecha)
            gen(n->right); 
            
            // 2. Guardar en variable (izquierda)
            if (n->left->type == NODE_LVALUE) {
                 if (n->left->left && n->left->left->sval) {
                     int addr = get_symbol_addr(n->left->left->sval);
                     emit(OP_STORE, addr);
                 }
            }
            break;

        case NODE_EXPR:
            gen(n->left);  
            if(n->right) gen(n->right); 
            
            if(n->sval) {
                if(strcmp(n->sval, "+") == 0) emit(OP_ADD, 0);
                else if(strcmp(n->sval, "-") == 0) emit(OP_SUB, 0);
                else if(strcmp(n->sval, "*") == 0) emit(OP_MUL, 0);
                else if(strcmp(n->sval, "/") == 0) emit(OP_DIV, 0);
                else if(strcmp(n->sval, "%") == 0) emit(OP_MOD, 0);
                else if(strcmp(n->sval, "<") == 0) emit(OP_LT, 0);
                else if(strcmp(n->sval, ">") == 0) emit(OP_GT, 0);
                else if(strcmp(n->sval, "==") == 0) emit(OP_EQ, 0);
                else if(strcmp(n->sval, "!=") == 0) emit(OP_NEQ, 0);
                else if(strcmp(n->sval, "&&") == 0) emit(OP_AND, 0);
                else if(strcmp(n->sval, "||") == 0) emit(OP_OR, 0);
                else if(strcmp(n->sval, "!") == 0) emit(OP_NOT, 0);
            }
            break;

        case NODE_IF: {
            gen(n->left); // Condición
            int jmpFalse = ip; 
            emit(OP_JMP_FALSE, 0); 

            gen(n->right->left); // Bloque True

            if(n->right->right) { // Else
                 int jmpEnd = ip;
                 emit(OP_JMP, 0); 
                 code[jmpFalse].arg = ip; 
                 gen(n->right->right); 
                 code[jmpEnd].arg = ip; 
            } else {
                 code[jmpFalse].arg = ip; 
            }
            break;
        }

        case NODE_WHILE: {
            int start = ip;
            gen(n->left); 
            int jmpExit = ip;
            emit(OP_JMP_FALSE, 0);

            gen(n->right); 
            emit(OP_JMP, start); 

            code[jmpExit].arg = ip;
            break;
        }

        case NODE_FOR: {
            // Estructura AST: left=Init, right=NODE_FOR(Cond, UpdateBody)
            gen(n->left); // Init
            
            int startLoop = ip;
            Node* subFor = n->right;
            if(subFor) {
                Node* cond = subFor->left;
                Node* updateBody = subFor->right; // STMT que contiene update y body
                
                // Generar Condición
                if(cond) gen(cond);
                
                int jmpExit = ip;
                if(cond) emit(OP_JMP_FALSE, 0);

                // En tu parser, el body y el update están anidados
                // Asumimos orden: Primero Body, luego Update, luego Jump
                if(updateBody && updateBody->right) gen(updateBody->right); // Body real
                if(updateBody && updateBody->left) gen(updateBody->left);   // Update (i++)
                
                emit(OP_JMP, startLoop);
                if(cond) code[jmpExit].arg = ip;
            }
            break;
        }

        case NODE_ACTION:
            if(n->left) gen(n->left); // Argumentos

            if (n->sval) {
                if(strcmp(n->sval, "move") == 0) emit(OP_MOVE, 0);
                else if(strcmp(n->sval, "stop") == 0) emit(OP_STOP, 0);
                else if(strcmp(n->sval, "turnLeft") == 0) emit(OP_TURN_LEFT, 0);
                else if(strcmp(n->sval, "turnRight") == 0) emit(OP_TURN_RIGHT, 0);
                else if(strcmp(n->sval, "delay") == 0) emit(OP_DELAY, 0);
                else if(strcmp(n->sval, "read") == 0) emit(OP_READ_SENSOR, 0);
                else if(strcmp(n->sval, "battery") == 0) emit(OP_BATTERY, 0);
            }
            break;
        
        case NODE_RETURN:
             if(n->left) gen(n->left);
             emit(OP_HALT, 0); 
             break;

        default:
            if(n->left) gen(n->left);
            if(n->right) gen(n->right);
            break;
    }
}

Instruction* compile_program(Node* ast, int* outSize) {
    ip = 0;
    symbolCount = 0;
    gen(ast);
    emit(OP_HALT, 0); 
    
    *outSize = ip;
    Instruction* result = malloc(sizeof(Instruction) * ip);
    if (result) {
        memcpy(result, code, sizeof(Instruction) * ip);
    }
    return result;
}