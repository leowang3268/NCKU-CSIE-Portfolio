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
#line 4 "compiler_hw3.y" /* yacc.c:339  */

    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

        
    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol(int level);
    static void insert_symbol(char *id, int addr_in);
    static void lookup_symbol(char *id);
    static void dump_symbol(int which_table);
    static void update_table(char *id);

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }
    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Global variables */
    bool g_has_error = false;
    FILE *fout;
    int g_indent_cnt = 0;

#line 106 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    VAR = 258,
    NEWLINE = 259,
    INT = 260,
    FLOAT = 261,
    BOOL = 262,
    STRING = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LEQ = 267,
    EQL = 268,
    NEQ = 269,
    LOR = 270,
    LAND = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    QUO_ASSIGN = 275,
    REM_ASSIGN = 276,
    IF = 277,
    ELSE = 278,
    FOR = 279,
    SWITCH = 280,
    CASE = 281,
    DEFAULT = 282,
    PRINT = 283,
    PRINTLN = 284,
    TRUE = 285,
    FASLE = 286,
    IDENT = 287,
    PACKAGE = 288,
    FUNC = 289,
    RETURN = 290,
    INT_LIT = 291,
    FLOAT_LIT = 292,
    STRING_LIT = 293
  };
#endif
/* Tokens.  */
#define VAR 258
#define NEWLINE 259
#define INT 260
#define FLOAT 261
#define BOOL 262
#define STRING 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LEQ 267
#define EQL 268
#define NEQ 269
#define LOR 270
#define LAND 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define QUO_ASSIGN 275
#define REM_ASSIGN 276
#define IF 277
#define ELSE 278
#define FOR 279
#define SWITCH 280
#define CASE 281
#define DEFAULT 282
#define PRINT 283
#define PRINTLN 284
#define TRUE 285
#define FASLE 286
#define IDENT 287
#define PACKAGE 288
#define FUNC 289
#define RETURN 290
#define INT_LIT 291
#define FLOAT_LIT 292
#define STRING_LIT 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 50 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    /* ... */
    char *id;
    char *msg;

#line 231 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   563

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    53,     2,     2,    45,     2,     2,
      46,    47,    43,    41,    48,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    54,
      39,    52,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    99,   100,   104,   105,   112,   116,   117,
     121,   132,   138,   158,   163,   167,   177,   189,   203,   207,
     211,   308,   404,   566,   666,   772,   988,   989,  1012,  1013,
    1014,  1015,  1016,  1017,  1021,  1022,  1026,  1027,  1028,  1032,
    1033,  1034,  1038,  1038,  1042,  1043,  1059,  1063,  1142,  1146,
    1150,  1151,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1168,  1203,  1232,  1233,  1234,  1235,  1239,  1240,
    1241,  1242,  1243,  1247,  1247,  1247,  1251,  1378,  1379,  1380,
    1381,  1382,  1383,  1387,  1407,  1430,  1431,  1432,  1435,  1450,
    1450,  1452,  1454,  1456,  1458,  1467,  1468,  1476,  1485,  1560,
    1635,  1648
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "NEWLINE", "INT", "FLOAT", "BOOL",
  "STRING", "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ", "LOR", "LAND",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN",
  "IF", "ELSE", "FOR", "SWITCH", "CASE", "DEFAULT", "PRINT", "PRINTLN",
  "TRUE", "FASLE", "IDENT", "PACKAGE", "FUNC", "RETURN", "INT_LIT",
  "FLOAT_LIT", "STRING_LIT", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'('", "')'", "','", "'{'", "'}'", "'!'", "'='", "'\"'", "';'",
  "':'", "$accept", "Program", "GlobalStatementList", "GlobalStatement",
  "NEWLINES", "PackageStmt", "FunctionDeclStmt", "FuncParam", "FuncOpen",
  "ParameterList", "ReturnType", "FuncBlock", "Expression", "UnaryExpr",
  "cmp_op", "add_op", "mul_op", "unary_op", "PrimaryExpr", "Operand",
  "ConversionExpr", "Block", "BlockStart", "StatementList", "Statement",
  "DeclarationStmt", "Type", "Literal", "SimpleStmt", "AssignmentStmt",
  "assign_op", "IncDecStmt", "IfStmt", "Condition", "ForStmt", "ForClause",
  "InitStmt", "PostStmt", "SwitchStmt", "CaseStmt", "CaseNum", "PrintStmt",
  "ReturnStmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    60,
      62,    43,    45,    42,    47,    37,    40,    41,    44,   123,
     125,    33,    61,    34,    59,    58
};
# endif

