#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "semantic.h"
#include "compiler.h"
#include "vm.h"

extern FILE* yyin;
extern int yyparse();
extern Node* root; // Definido en parser.y

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <archivo_entrada>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error al abrir archivo");
        return 1;
    }

    printf("--- COMPILANDO ---\n");
    
    // 1. Parsing
    if (yyparse() != 0) {
        fprintf(stderr, "Error de sintaxis. Abortando.\n");
        fclose(yyin);
        return 1;
    }
    fclose(yyin);

    if (!root) {
        printf("El programa está vacío o hubo error.\n");
        return 0;
    }

    // 2. Análisis Semántico
    initSemantic(); // Inicializar tablas
    runSemantic(root); // Validar tipos

    // 3. Generación de Código
    printf("Generando Bytecode...\n");
    int codeSize = 0;
    Instruction* bytecode = compile_program(root, &codeSize);

    printf("Compilacion exitosa. Instrucciones generadas: %d\n", codeSize);

    // 4. Ejecución (Máquina Virtual)
    run_vm(bytecode, codeSize);

    // Limpieza
    free(bytecode);
    // freeTree(root); // Implementar si tienes función de limpieza
    return 0;
}