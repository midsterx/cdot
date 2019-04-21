%{
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
	
%}

%union
{
	int ival;
	struct nodeType *nPtr;
	char string[128];
}

%token HEADER
%token ELSE
%token IF WHILE DO BREAK CONTINUE
%nonassoc IF
%nonassoc ELSE
%nonassoc REDUCE

%token RETURN
%token SHORTHANDADD SHORTHANDSUB SHORTHANDMULT SHORTHANDDIV
%token INCREMENT DECREMENT

%token <string> IDENTIFIER
%token <string> CONSTANT
%token TYPE_NAME
%token <string> CHAR INT LONG FLOAT DOUBLE VOID SHORT UNSIGNED SIGNED
%token <string> STRUCT
%token <string> GE_OP LE_OP NE_OP EQ_OP AND OR NOT
%token STATIC EXTERN REGISTER AUTO
%token ARRTYPE
%token '=' ';' ','
%token '(' ')' '{' '}'

%type <nPtr> primary_expression function_call param_decl params simple_expression
%type <nPtr> varList declarator type_specifier
%type <nPtr> and_expression unary_rel_expression rel_expression sum_expression
%type <nPtr> statement compound_statement expression_statement block_item
%type <nPtr> expression init_declarator init_declarator_list
%type <nPtr> iteration_statement conditional_statement translation_unit
%type <nPtr> external_declaration declaration block_scope_list
%type <nPtr> sumop mulop
%type <nPtr> term factor

%left '+' '-'
%left '*' '/'

%start start_state

%%

start_state
	: HEADER start_state
	| translation_unit
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;


external_declaration
	: function_definition
	| declaration
	;

/*FUNCTIONS*/

function_definition
	: type_specifier declarator '('params ')' compound_statement
	;

params
	: param_decl ',' params {$$ = opr(',', 2, $1, $3);}
	| param_decl {$$ = $1;}
	;

param_decl
	: type_specifier declarator
	| type_specifier
	;

function_call
	: declarator '(' varList ')' { $$ = $3; }
	;

varList
	: varList ',' declarator {$$ = opr(',', 2, $1, $3);}
	| declarator { $$ = $1; }
	;


/*DECLARATIONS*/

declarator
	: IDENTIFIER { $$ = id($1); }
	;

declaration
	: type_specifier init_declarator_list ';' {$$ = opr(';', 1, $2);}
	| type_specifier ';' {$$ = opr(';', 1, $1);}
	;

init_declarator_list
	: init_declarator {$$ = $1;}
	| init_declarator_list ',' init_declarator {$$ = opr(',', 2, $1, $3);}
	;

init_declarator
	: declarator '=' primary_expression {$$ = opr('=', 2, $1, $3);}
	| declarator '=' simple_expression {$$ = opr('=', 2, $1, $3);}
	| declarator '=' function_call {$$ = opr('=', 2, $1, $3);}
	| declarator {$$ = id($1);}
	;

type_specifier
	: VOID
	| CHAR
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| UNSIGNED INT
	| UNSIGNED SHORT INT
	| UNSIGNED LONG INT
	| UNSIGNED LONG LONG INT
	| SIGNED INT
	| SIGNED SHORT INT
	| SIGNED LONG INT
	| SIGNED LONG LONG INT
	;

primary_expression
	: declarator {$$ = $1;}
	| CONSTANT {$$ = con($1);}
	;

simple_expression
	: simple_expression OR and_expression {$$ = opr($2, 2, $1, $3);}
	| and_expression {$$ = $1;}
	;

and_expression
	: and_expression AND unary_rel_expression {$$ = opr($2, 2, $1, $3);}
	| unary_rel_expression {$$ = $1;}
	;

unary_rel_expression
	: NOT factor
	| rel_expression {$$ = $1;}
	;

rel_expression
	: sum_expression {$$ = $1;}
	| sum_expression GE_OP sum_expression {$$ = opr($2, 2, $1, $3);}
	| sum_expression NE_OP sum_expression {$$ = opr($2, 2, $1, $3);}
	| sum_expression LE_OP sum_expression {$$ = opr($2, 2, $1, $3);}
	| sum_expression EQ_OP sum_expression {$$ = opr($2, 2, $1, $3);}
	;

sum_expression
	: sum_expression sumop term {$$ = opr($2, 2, $1, $3);}
	| term {$$ = $1;}
	;

sumop
	: '+'
	| '-'
	;

logop
	: OR 
	| AND
	;

term
	: term mulop factor {$$ = opr($2, 2, $1, $3);}
	| factor {$$ = $1;}
	;

mulop
	: '*'
	| '/'
	;

factor
	: primary_expression {$$ = $1;}
	| '(' simple_expression ')'
	;


compound_statement
	: '{' '}'
	| '{' block_scope_list '}' {$$ = $2;}
	;

block_scope_list
	: block_item {$$ = $1;}
	| block_item block_scope_list {$$ = opr(';', 2, $2, $1);}
	;

block_item
	: declaration {$$ = $1;}
	| statement {$$ = $1;}
	;

statement
	: expression_statement {$$ = $1;}
	| compound_statement {$$ = $1;}
	| conditional_statement {$$ = $1;}
	| iteration_statement {$$ = $1;}
	| break_statement
	| continue_statement
	| return_statement
	| statement ';' statement
	| function_call 
	;

expression_statement
	: expression ';' {$$ = $1;}
	| ';' 
	;

expression
	: declarator '=' expression
	| simple_expression
	| declarator '=' function_call
	;

conditional_statement
	: IF '(' condition ')' compound_statement %prec REDUCE 
	| IF '(' condition ')' compound_statement ELSE compound_statement 
	;

condition
	: expression logop expression 
	| expression
	;

iteration_statement
	: DO compound_statement  WHILE '(' condition ')' ';'
	;

break_statement
	: BREAK ';'
	;

continue_statement
	: CONTINUE ';'
	;

return_statement
	: RETURN ';' 
	| RETURN simple_expression ';'
	;

%%


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
