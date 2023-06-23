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
#line 1 "yacc.y" /* yacc.c:339  */

// #include "symboltable.hpp"
#include "javaclass.hpp"
#define YACC_DEBUG 0
#define Trace(t)  if (YACC_DEBUG)  { printf("Reducing %s\n", t);}
#define table_msg(msg)    { printf("\n\033[34m\033[47m%s\033[0m\n", msg); }
extern int yylex(void);
extern void warning(char *msg);
extern void yyerror(char *msg);

JavaClass java_class;
TableList table_stack;
SymbolTable current_table;
vector<Data> para_list;
Func_return func_return;
bool inMain = false;

#line 84 "y.tab.cpp" /* yacc.c:339  */

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
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    BOOL = 268,
    ASSIGN = 269,
    PUT = 270,
    _BEGIN = 271,
    DECREASING = 272,
    DEFAULT = 273,
    DO = 274,
    WHEN = 275,
    IF = 276,
    ELSE = 277,
    END = 278,
    EXIT = 279,
    FOR = 280,
    FUNCTION = 281,
    GET = 282,
    LOOP = 283,
    OF = 284,
    PROCEDURE = 285,
    REAL = 286,
    RESULT = 287,
    RETURN = 288,
    SKIP = 289,
    THEN = 290,
    VAR = 291,
    CONST = 292,
    INT = 293,
    STRING = 294,
    ARRAY = 295,
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
#define BOOL 268
#define ASSIGN 269
#define PUT 270
#define _BEGIN 271
#define DECREASING 272
#define DEFAULT 273
#define DO 274
#define WHEN 275
#define IF 276
#define ELSE 277
#define END 278
#define EXIT 279
#define FOR 280
#define FUNCTION 281
#define GET 282
#define LOOP 283
#define OF 284
#define PROCEDURE 285
#define REAL 286
#define RESULT 287
#define RETURN 288
#define SKIP 289
#define THEN 290
#define VAR 291
#define CONST 292
#define INT 293
#define STRING 294
#define ARRAY 295
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

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "y.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

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
       0,    45,    45,    48,    51,    54,    54,    66,    69,    72,
      84,    99,   114,   132,   144,   174,   182,   190,   198,   209,
     217,   225,   233,   241,   252,   256,   262,   269,   275,   281,
     287,   293,   299,   305,   311,   317,   323,   329,   335,   341,
     347,   355,   364,   369,   378,   448,   470,   480,   490,   499,
     503,   507,   511,   518,   518,   565,   565,   640,   640,   683,
     683,   760,   778,   789,   816,   839,   842,   845,   849,   852,
     855,   858,   861,   864,   867,   870,   873,   876,   879,   885,
     885,   903,   994,  1064,  1064,  1085,  1118,  1146,  1152,  1161,
    1165,  1178,  1185,  1198,  1185,  1207,  1216,  1226,  1216,  1240,
    1240,  1263,  1282,  1263,  1318,  1337,  1318,  1376,  1384,  1403,
    1462,  1573,  1578
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "COMMA", "COLON", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "SEMICOLON",
  "BOOL", "ASSIGN", "PUT", "_BEGIN", "DECREASING", "DEFAULT", "DO", "WHEN",
  "IF", "ELSE", "END", "EXIT", "FOR", "FUNCTION", "GET", "LOOP", "OF",
  "PROCEDURE", "REAL", "RESULT", "RETURN", "SKIP", "THEN", "VAR", "CONST",
  "INT", "STRING", "ARRAY", "NOT", "AND", "OR", "LT", "LE", "EQ", "GE",
  "GT", "NE", "ADD", "SUB", "MUL", "DIV", "MOD", "UMINUS", "I_CONST",
  "F_CONST", "STR_CONST", "ID", "TRUE", "FALSE", "$accept", "program_body",
  "$@1", "stmt_list", "global_variable_declaration",
  "local_variable_declaration", "const_variable_declaration",
  "local_var_variable_declaration", "const_expr", "const_val", "datatype",
  "function_declaration", "$@2", "$@3", "procedure_declaration", "$@4",
  "$@5", "para_declaration", "block_program", "stmt", "block_stmt", "$@6",
  "assign_stmt", "put_stmt", "$@7", "get_stmt", "result_stmt", "exit_stmt",
  "skip_stmt", "if_stmt", "$@8", "$@9", "end_if_stmt", "$@10", "$@11",
  "loop_stmt", "$@12", "for_stmt", "$@13", "$@14", "$@15", "$@16",
  "for_para", "function_call_stmt", "function_call_para", YY_NULLPTR
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

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,   -53,   -47,   -39,    -3,    57,  -178,    42,    42,    42,
      55,    56,    27,    37,  -178,    -6,  -178,  -178,  -178,    -5,
      -4,    21,    67,   -14,    25,  -178,  -178,  -178,    69,   101,
     -10,    72,  -178,    69,  -178,  -178,   100,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   127,
     143,    70,  -178,    98,  -178,  -178,   135,  -178,  -178,  -178,
     139,   141,  -178,  -178,    69,   281,    69,    69,    69,  -178,
    -178,  -178,   103,  -178,  -178,   277,  -178,  -178,    69,   116,
    -178,   151,   281,    92,   106,    69,    69,    32,    -2,   119,
     155,   281,  -178,   120,   123,   124,    92,   122,   125,   281,
     160,   281,   173,   297,  -178,    69,  -178,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      92,  -178,   180,    69,   166,  -178,   148,   181,   195,    92,
    -178,  -178,   149,  -178,   201,    32,   184,   281,  -178,  -178,
    -178,    68,    37,  -178,  -178,  -178,  -178,   219,   281,   297,
     297,    65,    65,    65,    65,    65,    65,   117,   117,  -178,
    -178,  -178,   203,    48,   241,   182,    69,  -178,   199,   281,
     206,    32,  -178,   170,   207,    -8,    69,  -178,  -178,  -178,
    -178,    48,  -178,  -178,   228,  -178,  -178,  -178,    69,   209,
     230,  -178,   281,  -178,   175,   221,   222,    92,    17,   248,
     249,    92,   194,   198,   232,  -178,    69,    69,  -178,   235,
    -178,   254,    48,  -178,   229,   200,    92,    92,   281,  -178,
      48,  -178,    32,  -178,  -178,  -178,   281,   256,   251,   281,
     252,   217,   257,   258,   255,   273,  -178,   274,  -178,  -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     8,     5,     5,     5,
       0,     0,     0,     0,     1,     6,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     9,    83,    79,     0,    89,
       0,     0,    99,     0,    88,    91,     0,     7,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    57,     0,    50,    52,    49,    51,    10,    11,
       0,     0,    15,    17,     0,    67,     0,     0,     0,    41,
      42,    43,    44,    46,    47,     0,    24,    48,     0,     0,
     101,    85,    67,    87,     0,     0,     0,     0,     0,     0,
       0,    67,    59,     0,     0,     0,    84,     0,     0,    67,
       0,    67,     0,    38,    39,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,   104,     0,     0,     0,   109,   111,     0,     0,    81,
      49,    53,     0,    61,     0,     0,     0,    67,    12,    16,
      18,     0,     0,    65,    80,    66,    40,     0,    67,    30,
      31,    32,    33,    34,    35,    36,    37,    28,    29,    26,
      27,    25,     0,     0,     0,     0,     0,   110,     0,    67,
       0,     0,    55,     0,     0,     0,     0,    14,    13,    45,
      93,     0,   107,   108,     0,    86,   100,   112,     0,     0,
       0,    62,    67,    58,     0,    22,    20,    19,     0,     0,
       0,    82,     0,     0,     0,    60,     0,     0,    96,     0,
      94,     0,     0,    54,     0,     0,    23,    21,    67,    95,
       0,   102,     0,    56,    97,   105,    67,    63,     0,    67,
       0,     0,     0,     0,     0,    64,    98,     0,   103,   106
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,   165,  -178,  -178,  -178,  -178,   137,  -178,   -20,  -178,
     -71,  -178,  -178,  -178,  -178,  -178,  -178,   -19,   -68,   267,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -177,   -15,   132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    15,     7,    99,    25,   177,   126,    76,
      58,     8,   169,   192,     9,    91,   137,    51,   100,   101,
      38,    65,    39,    40,    64,    41,    42,    43,    44,    45,
     148,   198,   210,   218,   228,    46,    82,    47,   122,   226,
     162,   229,   184,    77,   127
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    53,    49,    52,   199,   195,    10,    79,    75,    26,
      27,    54,    11,    83,   124,    28,   131,   133,    29,    30,
      12,    31,    32,   136,    60,    61,    33,    34,    35,    55,
     196,   143,    21,   145,    54,   221,   130,    57,   132,   208,
     209,    22,    23,   225,    96,    54,   102,   103,   104,    80,
      48,    24,    55,    36,    50,    50,    13,    14,   120,    56,
      57,    19,    20,    55,   172,   128,   129,    48,     1,   174,
     130,    57,     2,   175,    89,    66,    48,    90,     3,     4,
     180,    62,   176,    63,    48,   147,    48,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     191,   189,    89,   164,   182,    92,    84,   183,    85,    84,
      67,   105,    66,   125,    86,   115,   116,   117,   118,   119,
      68,    78,    48,    59,   204,    69,    70,    71,    72,    73,
      74,    81,    87,    48,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    67,    88,    93,
     224,   227,   166,    94,    48,    95,   197,    68,   230,   123,
     135,   233,    69,    70,    71,    72,    73,    74,   201,   117,
     118,   119,    16,    17,    18,   121,   138,    48,   134,   139,
     146,   141,   140,   144,   142,   163,   216,   217,   167,   165,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    48,   168,   170,   171,   173,   181,   190,
     186,    48,   235,   188,    48,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   179,   193,
     194,   200,   202,   203,   205,   206,   207,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     185,   211,   212,   213,   214,   215,   219,   220,   222,   223,
     231,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   232,   234,    50,    89,   236,   178,
     238,   237,    37,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    26,    27,   187,   239,
       0,     0,    28,     0,     0,    29,    30,     0,    31,    32,
       0,     0,   106,    33,    34,    35,     0,    97,    98,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,     0,
      36,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119
};