#define YYPACT_NINF -98

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-98)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -98,   -16,    -8,    23,     4,   -98,    27,    28,   -15,
      22,   -13,   -98,   -98,   -98,   -98,   -98,    27,    28,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -21,   207,    22,   -98,
     -27,     7,   -14,   307,   307,   307,     5,   -12,    -6,    -2,
     -98,   -98,   -98,   307,   -98,   -98,   -98,   -98,   307,    28,
     -98,     8,    27,   366,   -98,   307,   -98,   -98,   -98,   -98,
     258,   105,   -98,    28,    -1,   -98,    28,   -98,   -98,   -98,
     -98,   -98,   -98,    -5,    28,    28,   -98,   -98,    15,    22,
     476,     0,   352,   -98,     0,     0,    -3,   401,   -98,     0,
     307,   307,   476,   412,    27,     1,   -98,   -98,   -98,   -98,
     -98,   -98,   307,   307,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   307,   307,   307,
     307,   -98,   156,   -98,   -98,    27,   307,    27,     0,    27,
      27,    22,    -4,    29,   -98,   -98,   307,   -98,   -98,   421,
     458,   -98,   -98,   511,   518,   476,   476,   476,   476,   -98,
     467,   -98,   -98,   307,    -7,     2,   -98,   -98,   -98,   476,
     -98,   -98,   307,   -98,   -98
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,     0,     0,     0,     2,     4,     7,     0,     0,
      12,     0,    10,    15,     1,     3,     8,     5,     0,     6,
      64,    65,    67,    66,    11,    18,     0,     0,     0,    13,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
      71,    72,    45,   101,    68,    69,    39,    40,     0,     0,
      41,     0,    61,    74,    25,     0,    26,    42,    43,    54,
       0,     0,    51,     0,     0,    44,     0,    73,    75,    55,
      56,    57,    58,     0,     0,     0,    17,    14,     0,     0,
      88,     0,    74,    92,     0,     0,     0,     0,    97,     0,
       0,     0,   100,     0,    49,     0,    83,    84,    33,    31,
      28,    29,     0,     0,    78,    79,    80,    81,    82,    30,
      32,    34,    35,    36,    37,    38,    77,     0,     0,     0,
       0,    27,     0,    19,    50,    52,     0,    53,     0,    59,
      60,     0,    62,    85,    89,    90,     0,    94,    96,     0,
       0,    46,    70,    20,    21,    22,    23,    24,    76,    48,
       0,    95,    16,     0,     0,     0,    98,    99,    47,    63,
      87,    86,     0,    93,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -98,    50,    17,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -30,     3,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -75,   -98,     9,   -54,   -98,    -9,   -98,   -34,   -98,
     -98,   -98,   -97,   -32,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    52,     8,     9,    10,    11,    30,
      24,    19,    53,    54,   117,   118,   119,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     120,    68,    69,    81,    70,    85,    86,   164,    71,    72,
      73,    74,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    25,    84,    80,    82,    87,   133,   124,     1,   134,
     135,    28,   137,    92,   138,    33,    12,     7,    93,    76,
      77,    78,     7,    14,    13,    17,    29,    20,    21,    22,
      23,    16,     1,    26,    18,    27,    -9,     2,     3,    79,
      90,    88,    49,    89,    91,   126,    95,   131,   153,    49,
     128,   136,   154,   151,   142,    15,   162,   161,   121,     0,
     139,   140,     0,     0,     0,     0,    94,     0,   124,   122,
     132,     0,   143,   144,     0,     0,     0,     0,     0,   160,
     125,     0,     0,   127,     0,     0,     0,   145,   146,   147,
     148,   129,   130,     0,     0,     0,   150,     0,     0,     0,
       0,     0,     0,     0,   155,     0,    80,     0,    31,     1,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   159,     0,     0,     0,    33,   163,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,     0,
      43,    44,    45,     0,     0,     0,    46,    47,     0,     0,
       0,    48,     0,     0,    49,   123,    50,     0,    51,    31,
       1,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     0,
       0,    43,    44,    45,     0,     0,     0,    46,    47,     0,
       0,     0,    48,     0,     0,    49,   149,    50,     0,    51,
      31,    32,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,     0,    43,    44,    45,     0,     0,     0,    46,    47,
       0,     0,     0,    48,     0,     0,    49,     0,    50,     0,
      51,    31,     1,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,     0,    43,    44,    45,     0,     0,     0,    46,
      47,     0,     0,     0,    48,     0,     0,    49,     0,    50,
       0,    51,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    41,    42,
       0,     0,     0,    44,    45,     0,     0,     0,    46,    47,
       0,     0,     0,    48,     0,     0,     0,     0,    50,     0,
      51,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   -88,     0,     0,   116,   109,   110,   111,   112,   113,
     114,   115,    98,    99,   100,   101,   102,   103,   116,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,     0,
     109,   110,   111,   112,   113,   114,   115,     0,     0,     0,
      49,   109,   110,   111,   112,   113,   114,   115,     0,   141,
     109,   110,   111,   112,   113,   114,   115,     0,   156,    98,
      99,   100,   101,   102,   103,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,     0,     0,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,     0,   157,   109,   110,   111,   112,
     113,   114,   115,     0,   158,   109,   110,   111,   112,   113,
     114,   115,    98,    99,   100,   101,     0,   103,     0,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   109,   110,   111,
     112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
      34,    10,    34,    33,    34,    35,    81,    61,     4,    84,
      85,    32,    87,    43,    89,    22,    32,     0,    48,    28,
      47,    48,     5,     0,    32,     8,    47,     5,     6,     7,
       8,     4,     4,    46,    49,    18,    50,    33,    34,    32,
      46,    36,    49,    55,    46,    46,    38,    32,    52,    49,
      55,    54,    23,   128,    53,     5,    54,   154,    55,    -1,
      90,    91,    -1,    -1,    -1,    -1,    49,    -1,   122,    60,
      79,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,   154,
      63,    -1,    -1,    66,    -1,    -1,    -1,   117,   118,   119,
     120,    74,    75,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   136,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   153,    -1,    -1,    -1,    22,   162,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    41,    42,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    -1,    53,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    41,    42,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    -1,    53,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    -1,    -1,    41,    42,
      -1,    -1,    -1,    46,    -1,    -1,    49,    -1,    51,    -1,
      53,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    41,
      42,    -1,    -1,    -1,    46,    -1,    -1,    49,    -1,    51,
      -1,    53,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    41,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    -1,    -1,    52,    39,    40,    41,    42,    43,
      44,    45,    11,    12,    13,    14,    15,    16,    52,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    39,    40,    41,    42,    43,    44,    45,    -1,    47,
      39,    40,    41,    42,    43,    44,    45,    -1,    47,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    39,    40,    41,    42,
      43,    44,    45,    -1,    47,    39,    40,    41,    42,    43,
      44,    45,    11,    12,    13,    14,    -1,    16,    -1,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    39,    40,    41,
      42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    33,    34,    57,    58,    59,    60,    61,    62,
      63,    64,    32,    32,     0,    59,     4,    60,    49,    67,
       5,     6,     7,     8,    66,    82,    46,    60,    32,    47,
      65,     3,     4,    22,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    35,    36,    37,    41,    42,    46,    49,
      51,    53,    60,    68,    69,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    87,    88,
      90,    94,    95,    96,    97,    98,    82,    47,    48,    32,
      68,    89,    68,    84,    89,    91,    92,    68,    36,    55,
      46,    46,    68,    68,    60,    38,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    39,
      40,    41,    42,    43,    44,    45,    52,    70,    71,    72,
      86,    69,    79,    50,    80,    60,    46,    60,    55,    60,
      60,    32,    82,    77,    77,    77,    54,    77,    77,    68,
      68,    47,    53,    68,    68,    68,    68,    68,    68,    50,
      68,    77,    82,    52,    23,    89,    47,    47,    47,    68,
      77,    88,    54,    84,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    60,    60,
      61,    62,    62,    63,    63,    64,    65,    65,    66,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    73,
      73,    73,    74,    74,    75,    75,    75,    76,    77,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    89,    90,
      90,    91,    92,    93,    94,    95,    95,    96,    97,    97,
      98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     2,     1,
       2,     2,     1,     3,     4,     2,     4,     2,     1,     4,
       3,     3,     3,     3,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     5,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     5,     5,     1,     3,
       3,     5,     1,     1,     3,     3,     3,     2,     4,     4,
       2,     1
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
#line 95 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(scope_level);}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(no_return)
            fprintf(fout, "return\n");
        fprintf(fout, ".end method\n");
        no_return = true;
    }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "compiler_hw3.y" /* yacc.c:1646  */
    {which_expr=0;}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "compiler_hw3.y" /* yacc.c:1646  */
    {which_expr=0;}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol(scope_level);
        printf("package: %s\n", yylval.s_val);
        fprintf(fout, ".source hw3.j\n");
        fprintf(fout, ".class public Main\n");
        fprintf(fout, ".super java/lang/Object\n");
    }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 133 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(fout, "%s\n", param_type[param_count-1]);
        fprintf(fout, ".limit stack 100\n");
        fprintf(fout, ".limit locals 100\n");
    }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("func_signature: ()V\n");
        strcpy(id_buf, func_id_buf);
        strcpy(type_buf, "func");
        strcpy(func_sig_buf, "()V");
        int tmp = addr;
        addr = 0;
        scope_level--;
        insert_symbol(func_id_buf, -1);
        update_table(func_id_buf); 
        addr = tmp;
        scope_level++;
        fprintf(fout, "V\n");
        fprintf(fout, ".limit stack 100\n");
        fprintf(fout, ".limit locals 100\n");
    }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 159 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if (!strcmp(func_id_buf, "main"))
            fprintf(fout, "[Ljava/lang/String;)");
    }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 168 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                    printf("func: %s\n", (yyvsp[0].s_val));
                    create_symbol(scope_level + 1); 
                    strcpy(func_id_buf, (yyvsp[0].s_val)); 
                    fprintf(fout, ".method public static %s(", (yyvsp[0].s_val));
                }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 178 "compiler_hw3.y" /* yacc.c:1646  */
    {
        //dfsdfdsfsedfsdfsdfsdfffffffffffffffffff
        printf("param %s, type: %s\n", (yyvsp[-1].s_val), param_type[param_count-1]);
        insert_symbol((yyvsp[-1].s_val), addr++); 
        strcpy(func_sig_buf, "-"); 
        update_table((yyvsp[-1].s_val));
        fprintf(fout, "%s", param_type[param_count-1]);
        
        // printf("> Insert `%s` (addr: %d) to scope level %d\n", $<s_val>3, table_instances[result[0]].addr[result[1]], scope_level);
        // printf("hey %d\n", result[0]);
    }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 190 "compiler_hw3.y" /* yacc.c:1646  */
    {

        printf("param %s, type: %s\n", (yyvsp[-1].s_val), param_type[param_count-1]);
        insert_symbol((yyvsp[-1].s_val), addr++); 
        strcpy(func_sig_buf, "-"); 
        update_table((yyvsp[-1].s_val));

        fprintf(fout, "%s)", param_type[param_count-1]);
        // printf("> Insert `%s` (addr: %d) to scope level %d\n", $<s_val>1, table_instances[result[0]].addr[result[1]], scope_level);
    }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 207 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(scope_level + 1); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 212 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        is_bi_op = true;
        lookup_symbol((yyvsp[-2].s_val));
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol((yyvsp[0].s_val));
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }

        if(strcmp(first_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, first_type);

            printf("LOR\n");   
        }
        else if(strcmp(second_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, second_type);
            printf("LOR\n");
        }
        literal_count = 0;
        has_type_converse = false;
    }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 309 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        is_bi_op = true;
        lookup_symbol((yyvsp[-2].s_val));
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol((yyvsp[0].s_val));
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }

        if(strcmp(first_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, first_type);
            printf("LAND\n");   
        }
        else if(strcmp(second_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, second_type);
            printf("LAND\n");   
        }
            literal_count = 0;
            has_type_converse = false;
    }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 405 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        is_bi_op = true;
        lookup_symbol((yyvsp[-2].s_val));
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol((yyvsp[0].s_val));
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }

        switch(b_op){
            case 6:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: EQL (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifeq L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                printf("EQL\n"); 
                break;
            case 7:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: NEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifne L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                printf("NEQ\n"); 
                break;
            case 8:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: LSS (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "iflt L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                printf("LSS\n"); 
               break;
            case 9:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: LEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifle L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);                
                printf("LEQ\n"); 
                break;
            case 10:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: GTR (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifgt L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                printf("GTR\n"); 
                break;
            case 11:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: GEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifge L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);                
                printf("GEQ\n"); 
                break;
        }
        strcpy(expr_type, "bool");
        literal_count = 0;
        has_type_converse = false;
        // label_cnt = 0;
    }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 567 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        is_bi_op = true;
        lookup_symbol((yyvsp[-2].s_val));
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol((yyvsp[0].s_val));
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }
        // printf("expr:%s, buf:%s, literal_count=%d\n", expr_type, type_buf, literal_count);
        switch(b_op){
            case 4:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "iadd\n") : fprintf(fout, "fadd\n");
                printf("ADD\n"); 
                break;
            case 5:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub\n") : fprintf(fout, "fsub\n");
                printf("SUB\n"); 
                break;
        }
        literal_count = 0;
        has_type_converse = false;
    }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 667 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        is_bi_op = true;
        lookup_symbol((yyvsp[-2].s_val));
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            // strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol((yyvsp[0].s_val));
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }

        switch(b_op){
            case 1:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "imul\n") : fprintf(fout, "fmul\n");
                printf("MUL\n"); 
                break;
            case 2:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "idiv\n") : fprintf(fout, "fdiv\n");
                printf("QUO\n"); 
                break;
            case 3:
                if(!strcmp(first_type, "float32") || !strcmp(second_type, "float32"))
                    printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno);
                fprintf(fout, "irem\n");
                printf("REM\n"); 
                break;
        }
        literal_count = 0;
        has_type_converse = false;
    }
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 990 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        switch(u_op){
            // case 1:
            //     printf("POS\n"); 
            //     break;
            case 2:
                printf("NEG\n"); 
                (!strcmp(expr_type, "int32")) ? fprintf(fout, "ineg\n") : fprintf(fout, "fneg\n");
                break;
            case 3:
                printf("NOT\n"); 
                fprintf(fout, "ixor\n");
                break;
        }
    }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 1012 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=6;}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 1013 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=7;}
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 1014 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=8;}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 1015 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=9;}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 1016 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=10;}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1017 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=11;}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1021 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=4;}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1022 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=5;}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1026 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=1;}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1027 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=2;}
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1028 "compiler_hw3.y" /* yacc.c:1646  */
    {b_op=3;}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1032 "compiler_hw3.y" /* yacc.c:1646  */
    {u_op=1;}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1033 "compiler_hw3.y" /* yacc.c:1646  */
    {u_op=2;}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1034 "compiler_hw3.y" /* yacc.c:1646  */
    {u_op=3;}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1044 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        lookup_symbol((yyvsp[0].s_val));
        strcpy(expr_type, table_instances[result[0]].type[result[1]]); 
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), table_instances[result[0]].addr[result[1]]);
        lookup_symbol((yyvsp[0].s_val));
        int index = result[1];
        if(!strcmp(expr_type, "int32"))
            fprintf(fout, "iload %d\n", index);
        else if(!strcmp(expr_type, "float32"))
            fprintf(fout, "fload %d\n", index);
        else if(!strcmp(expr_type, "string"))
            fprintf(fout, "aload %d\n", index);
        else if(!strcmp(expr_type, "bool"))
            fprintf(fout, "bload %d\n", index);
    }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1064 "compiler_hw3.y" /* yacc.c:1646  */
    {
        // lookup_symbol($<s_val>3);
        // int first_index = result[1];
        // // printf("%d\n", first_index);
        // if (first_index<0)
        // {
        //     strcpy(expr_type[0], expr_type[which_expr-1]);
        //     printf("hihi, it's %s\n", expr_type[0]);     
        // }
        // else
        //     strcpy(expr_type[0], table_instances[result[0]].type[first_index]);
        

        // add load here~~~~~~~~~~~~~~~
        has_type_converse = true;
        lookup_symbol((yyvsp[-1].s_val));
        int index = result[1];
        if (!strcmp(expr_type, "int32"))
        {
            // if (index!=-1)
            //     fprintf(fout, "iload %d\n", index);
            printf("i"); 
            fprintf(fout, "i");
        }
        else if (!strcmp(expr_type, "float32"))
        {
            // if (index!=-1)
            //     fprintf(fout, "fload %d\n", index);
            printf("f");
            fprintf(fout, "f");
        }
        else if (!strcmp(expr_type, "string"))
        {
            // if (index!=-1)
            //     fprintf(fout, "aload %d\n", index);
            printf("s");
            fprintf(fout, "s");
        }
        else if (!strcmp(expr_type, "bool"))
        {
            // if (index!=-1)
            //     fprintf(fout, "bload %d\n", index);
            printf("b");    
            fprintf(fout, "b");
        }
        
        printf("2");
        fprintf(fout, "2");

        if (!strcmp(type_buf, "int32"))
        {
            printf("i\n");
            fprintf(fout, "i\n");
        }
        else if (!strcmp(type_buf, "float32"))
        {
            printf("f\n");
            fprintf(fout, "f\n");
        }
        else if (!strcmp(type_buf, "string"))
        {
            printf("s\n");
            fprintf(fout, "s\n");
        }
        else if (!strcmp(type_buf, "bool"))
        {
            printf("b\n"); 
            fprintf(fout, "b\n");
        }
    }
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1142 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(scope_level + 1); }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1146 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol(scope_level); }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1169 "compiler_hw3.y" /* yacc.c:1646  */
    {
        lookup_symbol((yyvsp[-1].s_val));
        int index = result[1];
        // havn't been declare
        if (index==-1)
        {
            // insert symbol
            --yylineno;
            insert_symbol((yyvsp[-1].id), addr++); strcpy(func_sig_buf, "-"); update_table((yyvsp[-1].id)); 
            ++yylineno;
            lookup_symbol((yyvsp[-1].s_val));
            int cur_index = result[1];
            if (!strcmp(type_buf, "int32"))
            {
                fprintf(fout, "ldc 0\n");
                fprintf(fout, "istore %d\n", cur_index);
            }
            else if (!strcmp(type_buf, "float32"))
            {
                fprintf(fout, "ldc 0.000000\n");
                fprintf(fout, "fstore %d\n", cur_index);
            }
            else if (!strcmp(type_buf, "string"))
            {
                fprintf(fout, "ldc \"\"\n");
                fprintf(fout, "astore %d\n", cur_index);
            }
            else if (!strcmp(type_buf, "bool"))
            {
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "bstore %d\n", cur_index);  
            }
        }
    }
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1204 "compiler_hw3.y" /* yacc.c:1646  */
    {
        lookup_symbol((yyvsp[-3].s_val));
        int index = result[1];
        // havn't been declare
        if (index==-1)
        {
            --yylineno;
            insert_symbol((yyvsp[-3].id), addr++);
            strcpy(id_buf, (yyvsp[-3].id));
            strcpy(func_sig_buf, "-"); 
            update_table((yyvsp[-3].id));
            ++yylineno;
            lookup_symbol((yyvsp[-3].s_val));
            int cur_index = result[1];
            if (!strcmp(type_buf, "int32"))
                fprintf(fout, "istore %d\n", cur_index);
            else if (!strcmp(type_buf, "float32"))
                fprintf(fout, "fstore %d\n", cur_index);
            else if (!strcmp(type_buf, "string"))
                fprintf(fout, "astore %d\n", cur_index);
            else if (!strcmp(type_buf, "bool"))
                fprintf(fout, "bstore %d\n", cur_index);   
        }

    }
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1232 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(type_buf, "int32"); strcpy(param_type[param_count], "I"); param_count++; }
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1233 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(type_buf, "float32"); strcpy(param_type[param_count], "F"); param_count++; }
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1234 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(type_buf, "string"); strcpy(param_type[param_count], "S"); param_count++; }
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1235 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(type_buf, "bool"); strcpy(param_type[param_count], "B"); param_count++; }
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1239 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INT_LIT %d\n", atoi(yylval.msg)); if (literal_count==1) strcpy(type_buf, "int32"); else strcpy(expr_type, "int32"); literal_count++; fprintf(fout, "ldc %d\n", atoi(yylval.msg)); }
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1240 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FLOAT_LIT %f\n", atof(yylval.msg)); if (literal_count==1) strcpy(type_buf, "float32"); else strcpy(expr_type, "float32"); literal_count++; fprintf(fout, "ldc %f\n", atof(yylval.msg)); }
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1241 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("STRING_LIT %s\n", yylval.s_val); if (literal_count==1) strcpy(type_buf, "string"); else strcpy(expr_type, "string"); literal_count++; fprintf(fout, "ldc %s\n", yylval.s_val); }
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1242 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("TRUE 1\n"); if (literal_count==1) strcpy(type_buf, "bool"); else strcpy(expr_type, "bool"); literal_count++; fprintf(fout, "iconst_1\n"); }
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1243 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FALSE 0\n"); if (literal_count==1) strcpy(type_buf, "bool"); else strcpy(expr_type, "bool"); literal_count++; fprintf(fout, "iconst_0\n"); }
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1252 "compiler_hw3.y" /* yacc.c:1646  */
    {
        lookup_symbol((yyvsp[-2].s_val));
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            {
                fprintf(fout, "istore %d\n", first_index);
            }
            else if(!strcmp(first_type, "float32"))
            {
                fprintf(fout, "fstore %d\n", first_index);
            }
            else if(!strcmp(first_type, "string"))
            {
                fprintf(fout, "astore %d\n", first_index);
            }
        }
        lookup_symbol((yyvsp[0].s_val));
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", $<s_val>3);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!is_bi_op)
            // {
            //     if(!strcmp(first_type, "int32"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            //     else if(!strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "bload %d\n", second_index);
            //     }
            // }
        }
        switch(assign_op){
            case 0:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                // fprintf(fout, "istore %");
                printf("ASSIGN\n"); 
                break;
            case 1:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "iadd\n") : fprintf(fout, "fadd\n");
                printf("ADD\n"); 
                break;
            case 2:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub\n") : fprintf(fout, "fsub\n");
                printf("SUB\n"); 
                break;
            case 3:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "imul\n") : fprintf(fout, "fmul\n");
                printf("MUL\n"); 
                break;
            case 4:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "idiv\n") : fprintf(fout, "fdiv\n");
                printf("QUO\n"); 
                break;
            case 5:
                if(!strcmp(first_type, "float32") || !strcmp(second_type, "float32"))
                    printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno);
                printf("REM\n"); 
                fprintf(fout, "irem\n");
                break;
        }

        is_bi_op = false;
        literal_count = 0;
    }
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1378 "compiler_hw3.y" /* yacc.c:1646  */
    {assign_op=0;}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1379 "compiler_hw3.y" /* yacc.c:1646  */
    {assign_op=1;}
