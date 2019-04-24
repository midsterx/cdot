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
#line 1 "basic.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "symnode.h"
	#define YYDEBUG_LEXER_TEXT yytext

	struct scopeTable *symtab = NULL;
	int succ = 0;

	extern int yylineno;
	extern char *yytext;

	char gvar[15] = "";
	int gscope = 0;
	int yylex(void);
	int yyerror(const char *s);
  	int param_count;
	int ISFUNCCALL = 0;
	int ISCONDCALL = 0;
	int ISITERCALL = 0;

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

	//temp(top-2) =(top-1) b (top)
	void codegen_assign()
	{
	 	fprintf(f1,"%s\t=\t%s\n",st[top-1],st[top]);
	 	top-=2;
	}

	void codegen_func_def()
	{
		fprintf(f1,"func\tbegin\t%s\n",st[top]);
		top-=1;
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

  	void codegen_param(int n)
	{
		int l = n;
		while(l--)
		{
			fprintf(f1,"param\t%s\n", st[top-l]);
		}
		top=top-n;
	}

	void codegen_function_name(int n,int hasReturnType) 
	{
		if(ISFUNCCALL > 0) {
			if(hasReturnType) {
				fprintf(f1,"%s\t=\tcall %s,%d\n",st[top-1],st[top],n);
				top-=2;
			} else {
				fprintf(f1,"call %s,%d\n",st[top],n);
				top-=1;
			}
		}  	
	}

	void codegen_conditional_if()
	{
		lnum++;
		label[ltop] = lnum;
		ltop++;
		fprintf(f1, "ifFalse %s goto L%d\n", temp, lnum);
		top-=1;
	}
	void codegen_conditional_else()
	{
		lnum++;
		fprintf(f1, "goto L%d\n", lnum);
		fprintf(f1, "L%d:\n", label[ltop-1]);
		label[ltop] = lnum;
	}
	void codegen_conditional_end()
	{
		fprintf(f1, "L%d:\n", label[ltop-1]);
		ltop-=1;
	}

	void codegen_iterational_begin()
	{
		lnum++;
		label[ltop] = lnum;
		ltop++;
		fprintf(f1, "L%d:\n", label[ltop-1]);
	}
	void codegen_iterational_end()
	{
		fprintf(f1, "if %s goto L%d\n", temp, label[ltop-1]);
		ltop-=1;
	}

#line 193 "y.tab.c" /* yacc.c:339  */

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
    HEADER = 258,
    ELSE = 259,
    IF = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    CONTINUE = 264,
    REDUCE = 265,
    RETURN = 266,
    SHORTHANDADD = 267,
    SHORTHANDSUB = 268,
    SHORTHANDMULT = 269,
    SHORTHANDDIV = 270,
    INCREMENT = 271,
    DECREMENT = 272,
    IDENTIFIER = 273,
    CONSTANT = 274,
    TYPE_NAME = 275,
    CHAR = 276,
    INT = 277,
    LONG = 278,
    FLOAT = 279,
    DOUBLE = 280,
    VOID = 281,
    SHORT = 282,
    UNSIGNED = 283,
    SIGNED = 284,
    STRUCT = 285,
    RELOP = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    STATIC = 290,
    EXTERN = 291,
    REGISTER = 292,
    AUTO = 293,
    ARRTYPE = 294
  };
#endif
/* Tokens.  */
#define HEADER 258
#define ELSE 259
#define IF 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define CONTINUE 264
#define REDUCE 265
#define RETURN 266
#define SHORTHANDADD 267
#define SHORTHANDSUB 268
#define SHORTHANDMULT 269
#define SHORTHANDDIV 270
#define INCREMENT 271
#define DECREMENT 272
#define IDENTIFIER 273
#define CONSTANT 274
#define TYPE_NAME 275
#define CHAR 276
#define INT 277
#define LONG 278
#define FLOAT 279
#define DOUBLE 280
#define VOID 281
#define SHORT 282
#define UNSIGNED 283
#define SIGNED 284
#define STRUCT 285
#define RELOP 286
#define AND 287
#define OR 288
#define NOT 289
#define STATIC 290
#define EXTERN 291
#define REGISTER 292
#define AUTO 293
#define ARRTYPE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 129 "basic.y" /* yacc.c:355  */

	int ival;
	long int lival;
	double dval;
	float fval;
	char* idname;

