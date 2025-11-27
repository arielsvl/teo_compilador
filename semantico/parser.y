%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantic.h"

extern int yylex();
extern FILE *yyin;    
void yyerror(const char *s);
extern int yylineno;

Node* root = NULL;
%}

%token T_INT T_FLOAT T_BOOL T_CHAR
%token T_FLOAT_LITERAL
%token T_TRUE T_FALSE
%token T_IF T_ELSE T_WHILE T_FOR
%token T_SWITCH T_CASE T_DEFAULT
%token T_RETURN T_BREAK T_CONTINUE
%token T_FUNC T_MAIN
%token T_MOVE T_STOP T_TLEFT T_TRIGHT
%token T_BATTERY T_DELAY T_READ  /* <--- AGREGADO T_READ */
%token T_EQ T_NEQ T_LE T_GE
%token T_LT T_GT
%token T_AND T_OR
%token T_INC T_DEC
%token T_ASSIGN
%token T_PLUS T_MINUS T_MULT T_DIV T_MOD
%token T_NOT
%token T_SEMI T_COMMA
%token T_LBRACE T_RBRACE
%token T_LPAREN T_RPAREN
%token T_LBRACKET T_RBRACKET
%token T_ID
%token T_NUMBER
%token T_STRING
%token T_ERROR

%union {
    int ival;
    char* sval;
    Node* node;
}; 

%type <node> PROGRAMA DECLARACION_LIST DECLARACION DECLARACION_MAIN
%type <node> DECLARACION_DE_FUNCION DECLARACION_DE_VARIABLE
%type <node> VARIABLE_LIST VARIABLE VARIABLE_INDEXES_OPT
%type <node> VARIABLE_INDEX ASSIGN_OPT
%type <node> PARAMETROS_OPT PARAMETROS PARAM PARAMS_TAIL
%type <node> BLOQUE BLOQUE_BODY
%type <node> DECL_OR_STMT_LIST DECL_OR_STMT
%type <node> SENTENCIA
%type <node> IF ELSE_OPT WHILE FOR
%type <node> SWITCH CASE_LIST CASE DEFAULT_OPT STATEMENTS
%type <node> RETURN
/* AGREGADO READ AQUI ABAJO */
%type <node> ACCION_CARRITO MOVE STOP TURNLEFT TURNRIGHT BATTERY DELAY READ 
%type <node> ASIGNACION LVALUE LVALUE_TAIL
%type <node> ARGUMENTOS_OPT ARGUMENTOS ARG_TAIL
%type <node> EXPRESION LOGICA_OR LOGICA_AND
%type <node> IGUALDAD COMPARACION
%type <node> SUMA PRODUCTO
%type <node> UNARIO UNARIO_OP PRIMARIO PRIMARIO_TAIL
%type <node> LITERAL TIPO
%type <node> VARIABLE_LIST_TAIL ASIGNACION_OPT EXPRESION_OPT SWITCH_CASES

%type <sval> T_ID
%type <ival> T_NUMBER
%type <sval> T_STRING
%type <sval> T_FLOAT_LITERAL
%type <sval> T_CHAR

%start PROGRAMA 

%left T_OR
%left T_AND
%left T_EQ T_NEQ
%left T_LT T_GT T_LE T_GE
%left T_PLUS T_MINUS
%left T_MULT T_DIV T_MOD
%right T_NOT
%right T_ELSE

%%

PROGRAMA:
    DECLARACION_LIST {
        $$ = newNode2(NODE_PROGRAM, $1, NULL);
        root = $$;
    }
;

DECLARACION_LIST:
      DECLARACION DECLARACION_LIST {
        $$ = newNode2(NODE_DECL_LIST, $1, $2);
      }
    | /* vacío */ {
        $$ = NULL;
      }
;

DECLARACION:
      DECLARACION_DE_FUNCION   { $$ = $1; }
    | DECLARACION_DE_VARIABLE  { $$ = $1; }
    | DECLARACION_MAIN         { $$ = $1; }
;

DECLARACION_DE_VARIABLE:
    TIPO VARIABLE_LIST T_SEMI {
        $$ = newNode2(NODE_VAR_DECL, $1, $2);
    }
;

DECLARACION_MAIN:
      TIPO T_FUNC T_MAIN T_LPAREN PARAMETROS_OPT T_RPAREN BLOQUE {
            Node* func = newNode2(NODE_FUNC_DECL, $1, $7);
            func->sval = strdup("main");
            $$ = func;
      }
    ;