#line 2712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1380 "compiler_hw3.y" /* yacc.c:1646  */
    {assign_op=2;}
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1381 "compiler_hw3.y" /* yacc.c:1646  */
    {assign_op=3;}
#line 2724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1382 "compiler_hw3.y" /* yacc.c:1646  */
    {assign_op=4;}
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1383 "compiler_hw3.y" /* yacc.c:1646  */
    {assign_op=5;}
#line 2736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1388 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("INC\n"); 
        lookup_symbol((yyvsp[-1].s_val));
        int index = result[1];
        if(!strcmp(expr_type, "int32"))
        {
            // fprintf(fout, "iload %d\n", index);
            fprintf(fout, "ldc 1\n");
            fprintf(fout, "iadd\n");
            fprintf(fout, "istore %d\n", index);
        }
        else if(!strcmp(expr_type, "float32"))
        {
            // fprintf(fout, "fload %d\n", index);
            fprintf(fout, "ldc 1.0\n");
            fprintf(fout, "fadd\n");
            fprintf(fout, "fstore %d\n", index);
        }
    }
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1408 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        printf("DEC\n"); 
        lookup_symbol((yyvsp[-1].s_val));
        int index = result[1];
        if(!strcmp(expr_type, "int32"))
        {
            // fprintf(fout, "iload %d\n", index);
            fprintf(fout, "ldc 1\n");
            fprintf(fout, "isub\n");
            fprintf(fout, "istore %d\n", index);
        }
        else if(!strcmp(expr_type, "float32"))
        {
            // fprintf(fout, "fload %d\n", index);
            fprintf(fout, "ldc 1.0\n");
            fprintf(fout, "fsub\n");
            fprintf(fout, "fstore %d\n", index);
        }
    }