#line 319 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 336 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      43,    44,    49,    47,    42,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   171,   175,   176,   181,   182,   188,   188,
     188,   188,   192,   193,   197,   198,   202,   202,   202,   206,
     207,   214,   218,   219,   223,   224,   228,   229,   230,   231,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   252,   253,   260,   261,   265,   266,
     270,   271,   275,   276,   276,   280,   280,   281,   285,   286,
     290,   291,   295,   295,   296,   300,   301,   305,   306,   311,
     312,   316,   317,   321,   322,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   338,   339,   343,   344,   345,   349,
     349,   350,   350,   350,   354,   355,   359,   359,   359,   363,
     367,   371,   372
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HEADER", "ELSE", "IF", "WHILE", "DO",
  "BREAK", "CONTINUE", "REDUCE", "RETURN", "SHORTHANDADD", "SHORTHANDSUB",
  "SHORTHANDMULT", "SHORTHANDDIV", "INCREMENT", "DECREMENT", "IDENTIFIER",
  "CONSTANT", "TYPE_NAME", "CHAR", "INT", "LONG", "FLOAT", "DOUBLE",
  "VOID", "SHORT", "UNSIGNED", "SIGNED", "STRUCT", "RELOP", "AND", "OR",
  "NOT", "STATIC", "EXTERN", "REGISTER", "AUTO", "ARRTYPE", "'='", "';'",
  "','", "'('", "')'", "'{'", "'}'", "'+'", "'-'", "'*'", "'/'", "$accept",
  "start_state", "translation_unit", "external_declaration",
  "function_definition", "$@1", "$@2", "$@3", "params", "param_decl",
  "function_call", "$@4", "$@5", "varList", "declarator", "declaration",
  "init_declarator_list", "init_declarator", "type_specifier",
  "primary_expression", "simple_expression", "and_expression",
  "unary_rel_expression", "rel_expression", "$@6", "sum_expression", "$@7",
  "sumop", "logop", "term", "$@8", "mulop", "factor", "compound_statement",
  "block_scope_list", "block_item", "statement", "expression_statement",
  "expression", "conditional_statement", "$@9", "$@10", "$@11",
  "condition", "iteration_statement", "$@12", "$@13", "break_statement",
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
      61,    59,    44,    40,    41,   123,   125,    43,    45,    42,
      47
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -27

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,    49,   -89,   -89,   -89,   -89,   -89,   -89,    61,    88,
       3,    80,   -89,   -89,   -89,    38,   -89,   -89,    69,    -2,
     -89,    77,    22,   -89,   -89,   -89,   -89,     8,    76,   -89,
     -89,    24,   -89,   -89,    36,   -89,    47,   -36,   -89,    67,
     -89,   -89,   -89,    44,    47,   -89,    52,    89,    64,    82,
     -89,   -89,     6,    96,   -89,   -89,    72,   -89,   -89,   -89,
     -89,   -27,   -89,    47,    47,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,    80,   -89,    67,    82,   -89,    44,    44,    44,
     -89,    79,    67,    83,   -89,   116,    96,   -89,    75,    80,
     -89,    67,    85,    87,   -89,   -89,   -89,     4,   -89,    84,
     -89,   101,   106,     0,   -89,   -89,   -89,    46,   -89,    38,
      64,   -89,   107,   115,   114,   -89,   118,   -89,   -89,   -89,
     -89,   -89,    47,    87,   -89,   -89,   -89,   -25,    47,   -89,
     -89,   143,   -89,   117,   133,   -89,   161,   -89,   -89,   -89,
     114,   -89,   -89,    47,   124,   125,   127,   -89,    87,    87,
      47,   -89,   167,   128,   -89,   -89,    87,   132,   -89,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    31,    32,    33,    34,    35,    30,     0,     0,
       0,     3,     4,     6,     7,     0,     2,    36,     0,     0,
      40,     0,     0,     1,     5,    21,    23,    29,     0,    24,
      38,     0,    37,    42,     0,    41,     0,     0,    22,     0,
      39,    43,    45,     0,     0,    28,    44,    67,    27,    47,
      49,    51,    52,    57,    64,     9,    29,    25,    44,    67,
      50,     0,    16,     0,     0,    53,    58,    59,    55,    65,
      66,    62,     0,    68,     0,    46,    48,     0,     0,     0,
      10,    13,    15,    17,    20,    54,    56,    63,     0,     0,
      14,     0,     0,     0,    12,    19,    18,     0,    11,     0,
      96,     0,     0,     0,    85,    69,    83,    44,    73,     0,
      87,    76,     0,    71,    74,    75,     0,    77,    78,    79,
      80,    81,     0,     0,    99,   100,   101,     0,     0,    70,
      72,     0,    84,    44,    95,    89,     0,   102,    88,    86,
      82,    61,    60,     0,     0,     0,     0,    94,     0,     0,
       0,    90,     0,     0,    92,    97,     0,     0,    93,    98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   173,   -89,   164,   -89,   -89,   -89,   -89,    90,   -89,
     -35,   -89,   -89,   -89,   -15,   -17,   -89,   137,   -58,   142,
     -34,   119,   121,   -89,   -89,   103,   -89,   -89,   -89,   105,
     -89,   -89,   -39,   -88,    68,   -89,    56,   -89,   -86,   -89,
     -89,   -89,   -89,    39,   -89,   -89,   -89,   -89,   -89,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    37,    72,    88,    80,    81,
     106,    74,    92,    83,    58,    14,    28,    29,    15,    59,
     110,    49,    50,    51,    77,    52,    78,    68,   143,    53,
      79,    71,    54,   111,   112,   113,   114,   115,   116,   117,
     144,   145,   156,   135,   118,   123,   157,   119,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    45,    48,    23,    60,    98,    63,    55,    63,    99,
      61,   100,   101,   102,    82,   103,   137,    73,    25,    42,
      32,    46,    25,    42,    56,     2,     3,     4,     5,     6,
       7,    82,     8,     9,    43,   136,   134,    65,    43,   109,
      87,   126,   139,    44,    35,   104,    40,    44,    36,    97,
     105,    -8,     1,    66,    67,   109,    25,   147,    41,    84,
     151,   152,    25,    42,   134,    25,    42,    90,   158,   127,
       2,     3,     4,     5,     6,     7,    95,     8,     9,    26,
     108,    43,   107,    17,    18,    25,   128,    44,    19,    62,
      44,    30,    31,   138,    56,    62,   108,    63,   107,    33,
      34,     2,     3,     4,     5,     6,     7,   133,     8,     9,
      20,    21,    36,   107,    64,    22,   107,    38,    39,    93,
      99,    89,   100,   101,   102,    91,   103,   122,   133,    96,
     -26,   -26,    97,    25,    42,   133,     2,     3,     4,     5,
       6,     7,   124,     8,     9,    69,    70,   125,    99,    43,
     100,   101,   102,   129,   103,   131,   104,   128,    44,   132,
      97,    25,    42,    66,    67,   141,   142,   146,   148,   149,
     150,   154,   155,   159,    16,    24,    57,    43,    47,    94,
      85,   130,    75,    86,   104,    76,    44,   140,    97,   153
};