static const yytype_int16 yycheck[] =
{
      15,    20,     7,     7,   181,    13,    59,    17,    28,    15,
      16,    13,    59,    33,    82,    21,    87,    88,    24,    25,
      59,    27,    28,    91,    38,    39,    32,    33,    34,    31,
      38,    99,     5,   101,    13,   212,    38,    39,    40,    22,
      23,    14,     5,   220,    64,    13,    66,    67,    68,    59,
      65,    14,    31,    59,    59,    59,    59,     0,    78,    38,
      39,     6,     6,    31,   135,    85,    86,    82,    26,   137,
      38,    39,    30,     5,     4,     6,    91,     7,    36,    37,
     148,    56,    14,    58,    99,   105,   101,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     171,   169,     4,   123,    56,     7,     6,    59,     8,     6,
      41,     8,     6,     7,    14,    50,    51,    52,    53,    54,
      51,    20,   137,    56,   192,    56,    57,    58,    59,    60,
      61,    59,     5,   148,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    41,     5,    14,
     218,   222,     4,    14,   169,    14,   176,    51,   226,     8,
       5,   229,    56,    57,    58,    59,    60,    61,   188,    52,
      53,    54,     7,     8,     9,    59,    56,   192,    59,    56,
       7,    59,    58,    23,    59,     5,   206,   207,     7,    23,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   218,     9,    56,     5,    23,     5,     3,
      28,   226,   231,    14,   229,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     9,    59,
      23,     3,    23,     3,    59,    14,    14,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       9,     3,     3,    59,    56,    23,    21,     3,    29,    59,
       4,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    23,    23,    59,     4,    21,   142,
      25,    23,    15,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    15,    16,   166,    25,
      -1,    -1,    21,    -1,    -1,    24,    25,    -1,    27,    28,
      -1,    -1,    35,    32,    33,    34,    -1,    36,    37,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    30,    36,    37,    63,    64,    66,    73,    76,
      59,    59,    59,    59,     0,    65,    63,    63,    63,     6,
       6,     5,    14,     5,    14,    68,    15,    16,    21,    24,
      25,    27,    28,    32,    33,    34,    59,    81,    82,    84,
      85,    87,    88,    89,    90,    91,    97,    99,   105,     7,
      59,    79,     7,    79,    13,    31,    38,    39,    72,    56,
      38,    39,    56,    58,    86,    83,     6,    41,    51,    56,
      57,    58,    59,    60,    61,    70,    71,   105,    20,    17,
      59,    59,    98,    70,     6,     8,    14,     5,     5,     4,
       7,    77,     7,    14,    14,    14,    70,    36,    37,    67,
      80,    81,    70,    70,    70,     8,    35,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      70,    59,   100,     8,    80,     7,    70,   106,    70,    70,
      38,    72,    40,    72,    59,     5,    80,    78,    56,    56,
      58,    59,    59,    80,    23,    80,     7,    70,    92,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,   102,     5,    70,    23,     4,     7,     9,    74,
      56,     5,    72,    23,    80,     5,    14,    69,    68,     9,
      80,     5,    56,    59,   104,     9,    28,   106,    14,    80,
       3,    72,    75,    59,    23,    13,    38,    70,    93,   104,
       3,    70,    23,     3,    80,    59,    14,    14,    22,    23,
      94,     3,     3,    59,    56,    23,    70,    70,    95,    21,
       3,   104,    29,    59,    80,   104,   101,    72,    96,   103,
      80,     4,    23,    80,    23,    79,    21,    23,    25,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    63,    64,    63,    65,    65,    66,
      66,    66,    66,    67,    67,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    74,    73,    75,    73,    77,    76,    78,
      76,    79,    79,    79,    79,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    83,
      82,    84,    84,    86,    85,    87,    87,    88,    88,    89,
      89,    90,    92,    93,    91,    94,    95,    96,    94,    98,
      97,   100,   101,    99,   102,   103,    99,   104,   104,   105,
     105,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     2,     0,     3,
       4,     4,     6,     3,     3,     2,     4,     2,     4,     2,
       2,     4,     2,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     0,    10,     0,    11,     0,     8,     0,
       9,     3,     5,     9,    11,     2,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     3,     6,     0,     3,     2,     5,     2,     1,     1,
       3,     1,     0,     0,     7,     2,     0,     0,     6,     0,
       5,     0,     0,    12,     0,     0,    13,     1,     1,     3,
       4,     1,     3
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
#line 45 "yacc.y" /* yacc.c:1646  */
    {
        Trace("program_body -> variable_declaration program_body");
    }
#line 1526 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 48 "yacc.y" /* yacc.c:1646  */
    {
        Trace("program_body -> function_declaration program_body");
    }
#line 1534 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 51 "yacc.y" /* yacc.c:1646  */
    {
        Trace("program_body -> procedure_declaration program_body");
    }
#line 1542 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "yacc.y" /* yacc.c:1646  */
    {
        Trace("program_body -> stmt_list");
        java_class.mainFunction(current_table.level);
        inMain = true;
    }
#line 1552 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "yacc.y" /* yacc.c:1646  */
    {
        java_class.returnFunction(Type::void_type, current_table.level, inMain);
        java_class.closeFunction(current_table.level);
    }
#line 1561 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt_list -> stmt_list stmt");
    }