#line 2784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1436 "compiler_hw3.y" /* yacc.c:1646  */
    {
    // int id = result[1];
    // if (id!=-1)
    //     if(!(b_op>=6&&b_op<=11))
    //         strcpy(type_buf, table_instances[result[0]].type[id]);

    if (strcmp(expr_type, "bool"))
    {
        printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, expr_type);
        break;
    }
        
}
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1459 "compiler_hw3.y" /* yacc.c:1646  */
    {
                fprintf(fout, "goto L_switch_begin_%d:\n", switch_cnt++);
                fprintf(fout, "L_switch_begin_%d\n", switch_cnt-1);
                fprintf(fout, "lookupswitch\n");
                case_cnt = 0;
            }
#line 2813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1469 "compiler_hw3.y" /* yacc.c:1646  */
    {
            fprintf(fout, "default: L_case_%d\n", case_cnt);
            fprintf(fout, "L_switch_end_%d:\n", switch_cnt-1);
            fprintf(fout, "return\n");
        }
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1476 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                            printf("case %s\n", yylval.msg);   
                            fprintf(fout, "%d: L_case_%d\n",case_cnt, case_cnt);
                            fprintf(fout, "L_case_%d:\n", case_cnt);
                            fprintf(fout, "goto L_switch_end_%d\n", switch_cnt-1);
                            case_cnt++;
                        }
