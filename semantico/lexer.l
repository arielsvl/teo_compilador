%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "parser.tab.h"

extern int yylineno;
%}

%%

"\xEF\xBB\xBF"    { /* Ignorar BOM UTF-8 */ }
"\xFF\xFE"        { /* Ignorar BOM UTF-16 LE */ }
"\xFE\xFF"        { /* Ignorar BOM UTF-16 BE */ }

"int"     { return T_INT; }
"float"   { return T_FLOAT; }
"bool"    { return T_BOOL; }
"char"    { return T_CHAR; }
"true"    { return T_TRUE; }
"false"   { return T_FALSE; }
"if"      { return T_IF; }
"else"    { return T_ELSE; }
"while"   { return T_WHILE; }
"for"     { return T_FOR; }
"switch"  { return T_SWITCH; }
"case"    { return T_CASE; }
"default" { return T_DEFAULT; }
"return"  { return T_RETURN; }
"break"   { return T_BREAK; }
"continue" { return T_CONTINUE; }
"func"    { return T_FUNC; }
"main"    { return T_MAIN; }
"move"    { return T_MOVE; }
"stop"    { return T_STOP; }
"turnLeft" { return T_TLEFT; }
"turnRight" { return T_TRIGHT; }
"battery" { return T_BATTERY; }
"delay"   { return T_DELAY; }

"=="      { return T_EQ; }
"!="      { return T_NEQ; }
"<="      { return T_LE; }
">="      { return T_GE; }
"<"       { return T_LT; }
">"       { return T_GT; }
"&&"      { return T_AND; }
"||"      { return T_OR; }
"++"      { return T_INC; }
"--"      { return T_DEC; }
"="       { return T_ASSIGN; }
"+"       { return T_PLUS; }
"-"       { return T_MINUS; }
"*"       { return T_MULT; }
"/"       { return T_DIV; }
"%"       { return T_MOD; }
"!"       { return T_NOT; }
";"       { return T_SEMI; }
","       { return T_COMMA; }
"{"       { return T_LBRACE; }
"}"       { return T_RBRACE; }
"("       { return T_LPAREN; }
")"       { return T_RPAREN; }
"["       { return T_LBRACKET; }
"]"       { return T_RBRACKET; }

([0-9]+)\.([0-9]+)?([eE][+-]?[0-9]+)?     { yylval.sval = strdup(yytext); return T_FLOAT_LITERAL; }
[0-9]+    { yylval.ival = atoi(yytext); return T_NUMBER; }


\"(\\.|[^"\\])*\" {
    yytext[strlen(yytext)-1] = 0; 
    yylval.sval = strdup(yytext+1); 
    return T_STRING;
}


\'(\\.|[^'\\])\' {
    yytext[strlen(yytext)-1] = 0; 
    yylval.sval = strdup(yytext+1); 
    return T_CHAR;
}

[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return T_ID; }

[ \t]+    { /* Ignorar espacios */ }
\n        { yylineno++; }

"//".* { /* Comentario linea */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* Comentario bloque */ }

.         { printf("Error lexico: %s en linea %d\n", yytext, yylineno); return T_ERROR; }

%%

int yywrap() {
    return 1;
}