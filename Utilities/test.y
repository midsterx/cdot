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
	;




function_definition 
	: declaration_specifiers declarator compound_statement
	;

declarator
	: IDENTIFIER
	;


declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' primary_expression
	;





declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
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
	: compound_statement
	;



%%
#include <stdio.h>
extern char yytext[];

void main()
{
	yyparse();
}


void yyerror(char const *s)
{
	fflush(stdout);
}