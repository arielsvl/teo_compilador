#include <Arduino.h>

// --- 1. CONFIGURACIÓN DE PINES ---
// Motores (Tu configuración validada)
const int PIN_MI_1 = 21;
const int PIN_MI_2 = 4;
const int PIN_MD_1 = 3;
const int PIN_MD_2 = 2;

// Sensores IR (NUEVO)
const int PIN_SENSOR_IZQ = 1;
const int PIN_SENSOR_DER = 0;

const int VELOCIDAD_PWM_I = 100;
const int VELOCIDAD_PWM_D = 80;


// --- CONFIGURACIÓN VM ---
#define STACK_SIZE 256
#define MAX_VARS 64

// --- DEFINICIONES DE OPCODES ---
enum OpCode {
  OP_HALT,
  OP_PUSH,
  OP_POP,
  OP_PRINT,
  OP_LOAD,
  OP_STORE,
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_MOD,
  OP_EQ,
  OP_NEQ,
  OP_LT,
  OP_GT,
  OP_LE,
  OP_GE,
  OP_AND,
  OP_OR,
  OP_NOT,
  OP_JMP,
  OP_JMP_FALSE,
  OP_MOVE,
  OP_STOP,
  OP_TURN_LEFT,
  OP_TURN_RIGHT,
  OP_READ_SENSOR,
  OP_BATTERY,
  OP_DELAY
};

struct Instruction {
  int op;
  int arg;
};

// --- ESTADO GLOBAL ---
int stack[STACK_SIZE];
int sp = -1;
int globals[MAX_VARS];

// --- FUNCIONES MOTORES (Tus funciones) ---
void motores_stop() {
  // Para detener, escribimos 0 en todos los pines
  analogWrite(PIN_MI_1, 0);
  analogWrite(PIN_MI_2, 0);
  analogWrite(PIN_MD_1, 0);
  analogWrite(PIN_MD_2, 0);
}

void motores_adelante() {
  // Motor Izquierdo: Avanza al 50%
  analogWrite(PIN_MI_1, VELOCIDAD_PWM_I);
  analogWrite(PIN_MI_2, 0);

  // Motor Derecho: Avanza al 50%
  analogWrite(PIN_MD_1, VELOCIDAD_PWM_D);
  analogWrite(PIN_MD_2, 0);
}

void motores_giro_izquierda() {
  // Giro sobre el propio eje (Tanque)
  // Izquierdo: ATRÁS al 50%
  analogWrite(PIN_MI_1, 0);
  analogWrite(PIN_MI_2, 0);

  // Derecho: ADELANTE al 50%
  analogWrite(PIN_MD_1, VELOCIDAD_PWM_D);
  analogWrite(PIN_MD_2, 0);
}

void motores_giro_derecha() {
  // Giro sobre el propio eje (Tanque)
  // Izquierdo: ADELANTE al 50%
  analogWrite(PIN_MI_1, VELOCIDAD_PWM_I);
  analogWrite(PIN_MI_2, 0);

  // Derecho: ATRÁS al 50%
  analogWrite(PIN_MD_1, 0);
  analogWrite(PIN_MD_2, 0);
}

// --- VM CORE ---
void push(int v) {
  if (sp < STACK_SIZE - 1) stack[++sp] = v;
}
int pop() {
  return (sp >= 0) ? stack[sp--] : 0;
}

void run_vm(Instruction* code, int codeSize) {
  int pc = 0;
  Serial.println("--- INICIANDO ROBOT SIGUE-LINEAS ---");

  while (pc < codeSize) {
    Instruction instr = code[pc];
    switch (instr.op) {
      case OP_HALT: motores_stop(); return;

      // --- DATOS Y VARIABLES ---
      case OP_PUSH: push(instr.arg); break;
      case OP_POP: pop(); break;
      case OP_LOAD: push(globals[instr.arg]); break;
      case OP_STORE: globals[instr.arg] = pop(); break;

      // --- ARITMÉTICA (Necesaria para la lógica) ---
      case OP_ADD: push(pop() + pop()); break;
      case OP_SUB:
        {
          int b = pop();
          int a = pop();
          push(a - b);
        }
        break;

      // --- LÓGICA COMPARATIVA (Crítico para el IF de los sensores) ---
      case OP_EQ: push(pop() == pop()); break;
      case OP_NEQ: push(pop() != pop()); break;
      case OP_AND:
        {
          int b = pop();
          int a = pop();
          push(a && b);
        }
        break;  // Para (izq==1 && der==1)

      // --- SALTOS ---
      case OP_JMP: pc = instr.arg; continue;
      case OP_JMP_FALSE:
        if (!pop()) {
          pc = instr.arg;
          continue;
        }
        break;

      // --- HARDWARE: SENSORES (Aquí está lo que pediste) ---
      case OP_READ_SENSOR:
        {
          int pinALeer = (instr.arg == 0) ? PIN_SENSOR_IZQ : PIN_SENSOR_DER;

          // 1. Leer el pin físico
          int val = digitalRead(pinALeer);

          // 2. Mostrar en pantalla
          Serial.printf("[SENSOR] %s: %d\n", (instr.arg == 0 ? "IZQ" : "DER"), val);

          // 3. Poner valor en la pila para que la lógica lo use
          push(val);
          break;
        }

      // --- HARDWARE: MOTORES ---
      case OP_MOVE:
        pop();  // Sacamos la velocidad (no la usamos en digital simple)
        Serial.println("ACCION: Adelante");
        motores_adelante();
        break;
      case OP_STOP:
        Serial.println("ACCION: Stop");
        motores_stop();
        break;
      case OP_TURN_LEFT:
        pop();
        Serial.println("ACCION: Giro Izquierda");
        motores_giro_izquierda();
        break;
      case OP_TURN_RIGHT:
        pop();
        Serial.println("ACCION: Giro Derecha");
        motores_giro_derecha();
        break;
      case OP_DELAY:
        {
          int ms = pop();
          // Comentamos el print para no saturar si el delay es pequeño
          Serial.printf("Wait %d ms\n", ms);
          delay(ms);
          break;
        }

      default:
        // Ignorar otros opcodes por ahora
        break;
    }
    pc++;
  }
}

