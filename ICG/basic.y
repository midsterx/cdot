%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "symnode.h"

	struct scopeTable *symtab = NULL;
	int succ = 0;

	extern int yylineno;
	extern char *yytext;

	char gvar[15] = "";
	int gscope = 0;
	int yylex(void);
	int yyerror(const char *s);
  int param_count;

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
	: type_specifier declarator '('{ param_count=0; } params { codegen_param(param_count); param_count=0; } ')' compound_statement
	;

params
	: param_decl {param_count++;}
	| param_decl ',' params {param_count++;}
	;

param_decl
	: type_specifier declarator
	| type_specifier
	;


/*DECLARATIONS*/

declarator
	: IDENTIFIER { push(); }
	;

declaration
	: type_specifier init_declarator_list ';'
	| type_specifier ';'
	;

init_declarator_list
	: init_declarator {codegen_assign();}
	| init_declarator_list ',' init_declarator {codegen_assign();} 
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
	: declarator
	| CONSTANT
		{
			push();
		}
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


compound_statement
	: '{' '}'
	| '{' block_scope_list '}'
	;

block_scope_list
	: block_item
	| block_item block_scope_list
	;

block_item
	: declaration
	;


%%


void main()
{
  f1=fopen("output","w");
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
