/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 86 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_INT = 3,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 4,                    /* T_FLOAT  */
  YYSYMBOL_T_BOOL = 5,                     /* T_BOOL  */
  YYSYMBOL_T_CHAR = 6,                     /* T_CHAR  */
  YYSYMBOL_T_FLOAT_LITERAL = 7,            /* T_FLOAT_LITERAL  */
  YYSYMBOL_T_TRUE = 8,                     /* T_TRUE  */
  YYSYMBOL_T_FALSE = 9,                    /* T_FALSE  */
  YYSYMBOL_T_IF = 10,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 11,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 12,                   /* T_WHILE  */
  YYSYMBOL_T_FOR = 13,                     /* T_FOR  */
  YYSYMBOL_T_SWITCH = 14,                  /* T_SWITCH  */
  YYSYMBOL_T_CASE = 15,                    /* T_CASE  */
  YYSYMBOL_T_DEFAULT = 16,                 /* T_DEFAULT  */
  YYSYMBOL_T_RETURN = 17,                  /* T_RETURN  */
  YYSYMBOL_T_BREAK = 18,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 19,                /* T_CONTINUE  */
  YYSYMBOL_T_FUNC = 20,                    /* T_FUNC  */
  YYSYMBOL_T_MAIN = 21,                    /* T_MAIN  */
  YYSYMBOL_T_MOVE = 22,                    /* T_MOVE  */
  YYSYMBOL_T_STOP = 23,                    /* T_STOP  */
  YYSYMBOL_T_TLEFT = 24,                   /* T_TLEFT  */
  YYSYMBOL_T_TRIGHT = 25,                  /* T_TRIGHT  */
  YYSYMBOL_T_BATTERY = 26,                 /* T_BATTERY  */
  YYSYMBOL_T_DELAY = 27,                   /* T_DELAY  */
  YYSYMBOL_T_READ = 28,                    /* T_READ  */
  YYSYMBOL_T_EQ = 29,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 30,                     /* T_NEQ  */
  YYSYMBOL_T_LE = 31,                      /* T_LE  */
  YYSYMBOL_T_GE = 32,                      /* T_GE  */
  YYSYMBOL_T_LT = 33,                      /* T_LT  */
  YYSYMBOL_T_GT = 34,                      /* T_GT  */
  YYSYMBOL_T_AND = 35,                     /* T_AND  */
  YYSYMBOL_T_OR = 36,                      /* T_OR  */
  YYSYMBOL_T_INC = 37,                     /* T_INC  */
  YYSYMBOL_T_DEC = 38,                     /* T_DEC  */
  YYSYMBOL_T_ASSIGN = 39,                  /* T_ASSIGN  */
  YYSYMBOL_T_PLUS = 40,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 41,                   /* T_MINUS  */
  YYSYMBOL_T_MULT = 42,                    /* T_MULT  */
  YYSYMBOL_T_DIV = 43,                     /* T_DIV  */
  YYSYMBOL_T_MOD = 44,                     /* T_MOD  */
  YYSYMBOL_T_NOT = 45,                     /* T_NOT  */
  YYSYMBOL_T_SEMI = 46,                    /* T_SEMI  */
  YYSYMBOL_T_COMMA = 47,                   /* T_COMMA  */
  YYSYMBOL_T_LBRACE = 48,                  /* T_LBRACE  */
  YYSYMBOL_T_RBRACE = 49,                  /* T_RBRACE  */
  YYSYMBOL_T_LPAREN = 50,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 51,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACKET = 52,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 53,                /* T_RBRACKET  */
  YYSYMBOL_T_ID = 54,                      /* T_ID  */
  YYSYMBOL_T_NUMBER = 55,                  /* T_NUMBER  */
  YYSYMBOL_T_STRING = 56,                  /* T_STRING  */
  YYSYMBOL_T_ERROR = 57,                   /* T_ERROR  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_PROGRAMA = 60,                  /* PROGRAMA  */
  YYSYMBOL_DECLARACION_LIST = 61,          /* DECLARACION_LIST  */
  YYSYMBOL_DECLARACION = 62,               /* DECLARACION  */
  YYSYMBOL_DECLARACION_DE_VARIABLE = 63,   /* DECLARACION_DE_VARIABLE  */
  YYSYMBOL_DECLARACION_MAIN = 64,          /* DECLARACION_MAIN  */
  YYSYMBOL_DECLARACION_DE_FUNCION = 65,    /* DECLARACION_DE_FUNCION  */
  YYSYMBOL_PARAMETROS_OPT = 66,            /* PARAMETROS_OPT  */
  YYSYMBOL_PARAMETROS = 67,                /* PARAMETROS  */
  YYSYMBOL_PARAMS_TAIL = 68,               /* PARAMS_TAIL  */
  YYSYMBOL_PARAM = 69,                     /* PARAM  */
  YYSYMBOL_VARIABLE_LIST = 70,             /* VARIABLE_LIST  */
  YYSYMBOL_VARIABLE_LIST_TAIL = 71,        /* VARIABLE_LIST_TAIL  */
  YYSYMBOL_VARIABLE = 72,                  /* VARIABLE  */
  YYSYMBOL_VARIABLE_INDEXES_OPT = 73,      /* VARIABLE_INDEXES_OPT  */
  YYSYMBOL_VARIABLE_INDEX = 74,            /* VARIABLE_INDEX  */
  YYSYMBOL_ASSIGN_OPT = 75,                /* ASSIGN_OPT  */
  YYSYMBOL_TIPO = 76,                      /* TIPO  */
  YYSYMBOL_BLOQUE = 77,                    /* BLOQUE  */
  YYSYMBOL_BLOQUE_BODY = 78,               /* BLOQUE_BODY  */
  YYSYMBOL_DECL_OR_STMT_LIST = 79,         /* DECL_OR_STMT_LIST  */
  YYSYMBOL_DECL_OR_STMT = 80,              /* DECL_OR_STMT  */
  YYSYMBOL_SENTENCIA = 81,                 /* SENTENCIA  */
  YYSYMBOL_IF = 82,                        /* IF  */
  YYSYMBOL_ELSE_OPT = 83,                  /* ELSE_OPT  */
  YYSYMBOL_WHILE = 84,                     /* WHILE  */
  YYSYMBOL_FOR = 85,                       /* FOR  */
  YYSYMBOL_ASIGNACION_OPT = 86,            /* ASIGNACION_OPT  */
  YYSYMBOL_EXPRESION_OPT = 87,             /* EXPRESION_OPT  */
  YYSYMBOL_SWITCH = 88,                    /* SWITCH  */
  YYSYMBOL_SWITCH_CASES = 89,              /* SWITCH_CASES  */
  YYSYMBOL_CASE_LIST = 90,                 /* CASE_LIST  */
  YYSYMBOL_CASE = 91,                      /* CASE  */
  YYSYMBOL_DEFAULT_OPT = 92,               /* DEFAULT_OPT  */
  YYSYMBOL_STATEMENTS = 93,                /* STATEMENTS  */
  YYSYMBOL_RETURN = 94,                    /* RETURN  */
  YYSYMBOL_ACCION_CARRITO = 95,            /* ACCION_CARRITO  */
  YYSYMBOL_MOVE = 96,                      /* MOVE  */
  YYSYMBOL_STOP = 97,                      /* STOP  */
  YYSYMBOL_TURNLEFT = 98,                  /* TURNLEFT  */
  YYSYMBOL_TURNRIGHT = 99,                 /* TURNRIGHT  */
  YYSYMBOL_BATTERY = 100,                  /* BATTERY  */
  YYSYMBOL_DELAY = 101,                    /* DELAY  */
  YYSYMBOL_READ = 102,                     /* READ  */
  YYSYMBOL_ASIGNACION = 103,               /* ASIGNACION  */
  YYSYMBOL_LVALUE = 104,                   /* LVALUE  */
  YYSYMBOL_LVALUE_TAIL = 105,              /* LVALUE_TAIL  */
  YYSYMBOL_ARGUMENTOS_OPT = 106,           /* ARGUMENTOS_OPT  */
  YYSYMBOL_ARGUMENTOS = 107,               /* ARGUMENTOS  */
  YYSYMBOL_ARG_TAIL = 108,                 /* ARG_TAIL  */
  YYSYMBOL_EXPRESION = 109,                /* EXPRESION  */
  YYSYMBOL_LOGICA_OR = 110,                /* LOGICA_OR  */
  YYSYMBOL_LOGICA_AND = 111,               /* LOGICA_AND  */
  YYSYMBOL_IGUALDAD = 112,                 /* IGUALDAD  */
  YYSYMBOL_COMPARACION = 113,              /* COMPARACION  */
  YYSYMBOL_SUMA = 114,                     /* SUMA  */
  YYSYMBOL_PRODUCTO = 115,                 /* PRODUCTO  */
  YYSYMBOL_UNARIO = 116,                   /* UNARIO  */
  YYSYMBOL_UNARIO_OP = 117,                /* UNARIO_OP  */
  YYSYMBOL_PRIMARIO = 118,                 /* PRIMARIO  */
  YYSYMBOL_PRIMARIO_TAIL = 119,            /* PRIMARIO_TAIL  */
  YYSYMBOL_LITERAL = 120                   /* LITERAL  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    96,    99,   105,   106,   107,   111,   117,
     125,   133,   133,   134,   135,   135,   136,   138,   139,   139,
     141,   147,   147,   148,   149,   149,   152,   153,   154,   155,
     158,   159,   159,   160,   160,   161,   161,   164,   164,   164,
     164,   164,   165,   166,   167,   168,   169,   170,   173,   176,
     176,   178,   180,   184,   189,   189,   190,   190,   192,   193,
     193,   193,   194,   194,   195,   196,   196,   197,   197,   199,
     199,   202,   202,   202,   202,   202,   202,   202,   204,   205,
     206,   207,   208,   209,   212,   214,   215,   216,   216,   218,
     218,   219,   220,   220,   222,   223,   223,   224,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   241,   241,   242,   242,   243,   243,
     246,   247,   248,   249,   259,   261,   262,   263,   265,   266,
     267,   268,   269,   270
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_INT", "T_FLOAT",
  "T_BOOL", "T_CHAR", "T_FLOAT_LITERAL", "T_TRUE", "T_FALSE", "T_IF",
  "T_ELSE", "T_WHILE", "T_FOR", "T_SWITCH", "T_CASE", "T_DEFAULT",
  "T_RETURN", "T_BREAK", "T_CONTINUE", "T_FUNC", "T_MAIN", "T_MOVE",
  "T_STOP", "T_TLEFT", "T_TRIGHT", "T_BATTERY", "T_DELAY", "T_READ",
  "T_EQ", "T_NEQ", "T_LE", "T_GE", "T_LT", "T_GT", "T_AND", "T_OR",
  "T_INC", "T_DEC", "T_ASSIGN", "T_PLUS", "T_MINUS", "T_MULT", "T_DIV",
  "T_MOD", "T_NOT", "T_SEMI", "T_COMMA", "T_LBRACE", "T_RBRACE",
  "T_LPAREN", "T_RPAREN", "T_LBRACKET", "T_RBRACKET", "T_ID", "T_NUMBER",
  "T_STRING", "T_ERROR", "':'", "$accept", "PROGRAMA", "DECLARACION_LIST",
  "DECLARACION", "DECLARACION_DE_VARIABLE", "DECLARACION_MAIN",
  "DECLARACION_DE_FUNCION", "PARAMETROS_OPT", "PARAMETROS", "PARAMS_TAIL",
  "PARAM", "VARIABLE_LIST", "VARIABLE_LIST_TAIL", "VARIABLE",
  "VARIABLE_INDEXES_OPT", "VARIABLE_INDEX", "ASSIGN_OPT", "TIPO", "BLOQUE",
  "BLOQUE_BODY", "DECL_OR_STMT_LIST", "DECL_OR_STMT", "SENTENCIA", "IF",
  "ELSE_OPT", "WHILE", "FOR", "ASIGNACION_OPT", "EXPRESION_OPT", "SWITCH",
  "SWITCH_CASES", "CASE_LIST", "CASE", "DEFAULT_OPT", "STATEMENTS",
  "RETURN", "ACCION_CARRITO", "MOVE", "STOP", "TURNLEFT", "TURNRIGHT",
  "BATTERY", "DELAY", "READ", "ASIGNACION", "LVALUE", "LVALUE_TAIL",
  "ARGUMENTOS_OPT", "ARGUMENTOS", "ARG_TAIL", "EXPRESION", "LOGICA_OR",
  "LOGICA_AND", "IGUALDAD", "COMPARACION", "SUMA", "PRODUCTO", "UNARIO",
  "UNARIO_OP", "PRIMARIO", "PRIMARIO_TAIL", "LITERAL", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-188)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      62,  -188,  -188,  -188,  -188,    24,  -188,    62,  -188,  -188,
    -188,   -13,  -188,  -188,    -2,   -25,    -9,     6,    11,    23,
     304,    48,   -25,  -188,    34,  -188,    62,    62,  -188,  -188,
    -188,  -188,    39,    42,  -188,  -188,  -188,  -188,   304,   -19,
    -188,  -188,  -188,  -188,    40,    58,    64,    10,    38,     9,
       0,  -188,   304,  -188,  -188,   304,  -188,  -188,     6,    49,
    -188,    54,    50,    51,    52,   304,    57,   304,   -19,  -188,
    -188,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,  -188,  -188,  -188,    61,    62,  -188,
    -188,    61,  -188,    59,  -188,    60,  -188,    66,  -188,    64,
      10,    38,    38,     9,     9,     9,     9,     0,     0,  -188,
    -188,  -188,   179,  -188,    54,  -188,  -188,  -188,   304,  -188,
      -3,    65,    68,    69,    71,   253,    70,    76,    74,    78,
      79,    80,    82,   -16,  -188,  -188,    85,  -188,   179,  -188,
    -188,  -188,  -188,  -188,  -188,    89,  -188,  -188,  -188,  -188,
      91,  -188,    94,    99,    75,   101,  -188,    66,   304,   304,
       5,   304,  -188,   105,  -188,  -188,   304,   102,   304,   304,
     304,   -16,  -188,  -188,  -188,  -188,  -188,   304,  -188,  -188,
     103,   104,   -25,   304,    34,   106,  -188,   108,  -188,   110,
    -188,   111,   113,   114,  -188,  -188,   230,   230,   -25,   120,
    -188,   304,   119,  -188,  -188,  -188,  -188,   145,  -188,   116,
     122,    63,   230,  -188,   123,   116,     7,   115,   126,   155,
     161,  -188,  -188,   230,   129,   132,   230,  -188,  -188,  -188,
    -188,   230,   230,   230,  -188,  -188,  -188,  -188
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    26,    27,    28,    29,     0,     2,     4,     6,     7,
       5,     0,     1,     3,     0,    22,     0,    19,     0,     0,
       0,    25,    22,     8,     0,    17,    12,    12,   131,   128,
     132,   133,     0,     0,   118,   119,   117,   116,     0,   127,
     129,   130,   121,   122,     0,    94,    95,    97,    99,   102,
     107,   110,     0,   115,   120,     0,    20,    21,    19,     0,
      11,    15,     0,     0,     0,     0,     0,    90,   127,   123,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,    24,    18,     0,     0,    13,
      16,     0,    82,     0,   124,     0,    89,    93,   126,    96,
      98,   100,   101,   105,   106,   103,   104,   108,   109,   111,
     112,   113,    32,     9,    15,    10,    84,   125,     0,    91,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,    35,    47,     0,    31,    34,    36,
      37,    38,    39,    40,    41,     0,    71,    72,    73,    74,
     121,    76,   122,     0,     0,     0,    14,    93,     0,     0,
      55,     0,    70,     0,    42,    43,     0,     0,     0,     0,
       0,   127,    86,    30,    33,    44,    45,     0,    46,    92,
       0,     0,    88,    57,     0,     0,    54,     0,    69,     0,
      79,     0,     0,     0,    87,    85,     0,     0,    88,     0,
      56,    57,     0,    78,    80,    81,    83,    50,    51,    55,
       0,    61,     0,    48,     0,    55,     0,     0,     0,    66,
      63,    60,    49,     0,     0,     0,    68,    58,    59,    62,
      52,     0,    68,    68,    65,    53,    64,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,   187,   -92,    35,  -188,  -188,   172,  -188,    86,
     121,  -188,   150,   186,   189,   -38,  -188,   -24,   -62,  -188,
      77,  -188,  -100,  -188,  -188,  -188,  -188,  -187,    13,  -188,
    -188,    -8,  -188,    -6,  -152,  -188,  -188,  -188,  -188,  -188,
    -188,  -106,  -188,   -54,  -155,  -188,  -150,  -188,  -188,    73,
     -20,  -188,   147,   149,    12,    -1,     3,   -26,  -188,  -188,
     -64,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    10,    59,    60,    89,
      61,    16,    25,    17,    21,    22,    56,    11,   135,   136,
     137,   138,   233,   140,   213,   141,   142,   185,   199,   143,
     218,   219,   220,   221,   234,   144,   145,   146,   147,   148,
     149,    42,   151,    43,   153,   154,   172,    95,    96,   119,
     155,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      69,    54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    68,    62,    62,    98,   186,   150,    14,     1,     2,
       3,     4,   139,    28,    29,    30,    31,   -29,    66,    18,
     134,   194,   214,   -88,    12,   113,    84,    20,   224,   115,
      68,    67,   150,    20,    67,    85,    20,    23,   139,    73,
      74,    15,    81,    82,    83,    93,   134,    97,   194,    79,
      80,   -29,    19,    24,   186,   109,   110,   111,   152,   182,
     186,    26,    40,    41,    62,     1,     2,     3,     4,    75,
      76,    77,    78,    27,   103,   104,   105,   106,   216,   217,
     236,   237,   107,   108,   152,   101,   102,    55,    15,    64,
     150,   150,    65,    70,    71,   171,   207,   208,   157,    72,
      87,    88,    91,    92,    90,   163,   150,    98,    94,   112,
     116,   117,   222,   118,   177,   158,   164,   150,   159,   160,
     150,   161,   165,   230,   166,   150,   150,   150,   167,   168,
     169,   235,   170,   171,   173,   175,   184,   -75,   180,   181,
     -77,   187,   152,   152,   198,   176,   189,   178,   191,   192,
     193,   188,   201,   190,   196,   197,   212,   195,   152,   202,
     198,   203,   204,   200,   205,   206,   209,   211,   215,   152,
     182,   217,   152,   226,   223,   227,   216,   152,   152,   152,
     231,   200,     1,     2,     3,   120,    29,    30,    31,   121,
     232,   122,   123,   124,    13,   183,   125,   126,   127,    63,
     156,   128,   129,   130,   131,    32,   132,    33,    86,   114,
      58,    57,   229,   228,   210,   174,    34,    35,    99,     0,
      36,   100,     0,     0,    37,     0,     0,   112,     0,    38,
     179,   225,     0,   133,    40,    41,    28,    29,    30,    31,
     121,     0,   122,   123,   124,     0,     0,   125,   126,   127,
       0,     0,   128,   129,   130,   131,    32,   132,    33,    28,
      29,    30,    31,     0,     0,     0,     0,    34,    35,     0,
       0,    36,     0,     0,     0,    37,     0,     0,   112,    32,
      38,    33,     0,     0,   133,    40,    41,     0,     0,     0,
      34,    35,     0,     0,    36,     0,     0,     0,    37,   162,
       0,     0,     0,    38,     0,     0,     0,    39,    40,    41,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,     0,     0,    36,     0,     0,     0,    37,
       0,     0,     0,     0,    38,     0,     0,     0,    39,    40,
      41
};

static const yytype_int16 yycheck[] =
{
      20,    39,    26,    27,    68,   160,   112,    20,     3,     4,
       5,     6,   112,     6,     7,     8,     9,    20,    38,    21,
     112,   171,   209,    39,     0,    87,    52,    52,   215,    91,
      68,    50,   138,    52,    50,    55,    52,    46,   138,    29,
      30,    54,    42,    43,    44,    65,   138,    67,   198,    40,
      41,    54,    54,    47,   209,    81,    82,    83,   112,    54,
     215,    50,    55,    56,    88,     3,     4,     5,     6,    31,
      32,    33,    34,    50,    75,    76,    77,    78,    15,    16,
     232,   233,    79,    80,   138,    73,    74,    39,    54,    50,
     196,   197,    50,    53,    36,   133,   196,   197,   118,    35,
      51,    47,    51,    51,    54,   125,   212,   171,    51,    48,
      51,    51,   212,    47,    39,    50,    46,   223,    50,    50,
     226,    50,    46,   223,    50,   231,   232,   233,    50,    50,
      50,   231,    50,   171,    49,    46,   160,    46,   158,   159,
      46,   161,   196,   197,   182,    46,   166,    46,   168,   169,
     170,    46,    46,    51,    51,    51,    11,   177,   212,    51,
     198,    51,    51,   183,    51,    51,    46,    48,    46,   223,
      54,    16,   226,    58,    51,    49,    15,   231,   232,   233,
      51,   201,     3,     4,     5,     6,     7,     8,     9,    10,
      58,    12,    13,    14,     7,   160,    17,    18,    19,    27,
     114,    22,    23,    24,    25,    26,    27,    28,    58,    88,
      24,    22,   220,   219,   201,   138,    37,    38,    71,    -1,
      41,    72,    -1,    -1,    45,    -1,    -1,    48,    -1,    50,
     157,   216,    -1,    54,    55,    56,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    41,    -1,    -1,    -1,    45,    -1,    -1,    48,    26,
      50,    28,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      37,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    56,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    60,    61,    62,    63,    64,
      65,    76,     0,    61,    20,    54,    70,    72,    21,    54,
      52,    73,    74,    46,    47,    71,    50,    50,     6,     7,
       8,     9,    26,    28,    37,    38,    41,    45,    50,    54,
      55,    56,   100,   102,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   120,    39,    75,    73,    72,    66,
      67,    69,    76,    66,    50,    50,   109,    50,    74,   119,
      53,    36,    35,    29,    30,    31,    32,    33,    34,    40,
      41,    42,    43,    44,   116,   109,    71,    51,    47,    68,
      54,    51,    51,   109,    51,   106,   107,   109,   119,   111,
     112,   113,   113,   114,   114,   114,   114,   115,   115,   116,
     116,   116,    48,    77,    69,    77,    51,    51,    47,   108,
       6,    10,    12,    13,    14,    17,    18,    19,    22,    23,
      24,    25,    27,    54,    62,    77,    78,    79,    80,    81,
      82,    84,    85,    88,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   109,    68,   109,    50,    50,
      50,    50,    46,   109,    46,    46,    50,    50,    50,    50,
      50,    74,   105,    49,    79,    46,    46,    39,    46,   108,
     109,   109,    54,    63,    76,    86,   103,   109,    46,   109,
      51,   109,   109,   109,   105,   109,    51,    51,    74,    87,
     109,    46,    51,    51,    51,    51,    51,    81,    81,    46,
      87,    48,    11,    83,    86,    46,    15,    16,    89,    90,
      91,    92,    81,    51,    86,   120,    58,    49,    92,    90,
      81,    51,    58,    81,    93,    81,    93,    93
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    63,    64,
      65,    66,    66,    67,    68,    68,    69,    70,    71,    71,
      72,    73,    73,    74,    75,    75,    76,    76,    76,    76,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    83,
      83,    84,    85,    85,    86,    86,    87,    87,    88,    89,
      89,    89,    90,    90,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   105,   106,
     106,   107,   108,   108,   109,   110,   110,   111,   111,   112,
     112,   112,   113,   113,   113,   113,   113,   114,   114,   114,
     115,   115,   115,   115,   116,   116,   117,   117,   117,   117,
     118,   118,   118,   118,   118,   119,   119,   119,   120,   120,
     120,   120,   120,   120
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     3,     7,
       7,     1,     0,     2,     3,     0,     2,     2,     3,     0,
       3,     2,     0,     3,     2,     0,     1,     1,     1,     1,
       3,     1,     0,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     6,     2,
       0,     5,     8,     9,     1,     0,     1,     0,     7,     2,
       1,     0,     2,     0,     4,     3,     0,     2,     0,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       4,     4,     3,     4,     4,     3,     2,     2,     0,     1,
       0,     2,     3,     0,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     2,     0,     1,     1,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* PROGRAMA: DECLARACION_LIST  */
