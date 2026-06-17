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
#line 1 "sin.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabela.h"

int cont_read = 0;
int houve_erro = 0;
int dentro_switch = 0;
extern int yylex();
extern int yylineno;
void yyerror(const char *s) {
    fprintf(stderr, "\n----------------------------------------\n");
    fprintf(stderr, "Erro na linha %d:\n", yylineno);
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "----------------------------------------\n");
    houve_erro = 1;
}

char buf[200];
char c_decl[5000] = "";
char c_body[5000] = "";
char declaracoes_temp[5000] = "";
char instrucoes_funcoes[5000] = "";
char instrucoes_globais[5000] = "";
char inc_3ac[200] = "";
char inc_c[200] = "";   
char switch_exp[50] = "";
char switch_fim[50] = "";
char pilha_inicio[20][50];
char pilha_fim[20][50];
int topo_laco = 0;

Simbolo *simbolo_array_atual = NULL;
int idx_array_atual = 0;
int tam_array_atual = 0;

int escopo_atual = 0;

#line 112 "sin.tab.c"

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

#include "sin.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_FOR = 3,                  /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_MAIN = 4,                 /* TOKEN_MAIN  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_NUM_INT = 6,                    /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 7,                  /* NUM_FLOAT  */
  YYSYMBOL_CHAR_LIT = 8,                   /* CHAR_LIT  */
  YYSYMBOL_BOOL_LIT = 9,                   /* BOOL_LIT  */
  YYSYMBOL_STRING_LIT = 10,                /* STRING_LIT  */
  YYSYMBOL_TOKEN_INT = 11,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 12,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_CHAR = 13,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_BOOL = 14,                /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_STRING = 15,              /* TOKEN_STRING  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 17,                      /* PLUS  */
  YYSYMBOL_TOKEN_PRINT = 18,               /* TOKEN_PRINT  */
  YYSYMBOL_TOKEN_READ = 19,                /* TOKEN_READ  */
  YYSYMBOL_TOKEN_IF = 20,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 21,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 22,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 23,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_SWITCH = 24,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 25,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 26,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_BREAK = 27,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 28,            /* TOKEN_CONTINUE  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_LE = 33,                        /* LE  */
  YYSYMBOL_GE = 34,                        /* GE  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_PLUS_ASSIGN = 36,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 37,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 38,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 39,                /* DIV_ASSIGN  */
  YYSYMBOL_INC = 40,                       /* INC  */
  YYSYMBOL_DEC = 41,                       /* DEC  */
  YYSYMBOL_TOKEN_VOID = 42,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_RETURN = 43,              /* TOKEN_RETURN  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_CAST = 49,                      /* CAST  */
  YYSYMBOL_UMINUS = 50,                    /* UMINUS  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_programa = 61,                  /* programa  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_elementos_globais = 63,         /* elementos_globais  */
  YYSYMBOL_elemento_global = 64,           /* elemento_global  */
  YYSYMBOL_funcao = 65,                    /* funcao  */
  YYSYMBOL_66_2 = 66,                      /* $@2  */
  YYSYMBOL_67_3 = 67,                      /* $@3  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_70_6 = 70,                      /* $@6  */
  YYSYMBOL_71_7 = 71,                      /* $@7  */
  YYSYMBOL_parametros = 72,                /* parametros  */
  YYSYMBOL_parametro = 73,                 /* parametro  */
  YYSYMBOL_argumentos = 74,                /* argumentos  */
  YYSYMBOL_lista_args = 75,                /* lista_args  */
  YYSYMBOL_bloco = 76,                     /* bloco  */
  YYSYMBOL_77_8 = 77,                      /* $@8  */
  YYSYMBOL_comandos_bloco = 78,            /* comandos_bloco  */
  YYSYMBOL_if_cond = 79,                   /* if_cond  */
  YYSYMBOL_for_init = 80,                  /* for_init  */
  YYSYMBOL_incremento_for = 81,            /* incremento_for  */
  YYSYMBOL_casos_lista = 82,               /* casos_lista  */
  YYSYMBOL_caso = 83,                      /* caso  */
  YYSYMBOL_84_9 = 84,                      /* @9  */
  YYSYMBOL_default_caso = 85,              /* default_caso  */
  YYSYMBOL_86_10 = 86,                     /* $@10  */
  YYSYMBOL_comando = 87,                   /* comando  */
  YYSYMBOL_88_11 = 88,                     /* @11  */
  YYSYMBOL_89_12 = 89,                     /* @12  */
  YYSYMBOL_90_13 = 90,                     /* @13  */
  YYSYMBOL_91_14 = 91,                     /* @14  */
  YYSYMBOL_92_15 = 92,                     /* @15  */
  YYSYMBOL_93_16 = 93,                     /* @16  */
  YYSYMBOL_94_17 = 94,                     /* $@17  */
  YYSYMBOL_95_18 = 95,                     /* $@18  */
  YYSYMBOL_declaracao = 96,                /* declaracao  */
  YYSYMBOL_97_19 = 97,                     /* $@19  */
  YYSYMBOL_98_20 = 98,                     /* $@20  */
  YYSYMBOL_atribuicao = 99,                /* atribuicao  */
  YYSYMBOL_expressao = 100,                /* expressao  */
  YYSYMBOL_lista_valores = 101             /* lista_valores  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   625

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      51,    52,    47,     2,    56,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    53,
      44,     2,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    49,
      50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    82,    89,    90,    94,    95,    98,    98,
     123,   123,   148,   148,   171,   171,   194,   194,   217,   217,
     243,   244,   251,   257,   264,   271,   279,   286,   297,   298,
     304,   308,   317,   317,   323,   324,   328,   356,   373,   384,
     396,   409,   410,   411,   414,   414,   453,   453,   460,   461,
     462,   463,   464,   478,   502,   508,   508,   533,   543,   533,
     583,   583,   605,   621,   647,   605,   676,   676,   707,   729,
     739,   756,   770,   784,   798,   811,   824,   857,   861,   868,
     883,   889,   919,   919,   932,   938,   967,   967,   978,   983,
    1001,  1006,  1024,  1029,  1054,  1111,  1116,  1123,  1130,  1137,
    1146,  1169,  1189,  1254,  1282,  1312,  1350,  1365,  1380,  1395,
    1410,  1425,  1442,  1456,  1470,  1485,  1504,  1523,  1526,  1541,
    1568,  1589
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_FOR",
  "TOKEN_MAIN", "ID", "NUM_INT", "NUM_FLOAT", "CHAR_LIT", "BOOL_LIT",
  "STRING_LIT", "TOKEN_INT", "TOKEN_FLOAT", "TOKEN_CHAR", "TOKEN_BOOL",
  "TOKEN_STRING", "ASSIGN", "PLUS", "TOKEN_PRINT", "TOKEN_READ",
  "TOKEN_IF", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_DO", "TOKEN_SWITCH",
  "TOKEN_CASE", "TOKEN_DEFAULT", "TOKEN_BREAK", "TOKEN_CONTINUE", "AND",
  "OR", "EQ", "NE", "LE", "GE", "NOT", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULT_ASSIGN", "DIV_ASSIGN", "INC", "DEC", "TOKEN_VOID", "TOKEN_RETURN",
  "'<'", "'>'", "'-'", "'*'", "'/'", "CAST", "UMINUS", "'('", "')'", "';'",
  "'{'", "'}'", "','", "':'", "'['", "']'", "$accept", "programa", "$@1",
  "elementos_globais", "elemento_global", "funcao", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "parametros", "parametro", "argumentos",
  "lista_args", "bloco", "$@8", "comandos_bloco", "if_cond", "for_init",
  "incremento_for", "casos_lista", "caso", "@9", "default_caso", "$@10",
  "comando", "@11", "@12", "@13", "@14", "@15", "@16", "$@17", "$@18",
  "declaracao", "$@19", "$@20", "atribuicao", "expressao", "lista_valores", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     189,    -3,    43,    61,    74,    81,    92,    18,  -162,   189,
    -162,    52,    29,    33,    11,    12,    13,    85,  -162,   121,
    -162,  -162,   114,    88,   126,   114,    88,   134,   114,    88,
     114,    88,   114,    88,    88,    91,   -34,  -162,  -162,  -162,
    -162,  -162,   114,   114,    63,   569,   138,   139,   141,   145,
     146,   -33,  -162,    93,   569,   -26,    94,   569,    36,   569,
      37,   569,    55,    60,   111,   114,   114,  -162,  -162,   115,
     117,   470,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,  -162,  -162,  -162,  -162,  -162,   112,
      88,   155,   118,   159,   133,   142,   143,   151,   154,   136,
     153,   569,   210,   114,   114,  -162,   -13,   288,   577,    48,
      48,    48,    48,    48,    48,   -13,  -162,  -162,  -162,  -162,
     156,  -162,   157,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
     114,  -162,  -162,  -162,   171,  -162,   171,  -162,   171,   171,
     171,   171,   171,   569,   161,    90,   187,   211,   213,   214,
     215,   170,   172,   173,  -162,  -162,   175,   176,   177,    32,
    -162,   178,   171,   171,   182,   183,   270,   114,   190,   114,
     191,   193,   194,   196,   197,   223,   114,   114,   114,   114,
     114,   184,   200,   114,   114,   -12,   -11,   252,   254,   255,
     114,   261,   114,   221,   171,   114,  -162,  -162,  -162,   295,
    -162,   264,  -162,  -162,  -162,  -162,   569,    21,  -162,    79,
    -162,  -162,  -162,  -162,  -162,   257,   233,   569,   320,   345,
     370,   395,  -162,  -162,   236,   230,   479,   238,   503,   114,
     269,   512,  -162,  -162,  -162,   114,  -162,   114,  -162,  -162,
    -162,  -162,  -162,   239,   277,   253,   256,  -162,   536,   259,
    -162,   171,   569,   569,   114,  -162,   114,  -162,  -162,  -162,
     114,   276,  -162,   420,   445,   171,   545,   113,  -162,  -162,
    -162,   258,   114,   251,   283,   113,  -162,   308,  -162,   250,
    -162,  -162,  -162,    -9,   279,  -162,   171,   114,  -162,  -162,
    -162,   171,  -162,   569,   171,  -162,  -162
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     2,     5,
       7,     0,    80,    84,    88,    90,    92,     0,     1,     0,
       4,     6,     0,    22,     0,     0,    22,     0,     0,    22,
       0,    22,     0,    22,    22,     0,   100,    95,    96,    97,
      98,    99,     0,     0,     0,    81,     0,     0,     0,     0,
       0,     0,    20,     0,    85,     0,     0,    89,     0,    91,
       0,    93,     0,     0,     0,    29,     0,   114,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    26,    27,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    30,     0,     0,     0,   117,   102,   112,   113,   106,
     107,   111,   110,   109,   108,   103,   104,   105,    10,    21,
       0,    12,     0,    14,    16,    18,     8,    32,     3,   101,
       0,   119,   115,   116,    35,    82,    35,    86,    35,    35,
      35,    35,    35,    31,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    60,     0,     0,     0,     0,
      51,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    80,    84,    88,    90,    92,
       0,     0,     0,     0,     0,     0,    68,    69,    77,     0,
      11,    54,    34,    48,    49,    50,   120,     0,    13,     0,
      15,    17,    19,     9,    33,     0,     0,    94,     0,     0,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    55,    83,     0,    87,     0,    62,    70,
      71,    72,    73,   101,   119,     0,     0,    36,     0,     0,
      66,     0,   121,    37,     0,    79,     0,    52,    53,    58,
       0,     0,    56,     0,     0,     0,     0,    43,    63,    76,
      59,     0,     0,     0,     0,    43,    42,     0,    61,     0,
      46,    67,    41,     0,     0,    44,    35,     0,    39,    40,
      64,    35,    47,    38,     0,    45,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,   335,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,    84,   265,   162,  -162,   248,  -162,  -127,  -162,
    -162,  -162,    72,  -162,  -162,  -162,  -162,  -161,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,    16,  -162,  -162,  -162,
     -22,   188
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     7,    19,     8,     9,    10,   141,   134,   136,   138,
     139,   140,    51,    52,    99,   100,   160,   142,   161,   162,
     216,   284,   274,   275,   291,   276,   286,   163,   251,   193,
     265,   194,   254,   277,   294,   261,   164,   167,   169,   165,
     166,   207
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   201,    12,    54,    22,    25,    57,   287,    59,   168,
      61,   170,   171,   172,   173,   174,    11,    65,    18,    89,
      67,    68,    71,    90,    66,    11,    92,    28,    30,    32,
      90,   288,   289,   230,    82,    83,   202,    36,    37,    38,
      39,    40,    41,   101,   102,    22,    24,    27,    13,    25,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    29,    31,    33,    72,    14,    42,    36,    37,
      38,    39,    40,    41,    69,    70,   234,   235,    43,    15,
      23,   132,   133,    44,    26,   198,    16,    24,    94,    95,
     262,    27,    90,    90,    81,    82,    83,    17,    42,    46,
      47,    48,    49,    50,   270,    21,   176,    96,   143,    43,
      55,    90,    97,    58,    44,    60,    90,    62,    63,    36,
      37,    38,    39,    40,    41,    35,   177,   178,   179,   180,
     181,   182,    53,   296,   236,   235,    34,   199,   272,   273,
      56,   183,    64,    84,    85,   206,    86,   206,   184,    42,
      87,    88,    91,    93,   217,   218,   219,   220,   221,   292,
      43,   101,   225,    98,   295,    44,   118,   103,   226,   104,
     228,   120,   121,   231,   144,   122,   145,    37,    38,    39,
      40,    41,   146,   147,   148,   149,   150,   123,   129,   151,
     152,   153,   185,   154,   155,   156,   124,   125,   157,   158,
       1,     2,     3,     4,     5,   126,    42,   248,   127,   130,
     135,   137,   175,   252,   159,   253,   186,    43,   187,   188,
     189,   190,    44,   191,   192,   127,   195,    72,   215,   196,
     197,     6,   263,   200,   264,   203,   204,   222,   266,    73,
      74,    75,    76,    77,    78,   208,   210,    72,   211,   212,
     279,   213,   214,   223,    79,    80,    81,    82,    83,    73,
      74,    75,    76,    77,    78,   293,   227,    72,    28,   131,
      30,    32,   229,   237,    79,    80,    81,    82,    83,    73,
      74,    75,    76,    77,    78,   233,   238,    72,   243,   244,
     246,   249,   255,   256,    79,    80,    81,    82,    83,    73,
      74,    75,    76,    77,    78,    72,   257,   285,   280,   258,
     260,   278,    72,   283,    79,    80,    81,    82,    83,    75,
      76,    77,    78,   205,    73,    74,    75,    76,    77,    78,
     267,   290,    79,    80,    81,    82,    83,    72,   281,    79,
      80,    81,    82,    83,    20,   224,   128,   282,   232,    73,
      74,    75,    76,    77,    78,   119,     0,   209,     0,     0,
       0,     0,    72,     0,    79,    80,    81,    82,    83,     0,
       0,     0,     0,   239,    73,    74,    75,    76,    77,    78,
       0,     0,     0,     0,     0,     0,     0,    72,     0,    79,
      80,    81,    82,    83,     0,     0,     0,     0,   240,    73,
      74,    75,    76,    77,    78,     0,     0,     0,     0,     0,
       0,     0,    72,     0,    79,    80,    81,    82,    83,     0,
       0,     0,     0,   241,    73,    74,    75,    76,    77,    78,
       0,     0,     0,     0,     0,     0,     0,    72,     0,    79,
      80,    81,    82,    83,     0,     0,     0,     0,   242,    73,
      74,    75,    76,    77,    78,     0,     0,     0,     0,     0,
       0,     0,    72,     0,    79,    80,    81,    82,    83,     0,
       0,     0,     0,   268,    73,    74,    75,    76,    77,    78,
       0,     0,     0,     0,     0,     0,     0,    72,     0,    79,
      80,    81,    82,    83,     0,     0,    72,     0,   269,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
      72,     0,   105,    79,    80,    81,    82,    83,     0,    72,
       0,   245,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,    72,     0,   247,    79,    80,    81,    82,
      83,     0,    72,     0,   250,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,    72,     0,   259,    79,
      80,    81,    82,    83,    72,     0,     0,   271,    73,    74,
      75,    76,    77,    78,     0,     0,    73,     0,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,     0,     0,
       0,    79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      22,   162,     5,    25,    16,    16,    28,    16,    30,   136,
      32,   138,   139,   140,   141,   142,     0,    51,     0,    52,
      42,    43,    44,    56,    58,     9,    52,    16,    16,    16,
      56,    40,    41,   194,    47,    48,   163,     5,     6,     7,
       8,     9,    10,    65,    66,    16,    58,    58,     5,    16,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    51,    51,    51,    17,     5,    35,     5,     6,
       7,     8,     9,    10,    11,    12,    55,    56,    46,     5,
      51,   103,   104,    51,    51,    53,     5,    58,    52,    52,
     251,    58,    56,    56,    46,    47,    48,     5,    35,    11,
      12,    13,    14,    15,   265,    53,    16,    52,   130,    46,
      26,    56,    52,    29,    51,    31,    56,    33,    34,     5,
       6,     7,     8,     9,    10,     4,    36,    37,    38,    39,
      40,    41,     6,   294,    55,    56,    51,   159,    25,    26,
       6,    51,    51,     5,     5,   167,     5,   169,    58,    35,
       5,     5,    59,    59,   176,   177,   178,   179,   180,   286,
      46,   183,   184,    52,   291,    51,    54,    52,   190,    52,
     192,    16,    54,   195,     3,    16,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    54,    52,    18,
      19,    20,     5,    22,    23,    24,    54,    54,    27,    28,
      11,    12,    13,    14,    15,    54,    35,   229,    54,    56,
      54,    54,    51,   235,    43,   237,     5,    46,     5,     5,
       5,    51,    51,    51,    51,    54,    51,    17,     5,    53,
      53,    42,   254,    55,   256,    53,    53,    53,   260,    29,
      30,    31,    32,    33,    34,    55,    55,    17,    55,    55,
     272,    55,    55,    53,    44,    45,    46,    47,    48,    29,
      30,    31,    32,    33,    34,   287,     5,    17,    16,    59,
      16,    16,    51,    16,    44,    45,    46,    47,    48,    29,
      30,    31,    32,    33,    34,    21,    53,    17,    52,    59,
      52,    22,    53,    16,    44,    45,    46,    47,    48,    29,
      30,    31,    32,    33,    34,    17,    53,    57,    57,    53,
      51,    53,    17,     5,    44,    45,    46,    47,    48,    31,
      32,    33,    34,    53,    29,    30,    31,    32,    33,    34,
      54,    52,    44,    45,    46,    47,    48,    17,    55,    44,
      45,    46,    47,    48,     9,   183,    98,   275,    53,    29,
      30,    31,    32,    33,    34,    90,    -1,   169,    -1,    -1,
      -1,    -1,    17,    -1,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    17,    -1,    53,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    44,    45,    46,    47,    48,    -1,
      17,    -1,    52,    44,    45,    46,    47,    48,    -1,    17,
      -1,    52,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    44,    45,    46,
      47,    48,    -1,    17,    -1,    52,    44,    45,    46,    47,
      48,    -1,    17,    -1,    52,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      44,    45,    46,    47,    48,    -1,    17,    -1,    52,    44,
      45,    46,    47,    48,    17,    -1,    -1,    52,    29,    30,
      31,    32,    33,    34,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    -1,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    13,    14,    15,    42,    61,    63,    64,
      65,    96,     5,     5,     5,     5,     5,     5,     0,    62,
      63,    53,    16,    51,    58,    16,    51,    58,    16,    51,
      16,    51,    16,    51,    51,     4,     5,     6,     7,     8,
       9,    10,    35,    46,    51,   100,    11,    12,    13,    14,
      15,    72,    73,     6,   100,    72,     6,   100,    72,   100,
      72,   100,    72,    72,    51,    51,    58,   100,   100,    11,
      12,   100,    17,    29,    30,    31,    32,    33,    34,    44,
      45,    46,    47,    48,     5,     5,     5,     5,     5,    52,
      56,    59,    52,    59,    52,    52,    52,    52,    52,    74,
      75,   100,   100,    52,    52,    52,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,    54,    73,
      16,    54,    16,    54,    54,    54,    54,    54,    76,    52,
      56,    59,   100,   100,    67,    54,    68,    54,    69,    70,
      71,    66,    77,   100,     3,     5,    11,    12,    13,    14,
      15,    18,    19,    20,    22,    23,    24,    27,    28,    43,
      76,    78,    79,    87,    96,    99,   100,    97,    78,    98,
      78,    78,    78,    78,    78,    51,    16,    36,    37,    38,
      39,    40,    41,    51,    58,     5,     5,     5,     5,     5,
      51,    51,    51,    89,    91,    51,    53,    53,    53,   100,
      55,    87,    78,    53,    53,    53,   100,   101,    55,   101,
      55,    55,    55,    55,    55,     5,    80,   100,   100,   100,
     100,   100,    53,    53,    74,   100,   100,     5,   100,    51,
      87,   100,    53,    21,    55,    56,    55,    16,    53,    53,
      53,    53,    53,    52,    59,    52,    52,    52,   100,    22,
      52,    88,   100,   100,    92,    53,    16,    53,    53,    52,
      51,    95,    87,   100,   100,    90,   100,    54,    53,    53,
      87,    52,    25,    26,    82,    83,    85,    93,    53,   100,
      57,    55,    82,     5,    81,    57,    86,    16,    40,    41,
      52,    84,    78,   100,    94,    78,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    62,    61,    63,    63,    64,    64,    66,    65,
      67,    65,    68,    65,    69,    65,    70,    65,    71,    65,
      72,    72,    72,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    77,    76,    78,    78,    79,    80,    81,    81,
      81,    82,    82,    82,    84,    83,    86,    85,    87,    87,
      87,    87,    87,    87,    87,    88,    87,    89,    90,    87,
      91,    87,    92,    93,    94,    87,    95,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      96,    96,    97,    96,    96,    96,    98,    96,    96,    96,
      96,    96,    96,    96,    99,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     2,     1,     0,     9,
       0,     9,     0,     9,     0,     9,     0,     9,     0,     9,
       1,     3,     0,     2,     2,     2,     2,     2,     1,     0,
       1,     3,     0,     4,     2,     0,     4,     3,     3,     2,
       2,     2,     1,     0,     0,     5,     0,     4,     2,     2,
       2,     1,     5,     5,     2,     0,     5,     0,     0,     7,
       0,     8,     0,     0,     0,    12,     0,     8,     2,     2,
       4,     4,     4,     4,     3,     3,     7,     2,     3,     5,
       2,     4,     0,    10,     2,     4,     0,    10,     2,     4,
       2,     4,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     4,     4,     3,     2,     4,
       1,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* $@1: %empty  */