#line 2835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1485 "compiler_hw3.y" /* yacc.c:1646  */
    {  char tmp_type[10];
                                    lookup_symbol((yyvsp[-1].s_val));
                                    if (literal_count>1)    
                                    {
                                        printf("PRINT %s\n", type_buf);
                                        strcpy(tmp_type, type_buf);
                                    }
                                    else
                                    {
                                       printf("PRINT %s\n", expr_type);
                                       strcpy(tmp_type, expr_type);
                                    }
                                    literal_count = 0; 
                                    int which_type = 0;
                                    int index = result[1];
                                    if(!strcmp(tmp_type, "int32"))
                                    {
                                        // fprintf(fout, "ldc %d\n", atoi(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "iload %d\n", index);
                                        which_type = 1;
                                    }
                                    else if(!strcmp(tmp_type, "float32"))
                                    {
                                        // fprintf(fout, "ldc %f\n", atof(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "fload %d\n", index);
                                        which_type = 2;
                                    }
                                    else if(!strcmp(tmp_type, "string"))
                                    {
                                        // fprintf(fout, "ldc %s\n", $<s_val>3);
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "aload %d\n", index);
                                        which_type = 3; 
                                    }
                                    else if(!strcmp(tmp_type, "bool"))
                                    {
                                        // fprintf(fout, "ldc %d\n", atoi(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "bload %d\n", index);
                                        which_type = 4;
                                    }
                                    is_bi_op = false;
                                    fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                    fprintf(fout, "swap\n");
                                    
                                    switch(which_type)
                                    {
                                        case 1:
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(I)V\n");
                                            break;
                                        case 2:
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(F)V\n");
                                            break;
                                        case 3:                                            
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                            break;
                                        case 4:
                                            fprintf(fout, "iconst_1\n");
                                            fprintf(fout, "ifne L_ cmp_%d\n", label_cnt++);
                                            fprintf(fout, "ldc \"false\"\n");
                                            fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                                            fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                                            fprintf(fout, "ldc \"true\"\n");
                                            fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                                            fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                            fprintf(fout, "swap\n");
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                            break;
                                    }
                                    

                                
                                }