#line 1569 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 72 "yacc.y" /* yacc.c:1646  */
    {
        Trace("global_variable_declaration -> CONST ID const_variable_declaration");
        Data new_data;
        new_data.id = (yyvsp[-1].value).s_val;
        new_data.kind = Kind::const_kind;
        new_data.type = (yyvsp[0].data).type;
        new_data.value = (yyvsp[0].data).value;
        new_data.is_global = true;
        if(!current_table.insert(new_data)) {
            warning("Redeclaration of const in current scope");
        }
    }
#line 1586 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 84 "yacc.y" /* yacc.c:1646  */
    {
        Trace("global_variable_declaration -> VAR ID COLON");
        Data new_data;
        new_data.id = (yyvsp[-2].value).s_val;
        new_data.kind = Kind::var_kind;
        new_data.type = (yyvsp[0].type);
        new_data.has_value = false;
        new_data.is_global = true;
        if(current_table.insert(new_data)) {
            java_class.globalVarDeclaration(new_data);
        }
        else {
            warning("Redeclaration of var in current scope");
        }
    }
#line 1606 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "yacc.y" /* yacc.c:1646  */
    { // only int type
        Trace("global_variable_declaration -> VAR ID ASSIGN I_CONST");
        Data new_data;
        new_data.id = (yyvsp[-2].value).s_val;
        new_data.kind = Kind::var_kind;
        new_data.type = Type::i_type;
        new_data.value.i_val = (yyvsp[0].value).i_val;
        new_data.is_global = true;
        if(current_table.insert(new_data)) {
            java_class.globalVarDeclaration(new_data);
        }
        else {
            warning("Redeclaration of var in current scope");
        }
    }
