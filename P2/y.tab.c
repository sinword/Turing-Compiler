/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "yacc.y" /* yacc.c:339  */

#include "symboltable.hpp"
#define Trace(t)        { /*printf("Reducing %s\n", t);*/ }
#define table_msg(msg)    { printf("\n\033[34m\033[47m%s\033[0m\n", msg); }
extern int yylex(void);
extern void warning(char *msg);
extern void yyerror(char *msg);

TableList table_stack;
SymbolTable current_table;
vector<Data> para_list;
Func_return func_return;

#line 80 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DOT = 258,
    COMMA = 259,
    COLON = 260,
    LPAREN = 261,
    RPAREN = 262,
    LBRACKET = 263,
    RBRACKET = 264,
    LBRACE = 265,
    RBRACE = 266,
    SEMICOLON = 267,
    ASSIGN = 268,
    PUT = 269,
    _BEGIN = 270,
    DECREASING = 271,
    DEFAULT = 272,
    DO = 273,
    WHEN = 274,
    IF = 275,
    ELSE = 276,
    END = 277,
    EXIT = 278,
    FOR = 279,
    FUNCTION = 280,
    GET = 281,
    LOOP = 282,
    OF = 283,
    PROCEDURE = 284,
    REAL = 285,
    RESULT = 286,
    RETURN = 287,
    SKIP = 288,
    THEN = 289,
    VAR = 290,
    CONST = 291,
    INT = 292,
    STRING = 293,
    ARRAY = 294,
    BOOL = 295,
    NOT = 296,
    AND = 297,
    OR = 298,
    LT = 299,
    LE = 300,
    EQ = 301,
    GE = 302,
    GT = 303,
    NE = 304,
    ADD = 305,
    SUB = 306,
    MUL = 307,
    DIV = 308,
    MOD = 309,
    UMINUS = 310,
    I_CONST = 311,
    F_CONST = 312,
    STR_CONST = 313,
    ID = 314,
    TRUE = 315,
    FALSE = 316
  };
#endif
/* Tokens.  */
#define DOT 258
#define COMMA 259
#define COLON 260
#define LPAREN 261
#define RPAREN 262
#define LBRACKET 263
#define RBRACKET 264
#define LBRACE 265
#define RBRACE 266
#define SEMICOLON 267
#define ASSIGN 268
#define PUT 269
#define _BEGIN 270
#define DECREASING 271
#define DEFAULT 272
#define DO 273
#define WHEN 274
#define IF 275
#define ELSE 276
#define END 277
#define EXIT 278
#define FOR 279
#define FUNCTION 280
#define GET 281
#define LOOP 282
#define OF 283
#define PROCEDURE 284
#define REAL 285
#define RESULT 286
#define RETURN 287
#define SKIP 288
#define THEN 289
#define VAR 290
#define CONST 291
#define INT 292
#define STRING 293
#define ARRAY 294
#define BOOL 295
#define NOT 296
#define AND 297
#define OR 298
#define LT 299
#define LE 300
#define EQ 301
#define GE 302
#define GT 303
#define NE 304
#define ADD 305
#define SUB 306
#define MUL 307
#define DIV 308
#define MOD 309
#define UMINUS 310
#define I_CONST 311
#define F_CONST 312
#define STR_CONST 313
#define ID 314
#define TRUE 315
#define FALSE 316

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 248 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   402

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    44,    47,    50,    53,    57,    69,    93,
     100,   113,   120,   127,   137,   159,   163,   183,   220,   257,
     294,   331,   346,   361,   380,   398,   412,   430,   448,   462,
     477,   492,   500,   505,   510,   515,   535,   557,   562,   567,
     575,   579,   583,   587,   594,   594,   636,   636,   684,   684,
     722,   722,   775,   790,   801,   825,   848,   851,   854,   858,
     861,   864,   867,   870,   873,   876,   879,   882,   885,   891,
     891,   906,   985,  1054,  1071,  1104,  1132,  1138,  1146,  1149,
    1161,  1167,  1176,  1167,  1185,  1192,  1192,  1208,  1208,  1222,
    1222,  1281,  1281,  1349,  1406,  1515,  1520
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "COMMA", "COLON", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "SEMICOLON",
  "ASSIGN", "PUT", "_BEGIN", "DECREASING", "DEFAULT", "DO", "WHEN", "IF",
  "ELSE", "END", "EXIT", "FOR", "FUNCTION", "GET", "LOOP", "OF",
  "PROCEDURE", "REAL", "RESULT", "RETURN", "SKIP", "THEN", "VAR", "CONST",
  "INT", "STRING", "ARRAY", "BOOL", "NOT", "AND", "OR", "LT", "LE", "EQ",
  "GE", "GT", "NE", "ADD", "SUB", "MUL", "DIV", "MOD", "UMINUS", "I_CONST",
  "F_CONST", "STR_CONST", "ID", "TRUE", "FALSE", "$accept", "program",
  "variable_declaration", "const_variable_declaration",
  "var_variable_declaration", "const_expr", "const_val", "datatype",
  "function_declaration", "$@1", "$@2", "procedure_declaration", "$@3",
  "$@4", "para_declaration", "block_program", "stmt", "block_stmt", "$@5",
  "assign_stmt", "put_stmt", "get_stmt", "result_stmt", "exit_stmt",
  "skip_stmt", "if_stmt", "$@6", "$@7", "end_if_stmt", "$@8", "loop_stmt",
  "$@9", "for_stmt", "$@10", "$@11", "function_call_stmt",
  "function_call_para", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,   101,   -87,   101,    10,   -13,    -7,    -3,   -87,     5,
     101,   -87,   -87,    23,    31,     0,    79,    -8,    -8,    -8,
      -8,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   101,   101,   101,   -87,   -87,   -87,    39,   -87,   -87,
     337,   -87,   -87,   319,   314,   101,    36,   -87,    91,    97,
     319,    98,   337,     9,    37,   101,   101,   -87,   -87,   -87,
     -87,   -87,   191,   348,   -87,    42,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     319,    84,   319,   -87,   337,   -87,   103,    -6,   101,    87,
      -2,    -4,   101,   -87,   135,   101,   -87,   251,   337,   -87,
     -87,   173,   104,   264,   348,   348,   116,   116,   116,   116,
     116,   116,    32,    32,   -87,   -87,   -87,   -87,   -87,   -87,
     319,   105,   101,   113,   114,   115,   278,    93,   -87,   118,
     -87,   -87,   -87,    70,   -87,   110,   337,   122,   337,   123,
     101,   -87,   -87,   -87,   101,   143,   135,    94,   124,   -87,
     -87,   319,   -87,   136,   101,   101,   101,   -87,    67,   160,
     137,   -87,    82,   141,   135,   119,   319,   145,   337,   337,
     337,   -87,   129,   -87,   147,   101,   319,   161,   112,   -87,
     117,   156,   125,   319,   -87,   101,   232,   157,   177,   -87,
     319,   -87,   140,   154,   178,   232,   179,   169,   127,   207,
     -87,   135,   210,   209,   208,   -87,   220,   190,   -87,   -87,
     226,   -87,   135,   -87,   -87,   247,   112,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,    69,     0,    78,     0,     0,     0,    87,     0,
       0,    77,    80,     0,     0,     0,     0,     6,     6,     6,
       6,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,     0,     0,    32,    33,    34,    35,    37,    38,
      73,    15,    39,    58,     0,     0,     0,    89,     0,    74,
      58,     0,    76,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     0,    29,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,    58,    81,    79,    91,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     7,     0,    71,    31,
      93,    95,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    19,    20,    17,    18,    16,    56,    70,    57,
      58,     0,     0,     0,     0,     0,     0,     0,    48,     0,
      41,    40,    42,     0,    43,    12,    11,     0,     9,     0,
       0,    94,    36,    82,     0,     0,     0,     0,     0,    75,
      88,    58,    50,     0,     0,     0,     0,    96,     0,     0,
       0,    44,     0,    52,     0,     0,    58,     0,    13,    10,
      72,    85,     0,    83,     0,     0,    58,     0,     0,    46,
       0,     0,     0,    58,    84,     0,    58,     0,     0,    53,
      58,    49,     0,     0,     0,    58,     0,     0,     0,     0,
      51,     0,     0,     0,     0,    45,     0,     0,    14,    86,
       0,    90,     0,    47,    92,    54,     0,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,    41,    20,   -87,   -87,    -1,   -87,   -84,   -87,   -87,
     -87,   -87,   -87,   -87,   -86,   -39,    96,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    80,    96,    93,   101,    41,   135,    18,   176,
     190,    19,   151,   166,   125,    81,    82,    21,    43,    22,
      23,    24,    25,    26,    27,    28,   120,   158,   173,   183,
      29,    50,    30,    86,   121,    42,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,   123,    44,    46,   129,   128,     1,     2,    55,    52,
     137,    89,     3,    56,    91,     4,     5,     6,     7,     8,
      17,     9,    92,    10,    11,    12,   130,    13,    14,    45,
      62,    63,    64,   131,   132,   133,   134,    17,    17,    17,
      17,   117,    94,   119,    84,    65,    47,    66,    31,   100,
      95,    15,    48,   124,    97,    98,    49,   124,    58,    59,
      60,    61,   161,   163,    51,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    57,
     179,   143,    53,    32,    77,    78,    79,   126,   171,   172,
      54,   136,   189,    33,   138,    85,    20,    87,    34,    35,
      36,    37,    38,    39,    90,    88,   118,    31,   122,   127,
     144,   141,   165,    20,    20,    20,    20,   208,   146,   147,
     150,   145,   148,   154,   130,   152,   153,   181,   215,   164,
     217,   131,   132,   162,   134,   155,   156,   187,   177,   167,
     175,   180,    32,   159,   194,   178,   160,   196,   182,   184,
     185,   199,    33,   168,   169,   170,   203,    34,    35,    36,
      37,    38,    39,   174,   188,   130,    75,    76,    77,    78,
      79,   124,   131,   132,   186,   134,   191,   140,   192,   197,
     198,   193,   201,   206,   195,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    99,   200,
     202,   204,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,   205,   207,
     209,   210,   211,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     1,     2,   212,   213,
     214,   216,     3,     0,     0,     4,     5,     0,     7,     8,
     139,   157,     0,    10,    11,    12,     0,    13,    14,     0,
       0,     0,     0,   142,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,   149,     0,     0,
       0,    15,     0,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     1,     2,     0,     0,     0,     0,     3,
       0,     0,     4,     5,     0,     7,     8,     0,    83,     0,
      10,    11,    12,     0,    13,    14,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79
};