DECLARACION_DE_FUNCION:
      TIPO T_FUNC T_ID T_LPAREN PARAMETROS_OPT T_RPAREN BLOQUE {
            Node* type = $1;
            Node* id = newNodeS(NODE_LITERAL, $3);
            Node* header = newNode2(NODE_FUNC_DECL, type, id);
            $$ = newNode2(NODE_FUNC_DECL, header, $7);
      }
    ;

PARAMETROS_OPT: PARAMETROS { $$ = $1; } | { $$ = NULL; };
PARAMETROS: PARAM PARAMS_TAIL { $$ = newNode2(NODE_PARAM_LIST, $1, $2); };
PARAMS_TAIL: T_COMMA PARAM PARAMS_TAIL { $$ = newNode2(NODE_PARAM_LIST, $2, $3); } | { $$ = NULL; };
PARAM: TIPO T_ID { $$ = newNode2(NODE_PARAM, $1, newNodeS(NODE_LITERAL, $2)); };

VARIABLE_LIST: VARIABLE VARIABLE_LIST_TAIL { $$ = newNode2(NODE_VAR, $1, $2); };
VARIABLE_LIST_TAIL: T_COMMA VARIABLE VARIABLE_LIST_TAIL { $$ = newNode2(NODE_VAR, $2, $3); } | { $$ = NULL; };

VARIABLE: T_ID VARIABLE_INDEXES_OPT ASSIGN_OPT {
      Node* id = newNodeS(NODE_LITERAL, $1);
      Node* temp = newNode2(NODE_VAR, id, $2);
      $$ = newNode2(NODE_VAR, temp, $3);
};

VARIABLE_INDEXES_OPT: VARIABLE_INDEX VARIABLE_INDEXES_OPT { $$ = newNode2(NODE_INDEX, $1, $2); } | { $$ = NULL; };
VARIABLE_INDEX: T_LBRACKET EXPRESION T_RBRACKET { $$ = newNode2(NODE_INDEX, $2, NULL); };
ASSIGN_OPT: T_ASSIGN EXPRESION { $$ = newNode2(NODE_ASSIGN, NULL, $2); } | { $$ = NULL; };

TIPO:
      T_INT   { $$ = newNodeS(NODE_TYPE, "int"); }
    | T_FLOAT { $$ = newNodeS(NODE_TYPE, "float"); }
    | T_BOOL  { $$ = newNodeS(NODE_TYPE, "bool"); }
    | T_CHAR  { $$ = newNodeS(NODE_TYPE, "char"); }
;

BLOQUE: T_LBRACE BLOQUE_BODY T_RBRACE { $$ = newNode2(NODE_BLOCK, $2, NULL); };
BLOQUE_BODY: DECL_OR_STMT_LIST { $$ = $1; } | { $$ = NULL; };
DECL_OR_STMT_LIST: DECL_OR_STMT DECL_OR_STMT_LIST { $$ = newNode2(NODE_STMT_LIST, $1, $2); } | { $$ = NULL; };
DECL_OR_STMT: DECLARACION { $$ = $1; } | SENTENCIA { $$ = $1; };

SENTENCIA:
      IF { $$ = $1; } | WHILE { $$ = $1; } | FOR { $$ = $1; } | SWITCH { $$ = $1; } | RETURN { $$ = $1; }
    | T_BREAK T_SEMI { $$ = newNodeS(NODE_STMT, "break"); }
    | T_CONTINUE T_SEMI { $$ = newNodeS(NODE_STMT, "continue"); }
    | ACCION_CARRITO T_SEMI { $$ = $1; }
    | ASIGNACION T_SEMI { $$ = $1; }
    | EXPRESION T_SEMI { $$ = $1; }
    | BLOQUE { $$ = $1; }
;

IF: T_IF T_LPAREN EXPRESION T_RPAREN SENTENCIA ELSE_OPT {
      $$ = newNode2(NODE_IF, $3, newNode2(NODE_IF, $5, $6));
};
ELSE_OPT: T_ELSE SENTENCIA { $$ = $2; } | { $$ = NULL; };

WHILE: T_WHILE T_LPAREN EXPRESION T_RPAREN SENTENCIA { $$ = newNode2(NODE_WHILE, $3, $5); };