#line 1626 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 114 "yacc.y" /* yacc.c:1646  */
    {
        Trace("global_variable_declaration -> VAR ID COLON INT ASSIGN I_CONST");
        Data new_data;
        new_data.id = (yyvsp[-4].value).s_val;
        new_data.kind = Kind::var_kind;
        new_data.type = Type::i_type;
        new_data.value.i_val = (yyvsp[0].value).i_val;
        new_data.is_global = true;
        if(current_table.insert(new_data)) {
            java_class.globalVarDeclaration(new_data);
        }
        else {
            warning("Redeclaration of var in current scope");
        }
    }
#line 1646 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 132 "yacc.y" /* yacc.c:1646  */
    {
        Trace("variable_declaration -> CONST ID const_variable_declaration");
        Data new_data;
        new_data.id = (yyvsp[-1].value).s_val;
        new_data.kind = Kind::const_kind;
        new_data.type = (yyvsp[0].data).type;
        new_data.value = (yyvsp[0].data).value;
        if(!current_table.insert(new_data)) {
            warning("Redeclaration of const in current scope");
        }
        // current_table.dump();
    }
#line 1663 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 144 "yacc.y" /* yacc.c:1646  */
    {
        Trace("variable_declaration -> VAR ID var_variable_declaration");
        Data new_data;
        new_data.id = (yyvsp[-1].value).s_val;
        new_data.kind = Kind::var_kind;
        new_data.type = (yyvsp[0].data).type;
        
        // array
        if ((yyvsp[0].data).array.empty()) {
            new_data.value = (yyvsp[0].data).value;
        }
        else {
            new_data.arr_start = (yyvsp[0].data).arr_start;
            new_data.arr_end = (yyvsp[0].data).arr_end;
            new_data.array = (yyvsp[0].data).array;
        }

        if(current_table.insert(new_data)) {
            new_data.value = (yyvsp[0].data).value;
            new_data.has_value = (yyvsp[0].data).has_value;
            java_class.localVarDeclaration(new_data, current_table, current_table.level, inMain);
        }
        else {
            warning("Redeclaration of var in current scope");
        }
    }
#line 1694 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 174 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_variable_declaration -> ASSIGN I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = (yyvsp[0].value).i_val;
        (yyval.data) = return_data;
    }
#line 1707 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 182 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_variable_declaration -> COLON INT ASSIGN I_CONST");    
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = (yyvsp[0].value).i_val;
        (yyval.data) = return_data;
    }
#line 1720 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 190 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_variable_declaration -> ASSIGN STR_CONST");
        Data return_data;
        return_data.type = Type::s_type;
        return_data.kind = Kind::const_kind;
        return_data.value.s_val = (yyvsp[0].value).s_val;
        (yyval.data) = return_data;
    }
#line 1733 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 198 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_variable_declaration -> COLON STRING ASSIGN STR_CONST");
        Data return_data;
        return_data.type = Type::s_type;
        return_data.kind = Kind::const_kind;
        return_data.value.s_val = (yyvsp[0].value).s_val;
        (yyval.data) = return_data;
    }
#line 1746 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 209 "yacc.y" /* yacc.c:1646  */
    {
        Trace("var_variable_declaration -> ASSIGN I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.value = (yyvsp[0].data).value;
        (yyval.data) = return_data;
    }
#line 1759 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 217 "yacc.y" /* yacc.c:1646  */
    {
        Trace("var_variable_declaration -> COLON INT");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.has_value = false;
        (yyval.data) = return_data;
    }
#line 1772 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 225 "yacc.y" /* yacc.c:1646  */
    {
        Trace("var_variable_declaration -> COLON INT ASSIGN I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.value = (yyvsp[0].data).value;
        (yyval.data) = return_data;
    }
#line 1785 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 233 "yacc.y" /* yacc.c:1646  */
    {
        Trace("var_variable_declaration -> COLON REAL");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.has_value = false;
        (yyval.data) = return_data;
    }
#line 1798 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 241 "yacc.y" /* yacc.c:1646  */
    {
        Trace("var_variable_declaration -> COLON REAL ASSIGN F_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.value = (yyvsp[0].data).value;
        (yyval.data) = return_data;
    }
#line 1811 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 252 "yacc.y" /* yacc.c:1646  */
    { // return Data
        Trace("const_expr -> const_val");
        (yyval.data) = (yyvsp[0].data);
    }
#line 1820 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 256 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> const_expr MOD const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.modOperator(current_table.level, inMain);
    }
#line 1831 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 262 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> const_expr MUL const_expr");
        
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.mulOperator(current_table.level, inMain);
    }
#line 1843 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 269 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> const_expr DIV const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.divOperator(current_table.level, inMain);
    }
#line 1854 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 275 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> const_expr ADD const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.addOperator(current_table.level, inMain);
    }
#line 1865 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 281 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> const_expr SUB const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.subOperator(current_table.level, inMain);
    }
#line 1876 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 287 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> const_expr AND const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.andOperator(current_table.level, inMain);
    }
#line 1887 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 293 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> const_expr OR const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.orOperator(current_table.level, inMain);
    }