static const yytype_int16 yycheck[] =
{
       1,     7,     3,    16,    90,     7,    14,    15,     8,    10,
      94,    50,    20,    13,     5,    23,    24,    25,    26,    27,
       0,    29,    13,    31,    32,    33,    30,    35,    36,    19,
      31,    32,    33,    37,    38,    39,    40,    17,    18,    19,
      20,    80,     5,    82,    45,     6,    59,     8,     6,     7,
      13,    59,    59,    59,    55,    56,    59,    59,    17,    18,
      19,    20,   146,   147,    59,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
     164,   120,    59,    41,    52,    53,    54,    88,    21,    22,
      59,    92,   178,    51,    95,    59,     0,     6,    56,    57,
      58,    59,    60,    61,     6,     8,    22,     6,     5,    22,
       5,     7,   151,    17,    18,    19,    20,   201,     5,     5,
      27,   122,     7,    13,    30,     7,    56,   166,   212,     5,
     216,    37,    38,    39,    40,    13,    13,   176,    56,     3,
       3,    22,    41,   144,   183,     4,     3,   186,     3,    20,
       3,   190,    51,   154,   155,   156,   195,    56,    57,    58,
      59,    60,    61,     3,     3,    30,    50,    51,    52,    53,
      54,    59,    37,    38,   175,    40,    59,     4,    22,    22,
       3,    56,    28,    56,   185,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     7,    59,
      22,    22,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    59,    22,
      20,    22,    24,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    14,    15,    28,    59,
      24,     4,    20,    -1,    -1,    23,    24,    -1,    26,    27,
       9,   140,    -1,    31,    32,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,     9,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,     9,    -1,    -1,
      -1,    59,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    14,    15,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    23,    24,    -1,    26,    27,    -1,    34,    -1,
      31,    32,    33,    -1,    35,    36,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    20,    23,    24,    25,    26,    27,    29,
      31,    32,    33,    35,    36,    59,    63,    64,    70,    73,
      78,    79,    81,    82,    83,    84,    85,    86,    87,    92,
      94,     6,    41,    51,    56,    57,    58,    59,    60,    61,
      67,    68,    97,    80,    67,    19,    16,    59,    59,    59,
      93,    59,    67,    59,    59,     8,    13,     0,    63,    63,
      63,    63,    67,    67,    67,     6,     8,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      64,    77,    78,    34,    67,    59,    95,     6,     8,    77,
       6,     5,    13,    66,     5,    13,    65,    67,    67,     7,
       7,    67,    98,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    77,    22,    77,
      88,    96,     5,     7,    59,    76,    67,    22,     7,    76,
      30,    37,    38,    39,    40,    69,    67,    69,    67,     9,
       4,     7,     9,    77,     5,    67,     5,     5,     7,     9,
      27,    74,     7,    56,    13,    13,    13,    98,    89,    67,
       3,    69,    39,    69,     5,    77,    75,     3,    67,    67,
      67,    21,    22,    90,     3,     3,    71,    56,     4,    69,
      22,    77,     3,    91,    20,     3,    67,    77,     3,    76,
      72,    59,    22,    56,    77,    67,    77,    22,     3,    77,
      59,    28,    22,    77,    22,    59,    56,    22,    69,    20,
      22,    24,    28,    59,    24,    69,     4,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    71,    70,    72,    70,    74,    73,
      75,    73,    76,    76,    76,    76,    77,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    80,
      79,    81,    81,    82,    83,    83,    84,    84,    85,    85,
      86,    88,    89,    87,    90,    91,    90,    93,    92,    95,
      94,    96,    94,    97,    97,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     0,     3,     3,     2,
       4,     2,     2,     4,     8,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     0,    10,     0,    11,     0,     8,
       0,     9,     3,     5,     9,    11,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     3,     6,     2,     2,     5,     2,     1,     1,     3,
       1,     0,     0,     7,     2,     0,     5,     0,     5,     0,
      11,     0,    12,     3,     4,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 41 "yacc.y" /* yacc.c:1646  */
    {
                Trace("program -> variable_declaration program");
        }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 44 "yacc.y" /* yacc.c:1646  */
    {
                Trace("program -> function_declaration program");
        }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 47 "yacc.y" /* yacc.c:1646  */
    {
                Trace("program -> procedure_declaration program");
        }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 50 "yacc.y" /* yacc.c:1646  */
    {
                Trace("program -> stmt program");
        }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 57 "yacc.y" /* yacc.c:1646  */
    {
                Trace("variable_declaration -> CONST ID const_variable_declaration");
                Data new_data;
                new_data.id = (yyvsp[-1].value).s_val;
                new_data.kind = Kind::const_kind;
                new_data.type = (yyvsp[0].data).type;
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of const in current scope");
                }
                
                // current_table.dump();
        }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "yacc.y" /* yacc.c:1646  */
    {
                Trace("variable_declaration -> VAR ID var_variable_declaration");
                Data new_data;
                new_data.id = (yyvsp[-1].value).s_val;
                new_data.kind = Kind::var_kind;
                new_data.type = (yyvsp[0].data).type;
                if ((yyvsp[0].data).array.empty()) {
                        new_data.value = (yyvsp[0].data).value;
                }
                else {
                        new_data.arr_start = (yyvsp[0].data).arr_start;
                        new_data.arr_end = (yyvsp[0].data).arr_end;
                        new_data.array = (yyvsp[0].data).array;
                }

                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of var in current scope");
                }
        
                // current_table.dump();
        }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_variable_declaration -> ASSIGN const_expr");
                Data return_data;
                return_data.type = (yyvsp[0].data).type;
                return_data.kind = Kind::const_kind;
                (yyval.data) = return_data;
        }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 100 "yacc.y" /* yacc.c:1646  */
    {
                Trace("cosnt_variable_declaration -> COLON datatype ASSIGN const_expr");
                Data return_data;
                return_data.type = (yyvsp[-2].type);
                return_data.kind = Kind::const_kind;
                if((yyvsp[-2].type) != (yyvsp[0].data).type) {
                        warning("Constant declaration datatype mismatch");
                }
                (yyval.data) = return_data;
        }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "yacc.y" /* yacc.c:1646  */
    {
                Trace("var_variable_declaration -> ASSIGN const_expr");
                Data return_data;
                return_data.type = (yyvsp[0].data).type;
                return_data.kind = Kind::var_kind;
                (yyval.data) = return_data;
        }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "yacc.y" /* yacc.c:1646  */
    {
                Trace("var_variable_declaration -> COLON datatype");
                Data return_data;
                return_data.type = (yyvsp[0].type);
                return_data.kind = Kind::var_kind;
                (yyval.data) = return_data;
        }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "yacc.y" /* yacc.c:1646  */
    {
                Trace("var_variable_declaration -> COLON datatype ASSIGN const_expr");
                Data return_data;
                return_data.type = (yyvsp[-2].type);
                return_data.kind = Kind::var_kind;
                if((yyvsp[-2].type) != (yyvsp[0].data).type) {
                        warning("Varaible declaration datatype mismatch");
                }
                (yyval.data) = return_data;
        }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 137 "yacc.y" /* yacc.c:1646  */
    {
                Trace("var_variable_declaration -> COLON ARRAY I_CONST DOT DOT I_CONST OF datatype");
                Data return_data;
                return_data.type = (yyvsp[0].type);
                return_data.arr_start = (yyvsp[-5].value).i_val;
                return_data.arr_end = (yyvsp[-2].value).i_val;
                return_data.kind = Kind::var_kind;
                
                if(return_data.arr_start > return_data.arr_end) {
                        warning("Array startFound index is larger than end index");
                }
                else {
                        Value new_value;
                        for(int i = 0; i <= (yyvsp[-2].value).i_val - (yyvsp[-5].value).i_val; i++) {
                                return_data.array.push_back(new_value);
                        }
                }
                (yyval.data) = return_data;
        }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 159 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> const_val");
                (yyval.data) = (yyvsp[0].data);
        }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 163 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> const_expr MOD const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("MOD operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::i_type) {
                        (yyval.data).type = Type::i_type;
                }
                else if(((yyvsp[-2].data).type == Type::i_type || (yyvsp[-2].data).type == Type::b_type) 
                        && ((yyvsp[0].data).type == Type::i_type || (yyvsp[0].data).type == Type::b_type)) {
                        warning("Type conversion from boolean to int");
                        (yyval.data).type = Type::i_type;
                }
                else {
                        warning("MOD operation on non-integer");
                        (yyval.data).type = Type::void_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 183 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> const_expr MUL const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("MUL operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::s_type || (yyvsp[0].data).type == Type::s_type) {
                        warning("MUL operation on string");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::i_type) {
                                (yyval.data).type = Type::i_type;
                        }
                        else if((yyvsp[-2].data).type == Type::f_type && (yyvsp[0].data).type == Type::f_type) {
                                (yyval.data).type = Type::f_type;
                        }
                        else if(((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::f_type)
                                || ((yyvsp[-2].data).type == Type::f_type && (yyvsp[0].data).type == Type::i_type)) {
                                warning("Type conversion from int to real");
                                (yyval.data).type = Type::f_type;
                        }
                        else if((yyvsp[-2].data).type == Type::b_type && (yyvsp[0].data).type != Type::b_type) {
                                warning("Type conversion from boolean to $3's type");
                                (yyval.data).type = (yyvsp[0].data).type;
                        }
                        else if((yyvsp[-2].data).type != Type::b_type && (yyvsp[0].data).type == Type::b_type) {
                                warning("Type conversion from boolean to $1's type");
                                (yyval.data).type = (yyvsp[-2].data).type;
                        }
                        else {
                                warning("Type conversion from boolean to integer");
                                (yyval.data).type = Type::i_type;
                        }
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 220 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> const_expr DIV const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("DIV operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::s_type || (yyvsp[0].data).type == Type::s_type) {
                        warning("DIV operation on string");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::i_type) {
                                (yyval.data).type = Type::i_type;
                        }
                        else if((yyvsp[-2].data).type == Type::f_type && (yyvsp[0].data).type == Type::f_type) {
                                (yyval.data).type = Type::f_type;
                        }
                        else if(((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::f_type)
                                || ((yyvsp[-2].data).type == Type::f_type && (yyvsp[0].data).type == Type::i_type)) {
                                warning("Type conversion from int to real");
                                (yyval.data).type = Type::f_type;
                        }
                        else if((yyvsp[-2].data).type == Type::b_type && (yyvsp[0].data).type != Type::b_type) {
                                warning("Type conversion from boolean to $3's type");
                                (yyval.data).type = (yyvsp[0].data).type;
                        }
                        else if((yyvsp[-2].data).type != Type::b_type && (yyvsp[0].data).type == Type::b_type) {
                                warning("Type conversion from boolean to $1's type");
                                (yyval.data).type = (yyvsp[-2].data).type;
                        }
                        else {
                                warning("Type conversion from boolean to integer");
                                (yyval.data).type = Type::i_type;
                        }
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 257 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> const_expr ADD const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("ADD operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::s_type || (yyvsp[0].data).type == Type::s_type) {
                        warning("ADD operation on string");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::i_type) {
                                (yyval.data).type = Type::i_type;
                        }
                        else if((yyvsp[-2].data).type == Type::f_type && (yyvsp[0].data).type == Type::f_type) {
                                (yyval.data).type = Type::f_type;
                        }
                        else if(((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::f_type)
                                || ((yyvsp[-2].data).type == Type::f_type && (yyvsp[0].data).type == Type::i_type)) {
                                warning("Type conversion from int to real");
                                (yyval.data).type = Type::f_type;
                        }
                        else if((yyvsp[-2].data).type == Type::b_type && (yyvsp[0].data).type != Type::b_type) {
                                warning("Type conversion from boolean to $3's type");
                                (yyval.data).type = (yyvsp[0].data).type;
                        }
                        else if((yyvsp[-2].data).type != Type::b_type && (yyvsp[0].data).type == Type::b_type) {
                                warning("Type conversion from boolean to $1's type");
                                (yyval.data).type = (yyvsp[-2].data).type;
                        }
                        else {
                                warning("Type conversion from boolean to integer");
                                (yyval.data).type = Type::i_type;
                        }
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 294 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> const_expr SUB const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("SUB operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::s_type || (yyvsp[0].data).type == Type::s_type) {
                        warning("SUB operation on string");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::i_type) {
                                (yyval.data).type = Type::i_type;
                        }
                        else if((yyvsp[-2].data).type == Type::f_type && (yyvsp[0].data).type == Type::f_type) {
                                (yyval.data).type = Type::f_type;
                        }
                        else if(((yyvsp[-2].data).type == Type::i_type && (yyvsp[0].data).type == Type::f_type)
                                || ((yyvsp[-2].data).type == Type::f_type && (yyvsp[0].data).type == Type::i_type)) {
                                warning("Type conversion from int to real");
                                (yyval.data).type = Type::f_type;
                        }
                        else if((yyvsp[-2].data).type == Type::b_type && (yyvsp[0].data).type != Type::b_type) {
                                warning("Type conversion from boolean to $3's type");
                                (yyval.data).type = (yyvsp[0].data).type;
                        }
                        else if((yyvsp[-2].data).type != Type::b_type && (yyvsp[0].data).type == Type::b_type) {
                                warning("Type conversion from boolean to $1's type");
                                (yyval.data).type = (yyvsp[-2].data).type;
                        }
                        else {
                                warning("Type conversion from boolean to integer");
                                (yyval.data).type = Type::i_type;
                        }
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 331 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> const_expr AND const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("AND operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::b_type && (yyvsp[0].data).type == Type::b_type) {
                        (yyval.data).type = Type::b_type;
                }
                else {
                        warning("AND operation on non-boolean");
                        (yyval.data).type = Type::void_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 346 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> const_expr OR const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("OR operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::b_type && (yyvsp[0].data).type == Type::b_type) {
                        (yyval.data).type = Type::b_type;
                }
                else {
                        warning("OR operation on non-boolean");
                        (yyval.data).type = Type::void_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 361 "yacc.y" /* yacc.c:1646  */
    { // Less Than
                Trace("const_expr -> const_expr LT const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("LT operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::s_type || (yyvsp[0].data).type == Type::s_type) {
                        warning("LT operation on string");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        // only int, real, bool
                        if((yyvsp[-2].data).type != (yyvsp[0].data).type) {
                                warning("Auto type conversion");
                        }
                        (yyval.data).type = Type::b_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 380 "yacc.y" /* yacc.c:1646  */
    { // Less Equal
                Trace("const_expr -> const_expr LE const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("LE operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::s_type || (yyvsp[0].data).type == Type::s_type) {
                        warning("LE operation on string");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type != (yyvsp[0].data).type) {
                                warning("Auto type conversion");
                        }
                        (yyval.data).type = Type::b_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 398 "yacc.y" /* yacc.c:1646  */
    { // Equal
                Trace("const_expr -> const_expr EQ const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("EQ operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type != (yyvsp[0].data).type) {
                                warning("Auto type conversion");
                        }
                        (yyval.data).type = Type::b_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 412 "yacc.y" /* yacc.c:1646  */
    { // Greater Equal
                Trace("const_expr -> const_expr GE const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("GE operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::s_type || (yyvsp[0].data).type == Type::s_type) {
                        warning("GE operation on string");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type != (yyvsp[0].data).type) {
                                warning("Auto type conversion");
                        }
                        (yyval.data).type = Type::b_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 430 "yacc.y" /* yacc.c:1646  */
    { // Greater Than
                Trace("const_expr -> const_expr GE const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("GT operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[-2].data).type == Type::s_type || (yyvsp[0].data).type == Type::s_type) {
                        warning("GT operation on string");
                        (yyval.data).type= Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type != (yyvsp[0].data).type) {
                                warning("Auto type conversion");
                        }
                        (yyval.data).type = Type::b_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 448 "yacc.y" /* yacc.c:1646  */
    { // Not Equal
                Trace("const_expr -> const_expr NE const_expr");
                if((yyvsp[-2].data).type == Type::void_type || (yyvsp[0].data).type == Type::void_type) {
                        warning("NE operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        if((yyvsp[-2].data).type != (yyvsp[0].data).type) {
                                warning("Auto type conversion");
                        }
                        (yyval.data).type = Type::b_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 462 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> NOT const_expr");
                if((yyvsp[0].data).type == Type::void_type) {
                        warning("NOT operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[0].data).type == Type::b_type) {
                        (yyval.data).type = Type::b_type;
                }
                else {
                        warning("NOT operation on non-boolean");
                        (yyval.data).type = Type::void_type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 477 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> SUB const_expr");
                if((yyvsp[0].data).type == Type::void_type) {
                        warning("UMINUS operation on void");
                        (yyval.data).type = Type::void_type;
                }
                else if((yyvsp[0].data).type == Type::s_type) {
                        warning("UMINUS operation on string");
                        (yyval.data).type = Type::void_type;
                }
                else {
                        (yyval.data).type = (yyvsp[0].data).type;
                }
                (yyval.data).kind = Kind::const_kind;
        }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 492 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_expr -> LPAREN const_expr RPAREN");
                (yyval.data).type = (yyvsp[-1].data).type;
                (yyval.data).kind = (yyvsp[-1].data).kind;
        }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 500 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_val -> I_CONST");
                (yyval.data).type = Type::i_type;
                (yyval.data).kind = Kind::const_kind;
        }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 505 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_val -> F_CONST");
                (yyval.data).type = Type::f_type;
                (yyval.data).kind = Kind::const_kind;
        }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 510 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_val -> STR_CONST");
                (yyval.data).type = Type::s_type;
                (yyval.data).kind = Kind::const_kind;
        }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 515 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_val -> ID");
                auto iter = current_table.table.find((yyvsp[0].value).s_val);
                if(iter != current_table.table.end()) {
                        (yyval.data) = iter->second;
                }
                else {
                        int table_index = table_stack.lookup((yyvsp[0].value).s_val);
                        if(table_index != -1) {
                                Value new_value;
                                iter = table_stack.list[table_index].table.find((yyvsp[0].value).s_val);
                                (yyval.data) = iter->second;
                        }
                        else {
                                warning("Undeclared variable");
                                (yyval.data).type = Type::void_type;
                                (yyval.data).kind = Kind::const_kind;
                        }
                }
        }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 535 "yacc.y" /* yacc.c:1646  */
    { // array
                Trace("const_val -> ID LBRACKET const_expr RBRACKET");
                auto iter = current_table.table.find((yyvsp[-3].value).s_val);
                if(iter != current_table.table.end()) {
                        (yyval.data).type = iter->second.type;
                        (yyval.data).kind = Kind::var_kind;
                }
                else {
                        int table_index = table_stack.lookup((yyvsp[-3].value).s_val);
                        if(table_index != -1) {
                                Value new_value;
                                iter = table_stack.list[table_index].table.find((yyvsp[-3].value).s_val);
                                (yyval.data).type = iter->second.type;
                                (yyval.data).kind = Kind::var_kind;
                        }
                        else {
                                warning("Undeclared variable");
                                (yyval.data).type = Type::void_type;
                                (yyval.data).kind = Kind::var_kind;
                        }
                }
        }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 557 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_val -> TRUE");
                (yyval.data).type = Type::b_type;
                (yyval.data).kind = Kind::const_kind;
        }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 562 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_val -> FALSE");
                (yyval.data).type = Type::b_type;
                (yyval.data).kind = Kind::const_kind;
        }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 567 "yacc.y" /* yacc.c:1646  */
    {
                Trace("const_val -> function_call_stmt");
                (yyval.data).type = (yyvsp[0].data).type;
                (yyval.data).kind = Kind::const_kind;
        }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 575 "yacc.y" /* yacc.c:1646  */
    {
                Trace("datatype -> INT");
                (yyval.type) = Type::i_type;
        }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 579 "yacc.y" /* yacc.c:1646  */
    {
                Trace("datatype -> REAL");
                (yyval.type) = Type::f_type;
        }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 583 "yacc.y" /* yacc.c:1646  */
    {
                Trace("datatype -> STRING");
                (yyval.type) = Type::s_type;
        }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 587 "yacc.y" /* yacc.c:1646  */
    {
                Trace("datatype -> BOOL");
                (yyval.type) = Type::b_type;
        }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 594 "yacc.y" /* yacc.c:1646  */
    {
                Trace("function_declaration -> FUNCTION ID LPAREN RPAREN COLON datatype");
                Func_return new_func_return;
                func_return = new_func_return;
                func_return.return_type = Return_type::null;

                Data func_data;
                func_data.id = (yyvsp[-4].value).s_val;
                func_data.kind = Kind::func_kind;
                func_data.type = (yyvsp[0].type);
                
                if(!current_table.insert(func_data)) {
                        warning("Redeclaration of function in current scope");
                }
                
                // Trace("Function Level Table:")
                // current_table.dump();
                table_stack.insert(current_table);

                SymbolTable body_table;
                current_table = body_table;
        }
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 616 "yacc.y" /* yacc.c:1646  */
    {
                Trace("function_body -> block_program END ID");
                if((yyvsp[-8].value).s_val != (yyvsp[0].value).s_val) {
                        warning("Function name mismatch");
                }

                if(func_return.return_type != Return_type::result_type) {
                        warning("Function has no result statement");
                }
                else {
                        if(func_return.type != (yyvsp[-4].type)) {
                                warning("Function return type mismatch");
                        }
                }

                table_msg("function Table");
                current_table.dump();
                current_table = table_stack.get_top(); // switch back to function level table
                table_stack.pop();
        }
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 636 "yacc.y" /* yacc.c:1646  */
    {
                Trace("function_declaration -> FUNCTION ID LPAREN para_declaration RPAREN COLON datatype");
                Func_return new_func_return;
                func_return = new_func_return;
                func_return.return_type = Return_type::null;

                SymbolTable body_table;
                body_table = current_table;
                current_table = table_stack.get_top();
                table_stack.pop();

                Data func_data;
                func_data.id = (yyvsp[-5].value).s_val;
                func_data.kind = Kind::func_kind;
                func_data.type = (yyvsp[0].type);
                func_data.para_list = para_list;

                reverse(func_data.para_list.begin(), func_data.para_list.end());

                if(!current_table.insert(func_data)) {
                        warning("Redeclaration of function in current scope");
                }
                table_stack.insert(current_table);
                current_table = body_table;
        }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 661 "yacc.y" /* yacc.c:1646  */
    {
                Trace("function_body -> block_program END ID");
                if((yyvsp[-9].value).s_val != (yyvsp[0].value).s_val) {
                        warning("Function name mismatch");
                }

                if(func_return.return_type != Return_type::result_type) {
                        warning("Function has no result statement");
                }
                else {
                        if(func_return.type != (yyvsp[-4].type)) {
                                warning("Function return type mismatch");
                        }
                }

                table_msg("function Table");
                current_table.dump();
                current_table = table_stack.get_top(); // switch back to function level table
                table_stack.pop();
        }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 684 "yacc.y" /* yacc.c:1646  */
    {
                Trace("procedure_declaration -> PROCEDURE ID LPAREN RPAREN COLON datatype procedure_body");
                Func_return new_func_return;
                func_return = new_func_return;
                func_return.return_type = Return_type::null;

                Data proc_data;
                proc_data.id = (yyvsp[-2].value).s_val;
                proc_data.kind = Kind::proc_kind;
                proc_data.type = Type::void_type;

                if(!current_table.insert(proc_data)) {
                        warning("Redeclaration of function in current scope");
                }
                
                table_stack.insert(current_table);

                SymbolTable body_table;
                current_table = body_table;
        }
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 704 "yacc.y" /* yacc.c:1646  */
    {
                Trace("procedure_body -> block_program END ID");
                if((yyvsp[-6].value).s_val != (yyvsp[0].value).s_val) {
                        warning("Function name mismatch");
                }

                if(func_return.return_type == Return_type::result_type) {
                        warning("Procedure cannot return a value");
                }
                else if(func_return.return_type == Return_type::null) {
                        warning("Procedure has no return statement");
                }

                table_msg("procedure Table");
                current_table.dump();
                current_table = table_stack.get_top(); // switch back to function level table
                table_stack.pop();
        }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 722 "yacc.y" /* yacc.c:1646  */
    {
                Trace("procedure_declaration -> PROCEDURE ID LPAREN para_declaration RPAREN COLON datatype procedure_body");
                Func_return new_func_return;
                func_return = new_func_return;
                func_return.return_type = Return_type::null;

                SymbolTable body_table;
                body_table = current_table;
                current_table = table_stack.get_top();
                table_stack.pop();

                Data proc_data;
                proc_data.id = (yyvsp[-3].value).s_val;
                proc_data.kind = Kind::proc_kind;
                proc_data.type = Type::void_type;
                proc_data.para_list = para_list;
                reverse(proc_data.para_list.begin(), proc_data.para_list.end());
                // reverse the order of para_list

                if(table_stack.lookup(proc_data.id) == -1) {
                        if(!current_table.insert(proc_data)) {
                                warning("Redeclaration of function in current scope");
                        }
                }
                else {
                        warning("Reclaration of function in upper table");
                }

                table_stack.insert(current_table);
                current_table = body_table;
        }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 753 "yacc.y" /* yacc.c:1646  */
    {
                Trace("procedure_body -> block_program END ID");
                if((yyvsp[-7].value).s_val != (yyvsp[0].value).s_val) {
                        warning("Function name mismatch");
                }

                if(func_return.return_type == Return_type::result_type) {
                        warning("Procedure cannot have result statement");
                }
                else if(func_return.return_type == Return_type::null) {
                        warning("Procedure has no return statement");
                }

                table_msg("procedure Table");
                current_table.dump();
                current_table = table_stack.get_top(); // switch back to function level table
                table_stack.pop();
        }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 775 "yacc.y" /* yacc.c:1646  */
    {
                Trace("para_declaration -> ID COLON datatype");
                SymbolTable new_table;
                table_stack.insert(current_table);
                current_table = new_table;
                Data new_data;
                new_data.id = (yyvsp[-2].value).s_val;
                new_data.kind = Kind::para_kind;
                new_data.type = (yyvsp[0].type);
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of parameter in current scope");
                }
                para_list.clear();
                para_list.push_back(new_data);
        }
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 790 "yacc.y" /* yacc.c:1646  */
    {
                Trace("para_declaration -> ID COLON datatype COMMA para_declaration");
                Data new_data;
                new_data.id = (yyvsp[-4].value).s_val;
                new_data.kind = Kind::para_kind;
                new_data.type = (yyvsp[-2].type);
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of parameter in current scope");
                }
                para_list.push_back(new_data);
        }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 801 "yacc.y" /* yacc.c:1646  */
    { 
                Trace("para_declaration -> ID COLON ARRAY I_CONST DOT DOT I_CONST OF datatype");
                SymbolTable new_table;
                table_stack.insert(current_table);
                current_table = new_table;
                Data new_data;
                new_data.id = (yyvsp[-8].value).s_val;
                new_data.kind = Kind::para_kind;
                new_data.type = (yyvsp[0].type);
                new_data.arr_start = (yyvsp[-5].value).i_val;
                new_data.arr_end = (yyvsp[-2].value).i_val;
                if(new_data.arr_start > new_data.arr_end) {
                        warning("Array start index is larger than end index");
                }
                Value new_value;
                for(int i = 0; i <= (yyvsp[-2].value).i_val - (yyvsp[-5].value).i_val; i++) {
                        new_data.array.push_back(new_value);
                }
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of parameter in current scope");
                }
                para_list.clear();
                para_list.push_back(new_data);
        }
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 825 "yacc.y" /* yacc.c:1646  */
    {     
                Data new_data;
                new_data.id = (yyvsp[-10].value).s_val;
                new_data.kind = Kind::para_kind;
                new_data.type = (yyvsp[-2].type);
                new_data.arr_start = (yyvsp[-7].value).i_val;
                new_data.arr_end = (yyvsp[-4].value).i_val;
                if(new_data.arr_start > new_data.arr_end) {
                        warning("Array start index is larger than end index");
                }
                Value new_value;
                for(int i = 0; i <= (yyvsp[-4].value).i_val - (yyvsp[-7].value).i_val; i++) {
                        new_data.array.push_back(new_value);
                }
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of parameter in current cscope");
                }
                para_list.push_back(new_data);
        }
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 848 "yacc.y" /* yacc.c:1646  */
    {
                Trace("block_program -> variable_declaration block_program");
        }
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 851 "yacc.y" /* yacc.c:1646  */
    {
                Trace("block_program -> stmt block_program");
        }
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 858 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> block_stmt");
        }
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 861 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> assign_stmt");
        }
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 864 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> put_stmt");
        }
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 867 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> get_stmt");
        }
