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
	#include "symnode.h"

	//struct scopeTable *symtab = (struct scopeTable*)malloc(sizeof(struct scopeTable));
	//symtab->num = 0;
	//symtab->outer = NULL;

	extern int yylineno;
	extern char *yytext;

	int yylex(void);
	int yyerror(const char *s);

	// f1 -> output for the irc
	FILE * f1;
	

	//stack
	char st[1000][10];
	int top=0;
	int i=0;

	//temporary variable for t0,t1 ...
	char temp[2]="t"; 

	//array of labels used
	int label[200];
	int lnum=0; //label number
	int ltop=0; //keep track of label at top (might help in scope .. not sure)

	//copy to top of stack
	void push()
	{
		
		strcpy(st[++top],yytext);
	}

	//temp(top-2) =(top-1) b(top)
	void codegen_assign()
	{
	 	fprintf(f1,"%s\t=\t%s\n",st[top-2],st[top]);
	 	top-=3;
	}

	//a ( </>/+/* ...) b
	void codegen_logical()
	{
		sprintf(temp,"t%d",i);
		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		top-=2;
		strcpy(st[top],temp);
		i++;
	}
	 

	//if(condition = false) go to __
	void if_label1()
	{

	 	lnum++; 
	 	fprintf(f1,"\tif( not %s)",st[top]);
	 	fprintf(f1,"\tgoto L%d\n",lnum);
	 	label[++ltop]=lnum;
	 	

	 	//fprintf(f1,"\nTOP IS %s\n",st[top]);
	 	//fprintf(f1,"\nTOP-1 IS %s\n",st[top-1]);
	 	//fprintf(f1,"\nTOP-2 IS %s\n",st[top-2]);
	 	//fprintf(f1,"\nTOP-3 IS %s\n",st[top-3]);

	 	top-=2; //only with this will it come perfectly .. check by uncommenting above lines
	}

	// cond.false case
	void if_label2()
	{
		int x;
		lnum++;
		x=label[ltop--];

		fprintf(f1,"\t\tgoto L%d\n",lnum);
		fprintf(f1,"L%d: \n",x); 
		label[++ltop]=lnum;
	}

	// end.case
	void if_label3()
	{
		int y;
		y=label[ltop--];
		fprintf(f1,"L%d: \n",y);
		top--;
	}




#line 167 "y.tab.c" /* yacc.c:339  */

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



/* Copy the second part of user declarations.  */

#line 291 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

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
       0,   122,   122,   123,   127,   128,   132,   133,   134,   140,
     144,   145,   149,   150,   157,   165,   166,   167,   171,   172,
     176,   177,   178,   182,   183,   187,   188,   192,   193,   194,
     195,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   216,   216,   216,   220,   221,
     226,   227,   235,   236,   237,   238,   239,   240,   241,   242,
     246,   246,   247,   251,   252,   253,   254,   255,   256,   257,
     258,   263,   263,   264,   264,   268,   269,   273,   274,   278,
     278,   279,   279,   279,   283,   284,   288,   292,   296,   300,
     301,   305,   306,   310,   311,   315,   316,   320,   321,   321,
     325,   325,   326,   330,   331,   335,   336,   341,   341,   342,
     346,   347,   352,   353
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
  "$accept", "start_state", "translation_unit", "external_declaration",
  "function_definition", "params", "param_decl", "declarator",
  "declaration", "init_declarator_list", "init_declarator",
  "return_type_specifier", "scoped_type_specifier", "storage_class",
  "type_specifier", "record_declaration", "$@1", "$@2",
  "simple_declaration", "primary_expression", "statement",
  "expression_statement", "$@3", "expression", "compound_statement", "$@4",
  "$@5", "block_scope_list", "block_item", "conditional_statement", "$@6",
  "$@7", "$@8", "condition", "iteration_statement", "break_statement",
  "continue_statement", "return_statement", "simple_expression",
  "and_expression", "unary_rel_expression", "rel_expression", "$@9",
  "sum_expression", "$@10", "sumop", "logop", "term", "$@11", "mulop",
  "factor", YY_NULLPTR
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

