%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "symnode.h"

	struct scopeTable *symtab = (struct scopeTable*)malloc(sizeof(struct scopeTable));
	symtab->num = 0;
	symtab->outer = NULL;

	extern int yylineno;
	extern char yytext[];
%}

%token IDENTIFIER CONSTANT 
%token TYPE_NAME
%token CHAR INT LONG FLOAT DOUBLE VOID SHORT UNSIGNED SIGNED
%token IF ELSE WHILE DO BREAK CONTINUE 
%token RETURN
%token RELOP AND OR NOT
%token SHORTHANDADD SHORTHANDSUB SHORTHANDMULT SHORTHANDDIV 
%token INCREMENT DECREMENT
%token STRUCT
%token STATIC EXTERN REGISTER AUTO
%token ARRTYPE
%token HEADER
%left '+' '-' 
%left '*' '/'

%start start_state
%%

start_state
	: HEADER start_state
	| external_declaration				 
	| start_state external_declaration
	;

external_declaration
	: function_definition 
	| declaration  	
	| statement 
	| record_declaration
	;

/*FUNCTIONS*/

function_definition 
	: return_type_specifier declarator '(' params ')' compound_statement
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
		{
			superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
		}
	;

/*DECLARATIONS*/

declarator
	: IDENTIFIER
		{
			superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
		}    
	;

declaration
	: scoped_type_specifier ';' 
	| scoped_type_specifier init_declarator_list ';' 
	| STRUCT IDENTIFIER declarator ';'
	;

init_declarator_list
	: init_declarator        
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator   
	| declarator {printf("declarator\n");} '=' primary_expression 
	| declarator '=' simple_expression 	
	;

return_type_specifier
	: STATIC type_specifier
	| type_specifier
	;

scoped_type_specifier
	: storage_class type_specifier
	| type_specifier
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
	: STRUCT IDENTIFIER '{' { addScope(); }simple_declaration '}' { delScope(); } ';'
	;

simple_declaration
	: type_specifier IDENTIFIER ';'
	| simple_declaration type_specifier IDENTIFIER ';'
	;

primary_expression
	: IDENTIFIER
		{
			superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
		}
	| CONSTANT
		{
			superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
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
	: mutable '=' expression 
	| mutable SHORTHANDADD expression
	| mutable SHORTHANDSUB expression
	| mutable SHORTHANDMULT expression
	| mutable SHORTHANDDIV expression
	| mutable INCREMENT
	| mutable DECREMENT
	| simple_expression
	;


compound_statement
	: '{' { addScope(); } '}' { delScope(); }
	| '{' { addScope(); }block_scope_list '}' { delScope(); }
	;

block_scope_list
	: block_item
	| block_scope_list block_item
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
	: NOT unary_expression
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
		{
			superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
		}
	;


mutable
	: IDENTIFIER
		{
			superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
		}
	;

%%


void main()
{
	yyparse();
	// printsymtab();
}


void yyerror(char const *s)
{
	extern int yylineno;
	printf("\nParse Failed\n");
	printf("Error Line Number: %d %s", yylineno, s);
	fflush(stdout);
}