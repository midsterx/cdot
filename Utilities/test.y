%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>

	#define MOD 1007
	#define PRIME 23
	#define MAX 300

	extern int yylineno;
	extern char yytext[];

	struct node
	{
		int token_num;
		char type[100];
		char symbol[100];
		char value[100];
		int line_num;
		int scope_num;
		struct node *next;
	} *symtab[MAX];

	int token_count = 0; // total tokens count
	int scope_count = 0; // scope count

	void printsymtab(void);
	struct node* lookup(const char* str);
	int hash(char *str);
	void insert(int tn, char t[], char s[], char v[], int ln, int sn, int token_count_flag, int scope_count_flag);
	char* find(char* str);
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
			insert(token_count, "identfier", $1, "-", scope_count, yylineno, 1, 0);
		}
	;

/*DECLARATIONS*/

declarator
	: IDENTIFIER
		{
			insert(token_count, "identfier", $1, "-", scope_count, yylineno, 1, 0);
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
	: STRUCT IDENTIFIER '{' simple_declaration '}' ';'
	;

simple_declaration
	: type_specifier IDENTIFIER ';'
	| simple_declaration type_specifier IDENTIFIER ';'
	;

primary_expression
	: IDENTIFIER
		{
			insert(token_count, "identfier", $1, "-", scope_count, yylineno, 1, 0);
		}
	| CONSTANT
		{
			insert(token_count, "identfier", $1, "-", scope_count, yylineno, 1, 0);
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
			insert(token_count, "identfier", $1, "-", scope_count, yylineno, 1, 0);
		}
	;


mutable
	: IDENTIFIER
		{
			insert(token_count, "identfier", $1, "-", scope_count, yylineno, 1, 0);
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
	extern int yylineno;
	printf("\nParse Failed\n");
	printf("Error Line Number: %d %s", yylineno, s);
	fflush(stdout);
}

//hash function
int hash(char* str)
{
	int len = strlen(str);
    int hash_value = 0;

    for(int i=0; i<len; i++)
    {
    	hash_value = (hash_value * PRIME + str[i]) % MOD;
    }

    printf("Hashed result:%d\n",hash_value);

    return hash_value;
} 

//insert function
void insert(int tn, char t[], char s[], char v[], int ln, int sn, int token_count_flag, int scope_count_flag) 
{
    if(lookup(s) != NULL)
        return;
	int hashValue = hash(s);
    struct node *temp = malloc(sizeof(struct node));

    temp->token_num = tn++;
	strcpy(temp->type, t);
	strcpy(temp->symbol, s);
	strcpy(temp->value, v);
	temp->scope_num = sn;
	temp->line_num = ln;
	
	if (symtab[hashValue] == NULL)
	{
		symtab[hashValue] = temp;
	}
    else
	{
		struct node* start = symtab[hashValue];
		while (start->next != NULL)
			start = start->next;
		start->next = temp;
	}
    // temp->next = symtab[hashValue];
    // symtab[hashValue] = temp;
}

struct node *lookup(const char *str) 
{
	int len = strlen(str);
	int hashValue = hash(str);

	//get node at hash value
	struct node *temp = symtab[hashValue];

	while(temp != NULL) 
	{
	    if(!strcmp(str, temp->symbol))
	        return temp;
	    temp = temp->next;
	}
	return NULL;
}

void printsymtab(void)
{
	printf("\n\nSYMBOL TABLE\n\n");
	printf("Token No.\tType\tSymbol\tValue\tScope No.\tLine No.");
	int i;
	printf("\n");
	for (i = 0;i < MAX;i++)
	{
		printf("\n%d\t%s\t%s\t%s\t%d\t%d", symtab[i]->token_num, symtab[i]->type, symtab[i]->symbol, symtab[i]->value, symtab[i]->scope_num, symtab[i]->line_num);
	}
}