#line 2596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 870 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> result_stmt");
        }
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 873 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> exit_stmt");
        }
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 876 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> skip_stmt");
        }
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 879 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> if_stmt");
        }
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 882 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> loop_stmt");
        }
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 885 "yacc.y" /* yacc.c:1646  */
    {
                Trace("stmt -> for_stmt");
        }
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 891 "yacc.y" /* yacc.c:1646  */
    {
                SymbolTable body_table;
                table_stack.insert(current_table);
                current_table = body_table;
        }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 896 "yacc.y" /* yacc.c:1646  */
    {
                Trace("block_stmt -> BEGIN block_stmt_body");
                table_msg("block Table");
                current_table.dump();
                current_table = table_stack.get_top(); 
                table_stack.pop();
        }
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 906 "yacc.y" /* yacc.c:1646  */
    {
                Trace("assign_stmt -> ID ASSIGN const_expr");
                auto iter = current_table.table.find((yyvsp[-2].value).s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup((yyvsp[-2].value).s_val);
                        if(table_index == -1) {
                                warning("Undeclared variable");
                        }
                        else {
                                iter = table_stack.list[table_index].table.find((yyvsp[-2].value).s_val);
                                switch(iter->second.kind) {
                                        case Kind::func_kind:
                                                warning("Assign value to function");
                                                break;
                                        case Kind::proc_kind:
                                                warning("Assign value to procedure");
                                                break;
                                        case Kind::const_kind:
                                                warning("Assign value to constant");
                                                break;
                                        case Kind::para_kind:
                                        case Kind::var_kind:
                                                if(iter->second.type == Type::void_type) {
                                                        warning("Assign value to void type");
                                                }
                                                else if((iter->second.array.size() != 0 && (yyvsp[0].data).array.size() == 0)
                                                        || (iter->second.array.size() == 0 && (yyvsp[0].data).array.size() != 0)) {
                                                                warning("One is array, the other is not");
                                                }
                                                else if((yyvsp[0].data).kind == Kind::func_kind) {
                                                        if((yyvsp[0].data).type == Type::void_type) {
                                                                warning("Assign varaible to a function with no return value");
                                                        }
                                                }
                                                else if((yyvsp[0].data).kind == Kind::proc_kind) {
                                                        warning("Assgin varaible to a procedure");
                                                }
                                                else if(iter->second.type != (yyvsp[0].data).type) {
                                                        warning("Auto type conversion");
                                                }
                                                break;
                                }
                        }
                }
                else {
                        switch(iter->second.kind) {
                                case Kind::func_kind:
                                        warning("Assign value to function");
                                        break;
                                case Kind::proc_kind:
                                        warning("Assign value to function");
                                        break;
                                case Kind::const_kind:
                                        warning("Assign value to constant");
                                        break;
                                case Kind::para_kind:
                                case Kind::var_kind:
                                        if(iter->second.type == Type::void_type) {
                                                warning("Assign value to void type");
                                        }
                                        else if((iter->second.array.size() != 0 && (yyvsp[0].data).array.size() == 0)
                                                || (iter->second.array.size() == 0 && (yyvsp[0].data).array.size() != 0)) {
                                                        warning("One is array, the other is not");
                                                }
                                         else if((yyvsp[0].data).kind == Kind::func_kind) {
                                                        if((yyvsp[0].data).type == Type::void_type) {
                                                                warning("Assign varaible to a function with no return value");
                                                        }
                                        }
                                        else if((yyvsp[0].data).kind == Kind::proc_kind) {
                                                warning("Assgin varaible to a procedure");
                                        }
                                        else if(iter->second.type != (yyvsp[0].data).type) {
                                                warning("Auto type conversion");
                                        }
                                        break;
                        }
                }
        }
