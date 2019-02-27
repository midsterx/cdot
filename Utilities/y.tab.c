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
#line 1 "test.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>

	extern int yylineno;
	extern char yytext[];

	struct symbol_table
	{
		int token_num;
		char type[50];
		char symbol[50];
		char value[50];
		int line_num;
		int scope_num;
	} symtab[300];

	int count = 0; // symbol table element count
	int token_count = 0; // total tokens count
	int scope_count = 0; // scope count

	void printsymtab(void);

#line 91 "y.tab.c" /* yacc.c:339  */

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
    IDENTIFIER = 258,
    CONSTANT = 259,
    TYPE_NAME = 260,
    CHAR = 261,
    INT = 262,
    LONG = 263,
    FLOAT = 264,
    DOUBLE = 265,
    VOID = 266,
    SHORT = 267,
    UNSIGNED = 268,
    SIGNED = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    DO = 273,
    BREAK = 274,
    CONTINUE = 275,
    RETURN = 276,
    RELOP = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    SHORTHANDADD = 281,
    SHORTHANDSUB = 282,
    SHORTHANDMULT = 283,
    SHORTHANDDIV = 284,
    INCREMENT = 285,
    DECREMENT = 286,
    STRUCT = 287,
    STATIC = 288,
    EXTERN = 289,
    REGISTER = 290,
    AUTO = 291,
    ARRTYPE = 292,
    HEADER = 293
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define TYPE_NAME 260
#define CHAR 261
#define INT 262
#define LONG 263
#define FLOAT 264
#define DOUBLE 265
#define VOID 266
#define SHORT 267
#define UNSIGNED 268
#define SIGNED 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define DO 273
#define BREAK 274
#define CONTINUE 275
#define RETURN 276
#define RELOP 277
#define AND 278
#define OR 279
#define NOT 280
#define SHORTHANDADD 281
#define SHORTHANDSUB 282
#define SHORTHANDMULT 283
#define SHORTHANDDIV 284
#define INCREMENT 285
#define DECREMENT 286
#define STRUCT 287
#define STATIC 288
#define EXTERN 289
#define REGISTER 290
#define AUTO 291
#define ARRTYPE 292
#define HEADER 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    41,    39,    45,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
       0,    46,    46,    45,    55,    56,    60,    61,    62,    63,
      69,    73,    74,    78,    79,    83,    84,    88,   103,   117,
     127,   137,   141,   142,   146,   147,   148,   147,   158,   157,
     170,   171,   175,   176,   183,   184,   185,   186,   191,   201,
     211,   221,   231,   241,   251,   252,   253,   254,   255,   256,
     257,   258,   262,   266,   267,   271,   281,   294,   295,   296,
     297,   298,   299,   300,   301,   305,   315,   329,   328,   338,
     339,   340,   341,   342,   343,   344,   349,   349,   350,   350,
     354,   355,   359,   360,   364,   365,   369,   370,   374,   378,
     382,   385,   386,   392,   393,   397,   398,   402,   403,   407,
     408,   412,   413,   417,   427,   440,   441,   446,   447,   451,
     461,   475,   479,   480,   481,   486,   500
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "TYPE_NAME",
  "CHAR", "INT", "LONG", "FLOAT", "DOUBLE", "VOID", "SHORT", "UNSIGNED",
  "SIGNED", "IF", "ELSE", "WHILE", "DO", "BREAK", "CONTINUE", "RETURN",
  "RELOP", "AND", "OR", "NOT", "SHORTHANDADD", "SHORTHANDSUB",
  "SHORTHANDMULT", "SHORTHANDDIV", "INCREMENT", "DECREMENT", "STRUCT",
  "STATIC", "EXTERN", "REGISTER", "AUTO", "ARRTYPE", "HEADER", "'+'",
  "'-'", "'*'", "'/'", "'('", "')'", "','", "';'", "'='", "'{'", "'}'",
  "$accept", "start_state", "$@1", "external_declaration",
  "function_definition", "params", "paramTypeList", "paramIdList",
  "paramId", "declarator", "declaration", "init_declarator_list",
  "init_declarator", "$@2", "$@3", "$@4", "return_type_specifier",
  "scoped_type_specifier", "storage_class", "type_specifier",
  "record_declaration", "simple_declaration", "primary_expression",
  "statement", "expression_statement", "expression", "$@5",
  "compound_statement", "$@6", "$@7", "block_scope_list", "block_item",
  "conditional_statement", "condition", "iteration_statement",
  "break_statement", "continue_statement", "return_statement",
  "simple_expression", "and_expression", "unary_rel_expression",
  "rel_expression", "sum_expression", "sumop", "logop", "term", "mulop",
  "unary_expression", "factor", "immutable", "mutable", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    43,
      45,    42,    47,    40,    41,    44,    59,    61,   123,   125
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -77

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     205,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,    58,
      74,   -31,   -30,    -9,    -3,    32,    37,    36,   189,   -64,
     -64,   -64,   -64,    26,   -64,    11,    13,   -64,   -64,   -64,
      59,     8,   189,    31,   -64,    45,   -64,    56,   -64,   -64,
     -64,   -64,   -64,   -64,    50,    81,   -64,   -64,    28,    43,
     -64,   -64,   -64,    70,   -64,   100,   108,   -64,   106,   115,
      26,   111,   -64,   -64,   -64,    84,   -64,   -64,     4,   -64,
     205,    20,    83,   251,   -64,   -64,   -64,   105,   -64,    93,
      73,   -64,   -64,    91,   -64,    26,    26,    37,   -64,   -64,
      37,   -64,   -64,    37,    26,    26,    26,    26,   -64,   -64,
     -64,   -64,   144,   -64,   -64,   145,   -64,    97,   109,   112,
     -64,   189,   110,   297,   -64,   -64,   154,   -64,   -64,   -64,
      45,   158,   -64,   189,   -64,   116,    59,   -64,    45,    81,
     -64,    85,    43,   -64,   -64,   -64,   -64,   -64,    26,   -64,
     -64,   -64,   -64,    26,   -30,    26,   155,   136,   -64,    59,
     -64,   -64,   126,   -64,   171,    26,   -64,   -64,   -64,   -64,
     159,   137,   134,   138,   179,   -30,   -64,   -64,   141,    50,
     123,   -30,   142,   -64,   -64,   143,   -64,   189,   -64,   -64,
     -64,   -64,   -64,   -64,   171,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   116,   115,    39,    40,    41,    42,    43,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    37,     2,     0,    66,    78,     0,     4,     6,     7,
       0,     0,     0,    31,     9,     8,    57,     0,    58,    59,
      60,    61,    62,    63,    75,    94,    96,    98,    99,   102,
     108,   111,   112,   113,    44,     0,     0,    48,     0,     0,
       0,     0,    89,    90,    91,     0,    97,   113,     0,    30,
       0,     0,     0,     0,     1,     5,    18,     0,    19,    24,
       0,    22,    32,     0,    65,     0,     0,     0,   103,   104,
       0,   109,   110,     0,     0,     0,     0,     0,    73,    74,
      67,    46,     0,    45,    50,     0,    49,    87,     0,     0,
      92,     0,     0,     3,   114,    77,     0,    34,    82,    33,
      83,     0,    80,    12,    28,     0,     0,    20,    64,    93,
      95,   100,   101,   107,    69,    70,    71,    72,     0,    47,
      51,   106,   105,     0,     0,     0,     0,     0,    21,     0,
      79,    81,     0,    11,     0,     0,    26,    23,    68,    86,
      84,     0,     0,     0,     0,     0,    17,    13,    16,    29,
       0,     0,     0,    53,    52,     0,    10,     0,    55,    56,
      27,    85,    88,    54,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   117,   -64,   -21,   -64,   -64,   -64,    21,   -64,   -26,
     -63,   -64,    95,   -64,   -64,   -64,   -64,   -64,   -64,   -18,
     -64,   -64,   -64,   -58,   -64,    -7,   -64,   -11,   -64,   -64,
     -64,    89,   -64,    72,   -64,   -64,   -64,   -64,   -20,   146,
     147,   -64,   135,   -64,   -64,   139,   -64,   -10,   -64,   -64,
     -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    70,    27,    28,   152,   153,   167,   168,    79,
      29,    80,    81,   125,   170,   155,    30,    31,    32,    33,
      34,   147,   180,    35,    36,    37,   138,    38,    72,    73,
     121,   122,    39,   108,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    90,   143,    49,    93,    50,    51,    52,
      53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    61,    67,    71,    77,    75,    66,    76,    65,    67,
     118,    76,    60,    74,    82,   120,     1,     2,    25,     3,
       4,     5,     6,     7,     8,   128,     9,    10,    11,     1,
       2,    12,    13,    14,    15,     1,     2,    62,    16,    68,
       1,     2,   112,    63,    85,    17,    18,    19,    20,    21,
      87,    16,   111,   107,    78,   119,    23,    16,   118,    24,
     -76,    25,    76,   120,   114,    54,    55,    88,    89,    23,
      56,    67,    67,    67,    85,    23,    67,   -33,    64,    67,
      23,    57,    58,   133,    91,    92,    59,   134,   135,   136,
     137,    83,    75,   146,     1,     2,    94,    95,    96,    97,
      98,    99,    84,   119,    86,   154,    11,   101,   102,    12,
      13,    14,    15,   104,   105,   103,    16,   100,   126,   127,
     141,   142,   106,   112,    88,    89,   178,   179,   109,   164,
     110,   158,   115,   160,    23,   169,   159,    24,   107,    25,
     124,    67,     3,     4,     5,     6,     7,     8,   123,     9,
      10,   139,   140,   144,   176,   145,   148,   149,   162,   184,
     181,     1,     2,   156,     3,     4,     5,     6,     7,     8,
     165,     9,    10,    11,   166,   171,    12,    13,    14,    15,
     173,   172,   175,    16,   174,   163,   177,   113,   182,   183,
     116,   117,    19,    20,    21,     3,     4,     5,     6,     7,
       8,    23,     9,    10,    24,   185,    25,   150,     1,     2,
     151,     3,     4,     5,     6,     7,     8,   161,     9,    10,
      11,   157,   131,    12,    13,    14,    15,     0,     0,   132,
      16,   129,     0,   130,     0,     0,     0,    17,    18,    19,
      20,    21,     0,    22,     0,     0,     0,     0,    23,     0,
       0,    24,     0,    25,     1,     2,     0,     3,     4,     5,
       6,     7,     8,     0,     9,    10,    11,     0,     0,    12,
      13,    14,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,   116,   117,    19,    20,    21,     0,     0,
       0,     0,     0,     0,    23,     0,     0,    24,     0,    25,
       1,     2,     0,     3,     4,     5,     6,     7,     8,     0,
       9,    10,    11,     0,     0,    12,    13,    14,    15,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
      23,     0,     0,    24,     0,    25
};

