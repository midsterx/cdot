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
#line 1 "ast.y" /* yacc.c:339  */

	#include "header.h"
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <stdarg.h>
	

	#define YYDEBUG_LEXER_TEXT yytext

	extern int yylineno;
	extern char *yytext;

	int yylex(void);
	int yyerror(const char *s);

	int ex (nodeType *p, int flag);
	// prototype to create a node for an operation 
	nodeType *opr(int oper, int nops, ...);
	// prototype to create a node for an identifier 
	nodeType *id(char *identifier);
	// prototype to create a node for a constat 
	nodeType *con(char *value);
	
	int if_assign = 1;

#line 94 "y.tab.c" /* yacc.c:339  */

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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    HASH = 258,
    INCLUDE = 259,
    DEFINE = 260,
    STDIO = 261,
    STDLIB = 262,
    MATH = 263,
    STRING = 264,
    TIME = 265,
    HEADER_LITERAL = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    DO = 270,
    BREAK = 271,
    CONTINUE = 272,
    RETURN = 273,
    SHORTHANDADD = 274,
    SHORTHANDSUB = 275,
    SHORTHANDMULT = 276,
    SHORTHANDDIV = 277,
    INCREMENT = 278,
    DECREMENT = 279,
    IDENTIFIER = 280,
    CONSTANT = 281,
    TYPE_NAME = 282,
    CHAR = 283,
    INT = 284,
    LONG = 285,
    FLOAT = 286,
    DOUBLE = 287,
    VOID = 288,
    MAIN = 289,
    SHORT = 290,
    UNSIGNED = 291,
    SIGNED = 292,
    STRUCT = 293,
    GE_OP = 294,
    LE_OP = 295,
    NE_OP = 296,
    EQ_OP = 297,
    AND = 298,
    OR = 299,
    NOT = 300,
    STATIC = 301,
    EXTERN = 302,
    REGISTER = 303,
    AUTO = 304,
    ARRTYPE = 305
  };
#endif
/* Tokens.  */
#define HASH 258
#define INCLUDE 259
#define DEFINE 260
#define STDIO 261
#define STDLIB 262
#define MATH 263
#define STRING 264
#define TIME 265
#define HEADER_LITERAL 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define DO 270
#define BREAK 271
#define CONTINUE 272
#define RETURN 273
#define SHORTHANDADD 274
#define SHORTHANDSUB 275
#define SHORTHANDMULT 276
#define SHORTHANDDIV 277
#define INCREMENT 278
#define DECREMENT 279
#define IDENTIFIER 280
#define CONSTANT 281
#define TYPE_NAME 282
#define CHAR 283
#define INT 284
#define LONG 285
#define FLOAT 286
#define DOUBLE 287
#define VOID 288
#define MAIN 289
#define SHORT 290
#define UNSIGNED 291
#define SIGNED 292
#define STRUCT 293
#define GE_OP 294
#define LE_OP 295
#define NE_OP 296
#define EQ_OP 297
#define AND 298
#define OR 299
#define NOT 300
#define STATIC 301
#define EXTERN 302
#define REGISTER 303
#define AUTO 304
#define ARRTYPE 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "ast.y" /* yacc.c:355  */

	int ival;
	struct nodeType *nPtr;
	char string[128];

