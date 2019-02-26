%token IDENTIFIER CONSTANT 
%token TYPE_NAME
%token CHAR INT LONG FLOAT DOUBLE VOID
%token IF ELSE WHILE DO 

%start start_state
%%

start_state
	: external_declaration				 
	| start_state external_declaration
	;

external_declaration
	: function_definition
	| declaration   					
	| statement
	;

/*FUNCTIONS*/

function_definition 
	: type_specifier declarator '(' params ')' compound_statement	{printf("hello world\n");}
	;

params
	: paramTypeList
	|
	;

paramTypeList
	: type_specifier paramIdList
	| paramTypeList
	;

paramIdList
	: paramId ',' type_specifier paramIdList 
	| paramId
	;

paramId
	: IDENTIFIER 
	;

/*DECLARATIONS*/

declarator
	: IDENTIFIER    
	;


declaration
	: type_specifier ';' 
	| type_specifier init_declarator_list ';'
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

type_specifier
	: VOID
	| CHAR
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	;




compound_statement
	: '{' '}'
	| '{' block_scope_list '}'
	;

block_scope_list
	: block_item
	| block_scope_list block_item
	;

block_item
	: declaration
	| statement
	;




primary_expression
	: IDENTIFIER
	| CONSTANT
	;

statement
	: expression_statement 
	| compound_statement
	;

expression_statement
	: expression ';' 
	| ';'
	;
expression
	: mutable '=' expression 
	| simple_expression
	;

simple_expression
	: and_expression
	;

and_expression
	: unary_rel_expression
	;

unary_rel_expression
	: rel_expression
	;

rel_expression
	: sum_expression
	;

sum_expression
	: sum_expression sumop term  
	| term
	;
sumop
	: '+' 
	| '-'
	;

term
	: term mulop unary_expression 
	| unary_expression
	;

mulop
	: '*'
	| '/'
	;


unary_expression 
	: factor
	;

factor
	: immutable
	| mutable
	| '(' simple_expression ')'
	;


immutable
	: CONSTANT  
	;


mutable
	: IDENTIFIER
	;


%%
#include <stdio.h>
extern char yytext[];
// extern int yylineno;

void main()
{
	yyparse();
}


void yyerror(char const *s)
{
	fflush(stdout);
}