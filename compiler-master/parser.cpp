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
#include "stdlib.h"
#include <string>
#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

#define log if (debug == 1) printf

#define ASSIGNSTMT 900
#define IFSTMT 901
#define EXPR 902

extern FILE * yyin;
extern FILE * yyout;

void yyerror(const char*); 
int yylex();
int temp = 0;
int lines = -1;
int debug = 1;

Node* head = NULL;

/*Function Declares*/

Node *  gen_expr(int type, string value , int n, ...);

void reveal(Node * node);

template<typename T>
string to_string(T a);

string gen_temp_id(int no);

string gen_line_id(int no);

string newTemp();

/* Class defination */

/*Statement*/


#line 119 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_K_ELSE = 3,                     /* K_ELSE  */
  YYSYMBOL_K_IF = 4,                       /* K_IF  */
  YYSYMBOL_K_RETURN = 5,                   /* K_RETURN  */
  YYSYMBOL_K_WHILE = 6,                    /* K_WHILE  */
  YYSYMBOL_K_PRINTF = 7,                   /* K_PRINTF  */
  YYSYMBOL_K_READ = 8,                     /* K_READ  */
  YYSYMBOL_K_INT = 9,                      /* K_INT  */
  YYSYMBOL_K_VOID = 10,                    /* K_VOID  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_NUM = 12,                       /* NUM  */
  YYSYMBOL_O_ASSIGN = 13,                  /* O_ASSIGN  */
  YYSYMBOL_O_COMMA = 14,                   /* O_COMMA  */
  YYSYMBOL_O_SEMI = 15,                    /* O_SEMI  */
  YYSYMBOL_O_LSBRACKER = 16,               /* O_LSBRACKER  */
  YYSYMBOL_O_RSBRACKER = 17,               /* O_RSBRACKER  */
  YYSYMBOL_O_LMBRACKER = 18,               /* O_LMBRACKER  */
  YYSYMBOL_O_RMBRACKER = 19,               /* O_RMBRACKER  */
  YYSYMBOL_O_LLBRACKER = 20,               /* O_LLBRACKER  */
  YYSYMBOL_O_RLBRACKER = 21,               /* O_RLBRACKER  */
  YYSYMBOL_O_ADD = 22,                     /* O_ADD  */
  YYSYMBOL_O_SUB = 23,                     /* O_SUB  */
  YYSYMBOL_O_MUL = 24,                     /* O_MUL  */
  YYSYMBOL_O_DIV = 25,                     /* O_DIV  */
  YYSYMBOL_O_LESS = 26,                    /* O_LESS  */
  YYSYMBOL_O_L_EQUAL = 27,                 /* O_L_EQUAL  */
  YYSYMBOL_O_GREATER = 28,                 /* O_GREATER  */
  YYSYMBOL_O_G_EQUAL = 29,                 /* O_G_EQUAL  */
  YYSYMBOL_O_EQUAL = 30,                   /* O_EQUAL  */
  YYSYMBOL_O_U_EQUAL = 31,                 /* O_U_EQUAL  */
  YYSYMBOL_COMMENT = 32,                   /* COMMENT  */
  YYSYMBOL_SPACES = 33,                    /* SPACES  */
  YYSYMBOL_U_LEGAL = 34,                   /* U_LEGAL  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_U_neg = 39,                     /* U_neg  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_declaration_list = 42,          /* declaration_list  */
  YYSYMBOL_declaration = 43,               /* declaration  */
  YYSYMBOL_var_declaration = 44,           /* var_declaration  */
  YYSYMBOL_fun_declaration = 45,           /* fun_declaration  */
  YYSYMBOL_compound_stmt = 46,             /* compound_stmt  */
  YYSYMBOL_type_specifier = 47,            /* type_specifier  */
  YYSYMBOL_params = 48,                    /* params  */
  YYSYMBOL_param_list = 49,                /* param_list  */
  YYSYMBOL_param = 50,                     /* param  */
  YYSYMBOL_local_declaration = 51,         /* local_declaration  */
  YYSYMBOL_statement_list = 52,            /* statement_list  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_expression_stmt = 54,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 55,            /* selection_stmt  */
  YYSYMBOL_matched_if = 56,                /* matched_if  */
  YYSYMBOL_unmatched_if = 57,              /* unmatched_if  */
  YYSYMBOL_iteration_stmt = 58,            /* iteration_stmt  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_return_stmt = 60,               /* return_stmt  */
  YYSYMBOL_var = 61,                       /* var  */
  YYSYMBOL_simple_expression = 62,         /* simple_expression  */
  YYSYMBOL_relop = 63,                     /* relop  */
  YYSYMBOL_additive_expression = 64,       /* additive_expression  */
  YYSYMBOL_addop = 65,                     /* addop  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_mulop = 67,                     /* mulop  */
  YYSYMBOL_factor = 68,                    /* factor  */
  YYSYMBOL_call = 69,                      /* call  */
  YYSYMBOL_args = 70,                      /* args  */
  YYSYMBOL_arg_list = 71                   /* arg_list  */
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
typedef yytype_int8 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
       2,     2,    37,    35,     2,    36,     2,    38,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    88,    89,    93,    94,    98,    99,   103,
     108,   113,   114,   118,   119,   123,   124,   128,   129,   133,
     134,   138,   139,   143,   144,   145,   146,   147,   151,   152,
     155,   156,   159,   168,   170,   175,   179,   180,   183,   184,
     187,   188,   191,   192,   195,   196,   197,   198,   199,   200,
     203,   204,   207,   208,   211,   218,   221,   222,   225,   226,
     227,   228,   231,   234,   235,   238,   239
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
  "\"end of file\"", "error", "\"invalid token\"", "K_ELSE", "K_IF",
  "K_RETURN", "K_WHILE", "K_PRINTF", "K_READ", "K_INT", "K_VOID", "ID",
  "NUM", "O_ASSIGN", "O_COMMA", "O_SEMI", "O_LSBRACKER", "O_RSBRACKER",
  "O_LMBRACKER", "O_RMBRACKER", "O_LLBRACKER", "O_RLBRACKER", "O_ADD",
  "O_SUB", "O_MUL", "O_DIV", "O_LESS", "O_L_EQUAL", "O_GREATER",
  "O_G_EQUAL", "O_EQUAL", "O_U_EQUAL", "COMMENT", "SPACES", "U_LEGAL",
  "'+'", "'-'", "'*'", "'/'", "U_neg", "$accept", "program",
  "declaration_list", "declaration", "var_declaration", "fun_declaration",
  "compound_stmt", "type_specifier", "params", "param_list", "param",
  "local_declaration", "statement_list", "statement", "expression_stmt",
  "selection_stmt", "matched_if", "unmatched_if", "iteration_stmt",
  "expression", "return_stmt", "var", "simple_expression", "relop",
  "additive_expression", "addop", "term", "mulop", "factor", "call",
  "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      48,   -93,   -93,     2,   -93,    48,   -93,   -93,     4,   -93,
     -93,    36,   -93,    48,    43,    13,    14,   -93,    50,    46,
      49,    51,    48,    53,    47,    48,   -93,   -93,   -93,   -93,
      48,    58,    24,   -93,    -9,    54,     5,    56,    25,   -93,
     -93,    22,   -93,    55,    24,   -93,   -93,   -93,   -93,   -93,
      59,   -93,    62,   -93,    19,    37,    38,   -93,    22,   -93,
      63,    22,    22,    22,    60,   -93,   -93,   -93,    22,   -93,
     -93,   -93,   -93,   -93,   -93,    22,   -93,   -93,    22,   -93,
     -93,    22,    64,   -93,    65,    66,    67,   -93,    68,   -93,
     -93,   -93,   -93,   -93,   -93,    24,    24,    22,   -93,   -93,
      76,    80,   -93,   -93,    24,    81,   -93,    70,   -93,    22,
      71,    24,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,     0,     2,     4,     5,     6,     0,     1,
       3,     0,     7,    14,     0,     0,     0,    13,    16,     0,
      17,     0,     0,     0,     0,    20,     9,    15,     8,    18,
      20,     0,    21,    19,     0,     0,     0,     0,    40,    61,
      29,     0,    24,     0,    21,    23,    25,    30,    31,    26,
       0,    27,    59,    37,    43,    51,    55,    60,     0,    39,
       0,     0,    64,     0,     0,    10,    22,    28,     0,    45,
      44,    46,    47,    48,    49,     0,    52,    53,     0,    56,
      57,     0,     0,    38,     0,    66,     0,    63,     0,    58,
      36,    59,    42,    50,    54,     0,     0,     0,    62,    41,
      33,    30,    35,    65,     0,     0,    32,     0,    34,     0,
       0,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,    84,   -93,    12,   -93,    69,   -12,   -93,    72,
     -93,    61,    52,   -92,   -93,   -93,   -88,   -13,   -93,   -36,
     -93,   -67,   -93,   -93,   -22,   -93,    16,   -93,   -93,   -93,
     -93,    -4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    42,     8,    16,    17,
      18,    32,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    75,    54,    78,    55,    81,    56,    57,
      86,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    15,     9,   100,   102,    64,    12,   101,    91,    14,
      15,    91,   106,    31,    91,    11,    38,    39,    31,   112,
      59,    41,    82,   101,    20,    84,    85,    88,    35,    36,
      37,    21,    90,    38,    39,    38,    39,    30,    41,    40,
      41,    62,    30,    63,    25,    69,    70,    71,    72,    73,
      74,    12,    13,    92,    14,    19,    93,     1,     2,    76,
      77,    85,    79,    80,    22,    23,    29,    24,    28,    34,
      58,    25,    61,   110,    67,    68,    65,    89,    83,   104,
      97,    95,    96,   105,    98,   107,   109,    99,   111,    10,
      26,    33,   108,   103,    27,     0,    66,    94
};