#line 2915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1560 "compiler_hw3.y" /* yacc.c:1646  */
    {  char tmp_type[10];
                                    lookup_symbol((yyvsp[-1].s_val));
                                    if (literal_count>1)    
                                    {
                                        printf("PRINTLN %s\n", type_buf);
                                        strcpy(tmp_type, type_buf);
                                    }
                                    else
                                    {
                                       printf("PRINTLN %s\n", expr_type);
                                       strcpy(tmp_type, expr_type);
                                    }
                                    literal_count = 0; 
                                    int which_type = 0;
                                    int index = result[1];
                                    if(!strcmp(tmp_type, "int32"))
                                    {
                                        // fprintf(fout, "ldc %d\n", atoi(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "iload %d\n", index);
                                        which_type = 1;
                                    }
                                    else if(!strcmp(tmp_type, "float32"))
                                    {
                                        // fprintf(fout, "ldc %f\n", atof(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "fload %d\n", index);
                                        which_type = 2;
                                    }
                                    else if(!strcmp(tmp_type, "string"))
                                    {
                                        // fprintf(fout, "ldc %s\n", $<s_val>3);
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "aload %d\n", index);
                                        which_type = 3; 
                                    }
                                    else if(!strcmp(tmp_type, "bool"))
                                    {
                                        // fprintf(fout, "ldc %d\n", atoi(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "bload %d\n", index);
                                        which_type = 4;
                                    }
                                    is_bi_op = false;
                                    fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                    fprintf(fout, "swap\n");
                                    
                                    switch(which_type)
                                    {
                                        case 1:
                                            fprintf(fout, "invokevirtual java/io/PrintStream/println(I)V\n");
                                            break;
                                        case 2:
                                            fprintf(fout, "invokevirtual java/io/PrintStream/println(F)V\n");
                                            break;
                                        case 3:                                            
                                            fprintf(fout, "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                            break;
                                        case 4:
                                            fprintf(fout, "iconst_1\n");
                                            fprintf(fout, "ifne L_ cmp_%d\n", label_cnt++);
                                            fprintf(fout, "ldc \"false\"\n");
                                            fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                                            fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                                            fprintf(fout, "ldc \"true\"\n");
                                            fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                                            fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                            fprintf(fout, "swap\n");
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                            break;
                                    }
                                }