FOR: T_FOR T_LPAREN DECLARACION_DE_VARIABLE EXPRESION_OPT T_SEMI ASIGNACION_OPT T_RPAREN SENTENCIA {
      Node* inc = newNode2(NODE_STMT, $6, $8);
      $$ = newNode2(NODE_FOR, $3, newNode2(NODE_STMT, $4, inc));
}
| T_FOR T_LPAREN ASIGNACION_OPT T_SEMI EXPRESION_OPT T_SEMI ASIGNACION_OPT T_RPAREN SENTENCIA {
      Node* inc = newNode2(NODE_STMT, $7, $9);
      $$ = newNode2(NODE_FOR, $3, newNode2(NODE_STMT, $5, inc));
};

ASIGNACION_OPT: ASIGNACION { $$ = $1; } | { $$ = NULL; };
EXPRESION_OPT: EXPRESION { $$ = $1; } | { $$ = NULL; };

SWITCH: T_SWITCH T_LPAREN EXPRESION T_RPAREN T_LBRACE SWITCH_CASES T_RBRACE { $$ = newNode2(NODE_SWITCH, $3, $6); };
SWITCH_CASES: CASE_LIST DEFAULT_OPT { $$ = newNode2(NODE_SWITCH, $1, $2); } | DEFAULT_OPT { $$ = $1; } | { $$ = NULL; };
CASE_LIST: CASE CASE_LIST { $$ = newNode2(NODE_CASE, $1, $2); } | { $$ = NULL; };
CASE: T_CASE LITERAL ':' STATEMENTS { $$ = newNode2(NODE_CASE, $2, $4); };
DEFAULT_OPT: T_DEFAULT ':' STATEMENTS { $$ = newNode2(NODE_DEFAULT, $3, NULL); } | { $$ = NULL; };
STATEMENTS: SENTENCIA STATEMENTS { $$ = newNode2(NODE_STMT_LIST, $1, $2); } | { $$ = NULL; };

RETURN: T_RETURN EXPRESION T_SEMI { $$ = newNode2(NODE_RETURN, $2, NULL); } | T_RETURN T_SEMI { $$ = newNode(NODE_RETURN); };

/* AGREGADO READ AQUI */
ACCION_CARRITO: MOVE { $$=$1; } | STOP { $$=$1; } | TURNLEFT { $$=$1; } | TURNRIGHT { $$=$1; } | BATTERY { $$=$1; } | DELAY { $$=$1; } | READ { $$=$1; };

MOVE: T_MOVE T_LPAREN EXPRESION T_RPAREN { $$ = newNode2(NODE_ACTION, $3, NULL); $$->sval = strdup("move"); };
STOP: T_STOP T_LPAREN T_RPAREN { $$ = newNode(NODE_ACTION); $$->sval = strdup("stop"); };
TURNLEFT: T_TLEFT T_LPAREN EXPRESION T_RPAREN { $$ = newNode2(NODE_ACTION, $3, NULL); $$->sval = strdup("turnLeft"); };
TURNRIGHT: T_TRIGHT T_LPAREN EXPRESION T_RPAREN { $$ = newNode2(NODE_ACTION, $3, NULL); $$->sval = strdup("turnRight"); };
BATTERY: T_BATTERY T_LPAREN T_RPAREN { $$ = newNode(NODE_ACTION); $$->sval = strdup("battery"); };
DELAY: T_DELAY T_LPAREN EXPRESION T_RPAREN { $$ = newNode2(NODE_ACTION, $3, NULL); $$->sval = strdup("delay"); };

/* REGLA READ AGREGADA (Asumiendo que recibe una expresion o id de sensor) */
READ: T_READ T_LPAREN EXPRESION T_RPAREN { $$ = newNode2(NODE_ACTION, $3, NULL); $$->sval = strdup("read"); };

ASIGNACION: LVALUE T_ASSIGN EXPRESION { $$ = newNode2(NODE_ASSIGN, $1, $3); };
LVALUE: T_ID LVALUE_TAIL { $$ = newNode2(NODE_LVALUE, newNodeS(NODE_LITERAL, $1), $2); };
LVALUE_TAIL: VARIABLE_INDEX LVALUE_TAIL { $$ = newNode2(NODE_INDEX, $1, $2); } | { $$ = NULL; };

