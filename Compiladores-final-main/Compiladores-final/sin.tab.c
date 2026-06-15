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

Simbolo *simbolo_array_atual = NULL;
int idx_array_atual = 0;
int tam_array_atual = 0;

int escopo_atual = 0;

#line 105 "sin.tab.c"

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
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_CAST = 47,                      /* CAST  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ':'  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_programa = 59,                  /* programa  */
  YYSYMBOL_declaracoes_globais = 60,       /* declaracoes_globais  */
  YYSYMBOL_bloco = 61,                     /* bloco  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_comandos_bloco = 63,            /* comandos_bloco  */
  YYSYMBOL_if_cond = 64,                   /* if_cond  */
  YYSYMBOL_for_init = 65,                  /* for_init  */
  YYSYMBOL_incremento_for = 66,            /* incremento_for  */
  YYSYMBOL_casos_lista = 67,               /* casos_lista  */
  YYSYMBOL_caso = 68,                      /* caso  */
  YYSYMBOL_69_2 = 69,                      /* @2  */
  YYSYMBOL_default_caso = 70,              /* default_caso  */
  YYSYMBOL_71_3 = 71,                      /* $@3  */
  YYSYMBOL_comando = 72,                   /* comando  */
  YYSYMBOL_73_4 = 73,                      /* @4  */
  YYSYMBOL_74_5 = 74,                      /* @5  */
  YYSYMBOL_75_6 = 75,                      /* @6  */
  YYSYMBOL_76_7 = 76,                      /* @7  */
  YYSYMBOL_77_8 = 77,                      /* @8  */
  YYSYMBOL_78_9 = 78,                      /* @9  */
  YYSYMBOL_79_10 = 79,                     /* $@10  */
  YYSYMBOL_80_11 = 80,                     /* $@11  */
  YYSYMBOL_declaracao = 81,                /* declaracao  */
  YYSYMBOL_82_12 = 82,                     /* $@12  */
  YYSYMBOL_83_13 = 83,                     /* $@13  */
  YYSYMBOL_atribuicao = 84,                /* atribuicao  */
  YYSYMBOL_expressao = 85,                 /* expressao  */
  YYSYMBOL_lista_valores = 86              /* lista_valores  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   587

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      49,    50,    45,     2,    57,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    51,
      42,     2,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    78,    79,    82,    82,    88,    89,    93,
     121,   138,   149,   161,   174,   175,   176,   179,   179,   218,
     218,   225,   226,   227,   228,   229,   243,   267,   273,   273,
     298,   308,   298,   348,   348,   370,   383,   409,   370,   438,
     438,   469,   491,   501,   518,   532,   546,   560,   573,   586,
     620,   626,   656,   656,   669,   675,   704,   704,   715,   720,
     738,   743,   761,   766,   791,   848,   853,   860,   867,   874,
     883,   908,   973,  1001,  1031,  1069,  1084,  1099,  1114,  1129,
    1144,  1161,  1175,  1189,  1204,  1223,  1242,  1245,  1260,  1287,
    1308
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
  "MULT_ASSIGN", "DIV_ASSIGN", "INC", "DEC", "'<'", "'>'", "'-'", "'*'",
  "'/'", "CAST", "UMINUS", "'('", "')'", "';'", "'{'", "'}'", "':'", "'['",
  "']'", "','", "$accept", "programa", "declaracoes_globais", "bloco",
  "$@1", "comandos_bloco", "if_cond", "for_init", "incremento_for",
  "casos_lista", "caso", "@2", "default_caso", "$@3", "comando", "@4",
  "@5", "@6", "@7", "@8", "@9", "$@10", "$@11", "declaracao", "$@12",
  "$@13", "atribuicao", "expressao", "lista_valores", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,    18,    20,    25,    26,    39,    45,    42,     8,    -8,
      -7,    44,    46,    47,  -101,    12,    43,    78,    58,    78,
      59,    78,    78,    78,    16,  -101,    21,  -101,  -101,  -101,
    -101,  -101,    78,    78,    63,   518,    22,   518,    23,   518,
     518,   518,    29,    78,  -101,  -101,    27,    32,   386,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    75,    81,  -101,  -101,   161,    78,    78,  -101,   -34,
     541,   536,     7,     7,     7,     7,     7,     7,   -34,  -101,
    -101,    49,    51,   137,  -101,  -101,  -101,  -101,  -101,    55,
     192,    61,    65,    66,  -101,  -101,    67,    57,    68,  -101,
      64,   137,   137,    69,    70,   225,    78,    78,   113,    78,
      78,    78,    78,    78,    72,    73,    78,    78,   120,    78,
      77,   137,    78,  -101,  -101,  -101,   107,  -101,  -101,  -101,
    -101,   518,   -43,   -35,   115,    82,   518,   248,   271,   294,
     317,  -101,  -101,   167,   408,    79,   430,    78,   110,   452,
    -101,  -101,    78,  -101,    78,  -101,  -101,  -101,  -101,  -101,
     118,    85,    87,  -101,   474,    90,  -101,   137,   518,   518,
      78,    78,  -101,  -101,  -101,    78,    89,  -101,   340,   363,
     137,   496,    -6,  -101,  -101,  -101,   111,    78,   109,   114,
      -6,  -101,   163,  -101,   207,  -101,  -101,  -101,   -13,   116,
    -101,   137,    78,  -101,  -101,  -101,   137,  -101,   518,   137,
    -101,  -101
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      54,    58,    60,    62,     1,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     3,    70,    65,    66,    67,
      68,    69,     0,     0,     0,    51,     0,    55,     0,    59,
      61,    63,     0,     0,    83,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     2,     0,     0,     0,    86,    71,
      81,    82,    75,    76,    80,    79,    78,    77,    72,    73,
      74,     0,     0,     8,    88,    84,    85,    52,    56,     0,
      70,     0,     0,     0,    30,    33,     0,     0,     0,    24,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     6,    27,     7,    21,    22,
      23,    89,     0,     0,     0,     0,    64,     0,     0,     0,
       0,    47,    48,     0,     0,     0,     0,     0,     0,     0,
      28,    53,     0,    57,     0,    35,    43,    44,    45,    46,
      88,     0,     0,     9,     0,     0,    39,     0,    90,    10,
       0,     0,    25,    26,    31,     0,     0,    29,     0,     0,
       0,     0,    16,    36,    49,    32,     0,     0,     0,     0,
      16,    15,     0,    34,     0,    19,    40,    14,     0,     0,
      17,     8,     0,    12,    13,    37,     8,    20,    11,     0,
      18,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   153,   129,  -101,   -95,  -101,  -101,  -101,   -16,
    -101,  -101,  -101,  -101,  -100,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,    13,  -101,  -101,  -101,   -17,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    99,    83,   100,   101,   135,   199,   189,
     190,   206,   191,   201,   102,   167,   120,   180,   121,   170,
     192,   209,   176,   103,   106,   107,   104,   105,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,   126,    37,   202,    39,    40,    41,   127,    17,    19,
     151,    59,    60,     8,   152,    44,    45,    48,   153,   187,
     188,   148,   152,     9,    49,    10,    65,   203,   204,     8,
      11,    12,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    13,    14,    15,    18,    20,    85,
      86,    58,    59,    60,     1,     2,     3,     4,     5,    16,
      21,    24,    22,    23,    36,    38,    42,   177,    26,    27,
      28,    29,    30,    31,    46,    47,    43,    66,    61,    62,
     185,    63,    67,    26,    27,    28,    29,    30,    31,   131,
     131,    81,   136,   137,   138,   139,   140,    82,    32,   143,
     144,    87,   146,    88,   108,   149,   207,    33,   123,   211,
     117,   210,    34,    32,   118,   119,   122,   125,   134,   124,
     128,   129,    33,   141,   142,   145,   147,    34,   150,   162,
     164,   154,   165,   155,   171,   168,   172,   169,   173,   175,
      89,   182,    90,    27,    28,    29,    30,    31,     1,     2,
       3,     4,     5,   178,   179,    91,    92,    93,   181,    94,
      95,    96,   193,   195,    97,    98,   205,   196,   198,    25,
     194,    64,    32,     0,   197,     0,     0,     0,    49,     0,
       0,    33,     0,   133,    49,   208,    34,     0,     0,    63,
      50,    51,    52,    53,    54,    55,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,   109,    56,
      57,    58,    59,    60,     0,     0,     0,    84,     0,     0,
       0,     0,     0,   160,    49,     0,     0,     0,   110,   111,
     112,   113,   114,   115,     0,     0,    50,    51,    52,    53,
      54,    55,    49,     0,     0,     0,     0,   116,     0,    56,
      57,    58,    59,    60,    50,    51,    52,    53,    54,    55,
       0,   200,     0,     0,     0,    49,     0,    56,    57,    58,
      59,    60,     0,     0,     0,     0,   130,    50,    51,    52,
      53,    54,    55,     0,     0,     0,     0,     0,    49,     0,
      56,    57,    58,    59,    60,     0,     0,     0,     0,   156,
      50,    51,    52,    53,    54,    55,     0,     0,     0,     0,
       0,    49,     0,    56,    57,    58,    59,    60,     0,     0,
       0,     0,   157,    50,    51,    52,    53,    54,    55,     0,
       0,     0,     0,     0,    49,     0,    56,    57,    58,    59,
      60,     0,     0,     0,     0,   158,    50,    51,    52,    53,
      54,    55,     0,     0,     0,     0,     0,    49,     0,    56,
      57,    58,    59,    60,     0,     0,     0,     0,   159,    50,
      51,    52,    53,    54,    55,     0,     0,     0,     0,     0,
      49,     0,    56,    57,    58,    59,    60,     0,     0,     0,
       0,   183,    50,    51,    52,    53,    54,    55,     0,     0,
       0,     0,     0,    49,     0,    56,    57,    58,    59,    60,
       0,     0,     0,     0,   184,    50,    51,    52,    53,    54,
      55,     0,     0,     0,     0,    49,     0,     0,    56,    57,
      58,    59,    60,     0,     0,     0,    68,    50,    51,    52,
      53,    54,    55,     0,     0,     0,     0,    49,     0,     0,
      56,    57,    58,    59,    60,     0,     0,     0,   161,    50,
      51,    52,    53,    54,    55,     0,     0,     0,     0,    49,
       0,     0,    56,    57,    58,    59,    60,     0,     0,     0,
     163,    50,    51,    52,    53,    54,    55,     0,     0,     0,
       0,    49,     0,     0,    56,    57,    58,    59,    60,     0,
       0,     0,   166,    50,    51,    52,    53,    54,    55,     0,
       0,     0,     0,    49,     0,     0,    56,    57,    58,    59,
      60,     0,     0,     0,   174,    50,    51,    52,    53,    54,
      55,     0,     0,     0,     0,    49,     0,     0,    56,    57,
      58,    59,    60,     0,     0,     0,   186,    50,    51,    52,
      53,    54,    55,    49,     0,     0,     0,     0,    49,     0,
      56,    57,    58,    59,    60,    50,     0,    52,    53,    54,
      55,     0,    52,    53,    54,    55,     0,     0,    56,    57,
      58,    59,    60,    56,    57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
      17,   101,    19,    16,    21,    22,    23,   102,    16,    16,
      53,    45,    46,     0,    57,    32,    33,    34,    53,    25,
      26,   121,    57,     5,    17,     5,    43,    40,    41,    16,
       5,     5,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     5,     0,     4,    55,    55,    66,
      67,    44,    45,    46,    11,    12,    13,    14,    15,    51,
      16,    49,    16,    16,     6,     6,    50,   167,     5,     6,
       7,     8,     9,    10,    11,    12,    55,    50,    56,    56,
     180,    52,    50,     5,     6,     7,     8,     9,    10,   106,
     107,    16,   109,   110,   111,   112,   113,    16,    35,   116,
     117,    52,   119,    52,    49,   122,   201,    44,    51,   209,
      49,   206,    49,    35,    49,    49,    49,    53,     5,    51,
      51,    51,    44,    51,    51,     5,    49,    49,    21,    50,
     147,    16,    22,    51,    16,   152,    51,   154,    51,    49,
       3,    52,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   170,   171,    18,    19,    20,   175,    22,
      23,    24,    51,    54,    27,    28,    50,    53,     5,    16,
     187,    42,    35,    -1,   190,    -1,    -1,    -1,    17,    -1,
      -1,    44,    -1,   107,    17,   202,    49,    -1,    -1,    52,
      29,    30,    31,    32,    33,    34,    29,    30,    31,    32,
      33,    34,    -1,    42,    43,    44,    45,    46,    16,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    56,    17,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    -1,    -1,    29,    30,    31,    32,
      33,    34,    17,    -1,    -1,    -1,    -1,    55,    -1,    42,
      43,    44,    45,    46,    29,    30,    31,    32,    33,    34,
      -1,    54,    -1,    -1,    -1,    17,    -1,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    51,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    51,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    51,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    51,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    17,    -1,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    51,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    51,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    51,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    17,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    50,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    17,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    33,    34,    17,    -1,    -1,    -1,    -1,    17,    -1,
      42,    43,    44,    45,    46,    29,    -1,    31,    32,    33,
      34,    -1,    31,    32,    33,    34,    -1,    -1,    42,    43,
      44,    45,    46,    42,    43,    44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    13,    14,    15,    59,    60,    81,     5,
       5,     5,     5,     5,     0,     4,    51,    16,    55,    16,
      55,    16,    16,    16,    49,    60,     5,     6,     7,     8,
       9,    10,    35,    44,    49,    85,     6,    85,     6,    85,
      85,    85,    50,    55,    85,    85,    11,    12,    85,    17,
      29,    30,    31,    32,    33,    34,    42,    43,    44,    45,
      46,    56,    56,    52,    61,    85,    50,    50,    50,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    16,    16,    62,    56,    85,    85,    52,    52,     3,
       5,    18,    19,    20,    22,    23,    24,    27,    28,    61,
      63,    64,    72,    81,    84,    85,    82,    83,    49,    16,
      36,    37,    38,    39,    40,    41,    55,    49,    49,    49,
      74,    76,    49,    51,    51,    53,    72,    63,    51,    51,
      51,    85,    86,    86,     5,    65,    85,    85,    85,    85,
      85,    51,    51,    85,    85,     5,    85,    49,    72,    85,
      21,    53,    57,    53,    16,    51,    51,    51,    51,    51,
      56,    50,    50,    50,    85,    22,    50,    73,    85,    85,
      77,    16,    51,    51,    50,    49,    80,    72,    85,    85,
      75,    85,    52,    51,    51,    72,    50,    25,    26,    67,
      68,    70,    78,    51,    85,    54,    53,    67,     5,    66,
      54,    71,    16,    40,    41,    50,    69,    63,    85,    79,
      63,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    62,    61,    63,    63,    64,
      65,    66,    66,    66,    67,    67,    67,    69,    68,    71,
      70,    72,    72,    72,    72,    72,    72,    72,    73,    72,
      74,    75,    72,    76,    72,    77,    78,    79,    72,    80,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      81,    81,    82,    81,    81,    81,    83,    81,    81,    81,
      81,    81,    81,    81,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     0,     0,     4,     2,     0,     4,
       3,     3,     2,     2,     2,     1,     0,     0,     5,     0,
       4,     2,     2,     2,     1,     5,     5,     2,     0,     5,
       0,     0,     7,     0,     8,     0,     0,     0,    12,     0,
       8,     2,     2,     4,     4,     4,     4,     3,     3,     7,
       2,     4,     0,    10,     2,     4,     0,    10,     2,     4,
       2,     4,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     4,     4,     3,     2,     4,     1,
       3
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
  case 5: /* $@1: %empty  */
