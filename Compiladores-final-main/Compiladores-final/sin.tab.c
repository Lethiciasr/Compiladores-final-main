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

int houve_erro = 0;
int dentro_switch = 0;
extern int yylex();
void yyerror(const char *s) {printf("Erro: %s\n", s);
houve_erro = 1;
}

char buf[200];
char c_decl[5000] = "";
char c_body[5000] = "";
char declaracoes_temp[5000] = "";
char inc_3ac[200] = "";
char inc_c[200] = "";   
char switch_exp[50] = "";
char switch_fim[50] = "";
char pilha_inicio[20][50];
char pilha_fim[20][50];
int topo_laco = 0;

int escopo_atual = 0;

#line 100 "sin.tab.c"

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
  YYSYMBOL_36_ = 36,                       /* '<'  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_CAST = 41,                      /* CAST  */
  YYSYMBOL_UMINUS = 42,                    /* UMINUS  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_programa = 50,                  /* programa  */
  YYSYMBOL_declaracoes_globais = 51,       /* declaracoes_globais  */
  YYSYMBOL_bloco = 52,                     /* bloco  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_comandos_bloco = 54,            /* comandos_bloco  */
  YYSYMBOL_if_cond = 55,                   /* if_cond  */
  YYSYMBOL_for_init = 56,                  /* for_init  */
  YYSYMBOL_incremento_for = 57,            /* incremento_for  */
  YYSYMBOL_casos_lista = 58,               /* casos_lista  */
  YYSYMBOL_caso = 59,                      /* caso  */
  YYSYMBOL_60_2 = 60,                      /* @2  */
  YYSYMBOL_default_caso = 61,              /* default_caso  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_comando = 63,                   /* comando  */
  YYSYMBOL_64_4 = 64,                      /* @4  */
  YYSYMBOL_65_5 = 65,                      /* @5  */
  YYSYMBOL_66_6 = 66,                      /* @6  */
  YYSYMBOL_67_7 = 67,                      /* @7  */
  YYSYMBOL_68_8 = 68,                      /* @8  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_70_10 = 70,                     /* $@10  */
  YYSYMBOL_declaracao = 71,                /* declaracao  */
  YYSYMBOL_atribuicao = 72,                /* atribuicao  */
  YYSYMBOL_expressao = 73                  /* expressao  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      43,    44,    39,     2,     2,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    45,
      36,     2,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    68,    69,    72,    72,    78,    79,    83,
     111,   128,   144,   145,   146,   149,   149,   188,   188,   195,
     196,   197,   198,   199,   213,   241,   247,   247,   272,   272,
     307,   307,   329,   340,   366,   329,   390,   390,   415,   437,
     448,   453,   458,   463,   468,   475,   517,   522,   529,   536,
     543,   550,   565,   607,   635,   667,   701,   716,   731,   746,
     761,   776,   793,   807,   821,   836,   855,   874,   877
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_FOR",
  "TOKEN_MAIN", "ID", "NUM_INT", "NUM_FLOAT", "CHAR_LIT", "BOOL_LIT",
  "STRING_LIT", "TOKEN_INT", "TOKEN_FLOAT", "TOKEN_CHAR", "TOKEN_BOOL",
  "TOKEN_STRING", "ASSIGN", "PLUS", "TOKEN_PRINT", "TOKEN_READ",
  "TOKEN_IF", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_DO", "TOKEN_SWITCH",
  "TOKEN_CASE", "TOKEN_DEFAULT", "TOKEN_BREAK", "TOKEN_CONTINUE", "AND",
  "OR", "EQ", "NE", "LE", "GE", "NOT", "'<'", "'>'", "'-'", "'*'", "'/'",
  "CAST", "UMINUS", "'('", "')'", "';'", "'{'", "'}'", "':'", "$accept",
  "programa", "declaracoes_globais", "bloco", "$@1", "comandos_bloco",
  "if_cond", "for_init", "incremento_for", "casos_lista", "caso", "@2",
  "default_caso", "$@3", "comando", "@4", "@5", "@6", "@7", "@8", "$@9",
  "$@10", "declaracao", "atribuicao", "expressao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,     8,    11,    25,    44,    47,    68,    69,    32,   -42,
     -42,   -42,   -42,   -42,   -42,    39,    -5,    40,   -42,    37,
     -42,   -42,    52,    43,    72,   -42,   -42,   -42,   -42,   -42,
      46,    48,    49,   -42,   -42,    51,    54,    55,   108,   108,
      13,   -42,    50,    52,    52,    56,    57,   124,    91,   108,
     108,    98,   108,    62,    52,   108,   -42,   -42,   -42,   -42,
     -42,    66,    67,   160,   -42,    85,   -42,   -42,   -42,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   -42,   103,    75,   268,   178,    83,   196,   108,   111,
     214,   108,   108,   -42,   -42,     4,   296,   286,   -12,   -12,
     -12,   -12,   -12,   -12,     4,   -42,   -42,   108,   -42,    89,
      90,   -42,   232,    93,   -42,   -42,   -42,    52,   268,   108,
     -42,   -42,   -42,   108,    96,   -42,   142,   250,    21,   -42,
      94,   108,    97,   100,    21,   -42,   132,   -42,    92,   -42,
     -42,   -42,   122,   104,   -42,    52,   108,   -42,    52,   -42,
     268,    52,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     1,     0,     4,     0,     3,     0,
       5,     2,     8,     0,    51,    46,    47,    48,    49,    50,
       0,     0,     0,    28,    30,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    51,    64,
      68,     0,     0,     0,     6,    25,     7,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    26,    52,    62,    63,    56,    57,
      61,    60,    59,    58,    53,    54,    55,     0,    32,     0,
       0,     9,     0,     0,    36,    65,    66,     0,    10,     0,
      23,    24,    29,     0,     0,    27,     0,     0,    14,    33,
       0,     0,     0,     0,    14,    13,     0,    31,     0,    17,
      37,    12,     0,     0,    15,     8,     0,    34,     8,    18,
      11,     0,    16,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   128,   130,   -42,   -41,   -42,   -42,   -42,    16,
     -42,   -42,   -42,   -42,   -39,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,    29,   -42,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    41,    22,    42,    43,    83,   143,   133,
     134,   148,   135,   145,    44,   117,    53,    54,   119,   136,
     151,   124,    45,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    60,    63,    66,    65,    69,     1,     2,     3,     4,
       5,    84,    85,     9,    87,    89,    10,    90,    58,    25,
      26,    27,    28,    29,    61,    62,    78,    79,    80,     8,
      11,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    79,    80,     8,   131,   132,    38,    12,
     112,    39,    13,   115,   116,    23,    40,    24,    25,    26,
      27,    28,    29,     1,     2,     3,     4,     5,    14,   118,
      30,    31,    32,    15,    33,    34,    35,    16,   125,    36,
      37,   126,    17,    20,    19,   127,    48,    38,    49,    50,
      39,    51,    52,   138,    55,    40,    82,    64,    20,    56,
      57,    67,    68,    86,   149,    88,    94,   152,   150,    69,
      91,    92,   153,    58,    25,    26,    27,    28,    29,   107,
     108,    70,    71,    72,    73,    74,    75,   110,    76,    77,
      78,    79,    80,   113,   120,   121,   123,   142,   146,   137,
     144,    69,   128,    38,    18,   139,    39,   140,   147,    21,
     141,    40,     0,    70,    71,    72,    73,    74,    75,    69,
      76,    77,    78,    79,    80,     0,     0,     0,     0,    81,
       0,    70,    71,    72,    73,    74,    75,    69,    76,    77,
      78,    79,    80,     0,     0,     0,     0,   129,     0,    70,
      71,    72,    73,    74,    75,    69,    76,    77,    78,    79,
      80,     0,     0,     0,    93,     0,     0,    70,    71,    72,
      73,    74,    75,    69,    76,    77,    78,    79,    80,     0,
       0,     0,   109,     0,     0,    70,    71,    72,    73,    74,
      75,    69,    76,    77,    78,    79,    80,     0,     0,     0,
     111,     0,     0,    70,    71,    72,    73,    74,    75,    69,
      76,    77,    78,    79,    80,     0,     0,     0,   114,     0,
       0,    70,    71,    72,    73,    74,    75,    69,    76,    77,
      78,    79,    80,     0,     0,     0,   122,     0,     0,    70,
      71,    72,    73,    74,    75,    69,    76,    77,    78,    79,
      80,     0,     0,     0,   130,     0,     0,    70,    71,    72,
      73,    74,    75,    69,    76,    77,    78,    79,    80,     0,
       0,     0,     0,    69,     0,    70,     0,    72,    73,    74,
      75,     0,    76,    77,    78,    79,    80,    72,    73,    74,
      75,     0,    76,    77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      38,    39,    40,    44,    43,    17,    11,    12,    13,    14,
      15,    49,    50,     5,    52,    54,     5,    55,     5,     6,
       7,     8,     9,    10,    11,    12,    38,    39,    40,     0,
       5,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    39,    40,    16,    25,    26,    35,     5,
      88,    38,     5,    91,    92,     3,    43,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,   107,
      18,    19,    20,     4,    22,    23,    24,    45,   117,    27,
      28,   119,    43,    46,    44,   123,    43,    35,    16,    43,
      38,    43,    43,   131,    43,    43,     5,    47,    46,    45,
      45,    45,    45,     5,   145,    43,    21,   148,   146,    17,
      44,    44,   151,     5,     6,     7,     8,     9,    10,    16,
      45,    29,    30,    31,    32,    33,    34,    44,    36,    37,
      38,    39,    40,    22,    45,    45,    43,     5,    16,    45,
      48,    17,    46,    35,    16,    48,    38,    47,    44,    19,
     134,    43,    -1,    29,    30,    31,    32,    33,    34,    17,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      -1,    29,    30,    31,    32,    33,    34,    17,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,    29,
      30,    31,    32,    33,    34,    17,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    -1,    -1,    29,    30,    31,
      32,    33,    34,    17,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    44,    -1,    -1,    29,    30,    31,    32,    33,
      34,    17,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      44,    -1,    -1,    29,    30,    31,    32,    33,    34,    17,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    44,    -1,
      -1,    29,    30,    31,    32,    33,    34,    17,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    44,    -1,    -1,    29,
      30,    31,    32,    33,    34,    17,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    -1,    -1,    29,    30,    31,
      32,    33,    34,    17,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    17,    -1,    29,    -1,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    13,    14,    15,    50,    51,    71,     5,
       5,     5,     5,     5,     0,     4,    45,    43,    51,    44,
      46,    52,    53,     3,     5,     6,     7,     8,     9,    10,
      18,    19,    20,    22,    23,    24,    27,    28,    35,    38,
      43,    52,    54,    55,    63,    71,    72,    73,    43,    16,
      43,    43,    43,    65,    66,    43,    45,    45,     5,    73,
      73,    11,    12,    73,    47,    63,    54,    45,    45,    17,
      29,    30,    31,    32,    33,    34,    36,    37,    38,    39,
      40,    45,     5,    56,    73,    73,     5,    73,    43,    63,
      73,    44,    44,    44,    21,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    16,    45,    44,
      44,    44,    73,    22,    44,    73,    73,    64,    73,    67,
      45,    45,    44,    43,    70,    63,    73,    73,    46,    45,
      44,    25,    26,    58,    59,    61,    68,    45,    73,    48,
      47,    58,     5,    57,    48,    62,    16,    44,    60,    54,
      73,    69,    54,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    53,    52,    54,    54,    55,
      56,    57,    58,    58,    58,    60,    59,    62,    61,    63,
      63,    63,    63,    63,    63,    63,    64,    63,    65,    63,
      66,    63,    67,    68,    69,    63,    70,    63,    63,    63,
      71,    71,    71,    71,    71,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     0,     0,     4,     2,     0,     4,
       3,     3,     2,     1,     0,     0,     5,     0,     4,     2,
       2,     2,     1,     5,     5,     2,     0,     5,     0,     5,
       0,     8,     0,     0,     0,    12,     0,     8,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     4,     4,     3,     2
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
  case 5: /* $@1: %empty  */