ARGUMENTOS_OPT: ARGUMENTOS { $$=$1; } | { $$=NULL; };
ARGUMENTOS: EXPRESION ARG_TAIL { $$ = newNode2(NODE_ARG_LIST, $1, $2); };
ARG_TAIL: T_COMMA EXPRESION ARG_TAIL { $$ = newNode2(NODE_ARG_LIST, $2, $3); } | { $$ = NULL; };

EXPRESION: LOGICA_OR { $$=$1; };
LOGICA_OR: LOGICA_AND { $$=$1; } | LOGICA_OR T_OR LOGICA_AND { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("||"); };
LOGICA_AND: IGUALDAD { $$=$1; } | LOGICA_AND T_AND IGUALDAD { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("&&"); };
IGUALDAD: COMPARACION { $$=$1; } 
  | IGUALDAD T_EQ COMPARACION { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("=="); }
  | IGUALDAD T_NEQ COMPARACION { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("!="); };
COMPARACION: SUMA { $$=$1; }
  | COMPARACION T_LT SUMA { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("<"); }
  | COMPARACION T_GT SUMA { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup(">"); }
  | COMPARACION T_LE SUMA { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("<="); }
  | COMPARACION T_GE SUMA { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup(">="); };
SUMA: PRODUCTO { $$=$1; }
  | SUMA T_PLUS PRODUCTO { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("+"); }
  | SUMA T_MINUS PRODUCTO { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("-"); };
PRODUCTO: UNARIO { $$=$1; }
  | PRODUCTO T_MULT UNARIO { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("*"); }
  | PRODUCTO T_DIV UNARIO { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("/"); }
  | PRODUCTO T_MOD UNARIO { $$ = newNode2(NODE_EXPR, $1, $3); $$->sval = strdup("%"); };

UNARIO: UNARIO_OP UNARIO { $$ = newNode2(NODE_EXPR, $2, NULL); $$->sval = $1->sval; } | PRIMARIO { $$=$1; };
UNARIO_OP: T_NOT { $$ = newNodeS(NODE_EXPR, "!"); } | T_MINUS { $$ = newNodeS(NODE_EXPR, "-"); } 
         | T_INC { $$ = newNodeS(NODE_EXPR, "++"); } | T_DEC { $$ = newNodeS(NODE_EXPR, "--"); };


PRIMARIO: LITERAL { $$=$1; } 
  | BATTERY { $$=$1; }  /* <--- ESTO SOLUCIONA TU ERROR DE ASIGNACION */
  | READ { $$=$1; }     /* <--- ESTO PERMITE USAR read() EN EXPRESIONES */
  | T_ID PRIMARIO_TAIL { 
      Node* id = newNodeS(NODE_LITERAL, $1); 
      if ($2 == NULL) {
          // Antes: $$ = id; (Esto creaba un Literal "a" y confundía al semántico)
          // Ahora: Lo envolvemos como LVALUE para que se busque en la tabla de símbolos
          $$ = newNode2(NODE_LVALUE, id, NULL);
      } 
      else if ($2->type == NODE_FUNC_CALL) { $2->left = id; $$ = $2; }
      else { $$ = newNode2(NODE_LVALUE, id, $2); }
    }
  | T_LPAREN EXPRESION T_RPAREN { $$ = $2; };

PRIMARIO_TAIL: T_LPAREN ARGUMENTOS_OPT T_RPAREN { $$ = newNode2(NODE_FUNC_CALL, NULL, $2); }
             | VARIABLE_INDEX PRIMARIO_TAIL { $$ = newNode2(NODE_INDEX, $1, $2); }
             | { $$ = NULL; };

LITERAL: T_FLOAT_LITERAL { $$=newNodeS(NODE_LITERAL, "float"); $$->sval=strdup($1); }
       | T_NUMBER { $$=newNodeI(NODE_LITERAL, $1); }
       | T_STRING { $$=newNodeS(NODE_LITERAL, "string"); $$->sval=strdup($1); }
       | T_CHAR { $$=newNodeS(NODE_LITERAL, "char"); $$->sval=strdup($1); }
       | T_TRUE { $$=newNodeS(NODE_LITERAL, "bool"); $$->sval=strdup("true"); }
       | T_FALSE { $$=newNodeS(NODE_LITERAL, "bool"); $$->sval=strdup("false"); };

%%
void yyerror(const char *s) { fprintf(stderr, "Parser error: %s on line %d\n", s, yylineno); exit(1); }