#line 82 "sin.y"
            { escopo_atual++; }
#line 1660 "sin.tab.c"
    break;

  case 6: /* bloco: '{' $@1 comandos_bloco '}'  */
#line 82 "sin.y"
                                                   {
            remover_simbolos_do_nivel(escopo_atual);
            escopo_atual--;
        }
#line 1669 "sin.tab.c"
    break;

  case 9: /* if_cond: TOKEN_IF '(' expressao ')'  */
#line 93 "sin.y"
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
#line 1699 "sin.tab.c"
    break;

  case 10: /* for_init: ID ASSIGN expressao  */
#line 121 "sin.y"
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
#line 1719 "sin.tab.c"
    break;

  case 11: /* incremento_for: ID ASSIGN expressao  */
#line 138 "sin.y"
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
#line 1735 "sin.tab.c"
    break;

  case 12: /* incremento_for: ID INC  */
#line 149 "sin.y"
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
#line 1752 "sin.tab.c"
    break;

  case 13: /* incremento_for: ID DEC  */
#line 161 "sin.y"
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
#line 1768 "sin.tab.c"
    break;

  case 17: /* @2: %empty  */
#line 179 "sin.y"
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
#line 1801 "sin.tab.c"
    break;

  case 18: /* caso: TOKEN_CASE expressao ':' @2 comandos_bloco  */