#line 240 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    64,     2,     2,
      54,    55,    60,    58,    53,    59,     2,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    52,
      62,    51,    63,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    70,    73,    74,    80,    84,    85,    89,
      90,    91,    92,    93,    97,    98,    99,   103,   104,   105,
     108,   111,   114,   121,   122,   123,   127,   128,   129,   130,
     134,   135,   136,   140,   141,   142,   143,   144,   148,   149,
     150,   154,   155,   159,   160,   161,   162,   163,   164,   168,
     169,   173,   177,   178,   182,   183,   187,   188,   192,   193,
     194,   195,   196,   200,   201,   202,   206,   207,   211,   212,
     216,   217,   221,   222,   226,   227,   228,   232,   233,   234,
     235,   236,   237,   238,   242,   243,   247,   248,   252,   253,
     257,   258,   262,   263,   267,   271,   275,   279,   280
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HASH", "INCLUDE", "DEFINE", "STDIO",
  "STDLIB", "MATH", "STRING", "TIME", "HEADER_LITERAL", "IF", "ELSE",
  "WHILE", "DO", "BREAK", "CONTINUE", "RETURN", "SHORTHANDADD",
  "SHORTHANDSUB", "SHORTHANDMULT", "SHORTHANDDIV", "INCREMENT",
  "DECREMENT", "IDENTIFIER", "CONSTANT", "TYPE_NAME", "CHAR", "INT",
  "LONG", "FLOAT", "DOUBLE", "VOID", "MAIN", "SHORT", "UNSIGNED", "SIGNED",
  "STRUCT", "GE_OP", "LE_OP", "NE_OP", "EQ_OP", "AND", "OR", "NOT",
  "STATIC", "EXTERN", "REGISTER", "AUTO", "ARRTYPE", "'='", "';'", "','",
  "'('", "')'", "'{'", "'}'", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'",
  "'%'", "'?'", "':'", "$accept", "translation_unit",
  "external_declaration", "headers", "libraries", "primary_expression",
  "postfix_expression", "unary_expression", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "conditional_expression", "assignment_expression", "expression",
  "constant_expression", "declaration", "init_declarator_list",
  "init_declarator", "type_specifier", "struct_specifier",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "conditional_statement", "iteration_statement", "break_statement",
  "continue_statement", "return_statement", YY_NULLPTR
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
     305,    61,    59,    44,    40,    41,   123,   125,    43,    45,
      42,    47,    60,    62,    37,    63,    58
};
# endif

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,    26,  -103,    37,  -103,  -103,   -19,   146,  -103,  -103,
    -103,   -21,  -103,    -6,    39,    50,   190,  -103,  -103,    62,
    -103,    27,  -103,  -103,   224,    56,   190,  -103,   190,   160,
    -103,    -9,     9,  -103,    91,  -103,  -103,  -103,  -103,  -103,
      58,    63,   172,  -103,  -103,  -103,    67,  -103,     9,    35,
    -103,    60,    60,  -103,  -103,     9,     9,     9,  -103,    42,
      19,   -42,   -35,    95,   -29,  -103,  -103,  -103,  -103,    66,
    -103,  -103,     9,  -103,  -103,  -103,  -103,    -5,  -103,  -103,
    -103,   -26,  -103,  -103,  -103,  -103,    81,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,    87,   138,    92,    96,   157,  -103,
    -103,    75,  -103,  -103,  -103,   114,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,     9,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   -42,   -42,   -35,   -35,
     -35,   -35,    95,    95,   -45,     9,   137,  -103,  -103,  -103,
     107,  -103,  -103,  -103,  -103,     9,   -11,   113,  -103,  -103,
     138,     9,   152,    45,   138,   117,  -103,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    59,    60,    61,    58,     0,     0,     2,     6,
       5,     0,    62,     0,     0,    65,     0,     1,     3,    57,
      52,     0,    54,     7,     0,     0,     0,    60,    71,     0,
      66,     0,     0,    53,     0,     9,    10,    11,    12,    13,
       0,     0,     0,    70,    63,    67,    76,    68,     0,     0,
      72,     0,     0,    14,    15,     0,     0,     0,    17,    23,
      26,    30,    33,    38,    41,    43,    56,    55,     8,     0,
       4,    64,     0,    26,    51,    74,    69,     0,    21,    22,
      49,     0,    24,    25,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      84,     0,    88,    89,    77,     0,    86,    78,    80,    79,
      81,    82,    83,    75,    73,     0,    16,    18,    45,    46,
      47,    48,    44,    27,    28,    29,    31,    32,    37,    36,
      34,    35,    40,    39,     0,     0,     0,    95,    96,    97,
       0,    91,    85,    87,    50,     0,     0,     0,    98,    42,
       0,     0,    92,     0,     0,     0,    93,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,   169,  -103,  -103,   134,  -103,   -47,   111,   127,
     112,  -103,   -46,   -15,   -44,   106,   -55,  -103,   153,     0,
    -103,   173,   -14,   167,  -103,   125,  -102,   163,  -103,    93,
    -103,  -103,  -103,  -103,  -103,  -103
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    40,    58,    59,    60,    61,    62,
      63,    64,    65,    80,   111,    75,    10,    21,    22,    28,
      12,    29,    30,    31,    49,    50,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    73,    74,   146,    19,    23,    15,    11,   125,    82,
      83,    81,   101,   102,   112,    45,    46,    66,    92,    93,
      46,   155,    94,    95,    96,    73,    74,   125,    45,   126,
      13,    20,    51,    52,    53,    54,   103,    16,    87,    88,
      89,    90,   125,    47,   160,   133,   134,   135,    73,    73,
      73,    73,    73,    73,    73,    73,    24,    48,   162,   144,
     112,    48,   166,    55,   150,    84,    85,    56,    57,    11,
      91,    14,   128,   129,   130,   131,   132,     1,   104,    33,
      34,   105,   106,   107,   108,    53,    54,    76,    77,    51,
      52,    53,    54,    25,     2,    27,    86,     4,   125,     5,
     165,   156,     2,     3,     6,     4,    26,     5,    73,   159,
     154,    41,     6,    32,    55,    11,    19,   163,   109,    69,
      55,    68,    69,   110,    56,    57,   104,   151,   125,   105,
     106,   107,   108,    72,    97,    98,   127,    51,    52,    53,
      54,   145,     2,    27,   147,     4,    17,     5,   148,     1,
     104,   157,     6,   105,   106,   107,   108,    99,   100,   158,
     125,    51,    52,    53,    54,   164,   109,   161,    55,   167,
      69,   152,    56,    57,     2,     3,    18,     4,   123,     5,
      51,    52,    53,    54,     6,    78,    79,    67,     2,    27,
     109,     4,    55,     5,    69,    43,    56,    57,     6,    42,
       2,    27,   124,     4,    70,     5,   136,   137,   153,   149,
       6,    55,     0,   142,   143,    56,    57,    44,     2,    27,
       0,     4,     0,     5,   138,   139,   140,   141,     6,    71,
      35,    36,    37,    38,    39
};

