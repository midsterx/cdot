%{
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

	 	top-=2; //only with this will it come perfectly .. check by uncommenting above lines to see the stack
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
	| translation_unit
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
	| params ',' param_decl
	;

param_decl					
	: scoped_type_specifier declarator
	| scoped_type_specifier
	;


/*DECLARATIONS*/

declarator
	: IDENTIFIER
		{
			//superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
			push();
		}    
	;

declaration
	: scoped_type_specifier init_declarator_list ';' 
	| STRUCT IDENTIFIER declarator ';'
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
	: STRUCT IDENTIFIER '{' { /*addScope();*/ } simple_declaration '}' { /*delScope();*/ } ';'
	;

simple_declaration
	: type_specifier IDENTIFIER ';'
	| simple_declaration type_specifier IDENTIFIER ';'
	;


primary_expression
	: declarator
	| CONSTANT
		{
			//superAdd(token_count, "identifier", $1, "-", scope_count, yylineno, 1, 0);
			push();
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
	: expression {codegen_assign();}  ';' 
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
	: '{' { /*addScope*/} '}' { /*delScope();*/ }
	| '{' { /*addScope();*/ } block_scope_list '}' { /*delScope();*/ }
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
	: IF '(' condition ')'  {if_label1();}  compound_statement {if_label3();}
	| IF '(' condition ')'  {if_label1();} compound_statement {if_label2(); } ELSE compound_statement {if_label3();}
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
	| sum_expression RELOP {push();}  sum_expression {codegen_logical();}
	;

sum_expression
	: sum_expression sumop {push();}  term {codegen_logical();}
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
	: term mulop {push();} factor {codegen_logical();}
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