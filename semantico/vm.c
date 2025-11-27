#include <stdio.h>
#include <stdlib.h>
#include "vm.h"

#define STACK_SIZE 1024
#define MAX_VARS 500   // Espacio para variables globales

// Estado de la Máquina Virtual
int stack[STACK_SIZE];
int sp = -1;           // Stack Pointer (apunta al tope)
int globals[MAX_VARS]; // Memoria simple para variables

void push(int v) {
    if (sp < STACK_SIZE - 1) {
        stack[++sp] = v;
    } else {
        fprintf(stderr, "Error VM: Stack Overflow\n");
        exit(1);
    }
}

int pop() {
    if (sp >= 0) {
        return stack[sp--];
    } else {
        fprintf(stderr, "Error VM: Stack Underflow\n");
        exit(1);
    }
    return 0;
}

void run_vm(Instruction* code, int codeSize) {
    int pc = 0; // Program Counter
    printf("--- INICIANDO EJECUCION VM ---\n");

    while (pc < codeSize) {
        Instruction instr = code[pc];
        
        switch (instr.op) {
            case OP_HALT:
                printf("--- FIN DE EJECUCION ---\n");
                return;

            // --- Manejo de Datos ---
            case OP_PUSH:
                push(instr.arg);
                break;
            case OP_POP:
                pop();
                break;
            case OP_LOAD: // Cargar variable global
                push(globals[instr.arg]); 
                break;
            case OP_STORE: // Asignar a variable global [cite: 17, 34]
                // En asignación: valor = pila, guardamos en globals[arg]
                // Dependiendo de la implementación del compilador, a veces se hace peek o pop.
                // Asumimos pop para limpiar la pila tras asignar.
                globals[instr.arg] = pop(); 
                break;

            // --- Aritmética [cite: 41, 42] ---
            case OP_ADD: push(pop() + pop()); break; // Nota: Cuidado con el orden en resta/div
            case OP_SUB: { int b = pop(); int a = pop(); push(a - b); } break;
            case OP_MUL: push(pop() * pop()); break;
            case OP_DIV: { int b = pop(); int a = pop(); if(b==0) {printf("Err: Div/0\n"); exit(1);} push(a / b); } break;
            case OP_MOD: { int b = pop(); int a = pop(); push(a % b); } break;

            // --- Comparaciones y Lógica [cite: 37, 39, 40] ---
            case OP_EQ:  push(pop() == pop()); break;
            case OP_NEQ: push(pop() != pop()); break;
            case OP_LT:  { int b = pop(); int a = pop(); push(a < b); } break;
            case OP_GT:  { int b = pop(); int a = pop(); push(a > b); } break;
            case OP_LE:  { int b = pop(); int a = pop(); push(a <= b); } break;
            case OP_GE:  { int b = pop(); int a = pop(); push(a >= b); } break;
            case OP_AND: { int b = pop(); int a = pop(); push(a && b); } break;
            case OP_OR:  { int b = pop(); int a = pop(); push(a || b); } break;
            case OP_NOT: { int v = pop(); push(!v); } break; // [cite: 43]

            // --- Saltos (IF, WHILE, FOR)  ---
            case OP_JMP:
                pc = instr.arg;
                continue; // Evita el pc++ al final
            case OP_JMP_FALSE: {
                int cond = pop();
                if (!cond) {
                    pc = instr.arg;
                    continue;
                }
                break;
            }

            // --- ACCIONES DEL CARRITO (Simuladas) ---
            
            case OP_MOVE: { // 
                int dist = pop(); 
                printf("[HARDWARE] Robot avanza: %d unidades\n", dist);
                break;
            }
            case OP_STOP: // [cite: 28]
                printf("[HARDWARE] Robot detenido.\n");
                break;
            case OP_TURN_LEFT: { // [cite: 29]
                int ang = pop();
                printf("[HARDWARE] Girar Izquierda: %d grados\n", ang);
                break;
            }
            case OP_TURN_RIGHT: { // [cite: 30]
                int ang = pop();
                printf("[HARDWARE] Girar Derecha: %d grados\n", ang);
                break;
            }
            case OP_DELAY: { // [cite: 33]
                int ms = pop();
                printf("[HARDWARE] Esperando %d ms...\n", ms);
                break;
            }
            case OP_READ_SENSOR: { // [cite: 31]
                // En la gramática: read(SENSOR_CONST). El compilador debe pasar qué sensor es en 'arg'
                int sensor_id = instr.arg; 
                int lectura_simulada = rand() % 100; // Simulamos un valor
                printf("[SENSOR] Leyendo sensor ID %d -> Valor: %d\n", sensor_id, lectura_simulada);
                push(lectura_simulada); // Ponemos el resultado en la pila para que pueda ser asignado
                break;
            }
            case OP_BATTERY: { // [cite: 32]
                int nivel = 85; // Valor simulado
                printf("[BATERIA] Nivel actual: %d%%\n", nivel);
                push(nivel); // Retorna valor a la pila
                break;
            }
            
            case OP_PRINT:
                printf("OUT: %d\n", stack[sp]);
                break;

            default:
                printf("Error: OpCode desconocido %d\n", instr.op);
                exit(1);
        }
        pc++;
    }
}