#define YYPACT_NINF -118

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     133,  -118,  -118,  -118,  -118,  -118,  -118,     8,    51,    21,
     192,  -118,  -118,  -118,   133,    37,   145,  -118,  -118,  -118,
      45,     5,   192,     7,  -118,  -118,    61,    54,  -118,    72,
      67,     2,  -118,  -118,  -118,  -118,  -118,    33,  -118,    17,
      57,  -118,  -118,  -118,    75,  -118,  -118,    92,  -118,  -118,
      46,   176,    19,    45,  -118,  -118,  -118,   192,  -118,  -118,
      -5,  -118,    45,  -118,  -118,     6,    19,  -118,    85,    83,
      91,  -118,  -118,    79,    84,  -118,  -118,   125,    80,   101,
     176,  -118,  -118,  -118,    -6,    19,    19,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,   111,  -118,   159,   114,  -118,  -118,
    -118,    91,  -118,     6,     6,     6,  -118,   118,   124,   123,
     102,    93,    84,  -118,  -118,  -118,  -118,   130,   101,   128,
     129,    32,   173,  -118,   166,  -118,   142,  -118,  -118,  -118,
     155,   102,  -118,  -118,  -118,  -118,  -118,    83,    19,   174,
    -118,  -118,  -118,   161,    45,    19,    19,    19,    19,  -118,
    -118,    19,    52,   162,  -118,  -118,   137,   170,   172,  -118,
    -118,  -118,  -118,  -118,  -118,   142,  -118,  -118,  -118,    19,
    -118,    19,  -118,   101,   101,   175,  -118,  -118,   171,   200,
    -118,   101,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    32,    33,    34,    35,    36,    31,     0,     0,     0,
       0,    28,    29,    30,     0,     0,     3,     4,     6,     7,
       0,     0,     0,    24,     8,    37,     0,     0,    41,     0,
       0,     0,    23,     2,     1,     5,    14,     0,    17,    20,
       0,    18,    25,    39,     0,    38,    43,     0,    42,    45,
       0,     0,     0,     0,    15,    40,    44,     0,    16,    27,
       0,    10,    13,    26,    51,     0,     0,    50,   112,    22,
      92,    94,    96,    97,   102,   109,    19,     0,     0,     0,
       0,    12,   112,    95,     0,     0,     0,    98,   103,   104,
     100,   110,   111,   107,     0,    46,     0,    73,     9,    11,
     113,    91,    93,     0,     0,     0,    48,     0,     0,     0,
       0,    99,   101,   108,    47,    49,    72,     0,     0,     0,
       0,     0,     0,    62,    50,    77,    78,    52,    60,    53,
       0,    75,    54,    55,    56,    57,    58,    70,     0,     0,
      87,    88,    89,     0,     0,     0,     0,     0,     0,    68,
      69,     0,     0,     0,    74,    76,    85,     0,     0,    90,
      64,    65,    66,    67,    63,    59,    61,   106,   105,     0,
      79,     0,    84,     0,     0,     0,    80,    82,     0,     0,
      86,     0,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,   204,  -118,   205,  -118,  -118,   140,   -20,  -104,  -118,
     169,  -118,   -37,  -118,     3,  -118,  -118,  -118,  -118,   177,
      71,  -118,  -118,  -117,   -77,  -118,  -118,    94,  -118,  -118,
    -118,  -118,  -118,    53,  -118,  -118,  -118,  -118,   -40,   141,
     144,  -118,  -118,   131,  -118,  -118,  -118,   127,  -118,  -118,
     -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    60,    61,   124,    19,    40,
      41,    20,    21,    22,    63,    24,    57,   107,    78,    82,
     126,   127,   153,   128,   129,   109,   110,   130,   131,   132,
     173,   174,   179,   157,   133,   134,   135,   136,   137,    70,
      71,    72,   103,    73,   104,    90,   169,    74,   105,    93,
      75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    39,    98,    23,   143,    36,   125,    83,    36,    36,
      64,    50,    69,    32,    62,    25,    26,    23,    85,    23,
      27,   156,    36,    64,    31,    42,    84,   125,   160,   161,
     162,   163,    67,    39,   164,    36,    64,    34,   100,    79,
      80,   139,    81,    62,    65,    67,    67,   113,    36,    66,
      49,    38,   172,   -26,   156,    36,    64,    65,    28,    29,
      77,    45,    66,    30,    52,    67,    67,   117,    43,    44,
     118,   119,   120,   121,    48,    66,    51,    65,   142,    46,
      47,    96,    55,    67,    67,    67,     1,     2,     3,     4,
       5,     6,    58,     7,     8,    66,   176,   177,   123,    56,
      97,    87,    53,    54,   182,    36,    64,    85,     1,     2,
       3,     4,     5,     6,    86,     7,     8,   117,    88,    89,
     118,   119,   120,   121,    50,    91,    92,    65,    94,    95,
     -21,   -21,    88,    89,   122,    59,    11,    12,    13,     1,
       2,     3,     4,     5,     6,    66,     7,     8,   123,    97,
      97,     1,     2,     3,     4,     5,     6,   106,     7,     8,
     167,   168,   108,   -71,   114,     9,    10,    11,    12,    13,
     115,    14,   116,   138,   140,   141,   144,     9,    10,    11,
      12,    13,     1,     2,     3,     4,     5,     6,   152,     7,
       8,   158,   145,   146,   147,   148,   149,   150,     1,     2,
       3,     4,     5,     6,   154,     7,     8,   159,   166,    59,
      11,    12,    13,   151,   170,   171,   181,   180,    33,   178,
      99,    35,    76,   165,   175,   155,   101,     0,     0,    68,
     102,   112,     0,     0,   111
};

