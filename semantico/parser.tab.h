/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_INT = 258,                   /* T_INT  */
    T_FLOAT = 259,                 /* T_FLOAT  */
    T_BOOL = 260,                  /* T_BOOL  */
    T_CHAR = 261,                  /* T_CHAR  */
    T_FLOAT_LITERAL = 262,         /* T_FLOAT_LITERAL  */
    T_TRUE = 263,                  /* T_TRUE  */
    T_FALSE = 264,                 /* T_FALSE  */
    T_IF = 265,                    /* T_IF  */
    T_ELSE = 266,                  /* T_ELSE  */
    T_WHILE = 267,                 /* T_WHILE  */
    T_FOR = 268,                   /* T_FOR  */
    T_SWITCH = 269,                /* T_SWITCH  */
    T_CASE = 270,                  /* T_CASE  */
    T_DEFAULT = 271,               /* T_DEFAULT  */
    T_RETURN = 272,                /* T_RETURN  */
    T_BREAK = 273,                 /* T_BREAK  */
    T_CONTINUE = 274,              /* T_CONTINUE  */
    T_FUNC = 275,                  /* T_FUNC  */
    T_MAIN = 276,                  /* T_MAIN  */
    T_MOVE = 277,                  /* T_MOVE  */
    T_STOP = 278,                  /* T_STOP  */
    T_TLEFT = 279,                 /* T_TLEFT  */
    T_TRIGHT = 280,                /* T_TRIGHT  */
    T_BATTERY = 281,               /* T_BATTERY  */
    T_DELAY = 282,                 /* T_DELAY  */
    T_READ = 283,                  /* T_READ  */
    T_EQ = 284,                    /* T_EQ  */
    T_NEQ = 285,                   /* T_NEQ  */
    T_LE = 286,                    /* T_LE  */
    T_GE = 287,                    /* T_GE  */
    T_LT = 288,                    /* T_LT  */
    T_GT = 289,                    /* T_GT  */
    T_AND = 290,                   /* T_AND  */
    T_OR = 291,                    /* T_OR  */
    T_INC = 292,                   /* T_INC  */
    T_DEC = 293,                   /* T_DEC  */
    T_ASSIGN = 294,                /* T_ASSIGN  */
    T_PLUS = 295,                  /* T_PLUS  */
    T_MINUS = 296,                 /* T_MINUS  */
    T_MULT = 297,                  /* T_MULT  */
    T_DIV = 298,                   /* T_DIV  */
    T_MOD = 299,                   /* T_MOD  */
    T_NOT = 300,                   /* T_NOT  */
    T_SEMI = 301,                  /* T_SEMI  */
    T_COMMA = 302,                 /* T_COMMA  */
    T_LBRACE = 303,                /* T_LBRACE  */
    T_RBRACE = 304,                /* T_RBRACE  */
    T_LPAREN = 305,                /* T_LPAREN  */
    T_RPAREN = 306,                /* T_RPAREN  */
    T_LBRACKET = 307,              /* T_LBRACKET  */
    T_RBRACKET = 308,              /* T_RBRACKET  */
    T_ID = 309,                    /* T_ID  */
    T_NUMBER = 310,                /* T_NUMBER  */
    T_STRING = 311,                /* T_STRING  */
    T_ERROR = 312                  /* T_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "parser.y"

    int ival;
    char* sval;
    Node* node;

#line 127 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
