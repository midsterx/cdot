%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "symnode.h"

	struct scopeTable *symtab = NULL;
	int succ = 0;

	extern int yylineno;
	extern char yytext[];
	char gvar[15] = "";
	int gscope = 0;
	int yylex(void);
	int yyerror(const char *s);
%}

%union 
{
	int ival;
	long int lival;
	double dval;
	float fval;
	char* idname;
}

%token HEADER
%token IF ELSE WHILE DO BREAK CONTINUE 
%token RETURN
%token SHORTHANDADD SHORTHANDSUB SHORTHANDMULT SHORTHANDDIV 
%token INCREMENT DECREMENT

%token <idname> IDENTIFIER 
%token <ival> CONSTANT 
%token TYPE_NAME
%token <idname> CHAR INT LONG FLOAT DOUBLE VOID SHORT UNSIGNED SIGNED
%token <idname> STRUCT
%token RELOP AND OR NOT
%token STATIC EXTERN REGISTER AUTO
%token ARRTYPE
%token '=' ';' ','
%token '(' ')' '{' '}'
%type <idname> type_specifier
%type <idname> declarator 

%left '+' '-' 
%left '*' '/'

%start start_state
%%

start_state
	: HEADER start_state
	| translation_unit {gscope++; symtab = addScope(symtab,gscope);}
	;

translation_unit
	: external_declaration				 
	| translation_unit external_declaration
	;

external_declaration
	: function_definition 
	| declaration
	| record_declaration
	;

/*FUNCTIONS*/

function_definition 
	: return_type_specifier declarator '(' params ')' compound_statement
	;

params
	: param_decl
	| param_decl ',' params  
	;

param_decl					
	: scoped_type_specifier declarator 
	| scoped_type_specifier 
	;


/*DECLARATIONS*/

declarator
	: IDENTIFIER
		{
			superAdd(symtab, $1, 1, yylineno, gvar, 0, 4); 
			strcpy(gvar,"");
		}    
	;

declaration
	: scoped_type_specifier init_declarator_list ';' 
	| STRUCT IDENTIFIER { superAdd(symtab, $2, 1, yylineno, $1, 0, 4);} declarator ';'
	| scoped_type_specifier ';' 
	;

init_declarator_list
	: init_declarator        
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' primary_expression 
	| declarator '=' simple_expression 	
	;

return_type_specifier
	: STATIC type_specifier {strcpy(gvar, $2);}
	| type_specifier {strcpy(gvar, $1);}
	;

scoped_type_specifier
	: storage_class type_specifier {strcpy(gvar, $2);}
	| type_specifier {strcpy(gvar, $1);}
	;

storage_class
	: STATIC
	| EXTERN
	| REGISTER
	| AUTO
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

record_declaration
	: STRUCT IDENTIFIER '{' { gscope++; symtab = addScope(symtab,gscope); } simple_declaration '}' { gscope--;/*delScope(symtab);*/ } ';'
	;

simple_declaration
	: type_specifier IDENTIFIER { superAdd(symtab, $2, 1, yylineno, $1, 0, 4); }';'
	| simple_declaration type_specifier IDENTIFIER { superAdd(symtab, $3, 1, yylineno, $2, 0, 4); }';'
	;


primary_expression
	: declarator
	| CONSTANT
		{
			/*superAdd(symtab, $1, 1, yylineno, "constant", 0);*/
		}
	;

statement
	: expression_statement 
	| compound_statement
	| conditional_statement
	| iteration_statement
	| break_statement
	| continue_statement
	| return_statement
	| statement ';' statement
	;

expression_statement
	: expression ';' 
	| ';' 
	;

expression
	: declarator '=' expression 
	| declarator SHORTHANDADD expression
	| declarator SHORTHANDSUB expression
	| declarator SHORTHANDMULT expression
	| declarator SHORTHANDDIV expression
	| declarator INCREMENT
	| declarator DECREMENT
	| simple_expression
	;


compound_statement
	: '{' { gscope++; symtab = addScope(symtab,gscope); } '}' { gscope--;/*delScope(symtab);*/ }
	| '{' { gscope++; symtab = addScope(symtab,gscope); } block_scope_list '}' { gscope--;/*delScope(symtab);*/ }
	;

block_scope_list
	: block_item
	| block_item block_scope_list
	;

block_item
	: declaration  
	| statement 
	;

conditional_statement
	: IF '(' condition ')' compound_statement 
	| IF '(' condition ')' compound_statement ELSE compound_statement 
	;

condition
	: expression logop expression 
	| expression 
	;

iteration_statement
	: DO  compound_statement  WHILE '(' condition ')' ';'
	;

break_statement
	: BREAK ';'
	;

continue_statement
	: CONTINUE ';'
	;

return_statement
	: RETURN ';' 
	| RETURN expression ';'
	;

simple_expression 
	: simple_expression OR and_expression 
	| and_expression 
	;

and_expression
	: and_expression AND unary_rel_expression 
	| unary_rel_expression
	;

unary_rel_expression
	: NOT factor
	| rel_expression 
	;

rel_expression
	: sum_expression
	| sum_expression RELOP sum_expression
	;

sum_expression
	: sum_expression sumop term 
	| term
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
	: term mulop factor 
	| factor
	;

mulop
	: '*'
	| '/'
	;


factor
	: primary_expression
	| '(' simple_expression ')'
	;


%%


void main()
{
	yyparse();
	printsymtab(symtab);
}


int yyerror(char const *s)
{
	extern int yylineno;
	printf("\nParse Failed\n");
	printf("Error Line Number: %d %s", yylineno, s);
	fflush(stdout);
	return 0;
}