#ifndef COMPILER_H
#define COMPILER_H

#include "ast.h"
#include "vm.h"

// Convierte el AST en un arreglo de instrucciones ejecutables
// Retorna el arreglo y guarda el tamaño en 'outSize'
Instruction* compile_program(Node* ast, int* outSize);

#endif