// --- PROGRAMA COMPILADO (Tu lógica original de IF/ELSE) ---
// Inluye la lógica completa: Leer -> Comparar -> Mover -> Loop
Instruction program[] = {
  // Init Vars
  { OP_PUSH, 95 },   // 0
  { OP_STORE, 0 },   // 1 vel
  { OP_PUSH, 0 },    // 2
  { OP_STORE, 1 },   // 3 izq
  { OP_PUSH, 0 },    // 4
  { OP_STORE, 2 },   // 5 der

  // --- LOOP START (Index 6) ---
  { OP_READ_SENSOR, 0 }, // 6
  { OP_STORE, 1 },       // 7 izq
  { OP_READ_SENSOR, 1 }, // 8
  { OP_STORE, 2 },       // 9 der

  // IF (izq == 1 && der == 1) -> STOP
  { OP_LOAD, 1 },        // 10
  { OP_PUSH, 0 },        // 11
  { OP_EQ, 0 },          // 12 (izq == 1)
  { OP_LOAD, 2 },        // 13
  { OP_PUSH, 0 },        // 14
  { OP_EQ, 0 },          // 15 (der == 1)
  { OP_AND, 0 },         // 16 (izq==1 && der==1)
  { OP_JMP_FALSE, 26 },  // 17 si es falso -> siguiente if

  { OP_LOAD, 0 },        // 18  vel (aunque no la uses en MOVE)
  { OP_MOVE, 0 },        // 19  motores_adelante()
  { OP_PUSH, 25 },       // 20  50 ms
  { OP_DELAY, 0 },       // 21  pequeño delay
  { OP_STOP, 0 },        // 22  se detiene después de avanzar
  { OP_PUSH, 25 },       // 23  pausa parado 50 ms (opcional)
  { OP_DELAY, 0 },
  { OP_JMP, 6 },         // 22  vuelve a leer sensores

  // ELSE IF (izq == 0 && der == 1) -> DERECHA
  { OP_LOAD, 1 },        // 23
  { OP_PUSH, 0 },        // 24
  { OP_EQ, 0 },          // 25 (izq == 0)
  { OP_LOAD, 2 },        // 26
  { OP_PUSH, 1 },        // 27
  { OP_EQ, 0 },          // 28 (der == 1)
  { OP_AND, 0 },         // 29 (izq==0 && der==1)
  { OP_JMP_FALSE, 42 },  // 30 si es falso -> izquierda

  // Acción: Derecha
  { OP_PUSH, 0 },        // 31
  { OP_TURN_RIGHT, 0 },  // 32
  { OP_PUSH, 50 },       // 33
  { OP_DELAY, 0 },       // 34
  { OP_STOP, 0 },        // 35
  { OP_PUSH, 50 },       // 36
  { OP_DELAY, 0 },       // 37
  { OP_JMP, 6 },         // 38

  // ELSE IF (izq == 1 && der == 0) -> IZQUIERDA
  { OP_LOAD, 1 },        // 39
  { OP_PUSH, 1 },        // 40
  { OP_EQ, 0 },          // 41 (izq == 1)
  { OP_LOAD, 2 },        // 42
  { OP_PUSH, 0 },        // 43
  { OP_EQ, 0 },          // 44 (der == 0)
  { OP_AND, 0 },         // 45 (izq==1 && der==0)
  { OP_JMP_FALSE, 58 },  // 46 si es falso -> else

  // Acción: Izquierda
  { OP_PUSH, 0 },        // 47
  { OP_TURN_LEFT, 0 },   // 48
  { OP_PUSH, 50 },       // 49
  { OP_DELAY, 0 },       // 50
  { OP_STOP, 0 },        // 51
  { OP_PUSH, 50 },       // 52
  { OP_DELAY, 0 },       // 53
  { OP_JMP, 6 },         // 54

  // ELSE -> AVANCE
  { OP_STOP, 0 },        // 55  frena motores
  { OP_JMP, 6 }          // 56  vuelve a leer sensores
};


void setup() {
  Serial.begin(115200);

  // Configurar Motores
  pinMode(PIN_MI_1, OUTPUT);
  pinMode(PIN_MI_2, OUTPUT);
  pinMode(PIN_MD_1, OUTPUT);
  pinMode(PIN_MD_2, OUTPUT);

  // Configurar Sensores (IMPORTANTE)
  pinMode(PIN_SENSOR_IZQ, INPUT);
  pinMode(PIN_SENSOR_DER, INPUT);

  motores_stop();
  delay(2000);

  run_vm(program, sizeof(program) / sizeof(Instruction));
}

void loop() {}