#line 72 "sin.y"
            { escopo_atual++; }
#line 1293 "sin.tab.c"
    break;

  case 6: /* bloco: '{' $@1 comandos_bloco '}'  */
#line 72 "sin.y"
                                                   {
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
        }
#line 1302 "sin.tab.c"
    break;

  case 9: /* if_cond: TOKEN_IF '(' expressao ')'  */
#line 83 "sin.y"
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
#line 1332 "sin.tab.c"
    break;

  case 10: /* for_init: ID ASSIGN expressao  */
#line 111 "sin.y"
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
#line 1352 "sin.tab.c"
    break;

  case 11: /* incremento_for: ID ASSIGN expressao  */
#line 128 "sin.y"
                                     {
    Simbolo *s = buscar((yyvsp[-2].valor_str));
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
    } else {
        // Guarda o 3AC na variavel temporaria
        sprintf(inc_3ac, "%s = %s;\n", s->temp, (yyvsp[0].info).temp);
        
        // Em vez de imprimir no C, retorna a string formatada
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s = %s", s->nome, (yyvsp[0].info).c_expr);
        (yyval.valor_str) = inc_str;
    }
}
#line 1371 "sin.tab.c"
    break;

  case 15: /* @2: %empty  */
#line 149 "sin.y"
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
#line 1404 "sin.tab.c"
    break;

  case 16: /* caso: TOKEN_CASE expressao ':' @2 comandos_bloco  */