#line 1898 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 299 "yacc.y" /* yacc.c:1646  */
    { // Less Than
        Trace("const_expr -> const_expr LT const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.ltOperator(current_table.level, inMain);
    }
#line 1909 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 305 "yacc.y" /* yacc.c:1646  */
    { // Less Equal
        Trace("const_expr -> const_expr LE const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.leOperator(current_table.level, inMain);
    }
#line 1920 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 311 "yacc.y" /* yacc.c:1646  */
    { // Equal
        Trace("const_expr -> const_expr EQ const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.eqOperator(current_table.level, inMain);
    }
#line 1931 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 317 "yacc.y" /* yacc.c:1646  */
    { // Greater Equal
        Trace("const_expr -> const_expr GE const_expr");
        (yyval.data).type = Type::i_type;
        (yyval.data).kind = Kind::const_kind;
        java_class.geOperator(current_table.level, inMain);
    }
#line 1942 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 323 "yacc.y" /* yacc.c:1646  */
    { // Greater Than
        Trace("const_expr -> const_expr GE const_expr");
        (yyval.data).type = Type::i_type;
        (yyval.data).kind = Kind::const_kind;
        java_class.gtOperator(current_table.level, inMain);
    }
#line 1953 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 329 "yacc.y" /* yacc.c:1646  */
    { // Not Equal
        Trace("const_expr -> const_expr NE const_expr");
        (yyval.data).type = Type::i_type;
        (yyval.data).kind = Kind::const_kind;
        java_class.neOperator(current_table.level, inMain);
    }
#line 1964 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 335 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> NOT const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.notOperator(current_table.level, inMain);
    }
#line 1975 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 341 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_expr -> SUB const_expr");
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).type = Type::i_type;
        java_class.negOperator(current_table.level, inMain);
    }
#line 1986 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 347 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.data).type = (yyvsp[-1].data).type;
        (yyval.data).kind = (yyvsp[-1].data).kind;
        Trace("const_expr -> LPAREN const_expr RPAREN");
    }
#line 1996 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 355 "yacc.y" /* yacc.c:1646  */
    { // return Value
        Trace("const_val -> I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = (yyvsp[0].value).i_val;
        (yyval.data) = return_data;
        java_class.loadIntConst(return_data, current_table.level, inMain);
    }
#line 2010 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 364 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_val -> F_CONST");
        (yyval.data).type = Type::f_type;
        (yyval.data).kind = Kind::const_kind;
    }
#line 2020 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 369 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_val -> STR_CONST");
        Data return_data;
        return_data.type = Type::s_type;
        return_data.kind = Kind::const_kind;
        return_data.value.s_val = (yyvsp[0].value).s_val;
        (yyval.data) = return_data;
        java_class.loadStringConst(return_data, current_table.level, inMain);
    }
#line 2034 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 378 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_val -> ID");
        auto iter = current_table.table.find((yyvsp[0].value).s_val);
        Data return_data;
        if(iter != current_table.table.end()) { // found in current table
            if(iter->second.kind == Kind::func_kind || iter->second.kind == Kind::proc_kind) {
                warning("Function or procedure cannot be called without parenthesis");
            }
            else {
                return_data = iter->second;
                if(iter->second.kind == Kind::const_kind) {
                    if(iter->second.type == Type::i_type) {
                        java_class.loadIntConst(iter->second, current_table.level, inMain);
                    }
                    else if(iter->second.type == Type::s_type) {
                        java_class.loadStringConst(iter->second, current_table.level, inMain);
                    }
                    else if(iter->second.type == Type::b_type) {
                        java_class.loadBoolConst(iter->second, current_table.level, inMain);
                    }
                }
                else {
                    if(current_table.level == 0) {
                        java_class.loadGlobalVar(return_data, current_table.level, inMain);
                    }
                    else {
                        java_class.loadLocalVar(current_table, return_data, current_table.level, inMain);
                    }
                }          
            } 
        }
        else {
            int table_index = table_stack.lookup((yyvsp[0].value).s_val);
            if(table_index != -1) {
                Value new_value;
                iter = table_stack.list[table_index].table.find((yyvsp[0].value).s_val);
                if(iter->second.kind == Kind::func_kind || iter->second.kind == Kind::proc_kind) {
                    warning("Function or procedure cannot be called without parenthesis");
                }
                else {
                    return_data = iter->second;
                    if(iter->second.kind == Kind::const_kind) {
                        if(iter->second.type == Type::i_type) {
                            java_class.loadIntConst(iter->second, current_table.level, inMain);
                        }
                        else if(iter->second.type == Type::s_type) {
                            java_class.loadStringConst(iter->second, current_table.level, inMain);
                        }
                        else if(iter->second.type == Type::b_type) {
                            java_class.loadBoolConst(iter->second, current_table.level, inMain);
                        }
                    }
                    else {
                        if(table_index == 0) {
                            java_class.loadGlobalVar(return_data, current_table.level, inMain);
                        }
                        else {
                            java_class.loadLocalVar(current_table, return_data, current_table.level, inMain);
                        }
                    }          
                } 
            }
            else {
                warning("Undeclared variable");
                return_data.type = Type::void_type;
                return_data.kind = Kind::const_kind;
            }
        }
        (yyval.data) = return_data;
    }
#line 2109 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 448 "yacc.y" /* yacc.c:1646  */
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
#line 2136 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 470 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_val -> TRUE");
        Data return_data;
        // $$.type = Type::b_type;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = 1;
        (yyval.data) = return_data;
        java_class.loadBoolConst(return_data, current_table.level, inMain);
    }
#line 2151 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 480 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_val -> FALSE");
        Data return_data;
        // $$.type = Type::b_type;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = 0;
        (yyval.data) = return_data;
        java_class.loadBoolConst(return_data, current_table.level, inMain);
    }
#line 2166 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 490 "yacc.y" /* yacc.c:1646  */
    {
        Trace("const_val -> function_call_stmt");
        (yyval.data).type = (yyvsp[0].data).type;
        (yyval.data).kind = Kind::const_kind;
        (yyval.data).value = (yyvsp[0].data).value;
    }
#line 2177 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 499 "yacc.y" /* yacc.c:1646  */
    {
        Trace("datatype -> INT");
        (yyval.type) = Type::i_type;
    }
#line 2186 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 503 "yacc.y" /* yacc.c:1646  */
    {
        Trace("datatype -> REAL");
        (yyval.type) = Type::i_type;
    }