#line 89 "parser.y"
                     {
        (yyval.node) = newNode2(NODE_PROGRAM, (yyvsp[0].node), NULL);
        root = (yyval.node);
    }
#line 1400 "parser.tab.c"
    break;

  case 3: /* DECLARACION_LIST: DECLARACION DECLARACION_LIST  */
#line 96 "parser.y"
                                   {
        (yyval.node) = newNode2(NODE_DECL_LIST, (yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1408 "parser.tab.c"
    break;

  case 4: /* DECLARACION_LIST: %empty  */
#line 99 "parser.y"
                   {
        (yyval.node) = NULL;
      }
#line 1416 "parser.tab.c"
    break;

  case 5: /* DECLARACION: DECLARACION_DE_FUNCION  */
#line 105 "parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1422 "parser.tab.c"
    break;

  case 6: /* DECLARACION: DECLARACION_DE_VARIABLE  */
#line 106 "parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1428 "parser.tab.c"
    break;

  case 7: /* DECLARACION: DECLARACION_MAIN  */
#line 107 "parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1434 "parser.tab.c"
    break;

  case 8: /* DECLARACION_DE_VARIABLE: TIPO VARIABLE_LIST T_SEMI  */
#line 111 "parser.y"
                              {
        (yyval.node) = newNode2(NODE_VAR_DECL, (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1442 "parser.tab.c"
    break;

  case 9: /* DECLARACION_MAIN: TIPO T_FUNC T_MAIN T_LPAREN PARAMETROS_OPT T_RPAREN BLOQUE  */
#line 117 "parser.y"
                                                                 {
            Node* func = newNode2(NODE_FUNC_DECL, (yyvsp[-6].node), (yyvsp[0].node));
            func->sval = strdup("main");
            (yyval.node) = func;
      }
#line 1452 "parser.tab.c"
    break;

  case 10: /* DECLARACION_DE_FUNCION: TIPO T_FUNC T_ID T_LPAREN PARAMETROS_OPT T_RPAREN BLOQUE  */
#line 125 "parser.y"
                                                               {
            Node* type = (yyvsp[-6].node);
            Node* id = newNodeS(NODE_LITERAL, (yyvsp[-4].sval));
            Node* header = newNode2(NODE_FUNC_DECL, type, id);
            (yyval.node) = newNode2(NODE_FUNC_DECL, header, (yyvsp[0].node));
      }
#line 1463 "parser.tab.c"
    break;

  case 11: /* PARAMETROS_OPT: PARAMETROS  */
#line 133 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1469 "parser.tab.c"
    break;

  case 12: /* PARAMETROS_OPT: %empty  */
#line 133 "parser.y"
                                          { (yyval.node) = NULL; }
#line 1475 "parser.tab.c"
    break;

  case 13: /* PARAMETROS: PARAM PARAMS_TAIL  */
#line 134 "parser.y"
                              { (yyval.node) = newNode2(NODE_PARAM_LIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1481 "parser.tab.c"
    break;

  case 14: /* PARAMS_TAIL: T_COMMA PARAM PARAMS_TAIL  */
#line 135 "parser.y"
                                       { (yyval.node) = newNode2(NODE_PARAM_LIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1487 "parser.tab.c"
    break;

  case 15: /* PARAMS_TAIL: %empty  */
#line 135 "parser.y"
                                                                                     { (yyval.node) = NULL; }
#line 1493 "parser.tab.c"
    break;

  case 16: /* PARAM: TIPO T_ID  */
#line 136 "parser.y"
                 { (yyval.node) = newNode2(NODE_PARAM, (yyvsp[-1].node), newNodeS(NODE_LITERAL, (yyvsp[0].sval))); }
#line 1499 "parser.tab.c"
    break;

  case 17: /* VARIABLE_LIST: VARIABLE VARIABLE_LIST_TAIL  */
#line 138 "parser.y"
                                           { (yyval.node) = newNode2(NODE_VAR, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1505 "parser.tab.c"
    break;

  case 18: /* VARIABLE_LIST_TAIL: T_COMMA VARIABLE VARIABLE_LIST_TAIL  */
#line 139 "parser.y"
                                                        { (yyval.node) = newNode2(NODE_VAR, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1511 "parser.tab.c"
    break;

  case 19: /* VARIABLE_LIST_TAIL: %empty  */
#line 139 "parser.y"
                                                                                               { (yyval.node) = NULL; }
#line 1517 "parser.tab.c"
    break;

  case 20: /* VARIABLE: T_ID VARIABLE_INDEXES_OPT ASSIGN_OPT  */
#line 141 "parser.y"
                                               {
      Node* id = newNodeS(NODE_LITERAL, (yyvsp[-2].sval));
      Node* temp = newNode2(NODE_VAR, id, (yyvsp[-1].node));
      (yyval.node) = newNode2(NODE_VAR, temp, (yyvsp[0].node));
}
#line 1527 "parser.tab.c"
    break;

  case 21: /* VARIABLE_INDEXES_OPT: VARIABLE_INDEX VARIABLE_INDEXES_OPT  */
#line 147 "parser.y"
                                                          { (yyval.node) = newNode2(NODE_INDEX, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1533 "parser.tab.c"
    break;

  case 22: /* VARIABLE_INDEXES_OPT: %empty  */
#line 147 "parser.y"
                                                                                                   { (yyval.node) = NULL; }
#line 1539 "parser.tab.c"
    break;

  case 23: /* VARIABLE_INDEX: T_LBRACKET EXPRESION T_RBRACKET  */
#line 148 "parser.y"
                                                { (yyval.node) = newNode2(NODE_INDEX, (yyvsp[-1].node), NULL); }
#line 1545 "parser.tab.c"
    break;

  case 24: /* ASSIGN_OPT: T_ASSIGN EXPRESION  */
#line 149 "parser.y"
                               { (yyval.node) = newNode2(NODE_ASSIGN, NULL, (yyvsp[0].node)); }
#line 1551 "parser.tab.c"
    break;

  case 25: /* ASSIGN_OPT: %empty  */
#line 149 "parser.y"
                                                                           { (yyval.node) = NULL; }
#line 1557 "parser.tab.c"
    break;

  case 26: /* TIPO: T_INT  */
#line 152 "parser.y"
              { (yyval.node) = newNodeS(NODE_TYPE, "int"); }
#line 1563 "parser.tab.c"
    break;

  case 27: /* TIPO: T_FLOAT  */
#line 153 "parser.y"
              { (yyval.node) = newNodeS(NODE_TYPE, "float"); }
#line 1569 "parser.tab.c"
    break;

  case 28: /* TIPO: T_BOOL  */
#line 154 "parser.y"
              { (yyval.node) = newNodeS(NODE_TYPE, "bool"); }
#line 1575 "parser.tab.c"
    break;

  case 29: /* TIPO: T_CHAR  */
#line 155 "parser.y"
              { (yyval.node) = newNodeS(NODE_TYPE, "char"); }
#line 1581 "parser.tab.c"
    break;

  case 30: /* BLOQUE: T_LBRACE BLOQUE_BODY T_RBRACE  */
#line 158 "parser.y"
                                      { (yyval.node) = newNode2(NODE_BLOCK, (yyvsp[-1].node), NULL); }
#line 1587 "parser.tab.c"
    break;

  case 31: /* BLOQUE_BODY: DECL_OR_STMT_LIST  */
#line 159 "parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1593 "parser.tab.c"
    break;

  case 32: /* BLOQUE_BODY: %empty  */
#line 159 "parser.y"
                                              { (yyval.node) = NULL; }
#line 1599 "parser.tab.c"
    break;

  case 33: /* DECL_OR_STMT_LIST: DECL_OR_STMT DECL_OR_STMT_LIST  */
#line 160 "parser.y"
                                                  { (yyval.node) = newNode2(NODE_STMT_LIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1605 "parser.tab.c"
    break;

  case 34: /* DECL_OR_STMT_LIST: %empty  */
#line 160 "parser.y"
                                                                                               { (yyval.node) = NULL; }
#line 1611 "parser.tab.c"
    break;

  case 35: /* DECL_OR_STMT: DECLARACION  */
#line 161 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1617 "parser.tab.c"
    break;

  case 36: /* DECL_OR_STMT: SENTENCIA  */
#line 161 "parser.y"
                                                   { (yyval.node) = (yyvsp[0].node); }
#line 1623 "parser.tab.c"
    break;

  case 37: /* SENTENCIA: IF  */
#line 164 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1629 "parser.tab.c"
    break;

  case 38: /* SENTENCIA: WHILE  */
#line 164 "parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1635 "parser.tab.c"
    break;

  case 39: /* SENTENCIA: FOR  */
#line 164 "parser.y"
                                                 { (yyval.node) = (yyvsp[0].node); }
#line 1641 "parser.tab.c"
    break;

  case 40: /* SENTENCIA: SWITCH  */
#line 164 "parser.y"
                                                                       { (yyval.node) = (yyvsp[0].node); }
#line 1647 "parser.tab.c"
    break;

  case 41: /* SENTENCIA: RETURN  */
#line 164 "parser.y"
                                                                                             { (yyval.node) = (yyvsp[0].node); }
#line 1653 "parser.tab.c"
    break;

  case 42: /* SENTENCIA: T_BREAK T_SEMI  */
#line 165 "parser.y"
                     { (yyval.node) = newNodeS(NODE_STMT, "break"); }
#line 1659 "parser.tab.c"
    break;

  case 43: /* SENTENCIA: T_CONTINUE T_SEMI  */
#line 166 "parser.y"
                        { (yyval.node) = newNodeS(NODE_STMT, "continue"); }
#line 1665 "parser.tab.c"
    break;

  case 44: /* SENTENCIA: ACCION_CARRITO T_SEMI  */
#line 167 "parser.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1671 "parser.tab.c"
    break;

  case 45: /* SENTENCIA: ASIGNACION T_SEMI  */
#line 168 "parser.y"
                        { (yyval.node) = (yyvsp[-1].node); }
#line 1677 "parser.tab.c"
    break;

  case 46: /* SENTENCIA: EXPRESION T_SEMI  */
#line 169 "parser.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1683 "parser.tab.c"
    break;

  case 47: /* SENTENCIA: BLOQUE  */
#line 170 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1689 "parser.tab.c"
    break;

  case 48: /* IF: T_IF T_LPAREN EXPRESION T_RPAREN SENTENCIA ELSE_OPT  */
#line 173 "parser.y"
                                                        {
      (yyval.node) = newNode2(NODE_IF, (yyvsp[-3].node), newNode2(NODE_IF, (yyvsp[-1].node), (yyvsp[0].node)));
}
#line 1697 "parser.tab.c"
    break;

  case 49: /* ELSE_OPT: T_ELSE SENTENCIA  */
#line 176 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1703 "parser.tab.c"
    break;

  case 50: /* ELSE_OPT: %empty  */
#line 176 "parser.y"
                                          { (yyval.node) = NULL; }
#line 1709 "parser.tab.c"
    break;

  case 51: /* WHILE: T_WHILE T_LPAREN EXPRESION T_RPAREN SENTENCIA  */
#line 178 "parser.y"
                                                     { (yyval.node) = newNode2(NODE_WHILE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1715 "parser.tab.c"
    break;

  case 52: /* FOR: T_FOR T_LPAREN DECLARACION_DE_VARIABLE EXPRESION_OPT T_SEMI ASIGNACION_OPT T_RPAREN SENTENCIA  */
#line 180 "parser.y"
                                                                                                   {
      Node* inc = newNode2(NODE_STMT, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node) = newNode2(NODE_FOR, (yyvsp[-5].node), newNode2(NODE_STMT, (yyvsp[-4].node), inc));
}
#line 1724 "parser.tab.c"
    break;

  case 53: /* FOR: T_FOR T_LPAREN ASIGNACION_OPT T_SEMI EXPRESION_OPT T_SEMI ASIGNACION_OPT T_RPAREN SENTENCIA  */
#line 184 "parser.y"
                                                                                              {
      Node* inc = newNode2(NODE_STMT, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node) = newNode2(NODE_FOR, (yyvsp[-6].node), newNode2(NODE_STMT, (yyvsp[-4].node), inc));
}
#line 1733 "parser.tab.c"
    break;

  case 54: /* ASIGNACION_OPT: ASIGNACION  */
#line 189 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1739 "parser.tab.c"
    break;

  case 55: /* ASIGNACION_OPT: %empty  */
#line 189 "parser.y"
                                          { (yyval.node) = NULL; }
#line 1745 "parser.tab.c"
    break;

  case 56: /* EXPRESION_OPT: EXPRESION  */
#line 190 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1751 "parser.tab.c"
    break;

  case 57: /* EXPRESION_OPT: %empty  */
#line 190 "parser.y"
                                        { (yyval.node) = NULL; }
#line 1757 "parser.tab.c"
    break;

  case 58: /* SWITCH: T_SWITCH T_LPAREN EXPRESION T_RPAREN T_LBRACE SWITCH_CASES T_RBRACE  */
#line 192 "parser.y"
                                                                            { (yyval.node) = newNode2(NODE_SWITCH, (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1763 "parser.tab.c"
    break;

  case 59: /* SWITCH_CASES: CASE_LIST DEFAULT_OPT  */
#line 193 "parser.y"
                                    { (yyval.node) = newNode2(NODE_SWITCH, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1769 "parser.tab.c"
    break;

  case 60: /* SWITCH_CASES: DEFAULT_OPT  */
#line 193 "parser.y"
                                                                                          { (yyval.node) = (yyvsp[0].node); }
#line 1775 "parser.tab.c"
    break;

  case 61: /* SWITCH_CASES: %empty  */
#line 193 "parser.y"
                                                                                                         { (yyval.node) = NULL; }
#line 1781 "parser.tab.c"
    break;

  case 62: /* CASE_LIST: CASE CASE_LIST  */
#line 194 "parser.y"
                          { (yyval.node) = newNode2(NODE_CASE, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1787 "parser.tab.c"
    break;

  case 63: /* CASE_LIST: %empty  */
#line 194 "parser.y"
                                                                  { (yyval.node) = NULL; }
#line 1793 "parser.tab.c"
    break;

  case 64: /* CASE: T_CASE LITERAL ':' STATEMENTS  */
#line 195 "parser.y"
                                    { (yyval.node) = newNode2(NODE_CASE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1799 "parser.tab.c"
    break;

  case 65: /* DEFAULT_OPT: T_DEFAULT ':' STATEMENTS  */
#line 196 "parser.y"
                                      { (yyval.node) = newNode2(NODE_DEFAULT, (yyvsp[0].node), NULL); }
#line 1805 "parser.tab.c"
    break;

  case 66: /* DEFAULT_OPT: %empty  */
#line 196 "parser.y"
                                                                                   { (yyval.node) = NULL; }
#line 1811 "parser.tab.c"
    break;

  case 67: /* STATEMENTS: SENTENCIA STATEMENTS  */
#line 197 "parser.y"
                                 { (yyval.node) = newNode2(NODE_STMT_LIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1817 "parser.tab.c"
    break;

  case 68: /* STATEMENTS: %empty  */
#line 197 "parser.y"
                                                                              { (yyval.node) = NULL; }
#line 1823 "parser.tab.c"
    break;

  case 69: /* RETURN: T_RETURN EXPRESION T_SEMI  */
#line 199 "parser.y"
                                  { (yyval.node) = newNode2(NODE_RETURN, (yyvsp[-1].node), NULL); }
#line 1829 "parser.tab.c"
    break;

  case 70: /* RETURN: T_RETURN T_SEMI  */
#line 199 "parser.y"
                                                                                              { (yyval.node) = newNode(NODE_RETURN); }
#line 1835 "parser.tab.c"
    break;

  case 71: /* ACCION_CARRITO: MOVE  */
#line 202 "parser.y"
                     { (yyval.node)=(yyvsp[0].node); }
#line 1841 "parser.tab.c"
    break;

  case 72: /* ACCION_CARRITO: STOP  */
#line 202 "parser.y"
                                       { (yyval.node)=(yyvsp[0].node); }
#line 1847 "parser.tab.c"
    break;

  case 73: /* ACCION_CARRITO: TURNLEFT  */
#line 202 "parser.y"
                                                             { (yyval.node)=(yyvsp[0].node); }
#line 1853 "parser.tab.c"
    break;

  case 74: /* ACCION_CARRITO: TURNRIGHT  */
#line 202 "parser.y"
                                                                                    { (yyval.node)=(yyvsp[0].node); }
#line 1859 "parser.tab.c"
    break;

  case 75: /* ACCION_CARRITO: BATTERY  */
#line 202 "parser.y"
                                                                                                         { (yyval.node)=(yyvsp[0].node); }
#line 1865 "parser.tab.c"
    break;

  case 76: /* ACCION_CARRITO: DELAY  */
#line 202 "parser.y"
                                                                                                                            { (yyval.node)=(yyvsp[0].node); }
#line 1871 "parser.tab.c"
    break;

  case 77: /* ACCION_CARRITO: READ  */
#line 202 "parser.y"
                                                                                                                                              { (yyval.node)=(yyvsp[0].node); }
#line 1877 "parser.tab.c"
    break;

  case 78: /* MOVE: T_MOVE T_LPAREN EXPRESION T_RPAREN  */
#line 204 "parser.y"
                                         { (yyval.node) = newNode2(NODE_ACTION, (yyvsp[-1].node), NULL); (yyval.node)->sval = strdup("move"); }
#line 1883 "parser.tab.c"
    break;

  case 79: /* STOP: T_STOP T_LPAREN T_RPAREN  */
#line 205 "parser.y"
                               { (yyval.node) = newNode(NODE_ACTION); (yyval.node)->sval = strdup("stop"); }
#line 1889 "parser.tab.c"
    break;

  case 80: /* TURNLEFT: T_TLEFT T_LPAREN EXPRESION T_RPAREN  */
#line 206 "parser.y"
                                              { (yyval.node) = newNode2(NODE_ACTION, (yyvsp[-1].node), NULL); (yyval.node)->sval = strdup("turnLeft"); }
#line 1895 "parser.tab.c"
    break;

  case 81: /* TURNRIGHT: T_TRIGHT T_LPAREN EXPRESION T_RPAREN  */
#line 207 "parser.y"
                                                { (yyval.node) = newNode2(NODE_ACTION, (yyvsp[-1].node), NULL); (yyval.node)->sval = strdup("turnRight"); }
#line 1901 "parser.tab.c"
    break;

  case 82: /* BATTERY: T_BATTERY T_LPAREN T_RPAREN  */
#line 208 "parser.y"
                                     { (yyval.node) = newNode(NODE_ACTION); (yyval.node)->sval = strdup("battery"); }
#line 1907 "parser.tab.c"
    break;

  case 83: /* DELAY: T_DELAY T_LPAREN EXPRESION T_RPAREN  */
#line 209 "parser.y"
                                           { (yyval.node) = newNode2(NODE_ACTION, (yyvsp[-1].node), NULL); (yyval.node)->sval = strdup("delay"); }
#line 1913 "parser.tab.c"
    break;

  case 84: /* READ: T_READ T_LPAREN EXPRESION T_RPAREN  */
#line 212 "parser.y"
                                         { (yyval.node) = newNode2(NODE_ACTION, (yyvsp[-1].node), NULL); (yyval.node)->sval = strdup("read"); }
#line 1919 "parser.tab.c"
    break;

  case 85: /* ASIGNACION: LVALUE T_ASSIGN EXPRESION  */
#line 214 "parser.y"
                                      { (yyval.node) = newNode2(NODE_ASSIGN, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1925 "parser.tab.c"
    break;

  case 86: /* LVALUE: T_ID LVALUE_TAIL  */
#line 215 "parser.y"
                         { (yyval.node) = newNode2(NODE_LVALUE, newNodeS(NODE_LITERAL, (yyvsp[-1].sval)), (yyvsp[0].node)); }
#line 1931 "parser.tab.c"
    break;

  case 87: /* LVALUE_TAIL: VARIABLE_INDEX LVALUE_TAIL  */
#line 216 "parser.y"
                                        { (yyval.node) = newNode2(NODE_INDEX, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1937 "parser.tab.c"
    break;

  case 88: /* LVALUE_TAIL: %empty  */
#line 216 "parser.y"
                                                                                 { (yyval.node) = NULL; }
#line 1943 "parser.tab.c"
    break;

  case 89: /* ARGUMENTOS_OPT: ARGUMENTOS  */
#line 218 "parser.y"
                           { (yyval.node)=(yyvsp[0].node); }
#line 1949 "parser.tab.c"
    break;

  case 90: /* ARGUMENTOS_OPT: %empty  */
#line 218 "parser.y"
                                        { (yyval.node)=NULL; }
#line 1955 "parser.tab.c"
    break;

  case 91: /* ARGUMENTOS: EXPRESION ARG_TAIL  */
#line 219 "parser.y"
                               { (yyval.node) = newNode2(NODE_ARG_LIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1961 "parser.tab.c"
    break;

  case 92: /* ARG_TAIL: T_COMMA EXPRESION ARG_TAIL  */
#line 220 "parser.y"
                                     { (yyval.node) = newNode2(NODE_ARG_LIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1967 "parser.tab.c"
    break;

  case 93: /* ARG_TAIL: %empty  */
#line 220 "parser.y"
                                                                                 { (yyval.node) = NULL; }
#line 1973 "parser.tab.c"
    break;

  case 94: /* EXPRESION: LOGICA_OR  */
#line 222 "parser.y"
                     { (yyval.node)=(yyvsp[0].node); }
#line 1979 "parser.tab.c"
    break;

  case 95: /* LOGICA_OR: LOGICA_AND  */
#line 223 "parser.y"
                      { (yyval.node)=(yyvsp[0].node); }
#line 1985 "parser.tab.c"
    break;

  case 96: /* LOGICA_OR: LOGICA_OR T_OR LOGICA_AND  */
#line 223 "parser.y"
                                                             { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("||"); }
#line 1991 "parser.tab.c"
    break;

  case 97: /* LOGICA_AND: IGUALDAD  */
#line 224 "parser.y"
                     { (yyval.node)=(yyvsp[0].node); }
#line 1997 "parser.tab.c"
    break;

  case 98: /* LOGICA_AND: LOGICA_AND T_AND IGUALDAD  */
#line 224 "parser.y"
                                                            { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("&&"); }
#line 2003 "parser.tab.c"
    break;

  case 99: /* IGUALDAD: COMPARACION  */
#line 225 "parser.y"
                      { (yyval.node)=(yyvsp[0].node); }
#line 2009 "parser.tab.c"
    break;

  case 100: /* IGUALDAD: IGUALDAD T_EQ COMPARACION  */
#line 226 "parser.y"
                              { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("=="); }
#line 2015 "parser.tab.c"
    break;

  case 101: /* IGUALDAD: IGUALDAD T_NEQ COMPARACION  */
#line 227 "parser.y"
                               { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("!="); }
#line 2021 "parser.tab.c"
    break;

  case 102: /* COMPARACION: SUMA  */
#line 228 "parser.y"
                  { (yyval.node)=(yyvsp[0].node); }
#line 2027 "parser.tab.c"
    break;

  case 103: /* COMPARACION: COMPARACION T_LT SUMA  */
#line 229 "parser.y"
                          { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("<"); }
#line 2033 "parser.tab.c"
    break;

  case 104: /* COMPARACION: COMPARACION T_GT SUMA  */
#line 230 "parser.y"
                          { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup(">"); }
#line 2039 "parser.tab.c"
    break;

  case 105: /* COMPARACION: COMPARACION T_LE SUMA  */
#line 231 "parser.y"
                          { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("<="); }
#line 2045 "parser.tab.c"
    break;

  case 106: /* COMPARACION: COMPARACION T_GE SUMA  */
#line 232 "parser.y"
                          { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup(">="); }
#line 2051 "parser.tab.c"
    break;

  case 107: /* SUMA: PRODUCTO  */
#line 233 "parser.y"
               { (yyval.node)=(yyvsp[0].node); }
#line 2057 "parser.tab.c"
    break;

  case 108: /* SUMA: SUMA T_PLUS PRODUCTO  */
#line 234 "parser.y"
                         { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("+"); }
#line 2063 "parser.tab.c"
    break;

  case 109: /* SUMA: SUMA T_MINUS PRODUCTO  */
#line 235 "parser.y"
                          { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("-"); }
#line 2069 "parser.tab.c"
    break;

  case 110: /* PRODUCTO: UNARIO  */
#line 236 "parser.y"
                 { (yyval.node)=(yyvsp[0].node); }
#line 2075 "parser.tab.c"
    break;

  case 111: /* PRODUCTO: PRODUCTO T_MULT UNARIO  */
#line 237 "parser.y"
                           { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("*"); }
#line 2081 "parser.tab.c"
    break;

  case 112: /* PRODUCTO: PRODUCTO T_DIV UNARIO  */
#line 238 "parser.y"
                          { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("/"); }
#line 2087 "parser.tab.c"
    break;

  case 113: /* PRODUCTO: PRODUCTO T_MOD UNARIO  */
#line 239 "parser.y"
                          { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->sval = strdup("%"); }
#line 2093 "parser.tab.c"
    break;

  case 114: /* UNARIO: UNARIO_OP UNARIO  */
#line 241 "parser.y"
                         { (yyval.node) = newNode2(NODE_EXPR, (yyvsp[0].node), NULL); (yyval.node)->sval = (yyvsp[-1].node)->sval; }
#line 2099 "parser.tab.c"
    break;

  case 115: /* UNARIO: PRIMARIO  */
#line 241 "parser.y"
                                                                                                 { (yyval.node)=(yyvsp[0].node); }
#line 2105 "parser.tab.c"
    break;

  case 116: /* UNARIO_OP: T_NOT  */
#line 242 "parser.y"
                 { (yyval.node) = newNodeS(NODE_EXPR, "!"); }
#line 2111 "parser.tab.c"
    break;

  case 117: /* UNARIO_OP: T_MINUS  */
#line 242 "parser.y"
                                                              { (yyval.node) = newNodeS(NODE_EXPR, "-"); }
#line 2117 "parser.tab.c"
    break;

  case 118: /* UNARIO_OP: T_INC  */
#line 243 "parser.y"
                 { (yyval.node) = newNodeS(NODE_EXPR, "++"); }
#line 2123 "parser.tab.c"
    break;

  case 119: /* UNARIO_OP: T_DEC  */
#line 243 "parser.y"
                                                             { (yyval.node) = newNodeS(NODE_EXPR, "--"); }
#line 2129 "parser.tab.c"
    break;

  case 120: /* PRIMARIO: LITERAL  */
#line 246 "parser.y"
                  { (yyval.node)=(yyvsp[0].node); }
#line 2135 "parser.tab.c"
    break;

  case 121: /* PRIMARIO: BATTERY  */
#line 247 "parser.y"
            { (yyval.node)=(yyvsp[0].node); }
#line 2141 "parser.tab.c"
    break;

  case 122: /* PRIMARIO: READ  */
#line 248 "parser.y"
         { (yyval.node)=(yyvsp[0].node); }
#line 2147 "parser.tab.c"
    break;

  case 123: /* PRIMARIO: T_ID PRIMARIO_TAIL  */
#line 249 "parser.y"
                       { 
      Node* id = newNodeS(NODE_LITERAL, (yyvsp[-1].sval)); 
      if ((yyvsp[0].node) == NULL) {
          // Antes: $$ = id; (Esto creaba un Literal "a" y confundía al semántico)
          // Ahora: Lo envolvemos como LVALUE para que se busque en la tabla de símbolos
          (yyval.node) = newNode2(NODE_LVALUE, id, NULL);
      } 
      else if ((yyvsp[0].node)->type == NODE_FUNC_CALL) { (yyvsp[0].node)->left = id; (yyval.node) = (yyvsp[0].node); }
      else { (yyval.node) = newNode2(NODE_LVALUE, id, (yyvsp[0].node)); }
    }
#line 2162 "parser.tab.c"
    break;

  case 124: /* PRIMARIO: T_LPAREN EXPRESION T_RPAREN  */
#line 259 "parser.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2168 "parser.tab.c"
    break;

  case 125: /* PRIMARIO_TAIL: T_LPAREN ARGUMENTOS_OPT T_RPAREN  */
#line 261 "parser.y"
                                                { (yyval.node) = newNode2(NODE_FUNC_CALL, NULL, (yyvsp[-1].node)); }
#line 2174 "parser.tab.c"
    break;

  case 126: /* PRIMARIO_TAIL: VARIABLE_INDEX PRIMARIO_TAIL  */
#line 262 "parser.y"
                                            { (yyval.node) = newNode2(NODE_INDEX, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2180 "parser.tab.c"
    break;

  case 127: /* PRIMARIO_TAIL: %empty  */
#line 263 "parser.y"
               { (yyval.node) = NULL; }
#line 2186 "parser.tab.c"
    break;

  case 128: /* LITERAL: T_FLOAT_LITERAL  */
#line 265 "parser.y"
                         { (yyval.node)=newNodeS(NODE_LITERAL, "float"); (yyval.node)->sval=strdup((yyvsp[0].sval)); }
#line 2192 "parser.tab.c"
    break;

  case 129: /* LITERAL: T_NUMBER  */
#line 266 "parser.y"
                  { (yyval.node)=newNodeI(NODE_LITERAL, (yyvsp[0].ival)); }
#line 2198 "parser.tab.c"
    break;

  case 130: /* LITERAL: T_STRING  */
#line 267 "parser.y"
                  { (yyval.node)=newNodeS(NODE_LITERAL, "string"); (yyval.node)->sval=strdup((yyvsp[0].sval)); }
#line 2204 "parser.tab.c"
    break;

  case 131: /* LITERAL: T_CHAR  */
#line 268 "parser.y"
                { (yyval.node)=newNodeS(NODE_LITERAL, "char"); (yyval.node)->sval=strdup((yyvsp[0].sval)); }
#line 2210 "parser.tab.c"
    break;

  case 132: /* LITERAL: T_TRUE  */
#line 269 "parser.y"
                { (yyval.node)=newNodeS(NODE_LITERAL, "bool"); (yyval.node)->sval=strdup("true"); }
#line 2216 "parser.tab.c"
    break;

  case 133: /* LITERAL: T_FALSE  */
#line 270 "parser.y"
                 { (yyval.node)=newNodeS(NODE_LITERAL, "bool"); (yyval.node)->sval=strdup("false"); }
#line 2222 "parser.tab.c"
    break;


#line 2226 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 272 "parser.y"

void yyerror(const char *s) { fprintf(stderr, "Parser error: %s on line %d\n", s, yylineno); exit(1); }