static const yytype_int16 yycheck[] =
{
      20,    21,    79,     0,   121,     3,   110,    65,     3,     3,
       4,    31,    52,    10,    51,     7,     8,    14,    24,    16,
      12,   138,     3,     4,     3,    22,    66,   131,   145,   146,
     147,   148,    52,    53,   151,     3,     4,     0,    44,    44,
      45,   118,    62,    80,    25,    65,    66,   105,     3,    43,
      48,    46,   169,    46,   171,     3,     4,    25,     7,     8,
      57,     7,    43,    12,    47,    85,    86,    15,     7,     8,
      18,    19,    20,    21,     7,    43,    43,    25,    46,     7,
       8,    78,     7,   103,   104,   105,     6,     7,     8,     9,
      10,    11,    46,    13,    14,    43,   173,   174,    46,     7,
      48,    22,    45,    46,   181,     3,     4,    24,     6,     7,
       8,     9,    10,    11,    23,    13,    14,    15,    39,    40,
      18,    19,    20,    21,   144,    41,    42,    25,     3,    49,
      45,    46,    39,    40,    32,    33,    34,    35,    36,     6,
       7,     8,     9,    10,    11,    43,    13,    14,    46,    48,
      48,     6,     7,     8,     9,    10,    11,    46,    13,    14,
      23,    24,     3,    49,    46,    32,    33,    34,    35,    36,
      46,    38,    49,    43,    46,    46,     3,    32,    33,    34,
      35,    36,     6,     7,     8,     9,    10,    11,    46,    13,
      14,    17,    26,    27,    28,    29,    30,    31,     6,     7,
       8,     9,    10,    11,    49,    13,    14,    46,    46,    33,
      34,    35,    36,    47,    44,    43,    16,    46,    14,    44,
      80,    16,    53,   152,   171,   131,    85,    -1,    -1,    52,
      86,   104,    -1,    -1,   103
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    11,    13,    14,    32,
      33,    34,    35,    36,    38,    51,    52,    53,    54,    58,
      61,    62,    63,    64,    65,     7,     8,    12,     7,     8,
      12,     3,    64,    51,     0,    53,     3,    57,    46,    57,
      59,    60,    64,     7,     8,     7,     7,     8,     7,    48,
      57,    43,    47,    45,    46,     7,     7,    66,    46,    33,
      55,    56,    62,    64,     4,    25,    43,    57,    69,    88,
      89,    90,    91,    93,    97,   100,    60,    64,    68,    44,
      45,    57,    69,   100,    88,    24,    23,    22,    39,    40,
      95,    41,    42,    99,     3,    49,    64,    48,    74,    56,
      44,    89,    90,    92,    94,    98,    46,    67,     3,    75,
      76,    93,    97,   100,    46,    46,    49,    15,    18,    19,
      20,    21,    32,    46,    57,    58,    70,    71,    73,    74,
      77,    78,    79,    84,    85,    86,    87,    88,    43,    74,
      46,    46,    46,    73,     3,    26,    27,    28,    29,    30,
      31,    47,    46,    72,    49,    77,    73,    83,    17,    46,
      73,    73,    73,    73,    73,    70,    46,    23,    24,    96,
      44,    43,    73,    80,    81,    83,    74,    74,    44,    82,
      46,    16,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    53,    53,    54,
      55,    55,    56,    56,    57,    58,    58,    58,    59,    59,
      60,    60,    60,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    66,    67,    65,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      72,    71,    71,    73,    73,    73,    73,    73,    73,    73,
      73,    75,    74,    76,    74,    77,    77,    78,    78,    80,
      79,    81,    82,    79,    83,    83,    84,    85,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    92,    91,
      94,    93,    93,    95,    95,    96,    96,    98,    97,    97,
      99,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     1,     1,     6,
       1,     3,     2,     1,     1,     3,     4,     2,     1,     3,
       1,     3,     3,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       4,     2,     3,     3,     4,     0,     0,     8,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     3,     1,     3,     3,     3,     3,     3,     2,     2,
       1,     0,     3,     0,     4,     1,     2,     1,     1,     0,
       6,     0,     0,     9,     3,     1,     7,     2,     2,     2,
       3,     3,     1,     3,     1,     2,     1,     1,     0,     4,
       0,     4,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     1,     3
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
        case 14:
#line 158 "test.y" /* yacc.c:1646  */
    {
			//superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
			push();
		}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 216 "test.y" /* yacc.c:1646  */
    { /*addScope();*/ }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 216 "test.y" /* yacc.c:1646  */
    { /*delScope();*/ }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 228 "test.y" /* yacc.c:1646  */
    {
			//superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
			push();
		}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 246 "test.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 263 "test.y" /* yacc.c:1646  */
    { /*addScope*/}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 263 "test.y" /* yacc.c:1646  */
    { /*delScope();*/ }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 264 "test.y" /* yacc.c:1646  */
    { /*addScope();*/ }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 264 "test.y" /* yacc.c:1646  */
    { /*delScope();*/ }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 278 "test.y" /* yacc.c:1646  */
    {if_label1();}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 278 "test.y" /* yacc.c:1646  */
    {if_label3();}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 279 "test.y" /* yacc.c:1646  */
    {if_label1();}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 279 "test.y" /* yacc.c:1646  */
    {if_label2(); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 279 "test.y" /* yacc.c:1646  */
    {if_label3();}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 321 "test.y" /* yacc.c:1646  */
    {push();}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 321 "test.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 325 "test.y" /* yacc.c:1646  */
    {push();}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 325 "test.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 341 "test.y" /* yacc.c:1646  */
    {push();}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 341 "test.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1649 "y.tab.c" /* yacc.c:1646  */
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
#line 357 "test.y" /* yacc.c:1906  */





void main()
{
	f1=fopen("output","w");
	yyparse();
	// printsymtab();
}


int yyerror(char const *s)
{
	extern int yylineno;
	printf("\nParse Failed\n");
	printf("Error Line Number: %d %s", yylineno, s);
	fflush(stdout);
	return 0;
}