static const yytype_int8 yycheck[] =
{
      36,    13,     0,    95,    96,    41,    15,    95,    75,    18,
      22,    78,   104,    25,    81,    11,    11,    12,    30,   111,
      15,    16,    58,   111,    11,    61,    62,    63,     4,     5,
       6,    17,    68,    11,    12,    11,    12,    25,    16,    15,
      16,    16,    30,    18,    20,    26,    27,    28,    29,    30,
      31,    15,    16,    75,    18,    12,    78,     9,    10,    22,
      23,    97,    24,    25,    14,    19,    19,    18,    15,    11,
      16,    20,    16,   109,    15,    13,    21,    17,    15,     3,
      14,    17,    17,     3,    17,     4,    16,    19,    17,     5,
      21,    30,   105,    97,    22,    -1,    44,    81
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    41,    42,    43,    44,    45,    47,     0,
      42,    11,    15,    16,    18,    47,    48,    49,    50,    12,
      11,    17,    14,    19,    18,    20,    46,    49,    15,    19,
      44,    47,    51,    51,    11,     4,     5,     6,    11,    12,
      15,    16,    46,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    64,    66,    68,    69,    16,    15,
      59,    16,    16,    18,    59,    21,    52,    15,    13,    26,
      27,    28,    29,    30,    31,    63,    22,    23,    65,    24,
      25,    67,    59,    15,    59,    59,    70,    71,    59,    17,
      59,    61,    64,    64,    66,    17,    17,    14,    17,    19,
      53,    56,    53,    71,     3,     3,    53,     4,    57,    16,
      59,    17,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    44,    45,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    69,    70,    70,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     6,
       4,     1,     1,     1,     0,     3,     1,     2,     4,     2,
       0,     0,     2,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     7,     5,     7,     5,     3,     1,     3,     2,
       1,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     4,     1,     0,     3,     1
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
  YYLTYPE *yylloc;
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 81 "parser.y"
                            { 
            (yyval.node) = gen_expr(0,"Program", 1, (yyvsp[0].node) ); 
            head = (yyval.node);
        }
#line 1644 "parser.cpp"
    break;

  case 3: /* declaration_list: declaration declaration_list  */
#line 88 "parser.y"
                                        { (yyval.node) = gen_expr( 0, "declaration_list", 2, (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1650 "parser.cpp"
    break;

  case 4: /* declaration_list: declaration  */
#line 89 "parser.y"
                                        { (yyval.node) = gen_expr( 1, "declaretion_list", 1, (yyvsp[0].node) ); }
#line 1656 "parser.cpp"
    break;

  case 5: /* declaration: var_declaration  */
#line 93 "parser.y"
                                        { (yyval.node) = gen_expr( 2, "declaration", 1, (yyvsp[0].node) ); }
#line 1662 "parser.cpp"
    break;

  case 6: /* declaration: fun_declaration  */
#line 94 "parser.y"
                                        { (yyval.node) = gen_expr( 2, "declaration", 1, (yyvsp[0].node) ); }
#line 1668 "parser.cpp"
    break;

  case 7: /* var_declaration: type_specifier ID O_SEMI  */
#line 98 "parser.y"
                                                                               { (yyval.node) = gen_expr( 0, "var_declaration", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1674 "parser.cpp"
    break;

  case 8: /* var_declaration: type_specifier ID O_LMBRACKER NUM O_RMBRACKER O_SEMI  */
#line 99 "parser.y"
                                                                { (yyval.node) = gen_expr( 0, "var_declaration", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1680 "parser.cpp"
    break;

  case 9: /* fun_declaration: type_specifier ID O_LSBRACKER params O_RSBRACKER compound_stmt  */
#line 104 "parser.y"
        { (yyval.node) = gen_expr( 0, "fun_declare", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1686 "parser.cpp"
    break;

  case 10: /* compound_stmt: O_LLBRACKER local_declaration statement_list O_RLBRACKER  */
#line 109 "parser.y"
        { (yyval.node) = gen_expr( 0, "compound_stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1692 "parser.cpp"
    break;

  case 11: /* type_specifier: K_INT  */
#line 113 "parser.y"
                        { (yyval.node) = gen_expr( 2, "type", 1, (yyvsp[0].node) ); }
#line 1698 "parser.cpp"
    break;

  case 12: /* type_specifier: K_VOID  */
#line 114 "parser.y"
                        { (yyval.node) = gen_expr( 2, "type", 1, (yyvsp[0].node) ); }
#line 1704 "parser.cpp"
    break;

  case 13: /* params: param_list  */
#line 118 "parser.y"
                        { (yyval.node) = gen_expr( 0, "params", 1, (yyvsp[0].node) ); }
#line 1710 "parser.cpp"
    break;

  case 14: /* params: %empty  */
#line 119 "parser.y"
                        { (yyval.node) = NULL; }
#line 1716 "parser.cpp"
    break;

  case 15: /* param_list: param O_COMMA param_list  */
#line 123 "parser.y"
                                       { (yyval.node) = gen_expr( 0, "param_list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1722 "parser.cpp"
    break;

  case 16: /* param_list: param  */
#line 124 "parser.y"
                                        { (yyval.node) = gen_expr( 0, "param_list", 1, (yyvsp[0].node) ); }
#line 1728 "parser.cpp"
    break;

  case 17: /* param: type_specifier ID  */
#line 128 "parser.y"
                                                       { (yyval.node) = gen_expr( 0, "param", 2, (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1734 "parser.cpp"
    break;

  case 18: /* param: type_specifier ID O_LMBRACKER O_RMBRACKER  */
#line 129 "parser.y"
                                                      { (yyval.node) = gen_expr( 0, "param", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1740 "parser.cpp"
    break;

  case 19: /* local_declaration: var_declaration local_declaration  */
#line 133 "parser.y"
                                                 { (yyval.node) = gen_expr( 0, "local_declaration", 2, (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1746 "parser.cpp"
    break;

  case 20: /* local_declaration: %empty  */
#line 134 "parser.y"
                                                             { (yyval.node) = NULL; }
#line 1752 "parser.cpp"
    break;

  case 21: /* statement_list: %empty  */
#line 138 "parser.y"
                                { (yyval.node) = NULL; }
#line 1758 "parser.cpp"
    break;

  case 22: /* statement_list: statement statement_list  */
#line 139 "parser.y"
                                { (yyval.node) = gen_expr( 6, "statement_list", 2, (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1764 "parser.cpp"
    break;

  case 23: /* statement: expression_stmt  */
#line 143 "parser.y"
                                    { (yyval.node) = gen_expr( 9, "statement", 1, (yyvsp[0].node) ); }
#line 1770 "parser.cpp"
    break;

  case 24: /* statement: compound_stmt  */
#line 144 "parser.y"
                                    { (yyval.node) = gen_expr( 12, "statement", 1, (yyvsp[0].node) ); }
#line 1776 "parser.cpp"
    break;

  case 25: /* statement: selection_stmt  */
#line 145 "parser.y"
                                    { (yyval.node) = gen_expr( 12, "statement", 1, (yyvsp[0].node) ); }
#line 1782 "parser.cpp"
    break;

  case 26: /* statement: iteration_stmt  */
#line 146 "parser.y"
                                    { (yyval.node) = gen_expr( 13, "statement", 1, (yyvsp[0].node) ); }
#line 1788 "parser.cpp"
    break;

  case 27: /* statement: return_stmt  */
#line 147 "parser.y"
                                    { (yyval.node) = gen_expr( 14, "statement", 1, (yyvsp[0].node) ); }
#line 1794 "parser.cpp"
    break;

  case 28: /* expression_stmt: expression O_SEMI  */
#line 151 "parser.y"
                            { (yyval.node) = gen_expr( 0, "expression_stmt", 2, (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1800 "parser.cpp"
    break;

  case 29: /* expression_stmt: O_SEMI  */
#line 152 "parser.y"
                            { (yyval.node) = gen_expr( 0, "expression_stmt", 1, (yyvsp[0].node) ); }
#line 1806 "parser.cpp"
    break;

  case 30: /* selection_stmt: matched_if  */
#line 155 "parser.y"
                    { (yyval.node) = gen_expr( 0, "expression_stmt", 1, (yyvsp[0].node) ); }
#line 1812 "parser.cpp"
    break;

  case 31: /* selection_stmt: unmatched_if  */
#line 156 "parser.y"
                    { (yyval.node) = gen_expr( 0, "expression_stmt", 1, (yyvsp[0].node) ); }
#line 1818 "parser.cpp"
    break;

  case 32: /* matched_if: K_IF O_LSBRACKER expression O_RSBRACKER statement K_ELSE statement  */
#line 159 "parser.y"
                                                                       { 
        (yyval.node) = gen_expr( 18, "matched_if", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); 
 //       $$->addCode( $3  );
//        $$->addCode( Code( "", iftrue, $3->place, "", $5->lable ) );
//        $$->addCode( Code( "", jump,   "",        "", $7->lable ) )
//        $1->false = $7
    }
#line 1830 "parser.cpp"
    break;

  case 33: /* unmatched_if: K_IF O_LSBRACKER expression O_RSBRACKER statement  */
#line 169 "parser.y"
        { (yyval.node) = gen_expr( 16, "unmatched_if", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1836 "parser.cpp"
    break;

  case 34: /* unmatched_if: K_IF O_LSBRACKER expression O_RSBRACKER matched_if K_ELSE unmatched_if  */
#line 171 "parser.y"
        { (yyval.node) = gen_expr( 18, "unmatched_if", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1842 "parser.cpp"
    break;

  case 35: /* iteration_stmt: K_WHILE O_LSBRACKER expression O_RSBRACKER statement  */
#line 176 "parser.y"
        { (yyval.node) = gen_expr( 18, "While", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1848 "parser.cpp"
    break;

  case 36: /* expression: var O_ASSIGN expression  */
#line 179 "parser.y"
                                    { (yyval.node) = gen_expr( 0, "expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1854 "parser.cpp"
    break;

  case 37: /* expression: simple_expression  */
#line 180 "parser.y"
                                    { (yyval.node) = gen_expr( 0, "expression", 1, (yyvsp[0].node) ); }
#line 1860 "parser.cpp"
    break;

  case 38: /* return_stmt: K_RETURN expression O_SEMI  */
#line 183 "parser.y"
                                                { (yyval.node) = gen_expr( 0, "Return", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1866 "parser.cpp"
    break;

  case 39: /* return_stmt: K_RETURN O_SEMI  */
#line 184 "parser.y"
                                        { (yyval.node) = gen_expr( 28, "Return", 2, (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1872 "parser.cpp"
    break;

  case 40: /* var: ID  */
#line 187 "parser.y"
                                             { (yyval.node) = gen_expr( 2, "Id", 1, (yyvsp[0].node) );}
#line 1878 "parser.cpp"
    break;

  case 41: /* var: ID O_LMBRACKER expression O_RMBRACKER  */
#line 188 "parser.y"
                                             { (yyval.node) = gen_expr( 29, "Id", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) );}
#line 1884 "parser.cpp"
    break;

  case 42: /* simple_expression: additive_expression relop additive_expression  */
#line 191 "parser.y"
                                                  { (yyval.node) = gen_expr( 0, "Return", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1890 "parser.cpp"
    break;

  case 43: /* simple_expression: additive_expression  */
#line 192 "parser.y"
                                                    { (yyval.node) = gen_expr( 2, "Id", 1, (yyvsp[0].node) ); }
#line 1896 "parser.cpp"
    break;

  case 44: /* relop: O_L_EQUAL  */
#line 195 "parser.y"
                { (yyval.node) = gen_expr( 2, "relop", 1, (yyvsp[0].node) ); }
#line 1902 "parser.cpp"
    break;

  case 45: /* relop: O_LESS  */
#line 196 "parser.y"
                { (yyval.node) = gen_expr( 2, "relop", 1, (yyvsp[0].node) ); }
#line 1908 "parser.cpp"
    break;

  case 46: /* relop: O_GREATER  */
#line 197 "parser.y"
                { (yyval.node) = gen_expr( 2, "relop", 1, (yyvsp[0].node) ); }
#line 1914 "parser.cpp"
    break;

  case 47: /* relop: O_G_EQUAL  */
#line 198 "parser.y"
                { (yyval.node) = gen_expr( 2, "relop", 1, (yyvsp[0].node) ); }
#line 1920 "parser.cpp"
    break;

  case 48: /* relop: O_EQUAL  */
#line 199 "parser.y"
                { (yyval.node) = gen_expr( 2, "relop", 1, (yyvsp[0].node) ); }
#line 1926 "parser.cpp"
    break;

  case 49: /* relop: O_U_EQUAL  */
#line 200 "parser.y"
                { (yyval.node) = gen_expr( 2, "relop", 1, (yyvsp[0].node) ); }
#line 1932 "parser.cpp"
    break;

  case 50: /* additive_expression: term addop additive_expression  */
#line 203 "parser.y"
                                    { (yyval.node) = gen_expr( 28, "additive_expression", 2, (yyvsp[-2].node), (yyvsp[-1].node) ); }
#line 1938 "parser.cpp"
    break;

  case 51: /* additive_expression: term  */
#line 204 "parser.y"
                                    { (yyval.node) = gen_expr( 2, "additive_expression", 1, (yyvsp[0].node) );}
#line 1944 "parser.cpp"
    break;

  case 52: /* addop: O_ADD  */
#line 207 "parser.y"
            { (yyval.node) = gen_expr( 2, "addop", 1, (yyvsp[0].node) ); }
#line 1950 "parser.cpp"
    break;

  case 53: /* addop: O_SUB  */
#line 208 "parser.y"
            { (yyval.node) = gen_expr( 2, "addop", 1, (yyvsp[0].node) ); }
#line 1956 "parser.cpp"
    break;

  case 54: /* term: factor mulop term  */
#line 211 "parser.y"
                        { 
        (yyval.node) = gen_expr( 0, "term", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) );
//        $$->place = newTemp();
//        $$->addCode( $1 );
//        $$->addCode( $3 );
//        $$->addCode( Lable("",""), )
    }
#line 1968 "parser.cpp"
    break;

  case 55: /* term: factor  */
#line 218 "parser.y"
                        { (yyval.node) = gen_expr( 2, "term", 1, (yyvsp[0].node) );}
#line 1974 "parser.cpp"
    break;

  case 56: /* mulop: O_MUL  */
#line 221 "parser.y"
            { (yyval.node) = gen_expr( 2, "mulop", 1, (yyvsp[0].node) ); }
#line 1980 "parser.cpp"
    break;

  case 57: /* mulop: O_DIV  */
#line 222 "parser.y"
            { (yyval.node) = gen_expr( 2, "mulop", 1, (yyvsp[0].node) ); }
#line 1986 "parser.cpp"
    break;

  case 58: /* factor: O_LSBRACKER expression O_RSBRACKER  */
#line 225 "parser.y"
                                        { (yyval.node) = gen_expr( 0, "factor", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 1992 "parser.cpp"
    break;

  case 59: /* factor: var  */
#line 226 "parser.y"
                                        { (yyval.node) = gen_expr( 2, "factor", 1, (yyvsp[0].node) ); }
#line 1998 "parser.cpp"
    break;

  case 60: /* factor: call  */
#line 227 "parser.y"
                                        { (yyval.node) = gen_expr( 2, "factor", 1, (yyvsp[0].node) ); }
#line 2004 "parser.cpp"
    break;

  case 61: /* factor: NUM  */
#line 228 "parser.y"
                                        { (yyval.node) = gen_expr( 2, "factor", 1, (yyvsp[0].node) ); }
#line 2010 "parser.cpp"
    break;

  case 62: /* call: ID O_LSBRACKER args O_RSBRACKER  */
#line 231 "parser.y"
                                        { (yyval.node) = gen_expr( 29, "call", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) );}
#line 2016 "parser.cpp"
    break;

  case 63: /* args: arg_list  */
#line 234 "parser.y"
                { (yyval.node) = gen_expr( 2, "args", 1, (yyvsp[0].node) ); }
#line 2022 "parser.cpp"
    break;

  case 64: /* args: %empty  */
#line 235 "parser.y"
                { (yyval.node) = NULL; }
#line 2028 "parser.cpp"
    break;

  case 65: /* arg_list: expression O_COMMA arg_list  */
#line 238 "parser.y"
                                { (yyval.node) = gen_expr( 0, "arg_list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node) ); }
#line 2034 "parser.cpp"
    break;

  case 66: /* arg_list: expression  */
#line 239 "parser.y"
                                { (yyval.node) = gen_expr( 2, "arg_list", 1, (yyvsp[0].node) ); }
#line 2040 "parser.cpp"
    break;


#line 2044 "parser.cpp"

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
  *++yylsp = yyloc;

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
          = {yyssp, yytoken, &yylloc};
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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
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

#line 242 "parser.y"


Node *  gen_expr(int type, string value , int n, ...){
    va_list pvar;   
    va_start (pvar, n);
    Node * new_node = new Var(value);
    Node * temp = new_node;
    for (int i=0;i<n;i++){
        Node * f = va_arg (pvar, Node *);
        if (f != NULL){
            if(temp == new_node)
                temp->lchild = f;
            else 
                temp->rchild = f;

            for( int i = 0; i < f->codes.size(); i++ )
                new_node->codes.push_back(f->codes[i]);
            
            temp = f;
        }
    }
    va_end (pvar);  
    return new_node;
}

void reveal(Node * node){
    static int depth = 0;
    if(!node)return;
    depth++;
    
    for(int i = 0; i < depth-1;i++)cout << "|  ";
    cout << node->toString()<< endl;

    reveal(node->lchild);
    depth--;
    reveal(node->rchild);
    
}

/*string to_string(int a){
    string ret = "";
//    while(a){
//        int t = a%10;
//        a/=10;
//        ret = string( '0' + t ) + ret; 
//    }
    return ret;
}*/

string genTemp(){
    static int no = 0; 
    string ret = "t";
    ret += to_string(no++);
    return ret;
}

string gen_line_id(int no){
    string ret = "L";
    ret += to_string(no);
    return ret;
}

int main(int argc,char* argv[]) {
    //yyout = fopen( "out.txt", "w" );
    yyin = fopen(argv[1],"r");
    //while(yylex());
    yyparse();
    reveal(head);
}
