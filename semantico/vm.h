#ifndef VM_H
#define VM_H

typedef enum {
    // --- Control de Flujo y Sistema ---
    OP_HALT,         // Detener ejecución
    OP_PUSH,         // Poner un número en la pila (LITERAL) 
    OP_POP,          // Sacar de la pila
    OP_PRINT,        // (Opcional) Para depurar

    // --- Variables ---
    OP_LOAD,         // Cargar valor de variable a la pila (usado en ID) [cite: 45]
    OP_STORE,        // Guardar valor de la pila en variable (usado en ASIGNACION) [cite: 17, 34]

    // --- Aritmética y Lógica [cite: 37-43] ---
    OP_ADD,          // +
    OP_SUB,          // -
    OP_MUL,          // *
    OP_DIV,          // /
    OP_MOD,          // %
    OP_EQ,           // ==
    OP_NEQ,          // !=
    OP_LT,           // <
    OP_GT,           // >
    OP_LE,           // <=
    OP_GE,           // >=
    OP_AND,          // &&
    OP_OR,           // ||
    OP_NOT,          // !

    // --- Saltos (Para IF, WHILE, FOR)  ---
    OP_JMP,          // Salto incondicional (para else, loops)
    OP_JMP_FALSE,    // Salto si el tope de la pila es falso (para if, while cond)

    // --- Acciones del Carrito (Gramática ACCION_CARRITO) ---
    OP_MOVE,         //  move(exp)
    OP_STOP,         // [cite: 28] stop()
    OP_TURN_LEFT,    // [cite: 29] turnLeft(exp)
    OP_TURN_RIGHT,   // [cite: 30] turnRight(exp)
    OP_READ_SENSOR,  // [cite: 31] read(sensor)
    OP_BATTERY,      // [cite: 32] battery()
    OP_DELAY         // [cite: 33] delay(exp)

} OpCode;

typedef struct {
    int op;    // El OpCode (ej. OP_ADD, OP_MOVE)
    int arg;   // Argumento (ej. valor del literal, dirección de salto, índice de variable)
} Instruction;

// Función principal para ejecutar el bytecode
void run_vm(Instruction* code, int codeSize);

#endif