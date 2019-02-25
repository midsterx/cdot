%{
#include <stdio.h>
%}

%start program

%token BOOL INT CHAR DOUBLE FLOAT LONG

%%
program: BOOL {printf("hi");} | INT {printf("hi");} | CHAR {printf("hi");} | DOUBLE {printf("hi");} | FLOAT {printf("hi");} | LONG {printf("hi");}
%%

int main() {
	yyparse();
}