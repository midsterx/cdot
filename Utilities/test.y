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
	: scoped_type_specifier ';' 
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| scoped_type_specifier init_declarator_list ';' 
		{
			symtab[count].token_num = token_count++;
			strcpy(symtab[count].type, "punctuation");
			strcpy(symtab[count].symbol, ";");
			strcpy(symtab[count].value, "-");
			symtab[count].scope_num = scope_count;
			symtab[count].line_num = yylineno;
			count++;
		}
	| STRUCT IDENTIFIER declarator ';'
	;

init_declarator_list
	: init_declarator        
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator   
	| declarator {printf("declarator\n");} '=' 
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
	: STRUCT IDENTIFIER '{' simple_declaration '}' ';'
	;

simple_declaration
	: type_specifier IDENTIFIER ';'
	| simple_declaration type_specifier IDENTIFIER ';'
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
	| conditional_statement
	| iteration_statement
	| break_statement
	| continue_statement
	| return_statement
	| statement ';' statement
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
	| mutable SHORTHANDADD expression
	| mutable SHORTHANDSUB expression
	| mutable SHORTHANDMULT expression
	| mutable SHORTHANDDIV expression
	| mutable INCREMENT
	| mutable DECREMENT
	| simple_expression
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