static const yytype_uint8 yycheck[] =
{
      15,    36,    36,     0,    43,    93,    33,    43,    33,     5,
      44,     7,     8,     9,    72,    11,    41,    44,    18,    19,
      22,    36,    18,    19,    39,    21,    22,    23,    24,    25,
      26,    89,    28,    29,    34,   123,   122,    31,    34,    97,
      79,    41,   128,    43,    22,    41,    22,    43,    40,    45,
      46,    43,     3,    47,    48,   113,    18,   143,    22,    74,
     148,   149,    18,    19,   150,    18,    19,    82,   156,   103,
      21,    22,    23,    24,    25,    26,    91,    28,    29,    41,
      97,    34,    97,    22,    23,    18,    40,    43,    27,    43,
      43,    22,    23,   128,   109,    43,   113,    33,   113,    22,
      23,    21,    22,    23,    24,    25,    26,   122,    28,    29,
      22,    23,    40,   128,    32,    27,   131,    41,    42,    44,
       5,    42,     7,     8,     9,    42,    11,    43,   143,    44,
      41,    42,    45,    18,    19,   150,    21,    22,    23,    24,
      25,    26,    41,    28,    29,    49,    50,    41,     5,    34,
       7,     8,     9,    46,    11,    41,    41,    40,    43,    41,
      45,    18,    19,    47,    48,    32,    33,     6,    44,    44,
      43,     4,    44,    41,     1,    11,    39,    34,    36,    89,
      77,   113,    63,    78,    41,    64,    43,   131,    45,   150
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    21,    22,    23,    24,    25,    26,    28,    29,
      52,    53,    54,    55,    66,    69,    52,    22,    23,    27,
      22,    23,    27,     0,    54,    18,    41,    65,    67,    68,
      22,    23,    22,    22,    23,    22,    40,    56,    41,    42,
      22,    22,    19,    34,    43,    61,    65,    70,    71,    72,
      73,    74,    76,    80,    83,    43,    65,    68,    65,    70,
      83,    71,    43,    33,    32,    31,    47,    48,    78,    49,
      50,    82,    57,    44,    62,    72,    73,    75,    77,    81,
      59,    60,    69,    64,    65,    76,    80,    83,    58,    42,
      65,    42,    63,    44,    59,    65,    44,    45,    84,     5,
       7,     8,     9,    11,    41,    46,    61,    65,    66,    69,
      71,    84,    85,    86,    87,    88,    89,    90,    95,    98,
      99,   100,    43,    96,    41,    41,    41,    71,    40,    46,
      85,    41,    41,    65,    89,    94,    84,    41,    61,    89,
      87,    32,    33,    79,    91,    92,     6,    89,    44,    44,
      43,    84,    84,    94,     4,    44,    93,    97,    84,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    56,    57,
      58,    55,    59,    59,    60,    60,    62,    63,    61,    64,
      64,    65,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    75,    74,    77,    76,    76,    78,    78,
      79,    79,    81,    80,    80,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    91,
      90,    92,    93,    90,    94,    94,    96,    97,    95,    98,
      99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     1,     0,     0,
       0,     9,     3,     1,     2,     1,     0,     0,     6,     3,
       1,     1,     3,     2,     1,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     1,     3,     1,     3,     1,
       2,     1,     1,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     3,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     1,     3,     1,     3,     0,
       6,     0,     0,     9,     3,     1,     0,     0,     9,     2,
       2,     2,     3
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
        case 8:
#line 188 "basic.y" /* yacc.c:1646  */
    {codegen_func_def();}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 188 "basic.y" /* yacc.c:1646  */
    { param_count=0; }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 188 "basic.y" /* yacc.c:1646  */
    { codegen_param(param_count); param_count=0; }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 192 "basic.y" /* yacc.c:1646  */
    {param_count++;}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 193 "basic.y" /* yacc.c:1646  */
    {param_count++;}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 202 "basic.y" /* yacc.c:1646  */
    {param_count=0;}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "basic.y" /* yacc.c:1646  */
    {codegen_param(param_count);}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 206 "basic.y" /* yacc.c:1646  */
    {param_count++;}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "basic.y" /* yacc.c:1646  */
    {param_count++;}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 214 "basic.y" /* yacc.c:1646  */
    { push(); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 223 "basic.y" /* yacc.c:1646  */
    {if(ISFUNCCALL) {codegen_function_name(param_count,1); param_count = 0;} else codegen_assign();}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 224 "basic.y" /* yacc.c:1646  */
    {if(ISFUNCCALL){codegen_function_name(param_count,1); param_count = 0;} else codegen_assign();}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 230 "basic.y" /* yacc.c:1646  */
    {ISFUNCCALL = 1;}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 254 "basic.y" /* yacc.c:1646  */
    {
			push();
		}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 276 "basic.y" /* yacc.c:1646  */
    {push();}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 280 "basic.y" /* yacc.c:1646  */
    {push();}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 280 "basic.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 290 "basic.y" /* yacc.c:1646  */
    {push();}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 291 "basic.y" /* yacc.c:1646  */
    {push();}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 295 "basic.y" /* yacc.c:1646  */
    {push();}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 295 "basic.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 334 "basic.y" /* yacc.c:1646  */
    {codegen_function_name(param_count,0); param_count = 0;}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 338 "basic.y" /* yacc.c:1646  */
    {if(ISFUNCCALL){codegen_function_name(param_count,1); param_count = 0;} else {codegen_assign();} }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 343 "basic.y" /* yacc.c:1646  */
    {ISFUNCCALL = 0;}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 344 "basic.y" /* yacc.c:1646  */
    {ISFUNCCALL = 0;}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 345 "basic.y" /* yacc.c:1646  */
    {ISFUNCCALL = 1;}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 349 "basic.y" /* yacc.c:1646  */
    {codegen_conditional_if(); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 349 "basic.y" /* yacc.c:1646  */
    {codegen_conditional_end();}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 350 "basic.y" /* yacc.c:1646  */
    {codegen_conditional_if(); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 350 "basic.y" /* yacc.c:1646  */
    {codegen_conditional_else();}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 350 "basic.y" /* yacc.c:1646  */
    {codegen_conditional_end();}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 355 "basic.y" /* yacc.c:1646  */
    {codegen_logical();}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 359 "basic.y" /* yacc.c:1646  */
    {codegen_iterational_begin();}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 359 "basic.y" /* yacc.c:1646  */
    {codegen_iterational_end(); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1749 "y.tab.c" /* yacc.c:1646  */
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
#line 375 "basic.y" /* yacc.c:1906  */



void main()
{
  	f1=fopen("output","w");
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