#line 2750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 985 "yacc.y" /* yacc.c:1646  */
    { // arary assignment
                Trace("assign_stmt -> ID LBRACKET const_expr RBRACKET ASSIGN const_expr");
                if((yyvsp[-3].data).type != Type::i_type) {
                        warning("Array index is not integer");
                }
                else {
                        auto iter = current_table.table.find((yyvsp[-5].value).s_val);
                        if(iter == current_table.table.end()) {
                                int table_index = table_stack.lookup((yyvsp[-5].value).s_val);
                                if(table_index == -1) {
                                        warning("Undeclared variable");
                                }
                                else {
                                        iter = table_stack.list[table_index].table.find((yyvsp[-5].value).s_val);
                                        switch(iter->second.kind) {
                                                case Kind::func_kind:
                                                        warning("Assign value to function");
                                                        break;
                                                case Kind::proc_kind:
                                                        warning("Assign value to procedure");
                                                        break;
                                                case Kind::const_kind:
                                                        warning("Assign value to constant");
                                                        break;
                                                case Kind::para_kind:
                                                case Kind::var_kind:
                                                        if(iter->second.type == Type::void_type) {
                                                                warning("Assign value to void type");
                                                        }
                                                        else if(iter->second.array.size() == 0) {
                                                                warning("It is not array");
                                                        }
                                                        else if(iter->second.type != (yyvsp[0].data).type) {
                                                                warning("Auto type conversion");
                                                        }
                                                        break;
                                        }
                                }
                        }
                        else {
                                switch(iter->second.kind) {
                                        case Kind::func_kind:
                                                warning("Assign value to function");
                                                break;
                                        case Kind::proc_kind:
                                                warning("Assign value to procedure");
                                                break;
                                        case Kind::const_kind:
                                                warning("Assign value to constant");
                                                break;
                                        case Kind::para_kind:
                                        case Kind::var_kind:
                                                if(iter->second.type == Type::void_type) {
                                                        warning("Assign value to void type");
                                                }
                                                else if(iter->second.array.size() == 0) {
                                                        warning("It is not array");
                                                }
                                                else if(iter->second.type != (yyvsp[0].data).type) {
                                                        warning("Auto type conversion");
                                                }
                                                break;
                                }
                        }
                }
        }
