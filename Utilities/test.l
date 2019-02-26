%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
int line1_flag = 0;
void show(void);
void myerror(void);
%}

%%
"/*"			{ comment(); }
"//"[^\n]*      { /* consume //-single comment */ }

"#include"[ ]*"<".*">" { show(); }
"#include"[ ]*"\"".*"\"" { show(); }
"char"			{ show(); return(CHAR); }
"do"			{ show(); return(DO); }
"double"		{ show(); return(DOUBLE); }
"else"			{ show(); return(ELSE); }
"float"			{ show(); return(FLOAT); }
"if"			{ show(); return(IF); }
"int"			{ show(); return(INT); }
"long"			{ show(); return(LONG); }
"void"			{ show(); return(VOID); }
"while"			{ show(); return(WHILE); }

[a-zA-Z_]([a-zA-Z_]|[0-9])*		{ show(); return(check_type()); }

([0-9])*								{ show(); return(CONSTANT);}
([0-9])+([Ee][+-]?([0-9])+)				{ show(); return(CONSTANT); }
([0-9])*"."([0-9])+([Ee][+-]?([0-9])+)?	{ show(); return(CONSTANT); }
([0-9])+"."([0-9])*([Ee][+-]?([0-9])+)?	{ show(); return(CONSTANT); }


";"			{ show(); return(';'); }
"{" 		{ show(); return('{'); }
"}" 		{ show(); return('}'); }
","			{ show(); return(','); }
"="			{ show(); return('='); }
"("			{ show(); return('('); }
")"			{ show(); return(')'); }
"-"			{ show(); return('-'); }
"+"			{ show(); return('+'); }
"*"			{ show(); return('*'); }
"/"			{ show(); return('/'); }

[\n]		{ yylineno++;
			  show();
			}
[\t]		{ show(); }
[" "]		{;}
.			{ myerror(); }

%%

int yywrap(void)
{
	return 1;
}


void comment(void)
{
	char c, prev = 0;
  
	while ((c = input()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	error("unterminated comment");
}


void show(void)
{
	if (yylineno == 1 && line1_flag == 0)
	{
		printf("%d", yylineno);
		line1_flag = 1;
	}
	if (strcmp(yytext,"\n") == 0)
	{
		printf("\n%d", yylineno);	
	}
	else
	{
		ECHO;
	}
	printf(" ");
}

void myerror(void)
{
	printf("Error at Line Number: %d %s", yylineno, yytext);
}

int check_type(void)
{
	return IDENTIFIER;
}