#line 2992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1636 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        no_return = false;
        printf("return\n");
        if (!strcmp(expr_type, "int32"))      
            fprintf(fout, "ireturn\n");
        else if (!strcmp(expr_type, "float32"))
            fprintf(fout, "freturn\n");
        else if (!strcmp(expr_type, "string"))
            fprintf(fout, "areturn\n");
        else if (!strcmp(expr_type, "bool"))
            fprintf(fout, "breturn\n"); 
    }
#line 3009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1648 "compiler_hw3.y" /* yacc.c:1646  */
    { no_return=false; printf("return\n"); fprintf(fout ,"return\n"); }
#line 3015 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3019 "y.tab.c" /* yacc.c:1646  */
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
#line 1651 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;

    scope_level = 0;

    for(int i=0; i<10; i++){
        scope_stack_top[i] = 0;
    }

    memset(expr_type,0,strlen(expr_type));
    memset(type_buf,0,strlen(type_buf));

    addr = 0;
    no_return = true;
    is_bi_op = false;
    has_type_converse = false;
    fout = fopen("hw3.j", "w");
    yyparse();

    printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    fclose(fout);
    /* CODEGEN("\n"); */
    /* CODEGEN("%d - %s\n", 100, "Hello world"); */
    return 0;
}

static void create_symbol(int level) {
    printf("> Create symbol table (scope level %d)\n", level);
}