#line 2821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1054 "yacc.y" /* yacc.c:1646  */
    {
                Trace("put_stmt -> PUT const_expr");
                if((yyvsp[0].data).array.size() != 0) {
                        warning("PUT operation on array");
                }
                else if((yyvsp[0].data).kind == Kind::proc_kind) {
                        warning("PUT operation on procedure");
                }
                else if((yyvsp[0].data).kind == Kind::func_kind) {
                        if((yyvsp[0].data).type == Type::void_type) {
                                warning("PUT operation on function with no return value");
                        }
                }
        }
#line 2840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1071 "yacc.y" /* yacc.c:1646  */
    {
                Trace("get_stmt -> GET ID");
                auto iter = current_table.table.find((yyvsp[0].value).s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup((yyvsp[0].value).s_val);
                        if(table_index == -1) {
                                warning("Undeclared variable");
                        }
                        else {
                                iter = table_stack.list[table_index].table.find((yyvsp[0].value).s_val);
                                if((iter->second.kind == Kind::func_kind) 
                                || (iter->second.kind == Kind::proc_kind)) {
                                        warning("GET operation on function or procedure");
                                }
                                else {
                                        if(iter->second.type == Type::void_type) {
                                                warning("GET operation on void");
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind == Kind::func_kind) 
                        || (iter->second.kind == Kind::proc_kind)) {
                                warning("GET operation on function or procedure");
                        }
                        else {
                                if(iter->second.type == Type::void_type) {
                                        warning("GET operation on void");
                                }
                        }
                }
        }
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1104 "yacc.y" /* yacc.c:1646  */
    {
                if ((yyvsp[-1].data).type != Type::i_type) {
                        warning("Array index is not integer");
                }
                else {
                        auto iter = current_table.table.find((yyvsp[-3].value).s_val);
                        if(iter == current_table.table.end()) {
                                int table_index = table_stack.lookup((yyvsp[-3].value).s_val);
                                if(table_index == -1) {
                                        warning("Undeclared variable");
                                }
                                else {
                                        iter = table_stack.list[table_index].table.find((yyvsp[-3].value).s_val);
                                        if(iter->second.array.empty()) {
                                                warning("GET operation on non-array");
                                        }
                                }
                        }
                        else {
                                if(iter->second.array.empty()) {
                                        warning("GET operation on non-array");
                                }
                        } 
                }
        }
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1132 "yacc.y" /* yacc.c:1646  */
    {
                Trace("result_stmt -> RESULT const_expr");

                func_return.return_type = Return_type::result_type;
                func_return.type = (yyvsp[0].data).type;
        }
#line 2919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1138 "yacc.y" /* yacc.c:1646  */
    {
                Trace("result_stmt -> RETURN");
                func_return.return_type = Return_type::return_type;
                func_return.type = Type::void_type;
        }
#line 2929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1146 "yacc.y" /* yacc.c:1646  */
    {
                Trace("exit_stmt -> EXIT");
        }
#line 2937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1149 "yacc.y" /* yacc.c:1646  */
    { // bool_expr
                Trace("exit_stmt -> EXIT WHEN bool_expr");
                if((yyvsp[0].data).type == Type::void_type) {
                        warning("EXIT operation on void");
                }
                else if((yyvsp[0].data).type != Type::b_type) {
                        warning("EXIT operation on non-boolean");
                }
        }
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1161 "yacc.y" /* yacc.c:1646  */
    {
                Trace("skip_stmt -> SKIP");
        }
#line 2959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1167 "yacc.y" /* yacc.c:1646  */
    { //bool_expr
                Trace("if_stmt -> IF bool_expr THEN")
                if((yyvsp[-1].data).type != Type::b_type) {
                        warning("IF condition is not bool");
                }
                table_stack.insert(current_table);
                SymbolTable body_table;
                current_table = body_table;
        }
#line 2973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1176 "yacc.y" /* yacc.c:1646  */
    { 
                Trace("if_stmt -> IF bool_expr THEN block_program");
        }
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1179 "yacc.y" /* yacc.c:1646  */
    {
                Trace("if_stmt -> IF bool_expr THEN block_program end_if_stmt");
        }
#line 2989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1185 "yacc.y" /* yacc.c:1646  */
    {
                Trace("end_if_stmt -> END IF");
                table_msg("if Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
#line 3001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1192 "yacc.y" /* yacc.c:1646  */
    {
                table_msg("if Table");
                current_table.dump();
                SymbolTable body_table;
                current_table = body_table;
        }
#line 3012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1198 "yacc.y" /* yacc.c:1646  */
    {
                Trace("end_if_stmt -> ELSE block_program END IF");
                table_msg("else Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
#line 3024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1208 "yacc.y" /* yacc.c:1646  */
    {
                SymbolTable body_table;
                table_stack.insert(current_table);
                current_table = body_table;
        }
#line 3034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1213 "yacc.y" /* yacc.c:1646  */
    {
                table_msg("loop Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
#line 3045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1222 "yacc.y" /* yacc.c:1646  */
    {
                auto iter = current_table.table.find((yyvsp[0].value).s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup((yyvsp[0].value).s_val);
                        if(table_index == -1) {
                                warning("Undeclared variable");
                        }
                        else {
                                iter = table_stack.list[table_index].table.find((yyvsp[0].value).s_val);
                                if(iter->second.kind != Kind::var_kind) {
                                        warning("FOR operation on non-variable");
                                }
                                else if(iter->second.array.size() != 0) {
                                        warning("FOR operation on array");
                                }
                                else {
                                        if(iter->second.type != Type::i_type) {
                                                warning("FOR operation on non-integer");
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind != Kind::var_kind) && (iter->second.kind != Kind::para_kind) ) {
                                warning("FOR operation on non-variable");
                        }
                        else if(iter->second.array.size() != 0) {
                                        warning("FOR operation on array");
                        }
                        else {
                                if(iter->second.type != Type::i_type) {
                                        warning("FOR operation on non-integer");
                                }
                        }
                }

                SymbolTable body_table;
                table_stack.insert(current_table);
                current_table = body_table;

                Data for_data;
                for_data.id = (yyvsp[0].value).s_val;
                for_data.kind = Kind::para_kind;
                for_data.type = Type::i_type;
                current_table.insert(for_data);
        }
#line 3096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1268 "yacc.y" /* yacc.c:1646  */
    {
                Trace("for_stmt -> FOR ID COLON const_expr DOT DOT const_expr for_stmt_body END FOR");
                if((yyvsp[-6].data).kind != Kind::const_kind || (yyvsp[-3].data).kind != Kind::const_kind) {
                        warning("For operation on non-constant");
                }
                if((yyvsp[-6].data).type != Type::i_type || (yyvsp[-3].data).type != Type::i_type) {
                        warning("FOR operation on non-integer");
                }
                table_msg("for Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
#line 3114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1281 "yacc.y" /* yacc.c:1646  */
    { 
                auto iter = current_table.table.find((yyvsp[0].value).s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup((yyvsp[0].value).s_val);
                        if(table_index == -1) {
                                warning("Undeclared variable");
                        }
                        else {
                                iter = table_stack.list[table_index].table.find((yyvsp[0].value).s_val);
                                if(iter->second.kind != Kind::var_kind) {
                                        warning("FOR operation on non-variable");
                                }
                                else if(iter->second.array.size() != 0) {
                                        warning("FOR operation on array");
                                }
                                else {
                                        if(iter->second.type != Type::i_type) {
                                                warning("FOR operation on non-integer");
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind != Kind::var_kind) && (iter->second.kind != Kind::para_kind) ) {
                                warning("FOR operation on non-variable");
                        }
                        else if(iter->second.array.size() != 0) {
                                warning("FOR operation on array");
                        }
                        else {
                                if(iter->second.type != Type::i_type) {
                                        warning("FOR operation on non-integer");
                                }
                        }
                }

                SymbolTable body_table;
                table_stack.insert(current_table);
                current_table = body_table;

                Data for_data;
                for_data.id = (yyvsp[0].value).s_val;
                for_data.kind = Kind::para_kind;
                for_data.type = Type::i_type;
                current_table.insert(for_data);
        }
#line 3165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1327 "yacc.y" /* yacc.c:1646  */
    {
                Trace("for_stmt -> FOR DECREASING ID COLON const_expr DOT DOT const_expr for_stmt_body END FOR");
                if((yyvsp[-6].data).type != Type::i_type || (yyvsp[-3].data).type != Type::i_type) {
                        warning("FOR operation on non-integer");
                }
                else {
                        if((yyvsp[-6].data).value.i_val < (yyvsp[-3].data).value.i_val) {
                                warning("For operation with wrong direction");
                        }
                }
                if((yyvsp[-6].data).kind != Kind::const_kind || (yyvsp[-3].data).kind != Kind::const_kind) {
                        warning("For operation on non-constant");
                }
                
                table_msg("for Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
#line 3189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1349 "yacc.y" /* yacc.c:1646  */
    {
                Trace("function_call_stmt -> ID LPAREN RPAREN");
                auto iter = current_table.table.find((yyvsp[-2].value).s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup((yyvsp[-2].value).s_val);
                        if(table_index == -1) {
                                warning("Undeclared function");
                                (yyval.data).type = Type::void_type;
                        }
                        else {
                                iter = table_stack.list[table_index].table.find((yyvsp[-2].value).s_val);
                                if((iter->second.kind != Kind::func_kind) && (iter->second.kind != Kind::proc_kind)) {
                                        warning("Call non-function");
                                        (yyval.data).type = Type::void_type;
                                }
                                else {
                                        if(iter->second.para_list.size() != 0) {
                                                warning("Call function with wrong number of parameters");
                                                (yyval.data).type = Type::void_type;
                                        }
                                        else if(iter->second.array.size() != 0) {
                                                warning("Call function with array");
                                                (yyval.data).type = Type::void_type;
                                        }
                                        else {
                                                (yyval.data).type = iter->second.type;
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind != Kind::func_kind) && (iter->second.kind != Kind::proc_kind)) {
                                warning("Call non-function");
                                (yyval.data).type = Type::void_type;
                        }
                        else {
                                if(iter->second.para_list.size() != 0) {
                                        warning("Call function with wrong number of parameters");
                                        (yyval.data).type = Type::void_type;
                                }
                                else if(iter->second.array.size() != 0) {
                                        warning("Call function with array");
                                        (yyval.data).type = Type::void_type;
                                }
                                else {
                                        (yyval.data).type= iter->second.type;
                                }
                        }
                }

                if(iter->second.kind == Kind::proc_kind) {
                        (yyval.data).kind = Kind::proc_kind;
                }
                else {
                        (yyval.data).kind = Kind::const_kind;
                }
        }
#line 3251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1406 "yacc.y" /* yacc.c:1646  */
    {
                Trace("function_call_stmt -> ID LPAREN function_call_para RPAREN");
                auto iter = current_table.table.find((yyvsp[-3].value).s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup((yyvsp[-3].value).s_val);
                        if(table_index == -1) {
                                warning("Undeclared function");
                                (yyval.data).type = Type::void_type;
                        }
                        else {
                                iter = table_stack.list[table_index].table.find((yyvsp[-3].value).s_val);
                                if((iter->second.kind != Kind::func_kind) && (iter->second.kind != Kind::proc_kind)) {
                                        warning("Call non-function");
                                        (yyval.data).type = Type::void_type;
                                }
                                else {
                                        if(iter->second.para_list.size() != para_list.size()) {
                                                warning("Call function with wrong number of parameters");
                                                (yyval.data).type = Type::void_type;
                                        }
                                        else {
                                                reverse(para_list.begin(), para_list.end());
                                                int i;
                                                for(i = 0; i < para_list.size(); i++) {
                                                        if((para_list[i].array.size() != 0) && (iter->second.para_list[i].array.size() == 0)) {
                                                                warning("function call with an array parameter, but the function is not");
                                                                break;
                                                        }
                                                        else if ((para_list[i].array.size() == 0) && (iter->second.para_list[i].array.size() != 0)) {
                                                                warning("function call with a non-array parameter, but the function is");
                                                                break;
                                                        }
                                                        else if(para_list[i].type != iter->second.para_list[i].type) {
                                                                if((para_list[i].type == Type::s_type && iter->second.para_list[i].type != Type::s_type)
                                                                || (para_list[i].type != Type::s_type && iter->second.para_list[i].type == Type::s_type)
                                                                || (para_list[i].type == Type::void_type) 
                                                                || (iter->second.para_list[i].type == Type::void_type)) {
                                                                        warning("Call function with wrong type of parameters");
                                                                        (yyval.data).type = Type::void_type;
                                                                        break;
                                                                } 
                                                                else {
                                                                        warning("Auto type conversion");
                                                                }
                                                        }
                                                }
                                                if(i == para_list.size()) {
                                                        // all parameters are correct
                                                        (yyval.data).type = iter->second.type;
                                                }
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind != Kind::func_kind) && (iter->second.kind != Kind::proc_kind)) {
                                warning("Call non-function");
                                (yyval.data).type = Type::void_type;
                        }
                        else {
                                if(iter->second.para_list.size() != para_list.size()) {
                                        warning("Call function with wrong number of parameters");
                                        (yyval.data).type = Type::void_type;
                                }
                                else {
                                        reverse(para_list.begin(), para_list.end());
                                        int i;
                                        for(i = 0; i < para_list.size(); i++) {
                                                if((para_list[i].array.size() != 0) && (iter->second.para_list[i].array.size() == 0)) {
                                                        warning("function call with an array parameter, but the function is not");
                                                        break;
                                                }
                                                else if ((para_list[i].array.size() == 0) && (iter->second.para_list[i].array.size() != 0)) {
                                                        warning("function call with a non-array parameter, but the function is");
                                                        break;
                                                }
                                                else if(para_list[i].type != iter->second.para_list[i].type) {
                                                        if((para_list[i].type == Type::s_type && iter->second.para_list[i].type != Type::s_type)
                                                        || (para_list[i].type != Type::s_type && iter->second.para_list[i].type == Type::s_type)
                                                        || (para_list[i].type == Type::void_type) 
                                                        || (iter->second.para_list[i].type == Type::void_type)) {
                                                                warning("Call function with wrong type of parameters");
                                                                (yyval.data).type = Type::void_type;
                                                                break;
                                                        } 
                                                        else {
                                                                warning("Auto type conversion");
                                                        }
                                                }
                                        }
                                        if(i == para_list.size()) {
                                                // all parameters are correct
                                                (yyval.data).type = iter->second.type;
                                        }

                                }
                        }
                }

                if(iter->second.kind == Kind::proc_kind) {
                        (yyval.data).kind = Kind::proc_kind;
                }
                else {
                        (yyval.data).kind = Kind::const_kind;
                }
        }
#line 3362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1515 "yacc.y" /* yacc.c:1646  */
    {
                Trace("function_call_para -> const_expr");
                para_list.clear();
                para_list.push_back((yyvsp[0].data));
        }
#line 3372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1520 "yacc.y" /* yacc.c:1646  */
    {
                Trace("function_call_para -> const_expr COMMA function_call_para");
                para_list.push_back((yyvsp[-2].data));
        }
#line 3381 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3385 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1526 "yacc.y" /* yacc.c:1906  */
 

#include "lex.yy.cpp"

void warning(char *msg) {
    fprintf(stderr, "\033[47m\033[31m\033[1mWANRING: %s\033[0m\n", msg);
}

void yyerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    table_msg("Current Table");
    current_table.dump();
    exit(1);
}

int main()
{
    printf("---------------------Parsing begin\n");
    
    /* perform parsing */
    yyparse();
    table_msg("\nMAIN Table");
    current_table.dump();
    
    printf("\n---------------------Parsing end\n");
    
    fclose(yyin);
}