#line 2195 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 507 "yacc.y" /* yacc.c:1646  */
    {
        Trace("datatype -> STRING");
        (yyval.type) = Type::s_type;
    }
#line 2204 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 511 "yacc.y" /* yacc.c:1646  */
    {
        Trace("datatype -> REAL");
        (yyval.type) = Type::i_type;
    }
#line 2213 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 518 "yacc.y" /* yacc.c:1646  */
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
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        
        java_class.newFunction(current_table, (yyvsp[-4].value).s_val, (yyvsp[0].type), current_table.level); // origin table level
    }
#line 2244 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 544 "yacc.y" /* yacc.c:1646  */
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
        java_class.closeFunction(current_table.level);
    }
#line 2270 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 565 "yacc.y" /* yacc.c:1646  */
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

        // reverse(func_data.para_list.begin(), func_data.para_list.end());

        if(!current_table.insert(func_data)) {
            warning("Redeclaration of function in current scope");
        }
        table_stack.insert(current_table);
        current_table = body_table;

        map<int, Data> sorted_map;
        // sort by index with map
        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                sorted_map.insert(pair<int, Data>(iter->second.index, iter->second));
            }
        }

        int cnt = 0;
        for(auto iter = sorted_map.begin(); iter != sorted_map.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                iter->second.stack_index = current_table.start_index + cnt;
                cnt++;
            }
        }

        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                auto sorted_iter = sorted_map.find(iter->second.index);
                iter->second.stack_index = sorted_iter->first;
            }
        }

        java_class.newFunction(current_table, (yyvsp[-5].value).s_val, (yyvsp[0].type), current_table.level);

    }
#line 2326 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 616 "yacc.y" /* yacc.c:1646  */
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
        java_class.closeFunction(current_table.level);
    }
#line 2352 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 640 "yacc.y" /* yacc.c:1646  */
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
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        
        java_class.newFunction(current_table, (yyvsp[-2].value).s_val, Type::void_type, current_table.level - 1);
    }
#line 2381 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 664 "yacc.y" /* yacc.c:1646  */
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
        java_class.closeFunction(current_table.level);
    }
#line 2405 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 683 "yacc.y" /* yacc.c:1646  */
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
        // reverse(proc_data.para_list.begin(), proc_data.para_list.end());
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
        map<int, Data> sorted_map;
        // sort by index with map
        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                sorted_map.insert(pair<int, Data>(iter->second.index, iter->second));
            }
        }

        int cnt = 0;
        for(auto iter = sorted_map.begin(); iter != sorted_map.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                iter->second.stack_index = current_table.start_index + cnt;
                cnt++;
            }
        }

        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                auto sorted_iter = sorted_map.find(iter->second.index);
                iter->second.stack_index = sorted_iter->first;
            }
        }

        java_class.newFunction(current_table, (yyvsp[-3].value).s_val, Type::void_type, current_table.level - 1);
    }
#line 2465 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 738 "yacc.y" /* yacc.c:1646  */
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
        java_class.closeFunction(current_table.level);
    }
#line 2489 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 760 "yacc.y" /* yacc.c:1646  */
    {
        Trace("para_declaration -> ID COLON datatype");
        SymbolTable new_table;
        table_stack.insert(current_table);
        new_table.level = table_stack.list.size();
        new_table.start_index = table_stack.programCounter;

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
#line 2512 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 778 "yacc.y" /* yacc.c:1646  */
    {
        Trace("para_declaration -> ID COLON datatype COMMA para_declaration");
        Data new_data;
        new_data.id = (yyvsp[-2].value).s_val;
        new_data.kind = Kind::para_kind;
        new_data.type = (yyvsp[0].type);
        if(!current_table.insert(new_data)) {
            warning("Redeclaration of parameter in current scope");
        }
        para_list.push_back(new_data);
    }
#line 2528 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 789 "yacc.y" /* yacc.c:1646  */
    { // array
        Trace("para_declaration -> ID COLON ARRAY I_CONST DOT DOT I_CONST OF datatype");
        SymbolTable new_table;
        table_stack.insert(current_table);
        new_table.level = table_stack.list.size();
        new_table.start_index = table_stack.programCounter;

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
#line 2560 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 816 "yacc.y" /* yacc.c:1646  */
    { // array
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
#line 2584 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 839 "yacc.y" /* yacc.c:1646  */
    {
        Trace("block_program -> variable_declaration block_program");
    }
#line 2592 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 842 "yacc.y" /* yacc.c:1646  */
    {
        Trace("block_program -> stmt block_program");
    }
#line 2600 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 849 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> block_stmt");
    }
#line 2608 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 852 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> assign_stmt");
    }
#line 2616 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 855 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> put_stmt");
    }
#line 2624 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 858 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> get_stmt");
    }
#line 2632 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 861 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> result_stmt");
    }
#line 2640 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 864 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> exit_stmt");
    }
#line 2648 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 867 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> skip_stmt");
    }
#line 2656 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 870 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> if_stmt");
    }
#line 2664 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 873 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> loop_stmt");
    }
#line 2672 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 876 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> for_stmt");
    }
#line 2680 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 879 "yacc.y" /* yacc.c:1646  */
    {
        Trace("stmt -> function_call_stmt");
    }
#line 2688 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 885 "yacc.y" /* yacc.c:1646  */
    {
        SymbolTable body_table;
        table_stack.insert(current_table);
        body_table.level = table_stack.list.size();
        current_table = body_table;
        current_table.level = table_stack.list.size();
    }
#line 2700 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 892 "yacc.y" /* yacc.c:1646  */
    {
        Trace("block_stmt -> BEGIN block_stmt_body");

        table_msg("block Table");
        current_table.dump();
        current_table = table_stack.get_top(); 
        table_stack.pop();
    }