static void insert_symbol(char *id, int addr_in) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", id, addr_in, scope_level);
}

static void lookup_symbol(char *id) {
    for(int a=scope_level; a>=0; a--){
        for(int i=0; i<10; i++){
            if(!strcmp(table_instances[a].name[i], id)){
                result[0] = a;
                result[1] = i;
                return;
            }
        }
    }
    
    result[1] = -1;
}

static void dump_symbol(int which_table) {
    printf("\n> Dump symbol table (scope level: %d)\n", which_table);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
            "Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
    for(int i=0; i<scope_stack_top[which_table]; i++){
        printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",
            table_instances[which_table].index[i], 
            table_instances[which_table].name[i], 
            table_instances[which_table].type[i], 
            table_instances[which_table].addr[i], 
            table_instances[which_table].lineno[i], 
            table_instances[which_table].funcsig[i]);
    }
    printf("\n");

    for(int i=scope_stack_top[which_table] - 1; i>=0; i--){
        table_instances[which_table].index[i] = -1;
        strcpy(table_instances[which_table].name[i], "");
        strcpy(table_instances[which_table].type[i], "");
        table_instances[which_table].addr[i] = -2;
        table_instances[which_table].lineno[i] = 0;
        strcpy(table_instances[which_table].funcsig[i], "");
    }
    scope_stack_top[which_table] = 0;
}

static void update_table(char *id) {
    int top = scope_stack_top[scope_level];
    table_instances[scope_level].index[top] = top;
    strcpy(table_instances[scope_level].name[top], id);
    strcpy(table_instances[scope_level].type[top], type_buf);
    table_instances[scope_level].addr[top] = addr - 1;
    table_instances[scope_level].lineno[top] = yylineno + 1;
    strcpy(table_instances[scope_level].funcsig[top], func_sig_buf);
    scope_stack_top[scope_level]++;
}



