%{
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
%}

%token IDENTIFIER CONSTANT 
%token TYPE_NAME
%token CHAR INT LONG FLOAT DOUBLE VOID
%token IF ELSE WHILE DO 
%token HEADER
%left '+' '-' 
%left '*' '/'

%start start_state
%%

start_state
	: HEADER 
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "preprocessor directive");
			strcpy(symtab[count].symbol, "include");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		} start_state
	| external_declaration				 
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
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "identfier");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	;

/*DECLARATIONS*/

declarator
	: IDENTIFIER
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "identfier");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}    
	;


declaration
	: type_specifier ';' 
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| type_specifier init_declarator_list ';'
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	;

init_declarator_list
	: init_declarator        
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator   
	| declarator '=' 
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "asgnop");
			strcpy(symtab[count].symbol, "=");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		} primary_expression
	| declarator '=' 
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "asgnop");
			strcpy(symtab[count].symbol, "=");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		} simple_expression 		
	;

type_specifier
	: VOID
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "void");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| CHAR
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "char");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| INT
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "int");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| LONG
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "long");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| FLOAT
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "float");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| DOUBLE
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "keyword");
			strcpy(symtab[count].symbol, "double");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	;




compound_statement
	: '{' {scope_count++;} '}' {scope_count--;}
	| '{' {scope_count++;}block_scope_list '}' {scope_count--;}
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
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "identifier");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| CONSTANT
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "constant");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	;

statement
	: expression_statement 
	| compound_statement
	;

expression_statement
	: expression ';' 
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| ';' 
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	;
expression
	: mutable '='
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "asgnop");
			strcpy(symtab[count].symbol, "=");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		} expression 
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
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "sumop");
			strcpy(symtab[count].symbol, "+");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| '-'
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "sumop");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;	
		}
	;

term
	: term mulop unary_expression 
	| unary_expression
	;

mulop
	: '*'
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "mulop");
			strcpy(symtab[count].symbol, "*");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| '/'
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "mulop");
			strcpy(symtab[count].symbol, "/");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
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
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "constant");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	;


mutable
	: IDENTIFIER
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "identfier");
			strcpy(symtab[count].symbol, "-");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	;

%%


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