#line 176 "sin.y"
                     {

        // 5. Fim do case: pula pro fim do switch
        sprintf(buf, "goto %s;\n", switch_fim);
        strcat(instrucoes, buf);

        // 6. Imprime o rótulo do próximo case
        sprintf(buf, "%s:\n", (yyvsp[-1].valor_str));
        strcat(instrucoes, buf);
    }
#line 1419 "sin.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 188 "sin.y"
                                 {
        strcat(c_body, "default:\n");
    }
#line 1427 "sin.tab.c"
    break;

  case 18: /* default_caso: TOKEN_DEFAULT ':' $@3 comandos_bloco  */
#line 190 "sin.y"
                     {
        // O default não precisa de break nem de desvios no 3AC, ele só termina.
    }
#line 1435 "sin.tab.c"
    break;

  case 23: /* comando: TOKEN_PRINT '(' expressao ')' ';'  */
#line 200 "sin.y"
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
#line 1452 "sin.tab.c"
    break;

  case 24: /* comando: TOKEN_READ '(' ID ')' ';'  */
#line 213 "sin.y"
                                    {
            Simbolo *s = buscar((yyvsp[-2].valor_str));
            if (!s) {
                char erro_msg[100];
                sprintf(erro_msg, "Erro: Variavel '%s' nao declarada para leitura.", (yyvsp[-2].valor_str));
                yyerror(erro_msg);
            } else {
                // 1. Gera o Código Intermediário (3AC)
                sprintf(buf, "read %s;\n", s->nome); 
                strcat(instrucoes, buf);

                // 2. Descobre o formato para o scanf do C
                char* formato = "";
                if (s->tipo == T_INT || s->tipo == T_BOOL) formato = "%d";
                else if (s->tipo == T_FLOAT) formato = "%f";
                else if (s->tipo == T_CHAR) formato = " %c"; 

                // 3. Gera o Código C 
                if (s->tipo == T_STRING) {
                    sprintf(buf, "%s = (char*) malloc(256);\n", s->nome);
                    strcat(c_body, buf);
                    sprintf(buf, "scanf(\"%%s\", %s);\n", s->nome);
                } else {
                    sprintf(buf, "scanf(\"%s\", &%s);\n", formato, s->nome);
                }
                strcat(c_body, buf);
            }
        }