static const yytype_int16 yycheck[] =
{
       0,    48,    48,   105,    25,    11,    25,     7,    53,    56,
      57,    55,    41,    42,    69,    29,    25,    32,    60,    61,
      25,    66,    64,    58,    59,    72,    72,    53,    42,    55,
       4,    52,    23,    24,    25,    26,    65,    56,    19,    20,
      21,    22,    53,    52,    55,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    62,    66,   160,   103,
     115,    66,   164,    54,   108,    23,    24,    58,    59,    69,
      51,    34,    87,    88,    89,    90,    91,     3,    12,    52,
      53,    15,    16,    17,    18,    25,    26,    52,    53,    23,
      24,    25,    26,    54,    28,    29,    54,    31,    53,    33,
      55,   145,    28,    29,    38,    31,    56,    33,   155,   155,
     125,    55,    38,    51,    54,   115,    25,   161,    52,    56,
      54,    63,    56,    57,    58,    59,    12,    52,    53,    15,
      16,    17,    18,    66,    39,    40,    55,    23,    24,    25,
      26,    54,    28,    29,    52,    31,     0,    33,    52,     3,
      12,    14,    38,    15,    16,    17,    18,    62,    63,    52,
      53,    23,    24,    25,    26,    13,    52,    54,    54,    52,
      56,    57,    58,    59,    28,    29,     7,    31,    72,    33,
      23,    24,    25,    26,    38,    51,    52,    34,    28,    29,
      52,    31,    54,    33,    56,    28,    58,    59,    38,    26,
      28,    29,    77,    31,    41,    33,    95,    96,   115,    52,
      38,    54,    -1,   101,   102,    58,    59,    57,    28,    29,
      -1,    31,    -1,    33,    97,    98,    99,   100,    38,    57,
       6,     7,     8,     9,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    31,    33,    38,    68,    69,    70,
      83,    86,    87,     4,    34,    25,    56,     0,    69,    25,
      52,    84,    85,    11,    62,    54,    56,    29,    86,    88,
      89,    90,    51,    52,    53,     6,     7,     8,     9,    10,
      71,    55,    88,    90,    57,    89,    25,    52,    66,    91,
      92,    23,    24,    25,    26,    54,    58,    59,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    85,    63,    56,
      94,    57,    66,    74,    79,    82,    52,    53,    72,    72,
      80,    81,    74,    74,    23,    24,    54,    19,    20,    21,
      22,    51,    60,    61,    64,    58,    59,    39,    40,    62,
      63,    41,    42,    65,    12,    15,    16,    17,    18,    52,
      57,    81,    83,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    82,    92,    53,    55,    55,    80,    80,
      80,    80,    80,    74,    74,    74,    75,    75,    76,    76,
      76,    76,    77,    77,    81,    54,    93,    52,    52,    52,
      81,    52,    57,    96,    80,    66,    81,    14,    52,    79,
      55,    54,    93,    81,    13,    55,    93,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    99,   100,   101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     5,     1,     1,     3,     5,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     2,
       2,     2,     2,     1,     2,     2,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     5,     1,     3,     3,     3,     3,     3,     1,
       3,     1,     2,     3,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     4,     5,     2,     1,     2,     2,     3,
       2,     1,     1,     3,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     2,     1,     1,
       1,     2,     5,     7,     7,     2,     2,     2,     3
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
        case 4:
#line 73 "ast.y" /* yacc.c:1646  */
    {ex((yyvsp[0].nPtr), 0); /*freeNode($2);*/}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "ast.y" /* yacc.c:1646  */
    {
												if(if_assign)
												{
													ex((yyvsp[0].nPtr), 2); /*freeNode($2);*/
												}
											}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 97 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 98 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 99 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 103 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 105 "ast.y" /* yacc.c:1646  */
    {
											(yyval.nPtr) = opr('=', 2, (yyvsp[-1].nPtr), opr('+', 2, (yyvsp[-1].nPtr), con("1") ) );
										}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 108 "ast.y" /* yacc.c:1646  */
    {
											(yyval.nPtr) = opr('=', 2, (yyvsp[-1].nPtr), opr('-', 2, (yyvsp[-1].nPtr), con("1") ) );
										}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "ast.y" /* yacc.c:1646  */
    {
											(yyval.nPtr) = opr('=', 2, (yyvsp[0].nPtr), opr('+', 2, (yyvsp[0].nPtr), con("1") ) );
										}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "ast.y" /* yacc.c:1646  */
    {
											(yyval.nPtr) = opr('=', 2, (yyvsp[0].nPtr), opr('-', 2, (yyvsp[0].nPtr), con("1") ) );
										}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 122 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('+', 1, (yyvsp[0].nPtr));}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 123 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('+', 1, (yyvsp[0].nPtr));}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 127 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 130 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 134 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 135 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 141 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 142 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 143 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(LE_OP, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 144 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(GE_OP, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 148 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 149 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(EQ_OP, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 150 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(NE_OP, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 154 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 155 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('?', 2, (yyvsp[-4].nPtr), opr(':', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)) );}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 159 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 160 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('=', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 161 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('=', 2, (yyvsp[-2].nPtr), opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)) );}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 162 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('=', 2, (yyvsp[-2].nPtr), opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)) );}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 163 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('=', 2, (yyvsp[-2].nPtr), opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)) );}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 164 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('=', 2, (yyvsp[-2].nPtr), opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)) );}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 168 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 173 "ast.y" /* yacc.c:1646  */
    {}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 178 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(';', 1, (yyvsp[-1].nPtr));}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 182 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 183 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 187 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr('=', 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 188 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 196 "ast.y" /* yacc.c:1646  */
    {if_assign = 0;}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 232 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 233 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 234 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 235 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 236 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 237 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 238 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 243 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 247 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 248 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 252 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 253 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 258 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 262 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 267 "ast.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(DO, 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr));}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1839 "y.tab.c" /* yacc.c:1646  */
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
#line 283 "ast.y" /* yacc.c:1906  */



void main()
{
	yydebug = 0;
	yyparse();
	//printsymtab(symtab);
}

int yyerror(char const *s)
{
	extern int yylineno;
	printf("\nParse Failed\n");
	printf("Error Line Number: %d %s", yylineno, s);
	fflush(stdout);
	return 0;
}

nodeType *con(char *value)
{
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
	strcpy(p->con.value, value);
	return p;
}

nodeType *id(char *identifier) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	strcpy(p->id.name,identifier);
//	printf("The copied identifier %s\n", p->id.name);
	return p;
}

nodeType *opr(int oper, int nops, ...)
{
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +(nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
}
