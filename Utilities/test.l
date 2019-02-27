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

"#include"[ ]*"<".*">" { show(); return(HEADER); }
"#include"[ ]*"\"".*"\"" { show(); return(HEADER); }
"do"			{ show(); return(DO); }
"else"			{ show(); return(ELSE); }
"if"			{ show(); return(IF); }
"while"			{ show(); return(WHILE); }


"int"			{ show(); return(INT); }
"char"			{ show(); return(CHAR); }
"long"			{ show(); return(LONG); }
"void"			{ show(); return(VOID); }
"double"		{ show(); return(DOUBLE); }
"float"			{ show(); return(FLOAT); }
"short"         { show(); return(SHORT); }
"long"         { show(); return(LONG); }
"unsigned"         { show(); return(UNSIGNED); }
"signed"         { show(); return(SIGNED); }


"static" { show(); return(STATIC); }
"extern" { show(); return(EXTERN); }
"register" { show(); return(REGISTER); }
"auto" { show(); return(AUTO); }

"+=" { show(); return(SHORTHANDADD); }
"-=" { show(); return(SHORTHANDSUB); }
"*=" { show(); return(SHORTHANDMULT); }
"/=" { show(); return(SHORTHANDDIV); }
"!" { show(); return(NOT); }

"++" { show(); return(INCREMENT); }
"--" { show(); return(DECREMENT); }

[><] { show(); return(RELOP); }
">=" { show(); return(RELOP); }
"<=" { show(); return(RELOP); }
"==" { show(); return(RELOP); }
"!=" { show(); return(RELOP); }

"&&" {show(); return(AND);}
"||" {show(); return(OR);}

"break"     { show(); return(BREAK); }
"continue"  { show(); return(CONTINUE); }
"return"    { show(); return(RETURN); }

"struct" { show(); return(STRUCT); }

"[]" { show(); return(ARRTYPE); }

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