#line 82 "sin.y"
                             { 
        strcpy(instrucoes_globais, instrucoes);
        instrucoes[0] = '\0';
    }
#line 1733 "sin.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 98 "sin.y"
                                              {
            // 1. Salva o TAC global gerado até agora e limpa pro corpo da função
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 

            inserir_funcao((yyvsp[-4].valor_str), T_VOID, escopo_atual);
            
            sprintf(buf, "\nvoid %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nvoid %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         }
#line 1753 "sin.tab.c"
    break;

  case 9: /* funcao: TOKEN_VOID ID '(' parametros ')' '{' $@2 comandos_bloco '}'  */
#line 112 "sin.y"
                              {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            // 2. Salva a função pronta e limpa para o próximo elemento global
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
#line 1769 "sin.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 123 "sin.y"
                                             {
            // 1. Salva o TAC global gerado até agora e limpa pro corpo da função
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 

            inserir_funcao((yyvsp[-4].valor_str), T_INT, escopo_atual);
            
            sprintf(buf, "\nint %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nint %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         }
#line 1789 "sin.tab.c"
    break;

  case 11: /* funcao: TOKEN_INT ID '(' parametros ')' '{' $@3 comandos_bloco '}'  */
#line 137 "sin.y"
                              {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            // 2. Salva a função pronta e limpa para o próximo elemento global
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
#line 1805 "sin.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 148 "sin.y"
                                                 {
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 
            
            inserir_funcao((yyvsp[-4].valor_str), T_FLOAT, escopo_atual);
            
            sprintf(buf, "\nfloat %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nfloat %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         }
#line 1824 "sin.tab.c"
    break;

  case 13: /* funcao: TOKEN_FLOAT ID '(' parametros ')' '{' $@4 comandos_bloco '}'  */
#line 161 "sin.y"
                              {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
#line 1839 "sin.tab.c"
    break;

  case 14: /* $@5: %empty  */
#line 171 "sin.y"
                                                {
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 
            
            inserir_funcao((yyvsp[-4].valor_str), T_CHAR, escopo_atual);
            
            sprintf(buf, "\nchar %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nchar %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         }
#line 1858 "sin.tab.c"
    break;

  case 15: /* funcao: TOKEN_CHAR ID '(' parametros ')' '{' $@5 comandos_bloco '}'  */
#line 184 "sin.y"
                              {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
#line 1873 "sin.tab.c"
    break;

  case 16: /* $@6: %empty  */
#line 194 "sin.y"
                                                {
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 
            
            inserir_funcao((yyvsp[-4].valor_str), T_BOOL, escopo_atual);
            
            sprintf(buf, "\nint %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nint %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         }
#line 1892 "sin.tab.c"
    break;

  case 17: /* funcao: TOKEN_BOOL ID '(' parametros ')' '{' $@6 comandos_bloco '}'  */
#line 207 "sin.y"
                              {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
#line 1907 "sin.tab.c"
    break;

  case 18: /* $@7: %empty  */
#line 217 "sin.y"
                                                {
            strcat(instrucoes_globais, instrucoes);
            instrucoes[0] = '\0'; 
            
            inserir_funcao((yyvsp[-4].valor_str), T_STRING, escopo_atual);
            
            sprintf(buf, "\nchar* %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "\nchar* %s(%s) {\n", (yyvsp[-4].valor_str), (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
            
            escopo_atual++;
         }
#line 1926 "sin.tab.c"
    break;

  case 19: /* funcao: TOKEN_STRING ID '(' parametros ')' '{' $@7 comandos_bloco '}'  */
#line 230 "sin.y"
                              {
            strcat(instrucoes, "}\n"); 
            strcat(c_body, "}\n");
            
            strcat(instrucoes_funcoes, instrucoes);
            instrucoes[0] = '\0'; 
            
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
         }
#line 1941 "sin.tab.c"
    break;

  case 20: /* parametros: parametro  */
#line 243 "sin.y"
                       { (yyval.info) = (yyvsp[0].info); }
#line 1947 "sin.tab.c"
    break;

  case 21: /* parametros: parametros ',' parametro  */
#line 244 "sin.y"
                                      {
                (yyval.info).temp = (char*) malloc(strlen((yyvsp[-2].info).temp) + strlen((yyvsp[0].info).temp) + 5);
                sprintf((yyval.info).temp, "%s, %s", (yyvsp[-2].info).temp, (yyvsp[0].info).temp);

                (yyval.info).c_expr = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 5);
                sprintf((yyval.info).c_expr, "%s, %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
           }
#line 1959 "sin.tab.c"
    break;

  case 22: /* parametros: %empty  */
#line 251 "sin.y"
                         { 
                (yyval.info).temp = strdup(""); 
                (yyval.info).c_expr = strdup(""); 
           }
#line 1968 "sin.tab.c"
    break;

  case 23: /* parametro: TOKEN_INT ID  */
#line 257 "sin.y"
                         {
                Simbolo* s = inserir((yyvsp[0].valor_str), T_INT, escopo_atual + 1);
                (yyval.info).temp = (char*) malloc(50);
                sprintf((yyval.info).temp, "int %s", s->temp); 
                (yyval.info).c_expr = (char*) malloc(50);
                sprintf((yyval.info).c_expr, "int %s", s->nome);
            }
#line 1980 "sin.tab.c"
    break;

  case 24: /* parametro: TOKEN_FLOAT ID  */
#line 264 "sin.y"
                           {
                Simbolo* s = inserir((yyvsp[0].valor_str), T_FLOAT, escopo_atual + 1);
                (yyval.info).temp = (char*) malloc(50);
                sprintf((yyval.info).temp, "float %s", s->temp); 
                (yyval.info).c_expr = (char*) malloc(50);
                sprintf((yyval.info).c_expr, "float %s", s->nome);
            }
#line 1992 "sin.tab.c"
    break;

  case 25: /* parametro: TOKEN_STRING ID  */
#line 271 "sin.y"
                            {
                Simbolo* s = inserir((yyvsp[0].valor_str), T_STRING, escopo_atual + 1);
                (yyval.info).temp = (char*) malloc(50);
                // Strings em C são passadas como ponteiros (char*)
                sprintf((yyval.info).temp, "char* %s", s->temp); 
                (yyval.info).c_expr = (char*) malloc(50);
                sprintf((yyval.info).c_expr, "char* %s", s->nome);
            }
#line 2005 "sin.tab.c"
    break;

  case 26: /* parametro: TOKEN_CHAR ID  */
#line 279 "sin.y"
                          {
                Simbolo* s = inserir((yyvsp[0].valor_str), T_CHAR, escopo_atual + 1);
                (yyval.info).temp = (char*) malloc(50);
                sprintf((yyval.info).temp, "char %s", s->temp); 
                (yyval.info).c_expr = (char*) malloc(50);
                sprintf((yyval.info).c_expr, "char %s", s->nome);
            }
#line 2017 "sin.tab.c"
    break;

  case 27: /* parametro: TOKEN_BOOL ID  */
#line 286 "sin.y"
                          {
                Simbolo* s = inserir((yyvsp[0].valor_str), T_BOOL, escopo_atual + 1);
                (yyval.info).temp = (char*) malloc(50);
                // Booleano na sua linguagem vira int no C gerado
                sprintf((yyval.info).temp, "int %s", s->temp); 
                (yyval.info).c_expr = (char*) malloc(50);
                sprintf((yyval.info).c_expr, "int %s", s->nome);
            }
#line 2030 "sin.tab.c"
    break;

  case 28: /* argumentos: lista_args  */
#line 297 "sin.y"
                        { (yyval.info) = (yyvsp[0].info); }
#line 2036 "sin.tab.c"
    break;

  case 29: /* argumentos: %empty  */
#line 298 "sin.y"
                         { 
                (yyval.info).temp = strdup(""); 
                (yyval.info).c_expr = strdup(""); 
           }
#line 2045 "sin.tab.c"
    break;

  case 30: /* lista_args: expressao  */
#line 304 "sin.y"
                       {
                (yyval.info).temp = strdup((yyvsp[0].info).temp);
                (yyval.info).c_expr = strdup((yyvsp[0].info).c_expr);
           }
#line 2054 "sin.tab.c"
    break;

  case 31: /* lista_args: lista_args ',' expressao  */
#line 308 "sin.y"
                                      {
                (yyval.info).temp = (char*) malloc(strlen((yyvsp[-2].info).temp) + strlen((yyvsp[0].info).temp) + 5);
                sprintf((yyval.info).temp, "%s, %s", (yyvsp[-2].info).temp, (yyvsp[0].info).temp);

                (yyval.info).c_expr = (char*) malloc(strlen((yyvsp[-2].info).c_expr) + strlen((yyvsp[0].info).c_expr) + 5);
                sprintf((yyval.info).c_expr, "%s, %s", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
           }
#line 2066 "sin.tab.c"
    break;

  case 32: /* $@8: %empty  */
#line 317 "sin.y"
            { escopo_atual++; }
#line 2072 "sin.tab.c"
    break;

  case 33: /* bloco: '{' $@8 comandos_bloco '}'  */
#line 317 "sin.y"
                                                   {
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
        }
#line 2081 "sin.tab.c"
    break;

  case 36: /* if_cond: TOKEN_IF '(' expressao ')'  */
#line 328 "sin.y"
                                     {
    if ((yyvsp[-1].info).tipo_val != T_BOOL) {
        yyerror("Erro Semantico: A condicao do 'if' deve ser booleana.");
    }
    char* l_false = novo_label();
    
    /* --- INICIO DA MODIFICACAO --- */
    char* t_inv = novo_temp(T_BOOL);
    
    // 1. Nega o resultado original
    sprintf(buf, "%s = !%s;\n", t_inv, (yyvsp[-1].info).temp);
    strcat(instrucoes, buf);
    
    // 2. Verifica se a negacao eh verdadeira para pular
    sprintf(buf, "if (%s) goto %s;\n", t_inv, l_false);
    strcat(instrucoes, buf);

    strcat(instrucoes, "\n");
    /* --- FIM DA MODIFICACAO --- */
    
    sprintf(buf, "if (%s) {\n", (yyvsp[-1].info).c_expr);
    strcat(c_body, buf);
    
    (yyval.valor_str) = l_false; /* Passa o label pra frente */
}
#line 2111 "sin.tab.c"
    break;

  case 37: /* for_init: ID ASSIGN expressao  */
#line 356 "sin.y"
                               {
    Simbolo *s = buscar((yyvsp[-2].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada na inicializacao do for.");
    } else {
        // Gera o 3AC direto
        sprintf(buf, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
        strcat(instrucoes, buf);
        
        // Em vez de imprimir no C, retorna a string formatada
        char* init_str = (char*) malloc(256);
        sprintf(init_str, "%s = %s", s->nome, (yyvsp[0].info).c_expr);
        (yyval.valor_str) = init_str;
    }
}
#line 2131 "sin.tab.c"
    break;

  case 38: /* incremento_for: ID ASSIGN expressao  */
#line 373 "sin.y"
                                     {
    Simbolo *s = buscar((yyvsp[-2].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
    } else {
        sprintf(inc_3ac, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s = %s", s->nome, (yyvsp[0].info).c_expr);
        (yyval.valor_str) = inc_str;
    }
}
#line 2147 "sin.tab.c"
    break;

  case 39: /* incremento_for: ID INC  */
#line 384 "sin.y"
         {
    Simbolo *s = buscar((yyvsp[-1].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
    } else {
        // Gera o 3AC somando 1
        sprintf(inc_3ac, "%s = %s + 1;\n", s->temp, s->temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s++", s->nome);
        (yyval.valor_str) = inc_str;
    }
}
#line 2164 "sin.tab.c"
    break;

  case 40: /* incremento_for: ID DEC  */
#line 396 "sin.y"
         {
    Simbolo *s = buscar((yyvsp[-1].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada no decremento do for.");
    } else {
        sprintf(inc_3ac, "%s = %s - 1;\n", s->temp, s->temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s--", s->nome);
        (yyval.valor_str) = inc_str;
    }
}
#line 2180 "sin.tab.c"
    break;

  case 44: /* @9: %empty  */
#line 414 "sin.y"
                                {
        // 1. Gera rótulo pro próximo case (se este falhar)
        char* l_proximo = novo_label();

        // 2. Compara a expressão do Switch com a expressão do Case
        char* t_cmp = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\n", t_cmp, switch_exp, (yyvsp[-1].info).temp);
        strcat(instrucoes, buf);

        /* --- INICIO DA MODIFICACAO --- */
        char* t_inv = novo_temp(T_BOOL);
        
        // 3. Nega a comparacao
        sprintf(buf, "%s = !%s;\n", t_inv, t_cmp);
        strcat(instrucoes, buf);

        // 4. Se a negacao for verdadeira, pula pro proximo case
        sprintf(buf, "if (%s) goto %s;\n", t_inv, l_proximo);
        strcat(instrucoes, buf);
        /* --- FIM DA MODIFICACAO --- */

        // 5. Código C
        sprintf(buf, "case %s:\n", (yyvsp[-1].info).c_expr);
        strcat(c_body, buf);

        (yyval.valor_str) = l_proximo;

    }
#line 2213 "sin.tab.c"
    break;

  case 45: /* caso: TOKEN_CASE expressao ':' @9 comandos_bloco  */
#line 441 "sin.y"
                     {

        // 5. Fim do case: pula pro fim do switch
        sprintf(buf, "goto %s;\n", switch_fim);
        strcat(instrucoes, buf);

        // 6. Imprime o rótulo do próximo case
        sprintf(buf, "%s:\n", (yyvsp[-1].valor_str));
        strcat(instrucoes, buf);
    }
#line 2228 "sin.tab.c"
    break;

  case 46: /* $@10: %empty  */
#line 453 "sin.y"
                                 {
        strcat(c_body, "default:\n");
    }
#line 2236 "sin.tab.c"
    break;

  case 47: /* default_caso: TOKEN_DEFAULT ':' $@10 comandos_bloco  */
#line 455 "sin.y"
                     {
        // O default não precisa de break nem de desvios no 3AC, ele só termina.
    }
#line 2244 "sin.tab.c"
    break;

  case 52: /* comando: TOKEN_PRINT '(' expressao ')' ';'  */
#line 465 "sin.y"
        {
            // Descobre o formato para o printf do C
            char* formato = "";
            if ((yyvsp[-2].info).tipo_val == T_INT || (yyvsp[-2].info).tipo_val == T_BOOL) formato = "%d";
            else if ((yyvsp[-2].info).tipo_val == T_FLOAT) formato = "%f";
            else if ((yyvsp[-2].info).tipo_val == T_CHAR) formato = "%c";
            else if ((yyvsp[-2].info).tipo_val == T_STRING) formato = "%s";

            // Gera o Código Intermediário já como printf válido no C
            sprintf(buf, "printf(\"%s\\n\", %s);\n", formato, (yyvsp[-2].info).temp);
            strcat(instrucoes, buf);
        }
#line 2261 "sin.tab.c"
    break;

  case 53: /* comando: TOKEN_READ '(' ID ')' ';'  */
#line 478 "sin.y"
                                        {
                Simbolo *s = buscar((yyvsp[-2].valor_str));
                if (!s) {
                    char erro_msg[100];
                    sprintf(erro_msg, "Erro: Variavel '%s' nao declarada para leitura.", (yyvsp[-2].valor_str));
                    yyerror(erro_msg);
                } else {
                    // 1. Descobre o formato para o scanf do C
                    char* formato = "";
                    if (s->tipo == T_INT || s->tipo == T_BOOL) formato = "%d";
                    else if (s->tipo == T_FLOAT) formato = "%f";
                    else if (s->tipo == T_CHAR) formato = " %c"; 

                    // 2. Gera o scanf correspondente direto na variável 'instrucoes'
                    if (s->tipo == T_STRING) {
                        // Limita o scanf a 255 letras para evitar que estoure o array de 256
                        sprintf(buf, "scanf(\"%%255s\", %s);\n", s->temp);
                        strcat(instrucoes, buf);
                    } else {
                        sprintf(buf, "scanf(\"%s\", &%s);\n", formato, s->temp);
                        strcat(instrucoes, buf); 
                    }
                }
            }
#line 2290 "sin.tab.c"
    break;

  case 54: /* comando: if_cond comando  */
#line 502 "sin.y"
                          {
            // IF SIMPLES (Sem else)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); // Puxa o rótulo do if_cond
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 2301 "sin.tab.c"
    break;

  case 55: /* @11: %empty  */
#line 508 "sin.y"
                                     {
            // METADE DO ELSE
            char* l_fim = novo_label();
            
            // 1. O 'true' pula pro fim
            sprintf(buf, "goto %s;\n", l_fim);
            strcat(instrucoes, buf);
            
            // 2. Imprime o label do 'false' (que veio do if_cond)
            sprintf(buf, "%s:\n", (yyvsp[-2].valor_str));
            strcat(instrucoes, buf);
            
            // 3. Código C
            strcat(c_body, "} else {\n");
            
            // Passa o label de fim para o próximo bloco
            (yyval.valor_str) = l_fim; 
            
        }
#line 2325 "sin.tab.c"
    break;

  case 56: /* comando: if_cond comando TOKEN_ELSE @11 comando  */
#line 526 "sin.y"
                  {
            // FIM DO ELSE
            // Imprime o label de fim (que veio do bloco anterior)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 2337 "sin.tab.c"
    break;

  case 57: /* @12: %empty  */
#line 533 "sin.y"
                      {
            strcat(instrucoes, "\n");
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; 
            
            // --- LINHA NOVA 1: Salva o início na pilha ---
            strcpy(pilha_inicio[topo_laco], l_inicio);
            
        }
#line 2353 "sin.tab.c"
    break;

  case 58: /* @13: %empty  */
#line 543 "sin.y"
                            {
            if ((yyvsp[-1].info).tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao deve ser booleana.");
            
            char* l_fim = novo_label();
            
            /* --- INICIO DA MODIFICACAO --- */
            char* t_inv = novo_temp(T_BOOL);
            
            sprintf(buf, "%s = !%s;\n", t_inv, (yyvsp[-1].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "if (%s) goto %s;\n", t_inv, l_fim);
            strcat(instrucoes, buf);

            strcat(instrucoes, "\n");
            /* --- FIM DA MODIFICACAO --- */
            
            sprintf(buf, "while (%s) {\n", (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);
            (yyval.valor_str) = l_fim; 
            
            // --- LINHAS NOVAS 2 e 3: Salva o fim e sobe a pilha ---
            strcpy(pilha_fim[topo_laco], l_fim);
            topo_laco++;
        }
#line 2383 "sin.tab.c"
    break;

  case 59: /* comando: TOKEN_WHILE @12 '(' expressao ')' @13 comando  */
#line 567 "sin.y"
                  { 
            
            // 1. Desce o topo da pilha para recuperar os labels deste laço
            topo_laco--; 
            
            // 2. No final do bloco, o TAC precisa voltar para o início do teste condicional
            sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco]);
            strcat(instrucoes, buf);
            
            // 3. Imprime o rótulo de FIM (O L2 que estava faltando!)
            sprintf(buf, "%s:\n", pilha_fim[topo_laco]);
            strcat(instrucoes, buf);
            
            // 4. Fecha as chaves do bloco no código C
            strcat(c_body, "}\n");
        }
#line 2404 "sin.tab.c"
    break;

  case 60: /* @14: %empty  */
#line 583 "sin.y"
                   {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio;
            strcat(c_body, "do {\n");
        }
#line 2416 "sin.tab.c"
    break;

  case 61: /* comando: TOKEN_DO @14 comando TOKEN_WHILE '(' expressao ')' ';'  */
#line 589 "sin.y"
                                                    {
            // Agora a expressao é o $6, porque:
            // 1=TOKEN_DO, 2={...}, 3=comando, 4=WHILE, 5='(', 6=expressao
            
            if ((yyvsp[-2].info).tipo_val != T_BOOL) {
                yyerror("Erro Semantico: A condicao do 'do-while' deve ser booleana.");
            }
            
            // Pula para o início se for verdadeiro
            sprintf(buf, "if (%s) goto %s;\n", (yyvsp[-2].info).temp, (yyvsp[-6].valor_str));
            strcat(instrucoes, buf);
            
            // Código C
            sprintf(buf, "} while (%s);\n", (yyvsp[-2].info).c_expr);
            strcat(c_body, buf);
        }
#line 2437 "sin.tab.c"
    break;

  case 62: /* @15: %empty  */
#line 605 "sin.y"
                                     {
            // 1. Marca visualmente no 3AC que é um FOR
            strcat(instrucoes, "\n");
            char* l_inicio = novo_label();
            char* l_inc = novo_label();
            
            // [REMOVIDO] char* l_incremento = novo_label(); 
            
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio;
            
            // ALTERAÇÃO: Como não há mais l_incremento, o 'continue' 
            // terá que pular para o início do laço.
            strcpy(pilha_inicio[topo_laco], l_inc);
            
        }
#line 2459 "sin.tab.c"
    break;

  case 63: /* @16: %empty  */
#line 621 "sin.y"
                        {
            // 2. Verifica a CONDIÇÃO
            if ((yyvsp[-1].info).tipo_val != T_BOOL) {
                yyerror("Erro Semantico: A condicao do 'for' deve ser booleana.");
            }
            char* l_fim = novo_label();
            
            /* --- INICIO DA MODIFICACAO (TAC INVERSO) --- */
            char* t_inv = novo_temp(T_BOOL);
            sprintf(buf, "%s = !%s;\n", t_inv, (yyvsp[-1].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "if (%s) goto %s;\n", t_inv, l_fim);
            strcat(instrucoes, buf);
            /* --- FIM DA MODIFICACAO --- */
            
            (yyval.valor_str) = l_fim; // Salva na posição $8
            
            // Salva o fim na pilha para o 'break' e sobe a pilha
            strcpy(pilha_fim[topo_laco], l_fim);
            topo_laco++; 
            
            // GERA O 'FOR' LITERAL NO CÓDIGO C
            sprintf(buf, "for (%s; %s; ", (yyvsp[-4].valor_str), (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);
            
        }
#line 2491 "sin.tab.c"
    break;

  case 64: /* $@17: %empty  */
#line 647 "sin.y"
                             {
            // 3. Fecha os parênteses do FOR no C
            sprintf(buf, "%s) {\n", (yyvsp[-1].valor_str));
            strcat(c_body, buf);
            
        }
#line 2502 "sin.tab.c"
    break;

  case 65: /* comando: TOKEN_FOR '(' for_init ';' @15 expressao ';' @16 incremento_for ')' $@17 comando  */
#line 652 "sin.y"
                  {
            // 4. Chegamos no final do laço!
            topo_laco--; // Desce a pilha de laços
            
            // [REMOVIDO] O sprintf que imprimia o pilha_inicio (L2) foi apagado aqui!
            
            // Imprime o incremento do 3AC que estava guardado direto
            sprintf(buf, "%s:\n", pilha_inicio[topo_laco]);
            strcat(instrucoes, buf);
            
            strcat(instrucoes, inc_3ac);
            
            // Pula de volta pro início (A condicional no $5) no 3AC
            sprintf(buf, "goto %s;\n", (yyvsp[-7].valor_str));
            strcat(instrucoes, buf);
            
            // Marca o rótulo de FIM (L3 que agora será equivalente ao L2) no 3AC
            sprintf(buf, "%s:\n", (yyvsp[-4].valor_str));
            strcat(instrucoes, buf);
            strcat(instrucoes, "\n");
            
            // Fecha a chave no C
            strcat(c_body, "}\n");
        }
#line 2531 "sin.tab.c"
    break;

  case 66: /* $@18: %empty  */
#line 676 "sin.y"
                                        {
            // Marca que entrou em um switch
            dentro_switch++;

            // Salva a expressão do switch e o label de saída
            strcpy(switch_exp, (yyvsp[-1].info).temp);
            strcpy(switch_fim, novo_label());

            strcpy(pilha_fim[topo_laco], switch_fim);
            strcpy(pilha_inicio[topo_laco], "ERRO_CONTINUE_SWITCH");
            topo_laco++;

            // Código C
            sprintf(buf, "switch (%s) {\n", (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);

        }
#line 2553 "sin.tab.c"
    break;

  case 67: /* comando: TOKEN_SWITCH '(' expressao ')' $@18 '{' casos_lista '}'  */
#line 692 "sin.y"
                              {

            // Saiu do switch
            dentro_switch--;

            topo_laco--;

            // Label de saída do switch no código intermediário
            sprintf(buf, "%s:\n", switch_fim);
            strcat(instrucoes, buf);

            // Fecha o switch no C
            strcat(c_body, "}\n");
        }
#line 2572 "sin.tab.c"
    break;

  case 68: /* comando: TOKEN_BREAK ';'  */
#line 707 "sin.y"
                          {

            if (topo_laco > 0) {

                // break dentro de while/for/do-while
                sprintf(buf, "goto %s;\n", pilha_fim[topo_laco - 1]);
                strcat(instrucoes, buf);

            } else if (dentro_switch > 0) {

                // break dentro de switch
                sprintf(buf, "goto %s;\n", switch_fim);
                strcat(instrucoes, buf);

            } else {

                yyerror("Erro Semantico: 'break' usado fora de um laco ou switch.");

            }

            strcat(c_body, "break;\n");
        }
#line 2599 "sin.tab.c"
    break;

  case 69: /* comando: TOKEN_CONTINUE ';'  */
#line 729 "sin.y"
                             {
            if (topo_laco == 0) {
                yyerror("Erro Semantico: 'continue' usado fora de um laco de repeticao.");
            } else {
                // Pula para o rótulo de INÍCIO do laço atual
                sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco - 1]);
                strcat(instrucoes, buf);
                strcat(c_body, "continue;\n");
            }
        }
#line 2614 "sin.tab.c"
    break;

  case 70: /* comando: ID PLUS_ASSIGN expressao ';'  */
#line 739 "sin.y"
                                       {
                Simbolo *s = buscar((yyvsp[-3].valor_str));
                if (!s) yyerror("Erro: Variavel nao declarada.");
                else if (s->tipo != (yyvsp[-1].info).tipo_val) yyerror("Erro Semantico: Tipos incompativeis.");
                else {
                    // TAC: temp = x + expr
                    char* t_op = novo_temp(s->tipo);
                    sprintf(buf, "%s = %s + %s;\n", t_op, s->temp, (yyvsp[-1].info).temp);
                    strcat(instrucoes, buf);
                    // Atribuição: x = temp
                    sprintf(buf, "%s = %s;\n", s->temp, t_op);
                    strcat(instrucoes, buf);
                    // C
                    sprintf(buf, "%s += %s;\n", s->nome, (yyvsp[-1].info).c_expr);
                    strcat(c_body, buf);
                }
            }
#line 2636 "sin.tab.c"
    break;

  case 71: /* comando: ID MINUS_ASSIGN expressao ';'  */
#line 756 "sin.y"
                                            {
                Simbolo *s = buscar((yyvsp[-3].valor_str));
                if (!s) yyerror("Erro: Variavel nao declarada.");
                else if (s->tipo != (yyvsp[-1].info).tipo_val) yyerror("Erro Semantico: Tipos incompativeis.");
                else {
                    char* t_op = novo_temp(s->tipo);
                    sprintf(buf, "%s = %s - %s;\n", t_op, s->temp, (yyvsp[-1].info).temp);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s = %s;\n", s->temp, t_op);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s -= %s;\n", s->nome, (yyvsp[-1].info).c_expr);
                    strcat(c_body, buf);
                }
            }
#line 2655 "sin.tab.c"
    break;

  case 72: /* comando: ID MULT_ASSIGN expressao ';'  */
#line 770 "sin.y"
                                           {
            Simbolo *s = buscar((yyvsp[-3].valor_str));
            if (!s) yyerror("Erro: Variavel nao declarada.");
            else if (s->tipo != (yyvsp[-1].info).tipo_val) yyerror("Erro Semantico: Tipos incompativeis.");
            else {
                char* t_op = novo_temp(s->tipo);
                sprintf(buf, "%s = %s * %s;\n", t_op, s->temp, (yyvsp[-1].info).temp);
                strcat(instrucoes, buf);
                sprintf(buf, "%s = %s;\n", s->temp, t_op);
                strcat(instrucoes, buf);
                sprintf(buf, "%s *= %s;\n", s->nome, (yyvsp[-1].info).c_expr);
                strcat(c_body, buf);
            }
        }
#line 2674 "sin.tab.c"
    break;

  case 73: /* comando: ID DIV_ASSIGN expressao ';'  */
#line 784 "sin.y"
                                      {
            Simbolo *s = buscar((yyvsp[-3].valor_str));
            if (!s) yyerror("Erro: Variavel nao declarada.");
            else if (s->tipo != (yyvsp[-1].info).tipo_val) yyerror("Erro Semantico: Tipos incompativeis.");
            else {
                char* t_op = novo_temp(s->tipo);
                sprintf(buf, "%s = %s / %s;\n", t_op, s->temp, (yyvsp[-1].info).temp);
                strcat(instrucoes, buf);
                sprintf(buf, "%s = %s;\n", s->temp, t_op);
                strcat(instrucoes, buf);
                sprintf(buf, "%s /= %s;\n", s->nome, (yyvsp[-1].info).c_expr);
                strcat(c_body, buf);
            }
        }
#line 2693 "sin.tab.c"
    break;

  case 74: /* comando: ID INC ';'  */
#line 798 "sin.y"
                     {
            Simbolo *s = buscar((yyvsp[-2].valor_str));
            if (!s) yyerror("Erro: Variavel nao declarada para incremento.");
            else {
                // Atualiza o valor no TAC (x = x + 1)
                sprintf(buf, "%s = %s + 1;\n", s->temp, s->temp);
                strcat(instrucoes, buf);
                
                // Transpila para C
                sprintf(buf, "%s++;\n", s->nome);
                strcat(c_body, buf);
            }
        }
#line 2711 "sin.tab.c"
    break;

  case 75: /* comando: ID DEC ';'  */
#line 811 "sin.y"
                     {
            Simbolo *s = buscar((yyvsp[-2].valor_str));
            if (!s) yyerror("Erro: Variavel nao declarada para decremento.");
            else {
                // Atualiza o valor no TAC (x = x - 1)
                sprintf(buf, "%s = %s - 1;\n", s->temp, s->temp);
                strcat(instrucoes, buf);
                
                // Transpila para C
                sprintf(buf, "%s--;\n", s->nome);
                strcat(c_body, buf);
            }
        }
#line 2729 "sin.tab.c"
    break;

  case 76: /* comando: ID '[' expressao ']' ASSIGN expressao ';'  */
#line 824 "sin.y"
                                                    {
            Simbolo *s = buscar((yyvsp[-6].valor_str));
            if (!s) yyerror("Erro: Matriz nao declarada.");
            else if (!s->array) yyerror("Erro: Variavel nao e uma matriz.");
            else if ((yyvsp[-4].info).tipo_val != T_INT) yyerror("Erro Semantico: Indice da matriz deve ser inteiro.");
            else {
                char* valor_final  = (yyvsp[-1].info).temp;
                char* c_expr_final = (yyvsp[-1].info).c_expr;
                int sem_erro = 1;

                if (s->tipo == T_FLOAT && (yyvsp[-1].info).tipo_val == T_INT) {
                    valor_final = gerar_cast((yyvsp[-1].info).temp, T_FLOAT);
                    char *tmp = (char*) malloc(256);
                    sprintf(tmp, "(float)(%s)", c_expr_final);
                    c_expr_final = tmp;
                } else if (s->tipo == T_INT && (yyvsp[-1].info).tipo_val == T_FLOAT) {
                    valor_final = gerar_cast((yyvsp[-1].info).temp, T_INT);
                    char *tmp = (char*) malloc(256);
                    sprintf(tmp, "(int)(%s)", c_expr_final);
                    c_expr_final = tmp;
                } else if (s->tipo != (yyvsp[-1].info).tipo_val) {
                    yyerror("Erro Semantico: Atribuicao com tipo incompativel na matriz.");
                    sem_erro = 0;
                }

                if (sem_erro) {
                    sprintf(buf, "%s[%s] = %s;\n", s->temp, (yyvsp[-4].info).temp, valor_final);
                    strcat(instrucoes, buf);
                    sprintf(buf, "%s[%s] = %s;\n", s->temp, (yyvsp[-4].info).c_expr, c_expr_final);
                    strcat(c_body, buf);
                }
            }
        }
#line 2767 "sin.tab.c"
    break;

  case 77: /* comando: TOKEN_RETURN ';'  */
#line 857 "sin.y"
                           {
            strcat(instrucoes, "return;\n");
            strcat(c_body, "return;\n");
        }
#line 2776 "sin.tab.c"
    break;

  case 78: /* comando: TOKEN_RETURN expressao ';'  */
#line 861 "sin.y"
                                     {
            sprintf(buf, "return %s;\n", (yyvsp[-1].info).temp);
            strcat(instrucoes, buf);
            
            sprintf(buf, "return %s;\n", (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);
        }
#line 2788 "sin.tab.c"
    break;

  case 79: /* comando: ID '(' argumentos ')' ';'  */
#line 868 "sin.y"
                                    {
            Simbolo *s = buscar((yyvsp[-4].valor_str));
            if (!s) { yyerror("Erro: Funcao nao declarada."); } 
            else if (s->cat != C_FUNC) { yyerror("Erro: Nao e funcao."); } 
            else {
                
                // Manda o $3.temp pros argumentos do TAC
                sprintf(buf, "%s(%s);\n", s->temp, (yyvsp[-2].info).temp);
                strcat(instrucoes, buf);
                
                sprintf(buf, "%s(%s);\n", s->nome, (yyvsp[-2].info).c_expr);
                strcat(c_body, buf);
            }
        }
#line 2807 "sin.tab.c"
    break;

  case 80: /* declaracao: TOKEN_INT ID  */
#line 883 "sin.y"
                          {
                // DECLARAÇÃO SIMPLES (Já existia)
                inserir((yyvsp[0].valor_str), T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 2818 "sin.tab.c"
    break;

  case 81: /* declaracao: TOKEN_INT ID ASSIGN expressao  */
#line 889 "sin.y"
                                           {
                // DECLARAÇÃO COM INICIALIZAÇÃO (Novo)
                inserir((yyvsp[-2].valor_str), T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", (yyvsp[-2].valor_str));
                strcat(c_decl, buf);

                Simbolo *s = buscar((yyvsp[-2].valor_str));
                char* valor_final = (yyvsp[0].info).temp;
                char* c_expr_final = (yyvsp[0].info).c_expr;

                // Verificação de tipo (Cast de float para int)
                if ((yyvsp[0].info).tipo_val == T_FLOAT) {
                    valor_final = gerar_cast((yyvsp[0].info).temp, T_INT);
                    char *tmp = (char*) malloc(256);
                    strcpy(tmp, "(int)(");
                    strcat(tmp, c_expr_final);
                    strcat(tmp, ")");
                    c_expr_final = tmp;
                } else if ((yyvsp[0].info).tipo_val != T_INT) {
                    yyerror("Erro Semantico: Inicializacao de 'int' com tipo incompativel.");
                }

                // Gera o TAC e o código C da atribuição
                sprintf(buf, "%s = %s;\n", s->temp, valor_final);
                strcat(instrucoes, buf);
                
                sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
                strcat(c_body, buf);
             }
#line 2852 "sin.tab.c"
    break;

  case 82: /* $@19: %empty  */
#line 919 "sin.y"
                                                   {
                int tamanho = atoi((yyvsp[-3].valor_str));
                inserir_array((yyvsp[-5].valor_str), T_INT, escopo_atual, tamanho);
                
                // Configura o estado para a regra lista_valores usar
                simbolo_array_atual = buscar((yyvsp[-5].valor_str));
                tam_array_atual = tamanho;
                idx_array_atual = 0;
           }
#line 2866 "sin.tab.c"
    break;

  case 83: /* declaracao: TOKEN_INT ID '[' NUM_INT ']' ASSIGN '{' $@19 lista_valores '}'  */
#line 927 "sin.y"
                               {
                // Limpa o estado após terminar a inicialização
                simbolo_array_atual = NULL; 
           }
#line 2875 "sin.tab.c"
    break;

  case 84: /* declaracao: TOKEN_FLOAT ID  */
#line 932 "sin.y"
                          {
                // DECLARAÇÃO SIMPLES
                inserir((yyvsp[0].valor_str), T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 2886 "sin.tab.c"
    break;

  case 85: /* declaracao: TOKEN_FLOAT ID ASSIGN expressao  */
#line 938 "sin.y"
                                             {
                // DECLARAÇÃO COM INICIALIZAÇÃO
                inserir((yyvsp[-2].valor_str), T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", (yyvsp[-2].valor_str));
                strcat(c_decl, buf);

                Simbolo *s = buscar((yyvsp[-2].valor_str));
                char* valor_final = (yyvsp[0].info).temp;
                char* c_expr_final = (yyvsp[0].info).c_expr;

                // Verificação de tipo (Cast de int para float)
                if ((yyvsp[0].info).tipo_val == T_INT) {
                    valor_final = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                    char *tmp = (char*) malloc(256);
                    strcpy(tmp, "(float)(");
                    strcat(tmp, c_expr_final);
                    strcat(tmp, ")");
                    c_expr_final = tmp;
                } else if ((yyvsp[0].info).tipo_val != T_FLOAT) {
                    yyerror("Erro Semantico: Inicializacao de 'float' com tipo incompativel.");
                }

                sprintf(buf, "%s = %s;\n", s->temp, valor_final);
                strcat(instrucoes, buf);
                
                sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
                strcat(c_body, buf);
             }
#line 2919 "sin.tab.c"
    break;

  case 86: /* $@20: %empty  */
#line 967 "sin.y"
                                                     {
                int tamanho = atoi((yyvsp[-3].valor_str));
                inserir_array((yyvsp[-5].valor_str), T_FLOAT, escopo_atual, tamanho);
                
                simbolo_array_atual = buscar((yyvsp[-5].valor_str));
                tam_array_atual = tamanho;
                idx_array_atual = 0;
           }
#line 2932 "sin.tab.c"
    break;

  case 87: /* declaracao: TOKEN_FLOAT ID '[' NUM_INT ']' ASSIGN '{' $@20 lista_valores '}'  */
#line 974 "sin.y"
                               {
                simbolo_array_atual = NULL;
           }
#line 2940 "sin.tab.c"
    break;

  case 88: /* declaracao: TOKEN_CHAR ID  */
#line 978 "sin.y"
                         {
                inserir((yyvsp[0].valor_str), T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 2950 "sin.tab.c"
    break;

  case 89: /* declaracao: TOKEN_CHAR ID ASSIGN expressao  */
#line 983 "sin.y"
                                            {
                inserir((yyvsp[-2].valor_str), T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", (yyvsp[-2].valor_str));
                strcat(c_decl, buf);

                Simbolo *s = buscar((yyvsp[-2].valor_str));
                if ((yyvsp[0].info).tipo_val != T_CHAR) {
                    yyerror("Erro Semantico: Inicializacao de 'char' com tipo incompativel.");
                } else {
                    // TAC
                    sprintf(buf, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    // C
                    sprintf(buf, "%s = %s;\n", s->nome, (yyvsp[0].info).c_expr);
                    strcat(c_body, buf);
                }
             }
#line 2972 "sin.tab.c"
    break;

  case 90: /* declaracao: TOKEN_BOOL ID  */
#line 1001 "sin.y"
                         {
                 inserir((yyvsp[0].valor_str), T_BOOL, escopo_atual);
                 sprintf(buf, "int %s;\n", (yyvsp[0].valor_str));
                 strcat(c_decl, buf);
             }
#line 2982 "sin.tab.c"
    break;

  case 91: /* declaracao: TOKEN_BOOL ID ASSIGN expressao  */
#line 1006 "sin.y"
                                            {
                 inserir((yyvsp[-2].valor_str), T_BOOL, escopo_atual);
                 sprintf(buf, "int %s;\n", (yyvsp[-2].valor_str));
                 strcat(c_decl, buf);

                 Simbolo *s = buscar((yyvsp[-2].valor_str));
                 if ((yyvsp[0].info).tipo_val != T_BOOL) {
                     yyerror("Erro Semantico: Inicializacao de 'boolean' com tipo incompativel.");
                 } else {
                     // TAC
                     sprintf(buf, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
                     strcat(instrucoes, buf);
                     // C
                     sprintf(buf, "%s = %s;\n", s->nome, (yyvsp[0].info).c_expr);
                     strcat(c_body, buf);
                 }
             }
#line 3004 "sin.tab.c"
    break;

  case 92: /* declaracao: TOKEN_STRING ID  */
#line 1024 "sin.y"
                           {
                inserir((yyvsp[0].valor_str), T_STRING, escopo_atual);
                sprintf(buf, "char %s[256];\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 3014 "sin.tab.c"
    break;

  case 93: /* declaracao: TOKEN_STRING ID ASSIGN expressao  */
#line 1029 "sin.y"
                                              {
                inserir((yyvsp[-2].valor_str), T_STRING, escopo_atual);
                sprintf(buf, "char %s[256];\n", (yyvsp[-2].valor_str));
                strcat(c_decl, buf);

                Simbolo *s = buscar((yyvsp[-2].valor_str));
                if ((yyvsp[0].info).tipo_val != T_STRING) {
                    yyerror("Erro Semantico: Inicializacao de 'string' com tipo incompativel.");
                } else {
                    // Atualiza o tamanho no array de temporarios
                    int id_temp;
                    sscanf(s->temp, "T%d", &id_temp);
                    tamanhos_t[id_temp] = (yyvsp[0].info).tam_str;

                    // TAC usando strcpy
                    sprintf(buf, "strcpy(%s, %s);\n", s->temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    
                    // C usando strcpy
                    sprintf(buf, "strcpy(%s, %s);\n", s->nome, (yyvsp[0].info).c_expr);
                    strcat(c_body, buf);
                }
             }
#line 3042 "sin.tab.c"
    break;

  case 94: /* atribuicao: ID ASSIGN expressao  */
#line 1054 "sin.y"
                                 {
    Simbolo *s = buscar((yyvsp[-2].valor_str));
    if (!s) {
        char erro_msg[100];
        sprintf(erro_msg, "Erro: Variavel '%s' nao declarada.", (yyvsp[-2].valor_str));
        yyerror(erro_msg);
    } else {
        char* valor_final  = (yyvsp[0].info).temp;
        char* c_expr_final = (yyvsp[0].info).c_expr;
        int sem_erro = 1;

        if (s->tipo == T_FLOAT && (yyvsp[0].info).tipo_val == T_INT) {
            valor_final = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
            char *tmp = (char*) malloc(256);
            strcpy(tmp, "(float)(");
            strcat(tmp, c_expr_final);
                strcat(tmp, ")");
            c_expr_final = tmp;

        } else if (s->tipo == T_INT && (yyvsp[0].info).tipo_val == T_FLOAT) {
        valor_final = gerar_cast((yyvsp[0].info).temp, T_INT);
        char *tmp = (char*) malloc(256);
        strcpy(tmp, "(int)(");
        strcat(tmp, c_expr_final);
        strcat(tmp, ")");
        c_expr_final = tmp;

        } else if (s->tipo != (yyvsp[0].info).tipo_val) {
            yyerror("Erro Semantico: Atribuicao com tipos incompativeis.");
            sem_erro = 0;
        }

        if (sem_erro) {
            if (s->tipo == T_STRING) {
                int id_temp;

                sscanf(s->temp, "T%d", &id_temp); 

                tamanhos_t[id_temp] = (yyvsp[0].info).tam_str;

                sprintf(buf, "strcpy(%s, %s);\n", s->temp, valor_final);
            } else {
                sprintf(buf, "%s = %s;\n", s->temp, valor_final);
            }
            strcat(instrucoes, buf);

            // Código C original
            if (s->tipo == T_STRING) {
                sprintf(buf, "strcpy(%s, %s);\n", s->nome, c_expr_final);
            } else {
                sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
            }
            strcat(c_body, buf);
        }
    }
}
#line 3103 "sin.tab.c"
    break;

  case 95: /* expressao: NUM_INT  */
#line 1111 "sin.y"
                    {
                (yyval.info).tipo_val = T_INT;
                (yyval.info).temp = strdup((yyvsp[0].valor_str));
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
            }
#line 3113 "sin.tab.c"
    break;

  case 96: /* expressao: NUM_FLOAT  */
#line 1116 "sin.y"
                      {
                (yyval.info).tipo_val = T_FLOAT;
                (yyval.info).temp   = novo_temp(T_FLOAT);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 3125 "sin.tab.c"
    break;

  case 97: /* expressao: CHAR_LIT  */
#line 1123 "sin.y"
                     {
                (yyval.info).tipo_val = T_CHAR;
                (yyval.info).temp   = novo_temp(T_CHAR);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 3137 "sin.tab.c"
    break;

  case 98: /* expressao: BOOL_LIT  */
#line 1130 "sin.y"
                     {
                (yyval.info).tipo_val = T_BOOL;
                (yyval.info).temp   = novo_temp(T_BOOL);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 3149 "sin.tab.c"
    break;

  case 99: /* expressao: STRING_LIT  */
#line 1137 "sin.y"
                         {
                (yyval.info).tipo_val = T_STRING;
                int tamanho_calculado = strlen((yyvsp[0].valor_str)) - 1; 
                (yyval.info).tam_str = tamanho_calculado;
                (yyval.info).temp = novo_temp_str(tamanho_calculado);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "strcpy(%s, %s);\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 3163 "sin.tab.c"
    break;

  case 100: /* expressao: ID  */
#line 1146 "sin.y"
               {
                Simbolo *s = buscar((yyvsp[0].valor_str));
                if (s) {
                    (yyval.info).tipo_val = s->tipo;
                    (yyval.info).temp   = s->temp;
                    (yyval.info).c_expr = strdup(s->nome);

                    if (s->tipo == T_STRING) {
                        int id_temp;
                        sscanf(s->temp, "T%d", &id_temp);
                        (yyval.info).tam_str = tamanhos_t[id_temp]; 
                    } else {
                        (yyval.info).tam_str = 0;
                    }
                    
                } else {
                    yyerror("Var nao declarada");
                    (yyval.info).temp   = "ERRO";
                    (yyval.info).c_expr = strdup("ERRO");
                    (yyval.info).tipo_val = T_INT;
                    (yyval.info).tam_str = 0;
                }
            }
#line 3191 "sin.tab.c"
    break;

  case 101: /* expressao: ID '(' argumentos ')'  */
#line 1169 "sin.y"
                                    {
                Simbolo *s = buscar((yyvsp[-3].valor_str));
                if (!s) { yyerror("Erro: Funcao nao declarada."); (yyval.info).tipo_val = T_INT; (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); } 
                else if (s->cat != C_FUNC) { yyerror("Erro: Nao e funcao."); (yyval.info).tipo_val = T_INT; (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); } 
                else if (s->tipo == T_VOID) { yyerror("Erro: Funcao VOID."); (yyval.info).tipo_val = T_INT; (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); } 
                else {
                    (yyval.info).tipo_val = s->tipo;
                    (yyval.info).temp = novo_temp(s->tipo);
                    
                    // Manda o $3.temp pros argumentos do TAC
                    sprintf(buf, "%s = %s(%s);\n", (yyval.info).temp, s->temp, (yyvsp[-1].info).temp);
                    strcat(instrucoes, buf);
                    
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "%s(%s)", s->nome, (yyvsp[-1].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3214 "sin.tab.c"
    break;

  case 102: /* expressao: expressao PLUS expressao  */
#line 1189 "sin.y"
                                     {
                // 1. Caso: String (String + String)
                if ((yyvsp[-2].info).tipo_val == T_STRING && (yyvsp[0].info).tipo_val == T_STRING) {
                    (yyval.info).tipo_val = T_STRING;

                    int tamanho_soma = (yyvsp[-2].info).tam_str + (yyvsp[0].info).tam_str - 1;
                    (yyval.info).tam_str = tamanho_soma;

                    (yyval.info).temp = novo_temp_str(tamanho_soma);

                    sprintf(buf, "strcpy(%s, %s);\n"
                                 "strcat(%s, %s);\n", 
                                 (yyval.info).temp, (yyvsp[-2].info).temp, 
                                 (yyval.info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    
                    char *ce = (char*) malloc(tamanho_soma);
                    sprintf(ce, "(%s + %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;

                    free((yyvsp[-2].info).c_expr);
                    free((yyvsp[0].info).c_expr);
                }
                // 2. Caso: Numérico (Int ou Float)
                else if (((yyvsp[-2].info).tipo_val == T_INT || (yyvsp[-2].info).tipo_val == T_FLOAT) && 
                        ((yyvsp[0].info).tipo_val == T_INT || (yyvsp[0].info).tipo_val == T_FLOAT)) {
                    
                    char *ce1 = (yyvsp[-2].info).c_expr;
                    char *ce3 = (yyvsp[0].info).c_expr;

                    if ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) {
                        (yyval.info).tipo_val = T_FLOAT;
                    } else {
                        (yyval.info).tipo_val = T_INT;
                    }

                    if ((yyval.info).tipo_val == T_FLOAT) {
                        if ((yyvsp[-2].info).tipo_val == T_INT) {
                            (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce1);
                            ce1 = tmp;
                        }
                        if ((yyvsp[0].info).tipo_val == T_INT) {
                            (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce3);
                            ce3 = tmp;
                        }
                    }

                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s + %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);

                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s + %s)", ce1, ce3);
                    (yyval.info).c_expr = ce;
                }
                // 3. Caso: Tipos incompatíveis (Erro Semântico)
                else {
                    yyerror("Erro Semantico: Operacao de soma com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                }
            }
#line 3284 "sin.tab.c"
    break;

  case 103: /* expressao: expressao '-' expressao  */
#line 1254 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de subtracao com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                    if ((yyvsp[-2].info).tipo_val != (yyvsp[0].info).tipo_val) {
                        if ((yyvsp[-2].info).tipo_val == T_INT) {
                            (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT); (yyvsp[-2].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT); (yyvsp[0].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s - %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);

                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s - %s)", ce1, ce3);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3317 "sin.tab.c"
    break;

  case 104: /* expressao: expressao '*' expressao  */
#line 1282 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de multiplicacao com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                    // Só converte se os tipos forem DIFERENTES
                    if ((yyvsp[-2].info).tipo_val != (yyvsp[0].info).tipo_val) {
                        if ((yyvsp[-2].info).tipo_val == T_INT) {
                            (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
                            (yyvsp[-2].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                            (yyvsp[0].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s * %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s * %s)", ce1, ce3);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3352 "sin.tab.c"
    break;

  case 105: /* expressao: expressao '/' expressao  */
#line 1312 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de divisao com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                    
                    // Só converte se os tipos forem DIFERENTES
                    if ((yyvsp[-2].info).tipo_val != (yyvsp[0].info).tipo_val) {
                        if ((yyvsp[-2].info).tipo_val == T_INT) {
                            (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
                            (yyvsp[-2].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce1); ce1 = tmp;
                        } else {
                            (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                            (yyvsp[0].info).tipo_val = T_FLOAT;
                            char *tmp = (char*) malloc(256);
                            sprintf(tmp, "(float)(%s)", ce3); ce3 = tmp;
                        }
                    }
                    
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    
                    // TAC
                    sprintf(buf, "%s = %s / %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    
                    // Código C (Corrigido de '+' para '/')
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s / %s)", ce1, ce3);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3393 "sin.tab.c"
    break;

  case 106: /* expressao: expressao EQ expressao  */
#line 1350 "sin.y"
                                   {
                if (((yyvsp[-2].info).tipo_val == T_BOOL && (yyvsp[0].info).tipo_val != T_BOOL) ||
                    ((yyvsp[-2].info).tipo_val != T_BOOL && (yyvsp[0].info).tipo_val == T_BOOL)) {
                    yyerror("Erro Semantico: Comparacao '==' entre tipos incompativeis.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s == %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s == %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3413 "sin.tab.c"
    break;

  case 107: /* expressao: expressao NE expressao  */
#line 1365 "sin.y"
                                   {
                if (((yyvsp[-2].info).tipo_val == T_BOOL && (yyvsp[0].info).tipo_val != T_BOOL) ||
                    ((yyvsp[-2].info).tipo_val != T_BOOL && (yyvsp[0].info).tipo_val == T_BOOL)) {
                    yyerror("Erro Semantico: Comparacao '!=' entre tipos incompativeis.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s != %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s < %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3433 "sin.tab.c"
    break;

  case 108: /* expressao: expressao '>' expressao  */
#line 1380 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '>' exige operandos numericos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s > %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                   char *ce = (char*) malloc(256);
                   sprintf(ce, "(%s > %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3453 "sin.tab.c"
    break;

  case 109: /* expressao: expressao '<' expressao  */
#line 1395 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '<' exige operandos numericos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s < %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s < %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3473 "sin.tab.c"
    break;

  case 110: /* expressao: expressao GE expressao  */
#line 1410 "sin.y"
                                   {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '>=' exige operandos numericos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s >= %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s >= %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3493 "sin.tab.c"
    break;

  case 111: /* expressao: expressao LE expressao  */
#line 1425 "sin.y"
                                   {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operador '<=' exige operandos numericos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s <= %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s <= %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3513 "sin.tab.c"
    break;

  case 112: /* expressao: expressao AND expressao  */
#line 1442 "sin.y"
                                    {
                if ((yyvsp[-2].info).tipo_val != T_BOOL || (yyvsp[0].info).tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador AND requer operandos booleanos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s && %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s && %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3532 "sin.tab.c"
    break;

  case 113: /* expressao: expressao OR expressao  */
#line 1456 "sin.y"
                                   {
                if ((yyvsp[-2].info).tipo_val != T_BOOL || (yyvsp[0].info).tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador OR requer operandos booleanos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = %s || %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s || %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3551 "sin.tab.c"
    break;

  case 114: /* expressao: NOT expressao  */
#line 1470 "sin.y"
                          {
                if ((yyvsp[0].info).tipo_val != T_BOOL) {
                    yyerror("Erro Semantico: Operador NOT requer operando booleano.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_BOOL;
                } else {
                    (yyval.info).tipo_val = T_BOOL;
                    (yyval.info).temp = novo_temp(T_BOOL);
                    sprintf(buf, "%s = !%s;\n", (yyval.info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    char *ce = (char*) malloc(200);
                    sprintf(ce, "(!%s)", (yyvsp[0].info).c_expr);
                     (yyval.info).c_expr = ce;
                }
            }
#line 3570 "sin.tab.c"
    break;

  case 115: /* expressao: '(' TOKEN_INT ')' expressao  */
#line 1485 "sin.y"
                                                                     {
                        char* temp_copia = novo_temp((yyvsp[0].info).tipo_val);
                        sprintf(buf, "%s = %s;\n", temp_copia, (yyvsp[0].info).temp);
                        strcat(instrucoes, buf);

                        (yyval.info).tipo_val = T_INT;
                        (yyval.info).temp = novo_temp(T_INT);

                        sprintf(buf, "%s = (int) %s;\n", (yyval.info).temp, temp_copia);
                        strcat(instrucoes, buf);

                        char *ce = (char*) malloc(256);

                        strcpy(ce, "(int)(");
                        strcat(ce, (yyvsp[0].info).c_expr);
                        strcat(ce, ")");

                        (yyval.info).c_expr = ce;
                    }
#line 3594 "sin.tab.c"
    break;

  case 116: /* expressao: '(' TOKEN_FLOAT ')' expressao  */
#line 1504 "sin.y"
                                                               {
                char* temp_copia = novo_temp((yyvsp[0].info).tipo_val);
                sprintf(buf, "%s = %s;\n", temp_copia, (yyvsp[0].info).temp);
                strcat(instrucoes, buf);

                (yyval.info).tipo_val = T_FLOAT;
                (yyval.info).temp = novo_temp(T_FLOAT);

                sprintf(buf, "%s = (float) %s;\n", (yyval.info).temp, temp_copia);
                strcat(instrucoes, buf);

                char *ce = (char*) malloc(256);

                strcpy(ce, "(float)(");
                strcat(ce, (yyvsp[0].info).c_expr);
                strcat(ce, ")");

                (yyval.info).c_expr = ce;
            }
#line 3618 "sin.tab.c"
    break;

  case 117: /* expressao: '(' expressao ')'  */
#line 1523 "sin.y"
                              {
                (yyval.info) = (yyvsp[-1].info);
            }
#line 3626 "sin.tab.c"
    break;

  case 118: /* expressao: '-' expressao  */
#line 1526 "sin.y"
                                                 {
                (yyval.info).tipo_val = (yyvsp[0].info).tipo_val;
                (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                sprintf(buf, "%s = -%s;\n", (yyval.info).temp, (yyvsp[0].info).temp);
                strcat(instrucoes, buf);

                char *ce = (char*) malloc(256);

                strcpy(ce, "(-");
                strcat(ce, (yyvsp[0].info).c_expr);
                strcat(ce, ")");

                (yyval.info).c_expr = ce;
            }
#line 3645 "sin.tab.c"
    break;

  case 119: /* expressao: ID '[' expressao ']'  */
#line 1541 "sin.y"
                                 {
                Simbolo *s = buscar((yyvsp[-3].valor_str));
                if (!s) {
                    yyerror("Erro: Matriz nao declarada.");
                    (yyval.info).tipo_val = T_INT; (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO");
                } else if (!s->array) {
                    yyerror("Erro: Variavel nao e uma matriz.");
                    (yyval.info).tipo_val = T_INT; (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO");
                } else if ((yyvsp[-1].info).tipo_val != T_INT) {
                    yyerror("Erro Semantico: Indice da matriz deve ser inteiro.");
                    (yyval.info).tipo_val = T_INT; (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO");
                } else {
                    (yyval.info).tipo_val = s->tipo;
                    (yyval.info).temp = novo_temp(s->tipo);
                    
                    // TAC: T_novo = vetor[T_indice]
                    sprintf(buf, "%s = %s[%s];\n", (yyval.info).temp, s->temp, (yyvsp[-1].info).temp);
                    strcat(instrucoes, buf);
                    
                    // Codigo C
                    char *ce = (char*) malloc(256);
                    sprintf(ce, "%s[%s]", s->temp, (yyvsp[-1].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
            }
#line 3675 "sin.tab.c"
    break;

  case 120: /* lista_valores: expressao  */
#line 1568 "sin.y"
                                    {
        if (simbolo_array_atual) {
            if (idx_array_atual < tam_array_atual) {
                // Checagem estrita de tipo (você pode adicionar casts aqui depois, se quiser)
                if (simbolo_array_atual->tipo != (yyvsp[0].info).tipo_val) {
                    yyerror("Erro Semantico: Tipo incompativel na inicializacao da matriz.");
                } else {
                    // TAC
                    sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->temp, idx_array_atual, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    // C Transpilado
                    sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->nome, idx_array_atual, (yyvsp[0].info).c_expr);
                    strcat(c_body, buf);
                    
                    idx_array_atual++;
                }
            } else {
                yyerror("Erro Semantico: Excesso de elementos na inicializacao da matriz.");
            }
        }
    }
#line 3701 "sin.tab.c"
    break;

  case 121: /* lista_valores: lista_valores ',' expressao  */
#line 1589 "sin.y"
                                  {
        if (simbolo_array_atual) {
            if (idx_array_atual < tam_array_atual) {
                if (simbolo_array_atual->tipo != (yyvsp[0].info).tipo_val) {
                    yyerror("Erro Semantico: Tipo incompativel na inicializacao da matriz.");
                } else {
                    // TAC
                    sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->temp, idx_array_atual, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);
                    // C Transpilado
                    sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->nome, idx_array_atual, (yyvsp[0].info).c_expr);
                    strcat(c_body, buf);
                    
                    idx_array_atual++;
                }
            } else {
                yyerror("Erro Semantico: Excesso de elementos na inicializacao da matriz.");
            }
        }
    }
#line 3726 "sin.tab.c"
    break;


#line 3730 "sin.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1611 "sin.y"


#include <stdlib.h> // Necessário para a função system()

int main() {
    yyparse();
    if (houve_erro) {
        return 1;
    }

    gerar_declaracoes_finais();

    /* 1. VISUALIZAÇÃO DO CÓDIGO INTERMEDIÁRIO (Terminal) */
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    printf("#include <string.h>\n");
    printf("#include <stdbool.h>\n\n");
    
    // Globais e Funções SEMPRE antes do main
    printf("%s", declaracoes);
    printf("%s\n", instrucoes_funcoes);

    printf("int main()\n{\n");
    printf("%s", instrucoes_globais);
    printf("%s", instrucoes);
    printf("    return 0;\n");
    printf("}\n");

    /* 2. GERAÇÃO DO CÓDIGO (Arquivo saida.c) */
    FILE *arquivo_c = fopen("saida.c", "w");
    if (!arquivo_c) {
        printf("Erro: Nao foi possivel criar o arquivo saida.c\n");
        return 1;
    }

    fprintf(arquivo_c, "#include <stdio.h>\n");
    fprintf(arquivo_c, "#include <stdlib.h>\n");
    fprintf(arquivo_c, "#include <string.h>\n");
    fprintf(arquivo_c, "#include <stdbool.h>\n\n");
    
    // Globais e Funções SEMPRE antes do main no arquivo C também
    fprintf(arquivo_c, "%s", declaracoes);
    fprintf(arquivo_c, "%s\n", instrucoes_funcoes);
    
    fprintf(arquivo_c, "int main()\n{\n");
    fprintf(arquivo_c, "%s", instrucoes_globais);
    fprintf(arquivo_c, "%s", instrucoes);
    fprintf(arquivo_c, "    return 0;\n}\n");

    fclose(arquivo_c);

    int status_gcc = system("gcc saida.c -o programa.exe");
    if (status_gcc != 0) {
        printf("Erro no compilador\n");
    }

    return 0;
}