#line 206 "sin.y"
                     {

        // 5. Fim do case: pula pro fim do switch
        sprintf(buf, "goto %s;\n", switch_fim);
        strcat(instrucoes, buf);

        // 6. Imprime o rótulo do próximo case
        sprintf(buf, "%s:\n", (yyvsp[-1].valor_str));
        strcat(instrucoes, buf);
    }
#line 1816 "sin.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 218 "sin.y"
                                 {
        strcat(c_body, "default:\n");
    }
#line 1824 "sin.tab.c"
    break;

  case 20: /* default_caso: TOKEN_DEFAULT ':' $@3 comandos_bloco  */
#line 220 "sin.y"
                     {
        // O default não precisa de break nem de desvios no 3AC, ele só termina.
    }
#line 1832 "sin.tab.c"
    break;

  case 25: /* comando: TOKEN_PRINT '(' expressao ')' ';'  */
#line 230 "sin.y"
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
#line 1849 "sin.tab.c"
    break;

  case 26: /* comando: TOKEN_READ '(' ID ')' ';'  */
#line 243 "sin.y"
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
#line 1878 "sin.tab.c"
    break;

  case 27: /* comando: if_cond comando  */
#line 267 "sin.y"
                          {
            // IF SIMPLES (Sem else)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); // Puxa o rótulo do if_cond
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1889 "sin.tab.c"
    break;

  case 28: /* @4: %empty  */
#line 273 "sin.y"
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
#line 1913 "sin.tab.c"
    break;

  case 29: /* comando: if_cond comando TOKEN_ELSE @4 comando  */
#line 291 "sin.y"
                  {
            // FIM DO ELSE
            // Imprime o label de fim (que veio do bloco anterior)
            sprintf(buf, "%s:\n", (yyvsp[-1].valor_str)); 
            strcat(instrucoes, buf);
            strcat(c_body, "}\n");
        }
#line 1925 "sin.tab.c"
    break;

  case 30: /* @5: %empty  */
#line 298 "sin.y"
                      {
            strcat(instrucoes, "\n");
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; 
            
            // --- LINHA NOVA 1: Salva o início na pilha ---
            strcpy(pilha_inicio[topo_laco], l_inicio);
            
        }
#line 1941 "sin.tab.c"
    break;

  case 31: /* @6: %empty  */
#line 308 "sin.y"
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
#line 1971 "sin.tab.c"
    break;

  case 32: /* comando: TOKEN_WHILE @5 '(' expressao ')' @6 comando  */
#line 332 "sin.y"
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
#line 1992 "sin.tab.c"
    break;

  case 33: /* @7: %empty  */
#line 348 "sin.y"
                   {
            char* l_inicio = novo_label();
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio;
            strcat(c_body, "do {\n");
        }
#line 2004 "sin.tab.c"
    break;

  case 34: /* comando: TOKEN_DO @7 comando TOKEN_WHILE '(' expressao ')' ';'  */
#line 354 "sin.y"
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
#line 2025 "sin.tab.c"
    break;

  case 35: /* @8: %empty  */
#line 370 "sin.y"
                                     {
            // 1. Marca visualmente no 3AC que é um FOR
            strcat(instrucoes, "\n");
            char* l_inicio = novo_label();
            char* l_incremento = novo_label(); // NOVO RÓTULO: Para o incremento!
            
            sprintf(buf, "%s:\n", l_inicio);
            strcat(instrucoes, buf);
            (yyval.valor_str) = l_inicio; // Salva o início (condicional) na posição $5
            
            // ALTERAÇÃO: Salva o rótulo do INCREMENTO na pilha para o 'continue' pular pra cá
            strcpy(pilha_inicio[topo_laco], l_incremento);
            
        }
#line 2044 "sin.tab.c"
    break;

  case 36: /* @9: %empty  */
#line 383 "sin.y"
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
#line 2076 "sin.tab.c"
    break;

  case 37: /* $@10: %empty  */
#line 409 "sin.y"
                             {
            // 3. Fecha os parênteses do FOR no C
            sprintf(buf, "%s) {\n", (yyvsp[-1].valor_str));
            strcat(c_body, buf);
            
        }
#line 2087 "sin.tab.c"
    break;

  case 38: /* comando: TOKEN_FOR '(' for_init ';' @8 expressao ';' @9 incremento_for ')' $@10 comando  */
#line 414 "sin.y"
                  {
            // 4. Chegamos no final do laço!
            topo_laco--; // Desce a pilha de laços
            
            // --- NOVO PASSO: Imprime o rótulo do INCREMENTO aqui ---
            // Recuperamos o l_incremento lendo a própria pilha_inicio!
            sprintf(buf, "%s:\n", pilha_inicio[topo_laco]);
            strcat(instrucoes, buf);
            
            // Imprime o incremento do 3AC que estava guardado
            strcat(instrucoes, inc_3ac);
            
            // Pula de volta pro início (A condicional no $5) no 3AC
            sprintf(buf, "goto %s;\n", (yyvsp[-7].valor_str));
            strcat(instrucoes, buf);
            
            // Marca o rótulo de FIM no 3AC
            sprintf(buf, "%s:\n", (yyvsp[-4].valor_str));
            strcat(instrucoes, buf);
            strcat(instrucoes, "\n");
            
            // Fecha a chave no C
            strcat(c_body, "}\n");
        }
#line 2116 "sin.tab.c"
    break;

  case 39: /* $@11: %empty  */
#line 438 "sin.y"
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
#line 2138 "sin.tab.c"
    break;

  case 40: /* comando: TOKEN_SWITCH '(' expressao ')' $@11 '{' casos_lista '}'  */
#line 454 "sin.y"
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
#line 2157 "sin.tab.c"
    break;

  case 41: /* comando: TOKEN_BREAK ';'  */
#line 469 "sin.y"
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
#line 2184 "sin.tab.c"
    break;

  case 42: /* comando: TOKEN_CONTINUE ';'  */
#line 491 "sin.y"
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
#line 2199 "sin.tab.c"
    break;

  case 43: /* comando: ID PLUS_ASSIGN expressao ';'  */
#line 501 "sin.y"
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
#line 2221 "sin.tab.c"
    break;

  case 44: /* comando: ID MINUS_ASSIGN expressao ';'  */
#line 518 "sin.y"
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
#line 2240 "sin.tab.c"
    break;

  case 45: /* comando: ID MULT_ASSIGN expressao ';'  */
#line 532 "sin.y"
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
#line 2259 "sin.tab.c"
    break;

  case 46: /* comando: ID DIV_ASSIGN expressao ';'  */
#line 546 "sin.y"
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
#line 2278 "sin.tab.c"
    break;

  case 47: /* comando: ID INC ';'  */
#line 560 "sin.y"
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
#line 2296 "sin.tab.c"
    break;

  case 48: /* comando: ID DEC ';'  */
#line 573 "sin.y"
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
#line 2314 "sin.tab.c"
    break;

  case 49: /* comando: ID '[' expressao ']' ASSIGN expressao ';'  */
#line 586 "sin.y"
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
#line 2352 "sin.tab.c"
    break;

  case 50: /* declaracao: TOKEN_INT ID  */
#line 620 "sin.y"
                          {
                // DECLARAÇÃO SIMPLES (Já existia)
                inserir((yyvsp[0].valor_str), T_INT, escopo_atual);
                sprintf(buf, "int %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 2363 "sin.tab.c"
    break;

  case 51: /* declaracao: TOKEN_INT ID ASSIGN expressao  */
#line 626 "sin.y"
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
#line 2397 "sin.tab.c"
    break;

  case 52: /* $@12: %empty  */
#line 656 "sin.y"
                                                   {
                int tamanho = atoi((yyvsp[-3].valor_str));
                inserir_array((yyvsp[-5].valor_str), T_INT, escopo_atual, tamanho);
                
                // Configura o estado para a regra lista_valores usar
                simbolo_array_atual = buscar((yyvsp[-5].valor_str));
                tam_array_atual = tamanho;
                idx_array_atual = 0;
           }
#line 2411 "sin.tab.c"
    break;

  case 53: /* declaracao: TOKEN_INT ID '[' NUM_INT ']' ASSIGN '{' $@12 lista_valores '}'  */
#line 664 "sin.y"
                               {
                // Limpa o estado após terminar a inicialização
                simbolo_array_atual = NULL; 
           }
#line 2420 "sin.tab.c"
    break;

  case 54: /* declaracao: TOKEN_FLOAT ID  */
#line 669 "sin.y"
                          {
                // DECLARAÇÃO SIMPLES
                inserir((yyvsp[0].valor_str), T_FLOAT, escopo_atual);
                sprintf(buf, "float %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 2431 "sin.tab.c"
    break;

  case 55: /* declaracao: TOKEN_FLOAT ID ASSIGN expressao  */
#line 675 "sin.y"
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
#line 2464 "sin.tab.c"
    break;

  case 56: /* $@13: %empty  */
#line 704 "sin.y"
                                                     {
                int tamanho = atoi((yyvsp[-3].valor_str));
                inserir_array((yyvsp[-5].valor_str), T_FLOAT, escopo_atual, tamanho);
                
                simbolo_array_atual = buscar((yyvsp[-5].valor_str));
                tam_array_atual = tamanho;
                idx_array_atual = 0;
           }
#line 2477 "sin.tab.c"
    break;

  case 57: /* declaracao: TOKEN_FLOAT ID '[' NUM_INT ']' ASSIGN '{' $@13 lista_valores '}'  */
#line 711 "sin.y"
                               {
                simbolo_array_atual = NULL;
           }
#line 2485 "sin.tab.c"
    break;

  case 58: /* declaracao: TOKEN_CHAR ID  */
#line 715 "sin.y"
                         {
                inserir((yyvsp[0].valor_str), T_CHAR, escopo_atual);
                sprintf(buf, "char %s;\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 2495 "sin.tab.c"
    break;

  case 59: /* declaracao: TOKEN_CHAR ID ASSIGN expressao  */
#line 720 "sin.y"
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
#line 2517 "sin.tab.c"
    break;

  case 60: /* declaracao: TOKEN_BOOL ID  */
#line 738 "sin.y"
                         {
                 inserir((yyvsp[0].valor_str), T_BOOL, escopo_atual);
                 sprintf(buf, "int %s;\n", (yyvsp[0].valor_str));
                 strcat(c_decl, buf);
             }
#line 2527 "sin.tab.c"
    break;

  case 61: /* declaracao: TOKEN_BOOL ID ASSIGN expressao  */
#line 743 "sin.y"
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
#line 2549 "sin.tab.c"
    break;

  case 62: /* declaracao: TOKEN_STRING ID  */
#line 761 "sin.y"
                           {
                inserir((yyvsp[0].valor_str), T_STRING, escopo_atual);
                sprintf(buf, "char %s[256];\n", (yyvsp[0].valor_str));
                strcat(c_decl, buf);
             }
#line 2559 "sin.tab.c"
    break;

  case 63: /* declaracao: TOKEN_STRING ID ASSIGN expressao  */
#line 766 "sin.y"
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
#line 2587 "sin.tab.c"
    break;

  case 64: /* atribuicao: ID ASSIGN expressao  */
#line 791 "sin.y"
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
#line 2648 "sin.tab.c"
    break;

  case 65: /* expressao: NUM_INT  */
#line 848 "sin.y"
                    {
                (yyval.info).tipo_val = T_INT;
                (yyval.info).temp = strdup((yyvsp[0].valor_str));
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
            }
#line 2658 "sin.tab.c"
    break;

  case 66: /* expressao: NUM_FLOAT  */
#line 853 "sin.y"
                      {
                (yyval.info).tipo_val = T_FLOAT;
                (yyval.info).temp   = novo_temp(T_FLOAT);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 2670 "sin.tab.c"
    break;

  case 67: /* expressao: CHAR_LIT  */
#line 860 "sin.y"
                     {
                (yyval.info).tipo_val = T_CHAR;
                (yyval.info).temp   = novo_temp(T_CHAR);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 2682 "sin.tab.c"
    break;

  case 68: /* expressao: BOOL_LIT  */
#line 867 "sin.y"
                     {
                (yyval.info).tipo_val = T_BOOL;
                (yyval.info).temp   = novo_temp(T_BOOL);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "%s = %s;\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 2694 "sin.tab.c"
    break;

  case 69: /* expressao: STRING_LIT  */
#line 874 "sin.y"
                         {
                (yyval.info).tipo_val = T_STRING;
                int tamanho_calculado = strlen((yyvsp[0].valor_str)) - 1; 
                (yyval.info).tam_str = tamanho_calculado;
                (yyval.info).temp = novo_temp_str(tamanho_calculado);
                (yyval.info).c_expr = strdup((yyvsp[0].valor_str));
                sprintf(buf, "strcpy(%s, %s);\n", (yyval.info).temp, (yyvsp[0].valor_str));
                strcat(instrucoes, buf);
            }
#line 2708 "sin.tab.c"
    break;

  case 70: /* expressao: ID  */
#line 883 "sin.y"
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
#line 2736 "sin.tab.c"
    break;

  case 71: /* expressao: expressao PLUS expressao  */
#line 908 "sin.y"
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
#line 2806 "sin.tab.c"
    break;

  case 72: /* expressao: expressao '-' expressao  */
#line 973 "sin.y"
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
#line 2839 "sin.tab.c"
    break;

  case 73: /* expressao: expressao '*' expressao  */
#line 1001 "sin.y"
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
#line 2874 "sin.tab.c"
    break;

  case 74: /* expressao: expressao '/' expressao  */
#line 1031 "sin.y"
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
#line 2915 "sin.tab.c"
    break;

  case 75: /* expressao: expressao EQ expressao  */
#line 1069 "sin.y"
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
#line 2935 "sin.tab.c"
    break;

  case 76: /* expressao: expressao NE expressao  */
#line 1084 "sin.y"
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
#line 2955 "sin.tab.c"
    break;

  case 77: /* expressao: expressao '>' expressao  */
#line 1099 "sin.y"
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
#line 2975 "sin.tab.c"
    break;

  case 78: /* expressao: expressao '<' expressao  */
#line 1114 "sin.y"
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
#line 2995 "sin.tab.c"
    break;

  case 79: /* expressao: expressao GE expressao  */
#line 1129 "sin.y"
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
#line 3015 "sin.tab.c"
    break;

  case 80: /* expressao: expressao LE expressao  */
#line 1144 "sin.y"
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
#line 3035 "sin.tab.c"
    break;

  case 81: /* expressao: expressao AND expressao  */
#line 1161 "sin.y"
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
#line 3054 "sin.tab.c"
    break;

  case 82: /* expressao: expressao OR expressao  */
#line 1175 "sin.y"
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
#line 3073 "sin.tab.c"
    break;

  case 83: /* expressao: NOT expressao  */
#line 1189 "sin.y"
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
#line 3092 "sin.tab.c"
    break;

  case 84: /* expressao: '(' TOKEN_INT ')' expressao  */
#line 1204 "sin.y"
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
#line 3116 "sin.tab.c"
    break;

  case 85: /* expressao: '(' TOKEN_FLOAT ')' expressao  */
#line 1223 "sin.y"
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
#line 3140 "sin.tab.c"
    break;

  case 86: /* expressao: '(' expressao ')'  */
#line 1242 "sin.y"
                              {
                (yyval.info) = (yyvsp[-1].info);
            }
#line 3148 "sin.tab.c"
    break;

  case 87: /* expressao: '-' expressao  */
#line 1245 "sin.y"
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
#line 3167 "sin.tab.c"
    break;

  case 88: /* expressao: ID '[' expressao ']'  */
#line 1260 "sin.y"
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
#line 3197 "sin.tab.c"
    break;

  case 89: /* lista_valores: expressao  */
#line 1287 "sin.y"
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
#line 3223 "sin.tab.c"
    break;

  case 90: /* lista_valores: lista_valores ',' expressao  */
#line 1308 "sin.y"
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
#line 3248 "sin.tab.c"
    break;


#line 3252 "sin.tab.c"

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

#line 1330 "sin.y"


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
    if (status_gcc != 0) {
        printf("Erro no compilador\n");
    }

    return 0;
}