#line 1485 "sin.tab.c"
    break;

  case 25: /* comando: if_cond comando  */
#line 241 "sin.y"
                          {
            // IF SIMPLES (Sem else)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); // Puxa o rótulo do if_cond
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1496 "sin.tab.c"
    break;

  case 26: /* @4: %empty  */
#line 247 "sin.y"
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
#line 1520 "sin.tab.c"
    break;

  case 27: /* comando: if_cond comando TOKEN_ELSE @4 comando  */
#line 265 "sin.y"
                  {
            // FIM DO ELSE
            // Imprime o label de fim (que veio do bloco anterior)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1532 "sin.tab.c"
    break;

  case 28: /* @5: %empty  */
#line 272 "sin.y"
                      {
            strcat(instrucoes, "\n");
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; 
            
            // --- LINHA NOVA 1: Salva o início na pilha ---
            strcpy(pilha_inicio[topo_laco], l_inicio);
            
        }
#line 1548 "sin.tab.c"
    break;

  case 29: /* comando: TOKEN_WHILE @5 '(' expressao ')'  */
#line 282 "sin.y"
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
#line 1578 "sin.tab.c"
    break;

  case 30: /* @6: %empty  */
#line 307 "sin.y"
                   {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio;
            strcat(c_body, "do {\n");
        }
#line 1590 "sin.tab.c"
    break;

  case 31: /* comando: TOKEN_DO @6 comando TOKEN_WHILE '(' expressao ')' ';'  */
#line 313 "sin.y"
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
#line 1611 "sin.tab.c"
    break;

  case 32: /* @7: %empty  */
#line 329 "sin.y"
                                     {
            // 1. Marca visualmente no 3AC que é um FOR
            strcat(instrucoes, "\n");
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; // Salva na posição $5
            
            // Salva o início na pilha para o 'continue'
            strcpy(pilha_inicio[topo_laco], l_inicio);
            
        }
#line 1628 "sin.tab.c"
    break;

  case 33: /* @8: %empty  */
#line 340 "sin.y"
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
            
            // GERA O 'FOR' LITERAL NO CÓDIGO C (Usando o init guardado no $3 e cond no $6)
            sprintf(buf, "for (%s; %s; ", (yyvsp[-4].valor_str), (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);
            
        }
#line 1660 "sin.tab.c"
    break;

  case 34: /* $@9: %empty  */
#line 366 "sin.y"
                             {
            // 3. Fecha os parênteses do FOR no C (Usando o incremento guardado no $9)
            sprintf(buf, "%s) {\n", (yyvsp[-1].valor_str));
            strcat(c_body, buf);
            
        }
#line 1671 "sin.tab.c"
    break;

  case 35: /* comando: TOKEN_FOR '(' for_init ';' @7 expressao ';' @8 incremento_for ')' $@9 comando  */
#line 371 "sin.y"
                  {
            // 4. Chegamos no final do laço!
            topo_laco--; // Desce a pilha de laços
            
            // Imprime o incremento do 3AC que estava guardado
            strcat(instrucoes, inc_3ac);
            
            // Pula de volta pro início no 3AC
            sprintf(buf, "goto %s;\n", (yyvsp[-7].valor_str));
            strcat(instrucoes, buf);
            
            // Marca o rótulo de FIM no 3AC
            sprintf(buf, "%s:\n", (yyvsp[-4].valor_str));
            strcat(instrucoes, buf);
            strcat(instrucoes, "\n");
            
            // Fecha a chave no C
            strcat(c_body, "}\n");
        }
#line 1695 "sin.tab.c"
    break;

  case 36: /* $@10: %empty  */
#line 390 "sin.y"
                                        {
            // Marca que entrou em um switch
            dentro_switch++;

            // Salva a expressão do switch e o label de saída
            strcpy(switch_exp, (yyvsp[-1].info).temp);
            strcpy(switch_fim, novo_label());

            // Código C
            sprintf(buf, "switch (%s) {\n", (yyvsp[-1].info).c_expr);
            strcat(c_body, buf);

        }
#line 1713 "sin.tab.c"
    break;

  case 37: /* comando: TOKEN_SWITCH '(' expressao ')' $@10 '{' casos_lista '}'  */
#line 402 "sin.y"
                              {

            // Saiu do switch
            dentro_switch--;

            // Label de saída do switch no código intermediário
            sprintf(buf, "%s:\n", switch_fim);
            strcat(instrucoes, buf);

            // Fecha o switch no C
            strcat(c_body, "}\n");
        }
#line 1730 "sin.tab.c"
    break;

  case 38: /* comando: TOKEN_BREAK ';'  */
#line 415 "sin.y"
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
#line 1757 "sin.tab.c"
    break;

  case 39: /* comando: TOKEN_CONTINUE ';'  */
#line 437 "sin.y"
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
#line 1772 "sin.tab.c"
    break;

  case 40: /* declaracao: TOKEN_INT ID  */
#line 448 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1782 "sin.tab.c"
    break;

  case 41: /* declaracao: TOKEN_FLOAT ID  */
#line 453 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1792 "sin.tab.c"
    break;

  case 42: /* declaracao: TOKEN_CHAR ID  */
#line 458 "sin.y"
                            {
                inserir((yyvsp[0].valor_str), T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1802 "sin.tab.c"
    break;

  case 43: /* declaracao: TOKEN_BOOL ID  */
#line 463 "sin.y"
                           {
                 inserir((yyvsp[0].valor_str), T_BOOL, escopo_atual);
                 sprintf(buf, "bool %s;\n", (yyvsp[0].valor_str));
                 strcat(c_decl, buf);
             }
#line 1812 "sin.tab.c"
    break;

  case 44: /* declaracao: TOKEN_STRING ID  */
#line 468 "sin.y"
                              {
                inserir((yyvsp[0].valor_str), T_STRING, escopo_atual);
                sprintf(buf, "char* %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 1822 "sin.tab.c"
    break;

  case 45: /* atribuicao: ID ASSIGN expressao  */
#line 475 "sin.y"
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
            sprintf(buf, "%s = %s;\n", s->temp, valor_final);
            strcat(instrucoes, buf);

            sprintf(buf, "%s = %s;\n", s->nome, c_expr_final);
            strcat(c_body, buf);
        }
    }
}
#line 1868 "sin.tab.c"
    break;

  case 46: /* expressao: NUM_INT  */
#line 517 "sin.y"
                    {
                (yyval.info).tipo_val = T_INT;
                (yyval.info).temp = strdup((yyvsp[0].valor_str));
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
            }
#line 1878 "sin.tab.c"
    break;

  case 47: /* expressao: NUM_FLOAT  */
#line 522 "sin.y"
                      {
                (yyval.info).tipo_val = T_FLOAT;
                (yyval.info).temp   = novo_temp(T_FLOAT);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1890 "sin.tab.c"
    break;

  case 48: /* expressao: CHAR_LIT  */
#line 529 "sin.y"
                     {
                (yyval.info).tipo_val = T_CHAR;
                (yyval.info).temp   = novo_temp(T_CHAR);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1902 "sin.tab.c"
    break;

  case 49: /* expressao: BOOL_LIT  */
#line 536 "sin.y"
                     {
                (yyval.info).tipo_val = T_BOOL;
                (yyval.info).temp   = novo_temp(T_BOOL);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1914 "sin.tab.c"
    break;

  case 50: /* expressao: STRING_LIT  */
#line 543 "sin.y"
                         {
                (yyval.info).tipo_val = T_STRING;
                (yyval.info).temp   = novo_temp(T_STRING);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 1926 "sin.tab.c"
    break;

  case 51: /* expressao: ID  */
#line 550 "sin.y"
               {
                Simbolo *s = buscar((yyvsp[0].valor_str));
                if (s) {
                    (yyval.info).tipo_val = s->tipo;
                    (yyval.info).temp   = s->temp;
                    (yyval.info).c_expr = strdup(s->nome);
                } else {
                    yyerror("Var nao declarada");
                    (yyval.info).temp   = "ERRO";
                    (yyval.info).c_expr = strdup("ERRO");
                    (yyval.info).tipo_val = T_INT;
                }
            }
#line 1944 "sin.tab.c"
    break;

  case 52: /* expressao: expressao PLUS expressao  */
#line 565 "sin.y"
                                     {
                    if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                        ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                        yyerror("Erro Semantico: Operacao de soma com tipos invalidos.");
                        (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                    } else {
                        char *ce1 = (yyvsp[-2].info).c_expr;
                        char *ce3 = (yyvsp[0].info).c_expr;
                        
                        // 1. Determina o tipo resultante
                        if ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) {
                            (yyval.info).tipo_val = T_FLOAT;
                        } else {
                            (yyval.info).tipo_val = T_INT;
                        }

                        // 2. Aplica cast se necessário para o código C
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

                        // 3. Gera UMA ÚNICA vez o código
                        (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                        sprintf(buf, "%s = %s + %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                        strcat(instrucoes, buf);

                        char *ce = (char*) malloc(256);
                        sprintf(ce, "(%s + %s)", ce1, ce3);
                        (yyval.info).c_expr = ce;
                    }
                }
#line 1991 "sin.tab.c"
    break;

  case 53: /* expressao: expressao '-' expressao  */
#line 607 "sin.y"
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
#line 2024 "sin.tab.c"
    break;

  case 54: /* expressao: expressao '*' expressao  */
#line 635 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de multiplicacao com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                    if ((yyvsp[-2].info).tipo_val == T_INT) {
                        (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
                        (yyvsp[-2].info).tipo_val = T_FLOAT;

                        char *tmp = (char*) malloc(256);
                        sprintf(tmp, "(float)(%s)", ce1);
                        ce1 = tmp;
                    } else {
                        (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                        (yyvsp[0].info).tipo_val = T_FLOAT;

                        char *tmp = (char*) malloc(256);
                        sprintf(tmp, "(float)(%s)", ce3);
                        ce3 = tmp;
                    }
                    }
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s * %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);

                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s + %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
#line 2061 "sin.tab.c"
    break;

  case 55: /* expressao: expressao '/' expressao  */
#line 667 "sin.y"
                                    {
                if (((yyvsp[-2].info).tipo_val != T_INT && (yyvsp[-2].info).tipo_val != T_FLOAT) ||
                    ((yyvsp[0].info).tipo_val != T_INT && (yyvsp[0].info).tipo_val != T_FLOAT)) {
                    yyerror("Erro Semantico: Operacao de divisao com tipos invalidos.");
                    (yyval.info).temp = "ERRO"; (yyval.info).c_expr = strdup("ERRO"); (yyval.info).tipo_val = T_INT;
                } else {
                    char *ce1 = (yyvsp[-2].info).c_expr, *ce3 = (yyvsp[0].info).c_expr;
                   if ((yyvsp[-2].info).tipo_val == T_INT) {
                        (yyvsp[-2].info).temp = gerar_cast((yyvsp[-2].info).temp, T_FLOAT);
                        (yyvsp[-2].info).tipo_val = T_FLOAT;

                        char *tmp = (char*) malloc(256);
                        sprintf(tmp, "(float)(%s)", ce1);
                        ce1 = tmp;
                    } else {
                        (yyvsp[0].info).temp = gerar_cast((yyvsp[0].info).temp, T_FLOAT);
                        (yyvsp[0].info).tipo_val = T_FLOAT;

                        char *tmp = (char*) malloc(256);
                        sprintf(tmp, "(float)(%s)", ce3);
                        ce3 = tmp;
                    }
                    }
                    (yyval.info).tipo_val = ((yyvsp[-2].info).tipo_val == T_FLOAT || (yyvsp[0].info).tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
                    (yyval.info).temp = novo_temp((yyval.info).tipo_val);
                    sprintf(buf, "%s = %s / %s;\n", (yyval.info).temp, (yyvsp[-2].info).temp, (yyvsp[0].info).temp);
                    strcat(instrucoes, buf);

                    char *ce = (char*) malloc(256);
                    sprintf(ce, "(%s + %s)", (yyvsp[-2].info).c_expr, (yyvsp[0].info).c_expr);
                    (yyval.info).c_expr = ce;
                }
#line 2098 "sin.tab.c"
    break;

  case 56: /* expressao: expressao EQ expressao  */
#line 701 "sin.y"
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
#line 2118 "sin.tab.c"
    break;

  case 57: /* expressao: expressao NE expressao  */
#line 716 "sin.y"
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
#line 2138 "sin.tab.c"
    break;

  case 58: /* expressao: expressao '>' expressao  */
#line 731 "sin.y"
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
#line 2158 "sin.tab.c"
    break;

  case 59: /* expressao: expressao '<' expressao  */
#line 746 "sin.y"
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
#line 2178 "sin.tab.c"
    break;

  case 60: /* expressao: expressao GE expressao  */
#line 761 "sin.y"
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
#line 2198 "sin.tab.c"
    break;

  case 61: /* expressao: expressao LE expressao  */
#line 776 "sin.y"
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
#line 2218 "sin.tab.c"
    break;

  case 62: /* expressao: expressao AND expressao  */
#line 793 "sin.y"
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
#line 2237 "sin.tab.c"
    break;

  case 63: /* expressao: expressao OR expressao  */
#line 807 "sin.y"
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
#line 2256 "sin.tab.c"
    break;

  case 64: /* expressao: NOT expressao  */
#line 821 "sin.y"
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
#line 2275 "sin.tab.c"
    break;

  case 65: /* expressao: '(' TOKEN_INT ')' expressao  */
#line 836 "sin.y"
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
#line 2299 "sin.tab.c"
    break;

  case 66: /* expressao: '(' TOKEN_FLOAT ')' expressao  */
#line 855 "sin.y"
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
#line 2323 "sin.tab.c"
    break;

  case 67: /* expressao: '(' expressao ')'  */
#line 874 "sin.y"
                              {
                (yyval.info) = (yyvsp[-1].info);
            }
#line 2331 "sin.tab.c"
    break;

  case 68: /* expressao: '-' expressao  */
#line 877 "sin.y"
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
#line 2350 "sin.tab.c"
    break;


#line 2354 "sin.tab.c"

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

#line 893 "sin.y"


#include <stdlib.h> // Necessário para a função system()

int main() {
    yyparse();
    if (houve_erro) {
        return 1;
    }

    /* 1. VISUALIZAÇÃO DO CÓDIGO INTERMEDIÁRIO (Terminal) */
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    printf("#include <string.h>\n");
    printf("#include <stdbool.h>\n\n");

    printf("int main()\n");
    printf("{\n");
    printf("%s\n", declaracoes);
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
    
    fprintf(arquivo_c, "int main()\n{\n");
    fprintf(arquivo_c, "%s\n", declaracoes);
    fprintf(arquivo_c, "%s", instrucoes);
    fprintf(arquivo_c, "    return 0;\n}\n");

    fclose(arquivo_c);

    int status_gcc = system("gcc saida.c -o programa.exe");
    if (status_gcc == 0) {
        printf("Finalizado com sucesso\n");
    } else {
        printf("Erro na compilacao.\n");
    }

    return 0;
}