#line 2713 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 903 "yacc.y" /* yacc.c:1646  */
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
                if(table_index == 0) {
                    java_class.assignToGlobal(current_table, iter->second, current_table.level, inMain);
                }
                else {
                    java_class.assignToLocal(current_table, iter->second, current_table.level, inMain);
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
            if(current_table.level == 0) {
                java_class.assignToGlobal(current_table, iter->second, current_table.level, inMain);
            }
            else {
                java_class.assignToLocal(current_table, iter->second, current_table.level, inMain);
            }
        }
    }
#line 2809 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 994 "yacc.y" /* yacc.c:1646  */
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
#line 2880 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1064 "yacc.y" /* yacc.c:1646  */
    {
        java_class.putStartStmt(current_table.level, inMain);
    }
#line 2888 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1067 "yacc.y" /* yacc.c:1646  */
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
        java_class.putEndStmt((yyvsp[0].data), current_table.level, inMain);
    }
#line 2908 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1085 "yacc.y" /* yacc.c:1646  */
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
#line 2946 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1118 "yacc.y" /* yacc.c:1646  */
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
#line 2976 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1146 "yacc.y" /* yacc.c:1646  */
    {
        Trace("result_stmt -> RESULT const_expr");
        func_return.return_type = Return_type::result_type;
        func_return.type = (yyvsp[0].data).type;
        java_class.returnFunction(func_return.type, current_table.level, inMain);
    }
#line 2987 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1152 "yacc.y" /* yacc.c:1646  */
    {
        Trace("result_stmt -> RETURN");
        func_return.return_type = Return_type::return_type;
        func_return.type = Type::void_type;
        java_class.returnFunction(func_return.type, current_table.level, inMain);
    }
#line 2998 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1161 "yacc.y" /* yacc.c:1646  */
    {
        Trace("exit_stmt -> EXIT");
        java_class.loopExitStmt(current_table.level, inMain);
    }
#line 3007 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1165 "yacc.y" /* yacc.c:1646  */
    { // bool_expr
        Trace("exit_stmt -> EXIT WHEN bool_expr");
        if((yyvsp[0].data).type == Type::void_type) {
            warning("EXIT operation on void");
        }
        else if((yyvsp[0].data).type != Type::b_type) {
            warning("EXIT operation on non-boolean");
        }
        java_class.loopExitWhenStmt(current_table.level, inMain);
    }
#line 3022 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1178 "yacc.y" /* yacc.c:1646  */
    {
        Trace("skip_stmt -> SKIP");
        java_class.skipStmt(current_table.level, inMain);
    }
#line 3031 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1185 "yacc.y" /* yacc.c:1646  */
    { //bool_expr
        Trace("if_stmt -> IF bool_expr THEN")
        if((yyvsp[-1].data).type != Type::b_type) {
            warning("IF condition is not bool");
        }
        table_stack.insert(current_table);
        SymbolTable body_table;
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        
        java_class.ifStmt(current_table.level, inMain);
    }
#line 3049 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1198 "yacc.y" /* yacc.c:1646  */
    { 
        Trace("if_stmt -> IF bool_expr THEN block_program");
    }
#line 3057 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1201 "yacc.y" /* yacc.c:1646  */
    {
        Trace("if_stmt -> IF bool_expr THEN block_program end_if_stmt");
    }
#line 3065 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1207 "yacc.y" /* yacc.c:1646  */
    {
        Trace("end_if_stmt -> END IF");
        table_msg("if Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();

        java_class.endIfStmt(current_table.level, inMain);
    }
#line 3079 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1216 "yacc.y" /* yacc.c:1646  */
    {
        table_msg("if Table");
        current_table.dump();
        SymbolTable body_table;
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;

        java_class.elseStmt(current_table.level, inMain);
    }
#line 3094 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1226 "yacc.y" /* yacc.c:1646  */
    {
        
    }
#line 3102 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1228 "yacc.y" /* yacc.c:1646  */
    {
        Trace("end_if_stmt -> ELSE block_program END IF");
        table_msg("else Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();

        java_class.blockEndIfStmt(current_table.level, inMain);
    }
#line 3116 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1240 "yacc.y" /* yacc.c:1646  */
    {
        Trace("loop_stmt -> LOOP");
        SymbolTable body_table;
        table_stack.insert(current_table);
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        body_table.start_index = table_stack.programCounter;

        java_class.loopStartStmt(current_table.level, inMain);
    }
#line 3132 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1251 "yacc.y" /* yacc.c:1646  */
    {
        Trace("loop_stmt -> LOOP block_program END LOOP");

        table_msg("loop Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();
        java_class.loopEndStmt(current_table.level, inMain);
    }
#line 3146 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1263 "yacc.y" /* yacc.c:1646  */
    {
        auto iter = current_table.table.find((yyvsp[0].value).s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup((yyvsp[0].value).s_val);
            iter = table_stack.list[table_index].table.find((yyvsp[0].value).s_val);
        }

        SymbolTable body_table;
        table_stack.insert(current_table);
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;

        Data for_data;
        for_data.id = (yyvsp[0].value).s_val;
        for_data.kind = Kind::para_kind;
        for_data.type = Type::i_type;
        current_table.insert(for_data);
    }
#line 3170 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1282 "yacc.y" /* yacc.c:1646  */
    {
        Trace("for_stmt -> FOR ID COLON for_para DOT DOT for_para block_program END FOR");

        auto iter = current_table.table.find((yyvsp[-6].value).s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup((yyvsp[-6].value).s_val);
            if(table_index != -1) {
               iter = table_stack.list[table_index].table.find((yyvsp[-6].value).s_val);
            }
        }
        int cnt = 0;
        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                iter->second.stack_index = current_table.start_index + cnt;
                cnt++;
            }
        }
        java_class.forStartStmt(iter->second, (yyvsp[-3].data), (yyvsp[0].data), current_table.level, inMain);
        java_class.forExitStmt(current_table.level, inMain);
    }
#line 3195 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1302 "yacc.y" /* yacc.c:1646  */
    {
        auto iter = current_table.table.find((yyvsp[-10].value).s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup((yyvsp[-10].value).s_val);
            if(table_index != -1) {
               iter = table_stack.list[table_index].table.find((yyvsp[-10].value).s_val);
            }
        }

        java_class.forEndStmt(iter->second, current_table.level, inMain);

        table_msg("for Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();
    }
#line 3216 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1318 "yacc.y" /* yacc.c:1646  */
    { // DECREASING
        auto iter = current_table.table.find((yyvsp[0].value).s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup((yyvsp[0].value).s_val);
            iter = table_stack.list[table_index].table.find((yyvsp[0].value).s_val);          
        }

        SymbolTable body_table;
        table_stack.insert(current_table);
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        
        Data for_data;
        for_data.id = (yyvsp[0].value).s_val;
        for_data.kind = Kind::para_kind;
        for_data.type = Type::i_type;
        current_table.insert(for_data);
    }
#line 3240 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1337 "yacc.y" /* yacc.c:1646  */
    {
        Trace("for_stmt -> FOR DECREASING ID COLON for_para DOT DOT for_para block_program END FOR");

        auto iter = current_table.table.find((yyvsp[-6].value).s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup((yyvsp[-6].value).s_val);
            if(table_index != -1) {
               iter = table_stack.list[table_index].table.find((yyvsp[-6].value).s_val);
            }
        }
        int cnt = 0;
        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                iter->second.stack_index = current_table.start_index + cnt;
                cnt++;
            }
        }
        java_class.forStartStmt(iter->second, (yyvsp[-3].data), (yyvsp[0].data), current_table.level, inMain);
        java_class.forDecreasingExitStmt(current_table.level, inMain);
    }