static const yytype_int16 yycheck[] =
{
      18,    12,    16,    23,    30,    26,    16,     3,    15,    23,
      73,     3,    43,     0,    32,    73,     3,     4,    48,     6,
       7,     8,     9,    10,    11,    83,    13,    14,    15,     3,
       4,    18,    19,    20,    21,     3,     4,    46,    25,     3,
       3,     4,    68,    46,    24,    32,    33,    34,    35,    36,
      22,    25,    48,    60,    46,    73,    43,    25,   121,    46,
      49,    48,     3,   121,    44,     7,     8,    39,    40,    43,
      12,    85,    86,    87,    24,    43,    90,    46,    46,    93,
      43,     7,     8,    93,    41,    42,    12,    94,    95,    96,
      97,    46,   113,   111,     3,     4,    26,    27,    28,    29,
      30,    31,    46,   121,    23,   123,    15,     7,     8,    18,
      19,    20,    21,     7,     8,     7,    25,    47,    45,    46,
      23,    24,     7,   149,    39,    40,     3,     4,    17,   147,
      46,   138,    49,   144,    43,   155,   143,    46,   145,    48,
      47,   155,     6,     7,     8,     9,    10,    11,    43,    13,
      14,     7,     7,    44,   165,    43,    46,     3,     3,   177,
     171,     3,     4,    47,     6,     7,     8,     9,    10,    11,
      44,    13,    14,    15,     3,    16,    18,    19,    20,    21,
      46,    44,     3,    25,    46,    49,    45,    70,    46,    46,
      32,    33,    34,    35,    36,     6,     7,     8,     9,    10,
      11,    43,    13,    14,    46,   184,    48,    49,     3,     4,
     121,     6,     7,     8,     9,    10,    11,   145,    13,    14,
      15,   126,    87,    18,    19,    20,    21,    -1,    -1,    90,
      25,    85,    -1,    86,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    46,    -1,    48,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    -1,    48,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    11,    13,
      14,    15,    18,    19,    20,    21,    25,    32,    33,    34,
      35,    36,    38,    43,    46,    48,    51,    53,    54,    60,
      66,    67,    68,    69,    70,    73,    74,    75,    77,    82,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    95,
      97,    98,    99,   100,     7,     8,    12,     7,     8,    12,
      43,    77,    46,    46,    46,    75,    97,   100,     3,    69,
      52,    88,    78,    79,     0,    53,     3,    59,    46,    59,
      61,    62,    69,    46,    46,    24,    23,    22,    39,    40,
      93,    41,    42,    96,    26,    27,    28,    29,    30,    31,
      47,     7,     8,     7,     7,     8,     7,    75,    83,    17,
      46,    48,    59,    51,    44,    49,    32,    33,    60,    69,
      73,    80,    81,    43,    47,    63,    45,    46,    73,    89,
      90,    92,    95,    97,    75,    75,    75,    75,    76,     7,
       7,    23,    24,    94,    44,    43,    69,    71,    46,     3,
      49,    81,    55,    56,    69,    65,    47,    62,    75,    75,
      77,    83,     3,    49,    69,    44,     3,    57,    58,    88,
      64,    16,    44,    46,    46,     3,    77,    45,     3,     4,
      72,    77,    46,    46,    69,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    51,    51,    51,    53,    53,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    58,    59,    60,
      60,    60,    61,    61,    62,    63,    64,    62,    65,    62,
      66,    66,    67,    67,    68,    68,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    76,    75,    75,
      75,    75,    75,    75,    75,    75,    78,    77,    79,    77,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    85,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    98,    98,    98,    99,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     2,     1,     1,     1,     1,
       6,     1,     0,     2,     1,     4,     1,     1,     1,     2,
       3,     4,     1,     3,     1,     0,     0,     5,     0,     4,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     4,     2,     3,
       3,     4,     6,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     0,     4,     3,
       3,     3,     3,     2,     2,     1,     0,     3,     0,     4,
       1,     2,     1,     1,     5,     7,     3,     1,     7,     2,
       2,     2,     3,     3,     1,     3,     1,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1
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
#line 46 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "preprocessor directive");
			strcpy(symtab[count].symbol, "include");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 89 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "identfier");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 104 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "identfier");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 118 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 128 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 147 "test.y" /* yacc.c:1646  */
    {printf("declarator\n");}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 148 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "asgnop");
			strcpy(symtab[count].symbol, "=");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 158 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "asgnop");
			strcpy(symtab[count].symbol, "=");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 192 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "void");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 202 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "char");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 212 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "int");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 222 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "long");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 232 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "float");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 242 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "double");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 272 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "identifier");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 282 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "constant");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 306 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 316 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 329 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "asgnop");
			strcpy(symtab[count].symbol, "=");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 349 "test.y" /* yacc.c:1646  */
    {scope_count++;}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 349 "test.y" /* yacc.c:1646  */
    {scope_count--;}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 350 "test.y" /* yacc.c:1646  */
    {scope_count++;}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 350 "test.y" /* yacc.c:1646  */
    {scope_count--;}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 418 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "sumop");
			strcpy(symtab[count].symbol, "+");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 428 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "sumop");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;	
		}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 452 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "mulop");
			strcpy(symtab[count].symbol, "*");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 462 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "mulop");
			strcpy(symtab[count].symbol, "/");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 487 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "constant");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 501 "test.y" /* yacc.c:1646  */
    {
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "identfier");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1838 "y.tab.c" /* yacc.c:1646  */
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
#line 512 "test.y" /* yacc.c:1906  */



void main()
{
	yyparse();
	printsymtab();
}


void yyerror(char const *s)
{
	fflush(stdout);
}

void printsymtab(void)
{
	printf("\n\nSYMBOL TABLE\n\n");
	printf("Token No.\tType\tSymbol\tValue\tScope No.\tLine No.");
	int i;
	printf("\n");
	for (i = 0;i < count;i++)
	{
		printf("\n%d\t%s\t%s\t%s\t%d\t%d", symtab[i].token_num, symtab[i].type, symtab[i].symbol, symtab[i].value, symtab[i].scope_num, symtab[i].line_num);
	}
}