#line 3265 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1357 "yacc.y" /* yacc.c:1646  */
    {
        auto iter = current_table.table.find((yyvsp[-10].value).s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup((yyvsp[-10].value).s_val);
            if(table_index != -1) {
               iter = table_stack.list[table_index].table.find((yyvsp[-10].value).s_val);
            }
        }

        java_class.forDecreasingEndStmt(iter->second, current_table.level, inMain);

        table_msg("for Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();
    }
#line 3286 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1376 "yacc.y" /* yacc.c:1646  */
    {
        Trace("for_para -> I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = (yyvsp[0].value).i_val;
        (yyval.data) = return_data;
    }
#line 3299 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1384 "yacc.y" /* yacc.c:1646  */
    {
        Trace("for_para -> ID");
        auto iter = current_table.table.find((yyvsp[0].value).s_val);
        Data return_data;
        if(iter != current_table.table.end()) { // found in current table
            return_data = iter->second;
        }
        else {
            int table_index = table_stack.lookup((yyvsp[0].value).s_val);
            if(table_index != -1) {
                iter = table_stack.list[table_index].table.find((yyvsp[0].value).s_val);
                return_data = iter->second;
            }           
        }
        (yyval.data) = return_data;
    }
#line 3320 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1403 "yacc.y" /* yacc.c:1646  */
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
                java_class.callFunction(iter->second, current_table.level, inMain);
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
                java_class.callFunction(iter->second, current_table.level, inMain);
            }
        }

        if(iter->second.kind == Kind::proc_kind) {
            (yyval.data).kind = Kind::proc_kind;
        }
        else {
            (yyval.data).kind = Kind::const_kind;
        }
    }
#line 3384 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1462 "yacc.y" /* yacc.c:1646  */
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
                        // reverse(para_list.begin(), para_list.end());
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
                        java_class.callFunction(iter->second, current_table.level, inMain);
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
                    // reverse(para_list.begin(), para_list.end());
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
                    java_class.callFunction(iter->second, current_table.level, inMain);
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
#line 3497 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1573 "yacc.y" /* yacc.c:1646  */
    {
        Trace("function_call_para -> const_expr");
        para_list.clear();
        para_list.push_back((yyvsp[0].data));
    }
#line 3507 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1578 "yacc.y" /* yacc.c:1646  */
    {
        Trace("function_call_para -> const_expr COMMA function_call_para");
        para_list.push_back((yyvsp[-2].data));
       
    }
#line 3517 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 3521 "y.tab.cpp" /* yacc.c:1646  */
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
#line 1585 "yacc.y" /* yacc.c:1906  */
 

#include "lex.yy.cpp"

void warning(char *msg) {
    // fprintf(stderr, "\033[47m\033[31m\033[1mWANRING: %s\033[0m\n", msg);
}

void yyerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    table_msg("Current Table");
    current_table.dump();
    exit(1);
}

int main(int argc, char* argv[]) {
    string input_file_name;
    if(argc == 1) {
        yyin = stdin;
    }
    else if(argc == 2) {
        yyin = fopen(argv[1], "r");
        input_file_name = argv[1];
    }
    else {
        yyerror("Too many arguments");
        exit(1);
    }

    if (java_class.openFile(input_file_name)) {
        cout << "Open file " << input_file_name << " successfully" << endl;
    }
    else {
        cout << "Open file " << input_file_name << " failed" << endl;
        exit(1);
    }

    printf("---------------------Parsing begin\n");
    /* perform parsing */
    if(yyparse()) {
        yyerror("Parsing failed");
    }
    else {
        java_class.endFile();
        table_msg("\nMAIN Table");
        current_table.dump();
    
        printf("\n---------------------Parsing end\n");
    }
    
    fclose(yyin);
}
